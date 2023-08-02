#include <ros/ros.h>
#include <actionlib_msgs/GoalID.h>


bool cancelGoals(ros::NodeHandle &nh) {
    ros::Publisher cancel_pub = nh.advertise<actionlib_msgs::GoalID>("/move_base/cancel", 1000);
    actionlib_msgs::GoalID msg;
    msg.stamp.sec = 0;
    msg.stamp.nsec = 0;
    msg.id = "";

    ros::Rate loop_rate(10);
    int count = 0;
    while (cancel_pub.getNumSubscribers() < 1) {
        loop_rate.sleep(); // wait for a connection to publisher
        count++;
    }
    while (count < 10) { // Broadcast for 1 sec.
        cancel_pub.publish(msg);
        loop_rate.sleep();
        count++;
    }
}

int main(int argc, char **argv) {
    ros::init(argc, argv, "cancel_node");
    ros::NodeHandle nh;
    cancelGoals(nh);
    return 0;
}
