cmake_minimum_required(VERSION 2.8.3)
project(jedgar_driver)

add_definitions(-std=c++11)

find_package(catkin REQUIRED COMPONENTS
  hardware_interface
  controller_manager
  roscpp
)

catkin_package()

# Specify additional locations of header files
# Your package locations should be listed before other locations
include_directories(
  ${catkin_INCLUDE_DIRS}
  include
)

# Declare a C++ executable
FILE(GLOB SRC_FILES src/*.cpp)
add_executable(jedgar_driver ${SRC_FILES})

# Add cmake target dependencies of the executable
# same as for the library above
add_dependencies(jedgar_driver ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

# Specify libraries to link a library or executable target against
target_link_libraries(jedgar_driver
  ${catkin_LIBRARIES}
)

