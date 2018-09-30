
cmake_minimum_required(VERSION 2.8)
project(normalizeFilter)
 
find_package(ITK REQUIRED)
include(${ITK_USE_FILE})
 
add_executable(normalizeFilter MACOSX_BUNDLE normalizeFilter.cxx)
target_link_libraries(normalizeFilter ${ITK_LIBRARIES})
