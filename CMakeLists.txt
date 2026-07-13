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

# Compiler Warnings
if("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
    target_compile_options(RouteGuard PRIVATE 
        $<$<COMPILE_LANGUAGE:CXX>: /W3 /std:c++latest /utf-8 /EHsc -m64 >
    )
else()
    target_compile_options(RouteGuard PRIVATE -Wall -Wextra -Wpedantic)
endif()

set_target_properties(RouteGuard PROPERTIES 
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}"
)
