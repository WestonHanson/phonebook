cmake_minimum_required(VERSION 3.16)
project(phonebook)

set(CMAKE_CXX_STANDARD 14)

add_executable(phonebook main.cpp person.cpp person.h)
