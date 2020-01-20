# Support CMake version shipping with Ubuntu 18.04 LTS
cmake_minimum_required(VERSION 3.10)

project(reaper_minimal_plugin VERSION 0.1.0 LANGUAGES CXX)

add_library(reaper_minimal_plugin SHARED
    src/main.cpp
    lib/WDL/WDL/swell/swell-modstub-generic.cpp
    )
target_include_directories(reaper_minimal_plugin
    PRIVATE
    lib/reaper
    lib/WDL
    )

# We want to use SWELL provided by REAPER itself
target_compile_definitions(reaper_minimal_plugin PRIVATE SWELL_PROVIDED_BY_APP)

# REAPER loads plugins only if they start with reaper_, not libreaper_ (so we need to strip "lib" prefix)
SET_TARGET_PROPERTIES(reaper_minimal_plugin PROPERTIES PREFIX "")

# We want strict C++-11
target_compile_features(reaper_minimal_plugin PRIVATE cxx_std_11)
set_target_properties(reaper_minimal_plugin PROPERTIES CXX_EXTENSIONS OFF)