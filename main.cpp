#include "main.hpp"
#include "signal-processor.hpp"
#include "file_io.hpp"
#include "settings.hpp"

#include <fstream>
#include <iostream>
#include <cstdlib>
#include <fftw3.h>
#include <complex>
#include <cmath>
#include <string>

int main(int argc, char *argv[]) {
    auto Settings = settings();
    Settings.parse_args(argc, argv);

    data_container signal = file_io::read_file(Settings.in_path, file_type::SIGNAL_FILE);
    auto spectrum = signal_processor::calculate_spectrum(signal);
    file_io::write_file(Settings.out_path_spectrum, spectrum, file_type::SPECTRUM_FILE);

//    std::cout << Params.number_of_data_points << std::endl;
//    std::vector<std::complex<double>> data(signal.size, 1.);
//    for (int i = 0; i < signal.size; i++) {
//        data[i] = signal.data[i];
//    }
//    std::cout << data[5000] << std::endl;
//    int fftSampleCount = Params.number_of_data_points / 2 + 1;
//
//    fftw_plan plan = fftw_plan_dft_r2c_1d(signal.size, &signal.data[0], (fftw_complex *) &data[0],
//                                      FFTW_ESTIMATE);

    // преобразование Фурье
//    fftw_execute(plan);
//    fftw_destroy_plan(plan);
//    std::cout << data[5000] << std::endl;


//
//    std::vector<std::complex<double>> tmp_signal_spectrum(Params.number_of_data_points, 1.);
//    for (int i = 0; i < Params.number_of_data_points; i++) {
//        tmp_signal_spectrum[i] = signal_spectrum[i];
//    }
//    for (size_t i = 0; i < fftSampleCount; ++i) {
//        if (i == 0 || i == fftSampleCount - 1) {
//            tmp_signal_spectrum[i] *= 1;
//        }
//        else {tmp_signal_spectrum[i] *= 2;}
//    }
//    for (size_t i = fftSampleCount; i < Params.number_of_data_points; ++i) {
//        tmp_signal_spectrum[i] *= 0;
//    }
//
//    fftw_plan plan2 = fftw_plan_dft_1d(Params.number_of_data_points, (fftw_complex *) &tmp_signal_spectrum[0], (fftw_complex *) &tmp_signal_spectrum[0], FFTW_BACKWARD,
//                                      FFTW_ESTIMATE);
//
//    fftw_execute(plan2);
//    fftw_destroy_plan(plan2);
//
//    std::vector<double> signal_envelope;
//
//    for (size_t i = 0; i < Params.number_of_data_points; ++i) {
//        signal_envelope.push_back(sqrt(tmp_signal_spectrum[i].real() * tmp_signal_spectrum[i].real() + tmp_signal_spectrum[i].imag() * tmp_signal_spectrum[i].imag()));
//    }
//
//    for (int i = 0; i < Params.number_of_data_points; i++) {
//        signal_envelope[i] = abs(signal_envelope[i]);
//    }
//
//    std::ofstream out2(Settings.out_path_envelope);
//    for (size_t i = 0; i < Params.number_of_data_points; ++i) {
//        out2 << signal_envelope[i] << std::endl;
//    }
//    out2.close();
//
//    std::vector<std::complex<double>> data2(Params.number_of_data_points, 1.);
//    std::vector<std::complex<double>> data3(Params.number_of_data_points, 1.);
//    for (int i = 0; i < Params.number_of_data_points; i++) {
//        data2[i] = signal_envelope[i];
//    }
//
//    fftw_plan plan3 = fftw_plan_dft_1d(data.size(), (fftw_complex *) &signal_envelope[0], (fftw_complex *) &data3[0], FFTW_FORWARD,
//                                      FFTW_ESTIMATE);
//
//    // преобразование Фурье
//    fftw_execute(plan3);
//    fftw_destroy_plan(plan3);
//
//
//    std::vector<double> signal_envelope_spectrum;
//
//    for (size_t i = 0; i < Params.number_of_data_points; ++i) {
//        signal_envelope_spectrum.push_back(sqrt(data3[i].real() * data3[i].real() + data3[i].imag() * data3[i].imag()));
//    }
//
//    std::ofstream out3(Settings.out_path_envelope_spectrum);
//    for (size_t i = 0; i < Params.number_of_data_points; ++i) {
//        out3 << signal_envelope_spectrum[i] << std::endl;
//    }
//    out3.close();


}

