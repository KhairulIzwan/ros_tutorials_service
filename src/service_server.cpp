// ROS Default Header File
#include "ros/ros.h"

// SrvTutorial Service File Header (Automatically created after build)
#include "ros_tutorials_service/SrvTutorial.h"

// The below process is performed when there is a service request
// The service request is declared as 'req', and the service response is declared as 'res'
bool calculation(ros_tutorials_service::SrvTutorial::Request &req, ros_tutorials_service::SrvTutorial::Response &res)
{
	// The service name is 'ros_tutorial_srv' and it will call 'calculation' function
	// upon the service request.
	res.result = req.a + req.b;

	// Displays 'a' and 'b' values used in the service request and
	// the 'result' value corresponding to the service response
	ROS_INFO("request: x=%ld, y=%ld", (long int)req.a, (long int)req.b);
	ROS_INFO("sending back response: %ld", (long int)res.result);

	return true;
}

// Node Main Function
int main(int argc, char **argv)
{
	// Initializes Node Name
	ros::init(argc, argv, "service_server");

	// Node handle declaration
	ros::NodeHandle nh;

	// Declare service server 'ros_tutorials_service_server'
	// using the 'SrvTutorial' service file in the 'ros_tutorials_service' package.
	// The service name is 'ros_tutorial_srv' and it will call 'calculation' function
	// upon the service request.
	ros::ServiceServer ros_tutorials_service_server = nh.advertiseService("ros_tutorial_srv", calculation);
	ROS_INFO("ready srv server!");

	// Wait for the service request
	ros::spin();

	return 0;
}

