#include <ros/ros.h>
#include <std_msgs/String.h>
void chatterCallback(const std_msgs::String::ConstPtr& msg)
{
    ROS_INFO("I heard: [%s]",msg->data.c_str()); //接收的消息
}
int main(int argc,char **argv)
{
    ros::init(argc,argv,"listener");    //a)
    ros::NodeHandle n;                            //b)
    ros::Subscriber sub = n.subscribe("message",1000,chatterCallback);    //c)
    ros::spin();                                  //回调函数
    return 0;
}
