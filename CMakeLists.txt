# Project's name
PROJECT (lunabotics_control)

# Specify the minimum version for CMake
cmake_minimum_required(VERSION 3.1)

add_definitions(-std=c++11)

set(THREADS_PREFER_PTHREAD_FLAG ON)

find_package(catkin REQUIRED)
find_package (Threads REQUIRED)
find_package(catkin REQUIRED COMPONENTS
	roscpp
	rospy
	std_msgs
	sensor_msgs
	laser_geometry
	tf2
	tf2_ros	
	geometry_msgs
	tf
	nav_msgs
)

catkin_package()

include_directories (src include ${catkin_INCLUDE_DIRS})

# NON EXECUTABLES (Classes. Not ROS Nodes, no main function)
# add_library(Task ${PROJECT_SOURCE_DIR}/src/Task.cpp)


# EXECUTABLES (ROS nodes, main function)
add_executable(Autonomy ${PROJECT_SOURCE_DIR}/src/Autonomy.cpp)

# Tasking, Task Includes
# target_link_libraries(DugNewNode Task TaskManager TaskLoop ${catkin_LIBRARIES})

message("<> ARCHITECTURE: ${CMAKE_LIBRARY_ARCHITECTURE}") # Display Architecture
if (${CMAKE_LIBRARY_ARCHITECTURE} STREQUAL "aarch64-linux-gnu") # Jetson TK1 / Pi

	#target_link_libraries(ExcvConveyorHW ${PROJECT_SOURCE_DIR}/lib/raspberry/libCTRE_Phoenix.a)
	#target_link_libraries(ExcvConveyorHW ${PROJECT_SOURCE_DIR}/lib/raspberry/libCTRE_PhoenixCCI.a)
	#target_link_libraries(ExcvConveyorHW ${PROJECT_SOURCE_DIR}/lib/raspberry/libCTRE_PhoenixPlatform_socketcan.a)
	#target_link_libraries(ExcvConveyorHW ${PROJECT_SOURCE_DIR}/lib/raspberry/libCTRE_PhoenixCanutils.a)
	
	
else()

	#target_link_libraries(ExcvConveyorHW ${PROJECT_SOURCE_DIR}/lib/x86-64/libCTRE_Phoenix.a)
	#target_link_libraries(ExcvConveyorHW ${PROJECT_SOURCE_DIR}/lib/x86-64/libCTRE_PhoenixCCI.a)
	#target_link_libraries(ExcvConveyorHW ${PROJECT_SOURCE_DIR}/lib/x86-64/libCTRE_PhoenixPlatformLinuxSocketCan.a)
	#target_link_libraries(ExcvConveyorHW ${PROJECT_SOURCE_DIR}/lib/x86-64/libCTRE_PhoenixCanutils.a)

	
endif()