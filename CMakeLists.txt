cmake_minimum_required(VERSION 3.0.2)
project(ros_tutorials_service)

## A component package required when building the Catkin.
## Has dependency on message_generation, std_msgs, roscpp.
## An error occurs during the build if these packages do not exist.
find_package(catkin REQUIRED COMPONENTS message_generation std_msgs roscpp rospy)

### Declaration Message: MsgTutorial.msg
#add_message_files(FILES MsgTutorial.msg)

## Serivce Declaration: SrvTutorial.srv
add_service_files(FILES SrvTutorial.srv)

## an option to configure the dependent message.
## An error occurs duing the build if "std_msgs" is not installed.
generate_messages(DEPENDENCIES std_msgs)

## A Catkin package option that describes the library, the Catkin build dependencies,
## and the system dependent packages.
catkin_package(
  LIBRARIES ros_tutorials_topic
  CATKIN_DEPENDS std_msgs roscpp rospy
)

## Include directory configuration.
include_directories(${catkin_INCLUDE_DIRS})

## Build option for the "service_server" node.
## Configuration of Executable files, target link libraries, and additional
## dependencies.
add_executable(service_server src/service_server.cpp)
add_dependencies(service_server ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
target_link_libraries(service_server ${catkin_LIBRARIES})

## Build option for the "service_client" node.
add_executable(service_client src/service_client.cpp)
add_dependencies(service_client ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
target_link_libraries(service_client ${catkin_LIBRARIES})
