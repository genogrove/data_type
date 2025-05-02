cmake_minimum_required(VERSION 3.10)
project(genogrove_data_type)
set(CMAKE_CXX_STANDARD 20)


if(NOT TARGET genogrove_config)
    include(FetchContent)
    FetchContent_Declare(
            genogrove_config
            GIT_REPOSITORY https://github.com/genogrove/config.git
            GIT_TAG main # TODO: change to release version
    )
    FetchContent_MakeAvailable(genogrove_config)
endif()

# Conditionally add range-v3 if using C++17 (and if hasn't been added yet)
if(CMAKE_CXX_STANDARD EQUAL 17)
    if(NOT TARGET range-v3)
        FetchContent_Declare(
                range-v3
                https://github.com/ericniebler/range-v3.git
                GIT_TAG 0.12.0
        )
        FetchContent_MakeAvailable(range-v3)
        set(RANGES_LIB range-v3)
    else()
        message(STATUS "Range-v3 already added")
    endif()
else()
    message(STATUS "C++20 or newer detected, skipping range-v3 dependency")
    set(RANGES_LIB "")
endif()


# create the data_type library
FILE(GLOB SOURCES "src/*.cpp")
add_library(genogrove_data_type ${SOURCES})
target_include_directories(genogrove_data_type
        PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
)

target_link_libraries(genogrove_data_type genogrove_config)

# optionally include tests
if(BUILD_TESTS)
    enable_testing()
    add_subdirectory(tests)
endif()



