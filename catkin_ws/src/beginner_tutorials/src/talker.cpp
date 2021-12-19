#include "ros/ros.h" 
#include "std_msgs/String.h" // 所要 publish 的 message type，std_msgs package 底下的 String.msg
#include <sstream>


int main(int argc, char **argv){
    // initialize
    ros::init(argc, argv, "talker");
    /* 
        該 node 與 ROS 系統通訊的存取點(handle)，建構子會初始化該 node，當離開此 scope，解構子會 delete 該 node 
    */
    ros::NodeHandle n;
    /*
        advertise() 會將建立 topic 的資訊告訴 master node，回傳一個 Publisher 物件,之後可使用該物件的 publish() 方法進行publish
        而預計 publish 的 message type 為 std::msgs::String   
        指定的 topic 名稱為 chatter
        1000指的是 message queue，若 publish 太快，超過 1000 個 message，新 publish 的 message 會被捨棄
    */
    ros::Publisher chatter_pub = n.advertise<std_msgs::String>("chatter", 1000);
    ros::Rate loop_rate(10); // loop 10 times per second
    int count = 0;

    // node is ready
    while (ros::ok()){
        std_msgs::String msg;

        std::stringstream ss;
        ss << "hello world " << count;
        msg.data = ss.str();

        ROS_INFO("%s", msg.data.c_str());

        chatter_pub.publish(msg);

        ros::spinOnce(); // 呼叫一次 callback function，在 subscriber 才有用
        loop_rate.sleep(); // sleep for the time remaining to let us hit our 10Hz publish rate
        
        ++count;
    }


    return 0;
}