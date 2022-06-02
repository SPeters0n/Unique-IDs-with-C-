#include "ros/ros.h"
#include "std_msgs/String.h"

#include "geometry_msgs/msg/twist.hpp"
#include <sstream>

geometry_msgs::msg::twist global_twist_variable;

void writeCallback(const geometry_msgs::msg::twist& msg)
{
  global_twist_variable = msg;// potential problem point

  /*
  global_twist_variable.linear = msg.linear;
  global_twist_variable.angular = msg.angular;
  */
  //ROS_INFO("I heard: [%s]", msg->data.c_str());
}

/*
  What we get in msg:
    - username 
    - password
    -

  What we do with the msg:
    1. 
    2. 
    3.       
*/
void team_two_output(const team_two_type& msg) {
  
}

int main(int argc, char **argv)
{
/*
	2. Subscribe to the output of Team 2
	
	4. Set up authentication so that we decide which 
	   commands get published and which ones don't
*/
  ros::init(argc, argv, "auth_node");

  ros::NodeHandle n;

  ros::Publisher chatter_pub = n.advertise<geometry_msgs::msg::twist>("authenticate_vel", 1000); // 3. Publish Velocity
  
  ros::Subscriber twist_mux_sub = n.subscribe("/husky_velocity_controller/cmd_vel", 1000, writeCallback); // 1. Subscribe to the output of twist_mux

  ros::Subscriber team_two_output_sub = n.subscribe("/fingerprint", 1000, team_two_output);

  ros::Rate loop_rate(10);

  int count = 0;
  while (ros::ok())
  {

    //ROS_INFO("%s", msg.data.c_str());

    chatter_pub.publish(global_twist_variable);


    ros::spinOnce();

    loop_rate.sleep();

    ++count;
  }

  return 0;
}
