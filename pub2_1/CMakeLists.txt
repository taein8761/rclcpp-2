cmake_minimum_required(VERSION 3.16)
project(pub2_1)

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)

add_executable(pub src/pub.cpp)
ament_target_dependencies(pub rclcpp std_msgs)

install(TARGETS
  pub
  DESTINATION lib/${PROJECT_NAME}
)

ament_package()
