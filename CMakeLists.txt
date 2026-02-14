cmake_minimum_required(VERSION 3.25)
project(mp_units_cgs_demo LANGUAGES CXX)

if(CMAKE_CXX_COMPILER_ID STREQUAL "AppleClang")
  message(FATAL_ERROR
    "AppleClang is not supported for this project. "
    "Use LLVM clang instead, for example: "
    "-DCMAKE_CXX_COMPILER=/opt/homebrew/opt/llvm/bin/clang++")
endif()

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Keep mp-units dependency-free in this standalone demo build.
set(MP_UNITS_API_CONTRACTS "NONE" CACHE STRING "" FORCE)
set(MP_UNITS_API_STD_FORMAT OFF CACHE BOOL "" FORCE)
set(MP_UNITS_API_NO_CRTP ON CACHE BOOL "" FORCE)
set(MP_UNITS_BUILD_INSTALL OFF CACHE BOOL "" FORCE)
set(MP_UNITS_BUILD_CXX_MODULES OFF CACHE BOOL "" FORCE)

add_subdirectory(mp-units/src)

add_executable(mp_units_cgs_demo mp_units_cgs_demo.cpp)
target_link_libraries(mp_units_cgs_demo PRIVATE mp-units::systems)
