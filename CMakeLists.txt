cmake_minimum_required(VERSION 3.13)
project(BD)

set(CMAKE_CXX_STANDARD 14)

include_directories(archivoslongdinamica)
include_directories(archivoslongfija)

add_executable(BD archivoslongfija/lab2.1.cpp )
