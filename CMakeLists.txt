cmake_minimum_required(VERSION 3.14)

include(cmake/prelude.cmake)

project(
    libnumerixpp
    VERSION 0.1.2
    DESCRIPTION "A Powerful C++ Library for High-Performance Numerical Computing"
    HOMEPAGE_URL "https://alxvdev.github.io/libnumerixpp"
    LANGUAGES CXX
)

include(cmake/project-is-top-level.cmake)
include(cmake/variables.cmake)

# ---- Declare library ----

add_library(
    libnumerixpp_libnumerixpp
    src/libnumerixpp.cpp
    src/core/common.cpp
    src/mathematics/equations.cpp
    src/mathematics/core.cpp
    src/mathematics/quadratic_equations.cpp
    src/mathematics/statistics.cpp
    src/physics/core.cpp
    src/physics/kinematics.cpp
    src/computerscience/core.cpp
)
add_library(libnumerixpp::libnumerixpp ALIAS libnumerixpp_libnumerixpp)

include(GenerateExportHeader)
generate_export_header(
    libnumerixpp_libnumerixpp
    BASE_NAME libnumerixpp
    EXPORT_FILE_NAME export/libnumerixpp/libnumerixpp_export.hpp
    CUSTOM_CONTENT_FROM_VARIABLE pragma_suppress_c4251
)

if(NOT BUILD_SHARED_LIBS)
  target_compile_definitions(libnumerixpp_libnumerixpp PUBLIC LIBNUMERIXPP_STATIC_DEFINE)
endif()

set_target_properties(
    libnumerixpp_libnumerixpp PROPERTIES
    CXX_VISIBILITY_PRESET hidden
    VISIBILITY_INLINES_HIDDEN YES
    VERSION "${PROJECT_VERSION}"
    SOVERSION "${PROJECT_VERSION_MAJOR}"
    EXPORT_NAME libnumerixpp
    OUTPUT_NAME libnumerixpp
)

target_include_directories(
    libnumerixpp_libnumerixpp ${warning_guard}
    PUBLIC
    "\$<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>"
)

target_include_directories(
    libnumerixpp_libnumerixpp SYSTEM
    PUBLIC
    "\$<BUILD_INTERFACE:${PROJECT_BINARY_DIR}/export>"
)

target_compile_features(libnumerixpp_libnumerixpp PUBLIC cxx_std_17)

find_package(fmt REQUIRED)
target_link_libraries(libnumerixpp_libnumerixpp PRIVATE fmt::fmt)

# ---- Install rules ----

if(NOT CMAKE_SKIP_INSTALL_RULES)
  include(cmake/install-rules.cmake)
endif()

# ---- Developer mode ----

if(NOT libnumerixpp_DEVELOPER_MODE)
  return()
elseif(NOT PROJECT_IS_TOP_LEVEL)
  message(
      AUTHOR_WARNING
      "Developer mode is intended for developers of libnumerixpp"
  )
endif()

include(cmake/dev-mode.cmake)
