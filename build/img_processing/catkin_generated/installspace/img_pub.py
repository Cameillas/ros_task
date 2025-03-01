#!/usr/bin/env python3

import rospy
import cv2
from sensor_msgs.msg import Image
from cv_bridge import CvBridge

def publish_image():
    rospy.init_node('image_publisher', anonymous=True)
    pub = rospy.Publisher('camera/image', Image, queue_size=10)
    bridge = CvBridge()
    cap = cv2.VideoCapture(0, cv2.CAP_V4L2)  # 强制使用 V4L2 后端
    cap.set(cv2.CAP_PROP_FRAME_WIDTH, 640)   # 设置分辨率
    cap.set(cv2.CAP_PROP_FRAME_HEIGHT, 480)
    rate = rospy.Rate(10)  # 10Hz

    while not rospy.is_shutdown():
        ret, frame = cap.read()
        if ret:
            ros_image = bridge.cv2_to_imgmsg(frame, "bgr8")
            pub.publish(ros_image)
        rate.sleep()

    cap.release()

if __name__ == '__main__':
    try:
        publish_image()
    except rospy.ROSInterruptException:
        pass
