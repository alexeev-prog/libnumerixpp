include(CMakeFindDependencyMacro)
find_dependency(fmt)

if(fmt_FOUND)
  include("${CMAKE_CURRENT_LIST_DIR}/libnumerixppTargets.cmake")
endif()
