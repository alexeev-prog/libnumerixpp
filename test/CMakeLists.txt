cmake_minimum_required(VERSION 3.14)

project(libnumerixppTests LANGUAGES CXX)

include(../cmake/project-is-top-level.cmake)
include(../cmake/folders.cmake)

# ---- Dependencies ----

if(PROJECT_IS_TOP_LEVEL)
  find_package(libnumerixpp REQUIRED)
  enable_testing()
endif()

find_package(Catch2 REQUIRED)
include(Catch)

# ---- Tests ----

add_executable(libnumerixpp_test source/libnumerixpp_test.cpp)
target_link_libraries(
    libnumerixpp_test PRIVATE
    libnumerixpp::libnumerixpp
    Catch2::Catch2WithMain
)
target_compile_features(libnumerixpp_test PRIVATE cxx_std_17)

catch_discover_tests(libnumerixpp_test)

# ---- End-of-file commands ----

add_folders(Test)
