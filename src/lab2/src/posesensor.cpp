/*
Copyright 2023 Stefano Carpin

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
*/

#include <rclcpp/rclcpp.hpp> // needed for basic functions
#include <std_msgs/msg/int32.hpp> // to receive integers
#include <std_msgs/msg/string.hpp> // to receive strings

rclcpp::Node::SharedPtr nodeh;

// callback function called every time a message is received from the
// topic "intsub"
int current = 0;
int past = 0;

void intCallback(const std_msgs::msg::Int32::SharedPtr msg) {
	past = current;
	current = msg->data;
	int sum = past + current;
  // print received integer to the screen
  RCLCPP_INFO(nodeh->get_logger(),"sum of ints: %d",sum);
}


int main(int argc,char **argv) {

  rclcpp::init(argc,argv); // initialize ROS subsystem
  
  rclcpp::Subscription<std_msgs::msg::Int32>::SharedPtr subi;
  
  nodeh = rclcpp::Node::make_shared("intsub"); // create node instance
                                           
   // subscribe to topic "intm" an register the callback function
  subi = nodeh->create_subscription<std_msgs::msg::Int32>("inttopic",10,&intCallback);
  rclcpp::spin(nodeh); // wait for messages and process them
 
  rclcpp::shutdown();
  return 0;
  
}


