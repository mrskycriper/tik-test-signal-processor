#include <fstream>
#include <iostream>
#include "file_io.hpp"

class data_container file_io::read_file(const std::string &path, file_type type) {
    data_container data = data_container();

    std::ifstream fin(path);
    if (!fin) {
        std::cerr << "error: open file for input failed!" << std::endl;
        abort();
    }
    std::string buffer;
    fin >> buffer;
    std::string tag = buffer.substr(0, 4);
    std::string file_type = buffer.substr(5);

    if (tag != "type") {
        std::cerr << "error: wrong file format!" << std::endl;
        abort();
    }

    if (tag == "signal") {
        if (type != file_type::SIGNAL_FILE) {
            std::cerr << "error: wrong file format!" << std::endl;
            abort();
        }
    }

    if (tag == "spectrum") {
        if (type != file_type::SPECTRUM_FILE) {
            std::cerr << "error: wrong file format!" << std::endl;
            abort();
        }
    }

    if (tag == "envelope") {
        if (type != file_type::ENVELOPE_FILE) {
            std::cerr << "error: wrong file format!" << std::endl;
            abort();
        }
    }

    fin >> buffer;
    tag = buffer.substr(0, 4);
    unsigned long long size = stoull(buffer.substr(5));
    if (tag != "size") {
        std::cerr << "error: wrong file format!" << std::endl;
        abort();
    }
    data.size = size;
    for (int i = 0; i < data.size; i++) {
        fin >> buffer;
        auto strings = split(buffer, ';');
        double double_buffer = stod(strings[1]);
        data.data.push_back(double_buffer);
    }
    fin.close();
    return data;
}

void file_io::write_file(const std::string &path, data_container data, file_type type) {
    std::ofstream out(path);
    std::string file_type;
    if (type == file_type::SIGNAL_FILE) {
        file_type = "signal";
    } else if (type == file_type::SPECTRUM_FILE) {
        file_type = "spectrum";
    } else if (type == file_type::ENVELOPE_FILE) {
        file_type = "envelope";
    }
    out << "type;" << file_type << std::endl;
    out << "size;" << data.size << std::endl;
    for (size_t i = 0; i < data.size; ++i) {
        out << i << ";" << data.data[i] << std::endl;
    }
    out.close();

}

std::vector<std::string> file_io::split(const std::string &str, char separator) {
    std::vector<std::string> strings;
    int startIndex = 0, endIndex = 0;
    for (int i = 0; i <= str.size(); i++) {

        // If we reached the end of the word or the end of the input.
        if (str[i] == separator || i == str.size()) {
            endIndex = i;
            std::string temp;
            temp.append(str, startIndex, endIndex - startIndex);
            strings.push_back(temp);
            startIndex = endIndex + 1;
        }
    }
    return strings;
}
