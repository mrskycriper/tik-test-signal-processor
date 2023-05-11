#include "settings.hpp"

void settings::parse_args(int argc, char **argv) {
    // Expected order of arguments:
    // in_path out_path_spectrum out_path_envelope out_path_envelope_spectrum
    if (argc != 5) {
        throw std::runtime_error("Invalid number of arguments provided. Expected: 5, got: " + std::to_string(argc));
    }
    this->in_path = argv[1];
    this->out_path_spectrum = argv[2];
    this->out_path_envelope = argv[3];
    this->out_path_envelope_spectrum = argv[4];
}
