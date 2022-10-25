#pragma once

#include <ros/ros.h>
#include <sensor_msgs/LaserScan.h>
#include <vector>

namespace smb_highlevel_controller {

/*!
 * Class containing the Husky Highlevel Controller
 */
class SmbHighlevelController {
public:
	/*!
	 * Constructor.
	 */
	SmbHighlevelController(ros::NodeHandle& nh);
	/* @brief: Copy constructor
     * defined as DELETED for simplicity 
     * @comments: at this moment, I don't think this is necessarily a good
     * practice to wrap up node handlers, subscribers etc. into a new class,
     * because we should be very careful with the behavior of copy constructors.
     * However, if we really want to copy this class, remember to
     * copy both vars 'nodeHandle' & 'subscriber'. Do NOT initialize
     * the subscriber again from the method 'NodeHandle.subscribe()'.
     * Refer to the source code
     * http://wiki.ros.org/roscpp/Overview/NodeHandles
     * https://github.com/ros/ros_comm/blob/kinetic-devel/clients/roscpp/src/libros/node_handle.cpp
     * https://github.com/ros/ros_comm/blob/kinetic-devel/clients/roscpp/src/libros/subscriber.cpp
     */
    SmbHighlevelController(const SmbHighlevelController &) = delete;
    /* @brief: no assignment = */
    SmbHighlevelController& operator=(const SmbHighlevelController &) = delete;

    /* @brief: Destructor */
    // ~SmbHighlevelController() = default;

	/*!
	 * Destructor.
	 */
	virtual ~SmbHighlevelController();

private:
	ros::NodeHandle nodeHandle;
    ros::Subscriber subscriber;
    void LaserCallback(const sensor_msgs::LaserScan &msg);


};

} /* namespace */
