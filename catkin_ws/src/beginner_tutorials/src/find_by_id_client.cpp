#include "ros/ros.h"
#include "beginner_tutorials/my_srv.h"
#include <cstdlib>

int main(int argc, char **argv)
{
    ros::init(argc, argv, "find_by_id_client");
    if (argc != 2)
    {
        ROS_INFO("usage: find_by_id_client id");
        return 1;
    }

    ros::NodeHandle n;
    ros::ServiceClient client = n.serviceClient<beginner_tutorials::my_srv>("find_by_id");
    beginner_tutorials::my_srv srv; 
    srv.request.id = atoll(argv[1]);
    if (client.call(srv))
    {
        ROS_INFO("Name: %s", srv.response.name.c_str());
        ROS_INFO("Gender: %s", srv.response.gender.c_str());
        ROS_INFO("Age: %ld", (long int)srv.response.age);
    }
    else
    {
        ROS_ERROR("Failed to call service add_two_ints");
        return 1;
    }

    return 0;
}