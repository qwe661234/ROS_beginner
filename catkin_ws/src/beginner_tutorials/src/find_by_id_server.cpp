#include "ros/ros.h"
#include "beginner_tutorials/my_srv.h" //include customized srv files

bool findById(beginner_tutorials::my_srv::Request  &req, beginner_tutorials::my_srv::Response &res){
    ROS_INFO("request: id = %ld", (long int)req.id);
    if(req.id == 1) {
        res.name = "Tom";
        res.gender = "male";
        res.age = 20;
    } else {
        res.name = "Amy";
        res.gender = "female";
        res.age = 55;
    }
    ROS_INFO("sending back response");
    ROS_INFO("Name: %s", res.name.c_str());
    ROS_INFO("Gender: %s", res.gender.c_str());
    ROS_INFO("Age: %ld", (long int)res.age);
    return true;
}
  
int main(int argc, char **argv) {
    ros::init(argc, argv, "find_by_id_server"); 
    ros::NodeHandle n;

    ros::ServiceServer service = n.advertiseService("find_by_id", findById);
    ROS_INFO("Ready to find by id.");
    ros::spin(); 

    return 0;
}