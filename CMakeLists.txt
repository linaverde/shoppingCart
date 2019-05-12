cmake_minimum_required(VERSION 3.12)
project(shop)

set(CMAKE_CXX_STANDARD 14)

add_executable(shop main.cpp Products.cpp Products.h Cart.cpp Cart.h)