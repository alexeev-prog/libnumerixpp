if(PROJECT_IS_TOP_LEVEL)
  set(
      CMAKE_INSTALL_INCLUDEDIR "include"
      CACHE STRING ""
  )
  set_property(CACHE CMAKE_INSTALL_INCLUDEDIR PROPERTY TYPE PATH)
endif()

include(CMakePackageConfigHelpers)
include(GNUInstallDirs)

# find_package(<package>) call for consumers to find this project
set(package libnumerixpp)

install(
    DIRECTORY
    include/
    "${PROJECT_BINARY_DIR}/export/"
    DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}"
    COMPONENT libnumerixpp_Development
)

install(
    TARGETS libnumerixpp_libnumerixpp
    EXPORT libnumerixppTargets
    RUNTIME #
    COMPONENT libnumerixpp_Runtime
    LIBRARY #
    COMPONENT libnumerixpp_Runtime
    NAMELINK_COMPONENT libnumerixpp_Development
    ARCHIVE #
    COMPONENT libnumerixpp_Development
    INCLUDES #
    DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}"
)

write_basic_package_version_file(
    "${package}ConfigVersion.cmake"
    COMPATIBILITY SameMajorVersion
)

# Allow package maintainers to freely override the path for the configs
set(
    libnumerixpp_INSTALL_CMAKEDIR "${CMAKE_INSTALL_LIBDIR}/cmake/${package}"
    CACHE STRING "CMake package config location relative to the install prefix"
)
set_property(CACHE libnumerixpp_INSTALL_CMAKEDIR PROPERTY TYPE PATH)
mark_as_advanced(libnumerixpp_INSTALL_CMAKEDIR)

install(
    FILES cmake/install-config.cmake
    DESTINATION "${libnumerixpp_INSTALL_CMAKEDIR}"
    RENAME "${package}Config.cmake"
    COMPONENT libnumerixpp_Development
)

install(
    FILES "${PROJECT_BINARY_DIR}/${package}ConfigVersion.cmake"
    DESTINATION "${libnumerixpp_INSTALL_CMAKEDIR}"
    COMPONENT libnumerixpp_Development
)

install(
    EXPORT libnumerixppTargets
    NAMESPACE libnumerixpp::
    DESTINATION "${libnumerixpp_INSTALL_CMAKEDIR}"
    COMPONENT libnumerixpp_Development
)

if(PROJECT_IS_TOP_LEVEL)
  include(CPack)
endif()
