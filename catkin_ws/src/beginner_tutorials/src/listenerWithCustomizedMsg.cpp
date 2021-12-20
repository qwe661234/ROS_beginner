#include "ros/ros.h"
#include "beginner_tutorials/my_msg.h"

/* subscriber 的回呼函式，參數為所接收的 message 的常數指標
   const pkg_name::msg_name::ConstPtr& msg
   之後使用 msg->field_name 即可存取 message 的欄位資料
*/
void chatterCallback(const beginner_tutorials::my_msg::ConstPtr& msg){
    ROS_INFO("I heard: [%ld]\n", msg->id);
    ROS_INFO("I heard: [%s]\n", msg->title.c_str());
    ROS_INFO("I heard: [%s]\n", msg->content.c_str());

}

int main(int argc, char **argv){
    ros::init(argc, argv, "listenerwithCustomizedMsg");
    ros::NodeHandle n;
    /*  
        subscribe() 會將建立 topic 的資訊告訴 master node，回傳一個S ubscriber物件
        指定的回呼函式名稱為 chatterCallback，
        1000指的是 message queue，若接收得太快，超過1000個 message，新接收的 message 會被捨棄
    */ 
    ros::Subscriber sub = n.subscribe("chatter", 1000, chatterCallback);
    /* 
        ros::spin() 會進入迴圈，然後呼叫所有在此執行緒(in main function)的
        回呼函式 (在此為chatterCallback)，直到Ctrl-C被輸入或當前的 node 被 master node 關掉
    */
    ros::spin();
    return 0;
}