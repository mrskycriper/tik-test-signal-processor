#pragma once
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
    static data_container calculate_spectrum(const data_container& signal);

    static data_container calculate_envelope(const data_container& signal);
};

#endif //TIK_SIGNAL_PROCESSOR_SIGNAL_PROCESSOR_HPP
