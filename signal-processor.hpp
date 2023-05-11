#ifndef TIK_SIGNAL_PROCESSOR_SIGNAL_PROCESSOR_HPP
#define TIK_SIGNAL_PROCESSOR_SIGNAL_PROCESSOR_HPP

#include <vector>
#include <complex>
#include <fftw3.h>

enum container_type {
    SIGNAL_CONTAINER,
    SPECTRUM_CONTAINER,
};

class data_container {
public:
    unsigned long long size = 0;
    unsigned long long length = 0;
    double lower_frequency = 0;
    double upper_frequency = 0;
    container_type type = container_type::SIGNAL_CONTAINER;
    std::vector<double> data;
};

class signal_processor {
public:
    static data_container calculate_spectrum(data_container signal) {
        unsigned long long input_size = signal.size;
        unsigned long long output_size = (input_size / 2 + 1);
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
};


#endif //TIK_SIGNAL_PROCESSOR_SIGNAL_PROCESSOR_HPP
