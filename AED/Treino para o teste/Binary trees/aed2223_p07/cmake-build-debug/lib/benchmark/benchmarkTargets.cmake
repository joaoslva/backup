# Generated by CMake

if("${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION}" LESS 2.6)
   message(FATAL_ERROR "CMake >= 2.6.0 required")
endif()
cmake_policy(PUSH)
cmake_policy(VERSION 2.6...3.21)
#----------------------------------------------------------------
# Generated CMake target import file.
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Protect against multiple inclusion, which would fail when already imported targets are added once more.
set(_targetsDefined)
set(_targetsNotDefined)
set(_expectedTargets)
foreach(_expectedTarget benchmark::benchmark benchmark::benchmark_main)
  list(APPEND _expectedTargets ${_expectedTarget})
  if(NOT TARGET ${_expectedTarget})
    list(APPEND _targetsNotDefined ${_expectedTarget})
  endif()
  if(TARGET ${_expectedTarget})
    list(APPEND _targetsDefined ${_expectedTarget})
  endif()
endforeach()
if("${_targetsDefined}" STREQUAL "${_expectedTargets}")
  unset(_targetsDefined)
  unset(_targetsNotDefined)
  unset(_expectedTargets)
  set(CMAKE_IMPORT_FILE_VERSION)
  cmake_policy(POP)
  return()
endif()
if(NOT "${_targetsDefined}" STREQUAL "")
  message(FATAL_ERROR "Some (but not all) targets in this export set were already defined.\nTargets Defined: ${_targetsDefined}\nTargets not yet defined: ${_targetsNotDefined}\n")
endif()
unset(_targetsDefined)
unset(_targetsNotDefined)
unset(_expectedTargets)


# Create imported target benchmark::benchmark
add_library(benchmark::benchmark STATIC IMPORTED)

set_target_properties(benchmark::benchmark PROPERTIES
  INTERFACE_COMPILE_DEFINITIONS "BENCHMARK_STATIC_DEFINE"
  INTERFACE_INCLUDE_DIRECTORIES "/home/juao/Desktop/AED/Treino para o teste/Binary trees/aed2223_p07/lib/benchmark/include"
  INTERFACE_LINK_LIBRARIES "\$<LINK_ONLY:Threads::Threads>;\$<LINK_ONLY:rt>"
)

# Create imported target benchmark::benchmark_main
add_library(benchmark::benchmark_main STATIC IMPORTED)

set_target_properties(benchmark::benchmark_main PROPERTIES
  INTERFACE_LINK_LIBRARIES "benchmark::benchmark"
)

# Import target "benchmark::benchmark" for configuration "Debug"
set_property(TARGET benchmark::benchmark APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(benchmark::benchmark PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_DEBUG "CXX"
  IMPORTED_LOCATION_DEBUG "/home/juao/Desktop/AED/Treino para o teste/Binary trees/aed2223_p07/cmake-build-debug/lib/benchmark/src/libbenchmark.a"
  )

# Import target "benchmark::benchmark_main" for configuration "Debug"
set_property(TARGET benchmark::benchmark_main APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(benchmark::benchmark_main PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_DEBUG "CXX"
  IMPORTED_LOCATION_DEBUG "/home/juao/Desktop/AED/Treino para o teste/Binary trees/aed2223_p07/cmake-build-debug/lib/benchmark/src/libbenchmark_main.a"
  )

# This file does not depend on other imported targets which have
# been exported from the same project but in a separate export set.

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
cmake_policy(POP)
