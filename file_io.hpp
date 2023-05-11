#ifndef TIK_SIGNAL_PROCESSOR_FILE_IO_HPP
#define TIK_SIGNAL_PROCESSOR_FILE_IO_HPP

#include <string>
#include "signal-processor.hpp"

enum file_type {
    SIGNAL_FILE,
    SPECTRUM_FILE,
    ENVELOPE_FILE,
};

class file_io {
public:
    static class data_container read_file(const std::string &path, file_type type);

    static void write_file(const std::string &path, class data_container data, file_type type);

    static std::vector<std::string> split(const std::string &str, char separator);
};


#endif //TIK_SIGNAL_PROCESSOR_FILE_IO_HPP
