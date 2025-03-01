#!/home/camellia/py3.10_env/yolo_env/bin/python3

import rospy
import cv2
import torch
import numpy as np
from sensor_msgs.msg import Image
from cv_bridge import CvBridge, CvBridgeError
from img_processing.msg import Detection

class YOLODetector:
    def __init__(self):
        # 初始化YOLOv5模型 (默认使用COCO预训练模型)
        self.model = torch.hub.load('ultralytics/yolov5', 'yolov5s', pretrained=True)
        self.model.conf = 0.5  # 置信度阈值
        
        # ROS初始化
        self.bridge = CvBridge()
        self.pub_detections = rospy.Publisher('yolo/detections', Detection, queue_size=10)
        self.pub_image = rospy.Publisher('yolo/image', Image, queue_size=10)
        rospy.Subscriber('camera/image', Image, self.image_callback)
        
        cv2.namedWindow("YOLO Detection", cv2.WINDOW_NORMAL)

    def image_callback(self, msg):
        try:
            # 转换ROS图像为OpenCV格式
            cv_image = self.bridge.imgmsg_to_cv2(msg, "bgr8")
            
            # YOLO推理
            results = self.model(cv_image)
            detections = results.pandas().xyxy[0]  # 获取检测结果
            
            # 绘制检测框并发布消息
            for _, det in detections.iterrows():
                x1, y1, x2, y2 = int(det['xmin']), int(det['ymin']), int(det['xmax']), int(det['ymax'])
                
                # 发布检测结果
                detection_msg = Detection()
                detection_msg.class_name = det['name']
                detection_msg.confidence = det['confidence']
                detection_msg.x = (x1 + x2) // 2  # 中心点x坐标
                detection_msg.y = (y1 + y2) // 2  # 中心点y坐标
                detection_msg.width = x2 - x1
                detection_msg.height = y2 - y1
                self.pub_detections.publish(detection_msg)
                
                # 绘制检测框
                cv2.rectangle(cv_image, (x1, y1), (x2, y2), (0, 255, 0), 2)
                label = f"{det['name']} {det['confidence']:.2f}"
                cv2.putText(cv_image, label, (x1, y1-10), 
                           cv2.FONT_HERSHEY_SIMPLEX, 0.5, (0, 255, 0), 2)
            
            # 显示并发布处理后的图像
            cv2.imshow("YOLO Detection", cv_image)
            cv2.waitKey(1)
            self.pub_image.publish(self.bridge.cv2_to_imgmsg(cv_image, "bgr8"))
            
        except CvBridgeError as e:
            rospy.logerr(f"CV Bridge Error: {e}")
        except Exception as e:
            rospy.logerr(f"YOLO Detection Error: {e}")

    def shutdown_hook(self):
        cv2.destroyAllWindows()

if __name__ == '__main__':
    rospy.init_node('yolo_detector')
    yd = YOLODetector()
    rospy.on_shutdown(yd.shutdown_hook)
    rospy.spin()
