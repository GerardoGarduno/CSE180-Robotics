//example to move turtle in a circle with stops
#include <rclcpp/rclcpp.hpp>
#include <geometry_msgs/msg/twist.hpp>

int main(int argc,char **argv) {
  
  rclcpp::init(argc,argv);
  rclcpp::Node::SharedPtr nodeh;
  rclcpp::Rate rate(1);

  nodeh = rclcpp::Node::make_shared("drawcircle");
  auto pub = nodeh->create_publisher<geometry_msgs::msg::Twist>
      ("turtle1/cmd_vel",100);

  geometry_msgs::msg::Twist msg;
  while (rclcpp::ok()) {
  
  	msg.linear.x = 1.0;
  	pub -> publish(msg);
  	//RCLCPP_INFO(nodeh->get_logger(), "SENT x %f",msg.linear.x);
  	rate.sleep();
  	msg.angular.z = 0.5;
  	pub -> publish(msg);
  	//RCLCPP_INFO(nodeh->get_logger(), "SENT z %f",msg.angular.z);
  	rate.sleep();
  
  

   
  }
}
