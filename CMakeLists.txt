cmake_minimum_required(VERSION 4.3.2)

set(CMAKE_CXX_STANDARD 26)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

project(RouteGuard VERSION 1.0 LANGUAGES CXX)

add_executable(RouteGuard
    "Program Files/Source Files/RouteGuard.cpp"
)

# Include Directories
target_include_directories(RouteGuard PRIVATE
    "Program Files/Header Files"
    "Program Files/Header Files/Core"
    "Program Files/Header Files/Networking"
    "Program Files/Header Files/Security"
    "Program Files/Header Files/Logging"
    "Program Files/Header Files/Simulation"
    "Program Files/Header Files/Utilities"
)

# Compiler Configuration
if(CMAKE_CXX_COMPILER_ID STREQUAL "Clang")

    target_compile_options(RouteGuard PRIVATE
        # Architecture
        -m64
        -march=x86-64-v3

        # Optimization
        -Ofast
        -fstrict-aliasing

        # Diagnostics
        -Wall
        -Wextra
        -Wshadow
        -Wpedantic
        -Wconversion

        # clang-cl compatibility
        /std:c++latest
        -Xclang -std=c++2c

        # Platform
        /EHsc
        /utf-8

        # Cleanup Crew
        -Wno-c++98-compat
        -Wno-c++98-compat-pedantic
        -Wno-unsafe-buffer-usage
        -Wno-padded
        -Wno-old-style-cast
        -Wno-missing-prototypes
    )

elseif(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")

    target_compile_options(RouteGuard PRIVATE
        # Architecture
        -m64
        -march=x86-64-v3

        # Optimization
        -O3
        -fstrict-aliasing

        # Diagnostics
        -Wall
        -Wextra
        -Wshadow
        -Wpedantic
        -Wconversion
    )

endif()

target_compile_features(RouteGuard PRIVATE cxx_std_26)

set_target_properties(RouteGuard PROPERTIES 
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}"
)
