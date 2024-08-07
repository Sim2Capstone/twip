#include <cstdio>
#include "rclcpp/rclcpp.hpp"

#include "std_msgs/msg/string.hpp"
#include "std_msgs/msg/int32.hpp"

using std::placeholders::_1;


class Controller: public rclcpp::Node{
    public:
        Controller()
        :Node("controller"){

            subscription_ = this->create_subscription<std_msgs::msg::Int32>(
            "micro_ros_arduino_node_publisher", 10, std::bind(&Controller::topic_callback, this, _1));
            
        }

    public:
        void topic_callback(const std_msgs::msg::Int32::SharedPtr msg) const {
            RCLCPP_INFO(this->get_logger(), "Received: '%d'", msg->data);
        }
        rclcpp::Subscription<std_msgs::msg::Int32>::SharedPtr subscription_;
        

};
int main(int argc, char *argv[])
{
  printf("hello world controller package\n");
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<Controller>());
  rclcpp::shutdown();
  return 0;
}
