cmake_minimum_required(VERSION 3.16)
project(pub2_3)

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(geometry_msgs REQUIRED)

add_executable(pub src/pub.cpp)
ament_target_dependencies(pub rclcpp geometry_msgs)

install(TARGETS
  pub
  DESTINATION lib/${PROJECT_NAME}
)

ament_package()
