#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/twist.hpp"
#include <chrono>
#include <memory>

using namespace std::chrono_literals;

class TurtleController : public rclcpp::Node
{
public:
    TurtleController()
    : Node("turtle_controller")
    {
        publisher_ = this->create_publisher<geometry_msgs::msg::Twist>("/turtle1/cmd_vel", 10);

        timer_ = this->create_wall_timer(
            100ms,
            [this]() {
                auto msg = geometry_msgs::msg::Twist();
                msg.linear.x = 2.0;     // 선속도
                msg.angular.z = 1.5;    // 각속도
                publisher_->publish(msg);
                RCLCPP_INFO(this->get_logger(), "Publishing: linear=%.2f angular=%.2f",
                            msg.linear.x, msg.angular.z);
            });
    }

private:
    rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr publisher_;
    rclcpp::TimerBase::SharedPtr timer_;
};

int main(int argc, char* argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<TurtleController>());
    rclcpp::shutdown();
    return 0;
}
