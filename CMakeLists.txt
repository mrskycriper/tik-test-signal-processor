cmake_minimum_required(VERSION 3.23)
project(tik-signal-processor)

set(CMAKE_CXX_STANDARD 20)

include_directories("/usr/local/include")

find_package(PkgConfig REQUIRED)
pkg_search_module(FFTW REQUIRED fftw3 IMPORTED_TARGET)
include_directories(PkgConfig::FFTW)
link_libraries(PkgConfig::FFTW)

add_executable(tik-signal-processor
        main.cpp
        main.hpp signal-processor.hpp settings.cpp settings.hpp file_io.cpp file_io.hpp signal-processor.cpp)