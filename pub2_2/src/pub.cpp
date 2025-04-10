#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/vector3.hpp"
#include <iostream>
#include <memory>

void publish_input(rclcpp::Node::SharedPtr node,
                   rclcpp::Publisher<geometry_msgs::msg::Vector3>::SharedPtr pub)
{
    geometry_msgs::msg::Vector3 msg;

    std::cout << "Enter 3 float values (x y z): ";
    std::cin >> msg.x >> msg.y >> msg.z;

    RCLCPP_INFO(node->get_logger(), "Publishing: x=%.2f, y=%.2f, z=%.2f", msg.x, msg.y, msg.z);
    pub->publish(msg);
}

int main(int argc, char* argv[]) {
    rclcpp::init(argc, argv);

    auto node = std::make_shared<rclcpp::Node>("pub2_2_node");
    auto pub = node->create_publisher<geometry_msgs::msg::Vector3>("vector_topic", 10);

    // 반복적으로 키보드 입력 받아서 publish
    while (rclcpp::ok()) {
        publish_input(node, pub);
        rclcpp::spin_some(node);  // 콜백 처리를 위해 필요
    }

    rclcpp::shutdown();
    return 0;
}
