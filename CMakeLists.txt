cmake_minimum_required(VERSION 3.16)
project(SA-SocialGau CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(PkgConfig REQUIRED)
pkg_check_modules(JSONCPP REQUIRED jsoncpp)

add_library(SA-SocialGau_core
    src/args.cpp
    src/io.cpp
    src/predictor.cpp
    src/metrics.cpp
    src/sd_utils.cpp
)
target_include_directories(SA-SocialGau_core PUBLIC include ${JSONCPP_INCLUDE_DIRS})
target_link_libraries(SA-SocialGau_core ${JSONCPP_LIBRARIES})

add_executable(SA-SocialGau src/main.cpp)
target_link_libraries(SA-SocialGau SA-SocialGau_core)

enable_testing()
add_executable(test_metrics tests/test_metrics.cpp)
target_link_libraries(test_metrics SA-SocialGau_core)
add_test(NAME metrics COMMAND test_metrics)
