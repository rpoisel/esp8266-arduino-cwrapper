project("ESP8266 Arduino C Wrapper" C CXX ASM)
cmake_minimum_required(VERSION 3.0)

add_subdirectory(external)

add_subdirectory(wrapper)
add_subdirectory(user)
