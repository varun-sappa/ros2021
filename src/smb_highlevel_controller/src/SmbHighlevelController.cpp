#include <smb_highlevel_controller/SmbHighlevelController.hpp>

namespace smb_highlevel_controller {

SmbHighlevelController::SmbHighlevelController(ros::NodeHandle& nh)
    : nodeHandle(nh) {
    // get param from config file
    std::string topic;
    int queue_size;
    if ( !nodeHandle.getParam("subscriber_topic", topic) 
        || !nodeHandle.getParam("queue_size", queue_size) ) 
    {
        ROS_ERROR("Could not find subscriber params!"); 
        ros::requestShutdown();
    }
    // create subscriber
    subscriber = nodeHandle.subscribe(topic, queue_size, 
        &SmbHighlevelController::LaserCallback, this);
    ROS_INFO(" highlevel controller node launched!");
}



void SmbHighlevelController::LaserCallback(const sensor_msgs::LaserScan &msg) {
    // typeof(msg.ranges) vector<float>(720)
    auto min_elem = std::min_element(msg.ranges.cbegin(), msg.ranges.cend());
    ROS_INFO_STREAM("Closest distance is " << *min_elem);
}


} /* namespace */

