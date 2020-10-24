#!/usr/bin/env python

from ros_tutorials_service.srv import SrvTutorial, SrvTutorialResponse
import rospy

def cbSrvTutorial(req):
	rospy.loginfo("Returning [%s + %s = %s]"%(req.a, req.b, (req.a + req.b)))
	return SrvTutorialResponse(req.a + req.b)

def SrvTutorialInfo():
	rospy.init_node('service_server')
	s = rospy.Service('ros_tutorial_srv', SrvTutorial, cbSrvTutorial)
	rospy.loginfo("ready srv server!")
	rospy.spin()

if __name__ == "__main__":
	SrvTutorialInfo()
