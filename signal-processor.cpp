#include "signal-processor.hpp"

data_container signal_processor::calculate_spectrum(const data_container& signal) {
    unsigned long long input_size = signal.size;
    unsigned long long output_size = (input_size / 2);
    std::vector<std::complex<double>> input_buffer(input_size, 0.);
    for (unsigned long long i = 0; i < input_size; i++) {
        input_buffer[i] = signal.data[i];
    }
    std::vector<std::complex<double>> output_buffer(input_size, 0.);

    // TODO добавить проверку на степень 2 или починить размерность
    fftw_plan f_plan = fftw_plan_dft_1d(input_size,
                                        (fftw_complex *) &input_buffer[0], (fftw_complex *) &output_buffer[0],
                                        FFTW_FORWARD, FFTW_ESTIMATE);
    fftw_execute(f_plan);
    fftw_destroy_plan(f_plan);

    data_container signal_spectrum = data_container();
    for (unsigned long long i = 0; i < output_size; ++i) {
        signal_spectrum.data.push_back(sqrt(output_buffer[i].real() * output_buffer[i].real() +
                                            output_buffer[i].imag() * output_buffer[i].imag()));
    }
    signal_spectrum.size = output_size;
    signal_spectrum.type = container_type::SPECTRUM_CONTAINER;
    return signal_spectrum;
}

data_container signal_processor::calculate_envelope(const data_container& signal) {
    auto spectrum = signal_processor::calculate_spectrum(signal);

    for (size_t i = 0; i < spectrum.size; ++i) {
        if (i != 0 ) {spectrum.data[i] *= 2;}
    }
    for (size_t i = spectrum.size; i < signal.size; ++i) {
        spectrum.data.push_back(0);
    }

    std::vector<std::complex<double>> input_buffer(signal.size, 0.);
    for (unsigned long long i = 0; i < signal.size; i++) {
        input_buffer[i] = spectrum.data[i];
    }
    std::vector<std::complex<double>> output_buffer(signal.size, 0.);

    fftw_plan plan = fftw_plan_dft_1d(signal.size, (fftw_complex *) &input_buffer[0], (fftw_complex *) &output_buffer[0], FFTW_BACKWARD,
                                      FFTW_ESTIMATE);

    fftw_execute(plan);
    fftw_destroy_plan(plan);

    data_container signal_envelope = data_container();

    for (size_t i = 0; i < signal.size; ++i) {
        signal_envelope.data.push_back(sqrt(output_buffer[i].real() * output_buffer[i].real() + output_buffer[i].imag() * output_buffer[i].imag()));
    }

    for (int i = 0; i < signal.size; i++) {
        //signal_envelope.data[i] = abs(signal_envelope.data[i]);
        signal_envelope.data[i] = signal_envelope.data[i] / signal.size;
    }
    signal_envelope.size = signal.size;
    signal_envelope.type = container_type::SIGNAL_CONTAINER;

    return signal_envelope;
}
