#!/usr/bin/env python
import rospy
from geometry_msgs.msg import Twist

def update(twist):
    global twist_pub

    if abs(twist.linear.y) > 0.01:
        twist.angular.z = twist.linear.y * 5
        twist.linear.y = 0

        if twist.linear.x < 0:
            twist.angular.z = -twist.angular.z

    twist_pub.publish(twist)

twist_pub = rospy.Publisher("jedgar_base_controller/cmd_vel", Twist, queue_size=0)
rospy.init_node("holo_driver")

rospy.Subscriber("cmd_vel", Twist, update)
rospy.spin()

