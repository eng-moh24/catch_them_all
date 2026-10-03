# generated from rosidl_cmake/cmake/rosidl_cmake_aggregate_target-extras.cmake.in

# Create a convenience aggregate target turtle_intfaces::turtle_intfaces
# that links all generated interface targets, so downstream packages can use
# a single modern CMake target name instead of ${turtle_intfaces_TARGETS}.
if(turtle_intfaces_TARGETS AND NOT TARGET turtle_intfaces::turtle_intfaces)
  add_library(turtle_intfaces::turtle_intfaces INTERFACE IMPORTED)
  set_target_properties(turtle_intfaces::turtle_intfaces PROPERTIES
    INTERFACE_LINK_LIBRARIES "${turtle_intfaces_TARGETS}")
endif()
