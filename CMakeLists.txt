cmake_minimum_required(VERSION 2.8.3)

project(mySFML)

file(GLOB sources_files src/**.cpp)
SET( sources ${sources_files})  

set(CMAKE_BUILD_TYPE Debug)
find_package( OpenCV REQUIRED )
find_package(roscpp REQUIRED)
find_package(cv_bridge REQUIRED)
find_package(std_msgs REQUIRED)
find_package(sensor_msgs REQUIRED)
include_directories(${roscpp_INCLUDE_DIRS})
include_directories(${std_msgs_INCLUDE_DIRS})
include_directories(${sensor_msgs_INCLUDE_DIRS})
include_directories( ${OpenCV_INCLUDE_DIRS})
set(EXECUTABLE_NAME "CarSim")
add_executable(${EXECUTABLE_NAME} ${sources})
# Detect and add SFML
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
#Find any version 2.X of SFML
#See the FindSFML.cmake file for additional details and instructions
find_package(SFML 2 REQUIRED network audio graphics window system)
if(SFML_FOUND)
  include_directories(${SFML_INCLUDE_DIR})
  target_link_libraries(${EXECUTABLE_NAME} ${SFML_LIBRARIES} ${SFML_DEPENDENCIES} ${roscpp_LIBRARIES} ${std_msgs_LIBRARIES} ${sensor_msgs_LIBRARIES} ${OpenCV_LIBRARIES} ${cv_bridge_LIBRARIES})
endif()