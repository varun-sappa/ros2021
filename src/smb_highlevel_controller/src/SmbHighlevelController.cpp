#include <smb_highlevel_controller/SmbHighlevelController.hpp>
#<

namespace smb_highlevel_controller {

SmbHighlevelController::SmbHighlevelController(ros::NodeHandle& nodeHandle) :
  nodeHandle_(nodeHandle)
{
}

SmbHighlevelController::~SmbHighlevelController()
{
}

} /* namespace */
#include <ros/ros.h>

int main(int argc, char** argv)
{
  ros::init(argc, argv, "husky_highlevel_controller");
  ros::NodeHandle nodeHandle("~");

  husky_highlevel_controller::HuskyHighlevelController huskyHighlevelController(nodeHandle);

  ros::spin();
  return 0;
}
