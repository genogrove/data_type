message(STATUS "Building tests")
include(FetchContent)
FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG v1.16.0
)
FetchContent_MakeAvailable(googletest)
include(GoogleTest)

# gather all test sources
#set(
#        TEST_SOURCES
#        index-test.cpp
#        interval-test.cpp
#)
FILE(GLOB TEST_SOURCES "*.cpp")

# create the test executable
add_executable(genogrove_data_type_tests ${TEST_SOURCES})

# add include paths
#target_include_directories(
#        genogrove_data_type_tests
#        PUBLIC
#        ${CMAKE_CURRENT_SOURCE_DIR}/../include
#)

target_link_libraries(genogrove_data_type_tests
        genogrove_data_type
        GTest::gtest
        GTest::gtest_main
)

gtest_discover_tests(genogrove_data_type_tests)



