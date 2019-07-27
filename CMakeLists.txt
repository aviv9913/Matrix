cmake_minimum_required(VERSION 3.13)
project(Matrix)

set(CMAKE_CXX_STANDARD 11)

add_executable(Matrix main.cpp Matrix.cpp Matrix.h Neural_Network.cpp Neural_Network.h)