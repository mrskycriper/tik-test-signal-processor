#include "main.hpp"

int main(int argc, char *argv[]) {
    auto Settings = settings();
    Settings.parse_args(argc, argv);

    data_container signal = file_io::read_file(Settings.in_path, file_type::SIGNAL_FILE);
    auto spectrum = signal_processor::calculate_spectrum(signal);
    file_io::write_file(Settings.out_path_spectrum, spectrum, file_type::SPECTRUM_FILE);

    auto envelope = signal_processor::calculate_envelope(signal);
    file_io::write_file(Settings.out_path_envelope, envelope, file_type::ENVELOPE_FILE);
}

