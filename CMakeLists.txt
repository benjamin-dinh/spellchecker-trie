cmake_minimum_required(VERSION 3.14)
project(p4)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(Testing)

add_executable(p4
        CheckerRunner.cpp
        CheckerRunner.h
        CPUTimer.h
        cmake-build-debug/words.txt
        checker.cpp
        checker.h
        Trie.h
        Trie.cpp)
