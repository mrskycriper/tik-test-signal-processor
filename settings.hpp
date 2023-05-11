#ifndef TIK_SIGNAL_PROCESSOR_SETTINGS_HPP
#define TIK_SIGNAL_PROCESSOR_SETTINGS_HPP

#include <string>
#include <stdexcept>

class settings {
public:
    std::string in_path;
    std::string out_path_spectrum;
    std::string out_path_envelope;
    std::string out_path_envelope_spectrum;

    void parse_args(int argc, char *argv[]);
};


#endif //TIK_SIGNAL_PROCESSOR_SETTINGS_HPP
