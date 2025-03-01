#!/usr/bin/env python3

import rospy
import cv2
import numpy as np
import os
from datetime import datetime
from sensor_msgs.msg import Image
from cv_bridge import CvBridge, CvBridgeError

class ImageProcessor:
    def __init__(self):
        self.bridge = CvBridge()
        self.pub = rospy.Publisher('processed_image', Image, queue_size=10)
        rospy.Subscriber('camera/image', Image, self.image_callback)
        
        # 初始化OpenCV窗口和拍照参数
        self.save_count = 0
        self.save_dir = os.path.expanduser("~/ros_saved_images")  # 保存路径
        self.latest_image = None
        
        # 创建保存目录
        if not os.path.exists(self.save_dir):
            os.makedirs(self.save_dir)
        
        cv2.namedWindow("Processed Image", cv2.WINDOW_NORMAL)

    def image_callback(self, msg):
        try:
            # 转换图像
            cv_image = self.bridge.imgmsg_to_cv2(msg, "bgr8")
            self.latest_image = cv_image.copy()  # 保存最新帧
            
            # 红色检测逻辑
            hsv = cv2.cvtColor(cv_image, cv2.COLOR_BGR2HSV)
            lower_red = np.array([0, 100, 100])
            upper_red = np.array([10, 255, 255])
            mask = cv2.inRange(hsv, lower_red, upper_red)
            
            # 绘制边界框
            contours, _ = cv2.findContours(mask, cv2.RETR_TREE, cv2.CHAIN_APPROX_SIMPLE)
            for cnt in contours:
                area = cv2.contourArea(cnt)
                if area > 500:
                    x, y, w, h = cv2.boundingRect(cnt)
                    cv2.rectangle(cv_image, (x, y), (x+w, y+h), (0, 255, 0), 2)
                    rospy.loginfo(f"检测到红色物体: x={x}, y={y}, 宽度={w}, 高度={h}")
            
            # 显示图像
            cv2.imshow("Processed Image", cv_image)
            
            # 检测按键（按 's' 保存图像）
            key = cv2.waitKey(1)
            if key == ord('s') or key == ord('S'):
                self.save_image()
            
            # 发布处理后的图像
            self.pub.publish(self.bridge.cv2_to_imgmsg(cv_image, "bgr8"))
            
        except CvBridgeError as e:
            rospy.logerr(f"CV桥接错误: {e}")
        except Exception as e:
            rospy.logerr(f"错误: {e}")

    def save_image(self):
        if self.latest_image is not None:
            # 生成唯一文件名（时间戳 + 计数器）
            timestamp = datetime.now().strftime("%Y%m%d_%H%M%S")
            filename = f"photo_{timestamp}_{self.save_count:03d}.jpg"
            save_path = os.path.join(self.save_dir, filename)
            
            # 保存图像
            cv2.imwrite(save_path, self.latest_image)
            rospy.loginfo(f"已保存照片到: {save_path}")
            self.save_count += 1  # 计数器递增
        else:
            rospy.logwarn("无可用图像可保存")

    def shutdown_hook(self):
        cv2.destroyAllWindows()

if __name__ == '__main__':
    rospy.init_node('image_subscriber')
    ip = ImageProcessor()
    rospy.on_shutdown(ip.shutdown_hook)
    rospy.spin()
