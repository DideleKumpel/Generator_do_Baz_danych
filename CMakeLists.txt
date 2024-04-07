cmake_minimum_required(VERSION 3.26)
project(Generator_do_Baz_danych)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_EXE_LINKER_FLAGS "-static")

add_executable(Generator_do_Baz_danych main.cpp
        Tstudent.cpp
        Tosoba.cpp
        Twykladowca.cpp
        BazaDanychFunkcje.cpp
        OblusgaBleduCin.cpp)
