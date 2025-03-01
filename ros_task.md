## TASK1

1. **输入图像** → **BGR转RGB** → **BGR转HSV**
2. **红色阈值分割** → **合并掩码** → **形态学去噪**
3. **轮廓检测** → **计算边界框** → **绘制标注**
4. **显示结果** → **输出坐标**

```
import cv2
import numpy as np
from matplotlib import pyplot as plt

# 读取图像
image_path = "image.png"
image = cv2.imread(image_path)
image_rgb = cv2.cvtColor(image, cv2.COLOR_BGR2RGB)

# 转换到 HSV 颜色空间
hsv = cv2.cvtColor(image, cv2.COLOR_BGR2HSV)

# 设定红色的 HSV 阈值范围
lower_red1 = np.array([0, 120, 70])
upper_red1 = np.array([10, 255, 255])
lower_red2 = np.array([170, 120, 70])
upper_red2 = np.array([180, 255, 255])

# 创建掩码
mask1 = cv2.inRange(hsv, lower_red1, upper_red1)
mask2 = cv2.inRange(hsv, lower_red2, upper_red2)
mask = mask1 + mask2

# 形态学操作去除噪声
kernel = np.ones((5, 5), np.uint8)
mask = cv2.morphologyEx(mask, cv2.MORPH_CLOSE, kernel)
mask = cv2.morphologyEx(mask, cv2.MORPH_OPEN, kernel)

# 查找轮廓
contours, _ = cv2.findContours(
    mask, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)

# 画出边界框并获取坐标
bounding_boxes = []
for contour in contours:
    x, y, w, h = cv2.boundingRect(contour)
    bounding_boxes.append((x, y, w, h))
    cv2.rectangle(image_rgb, (x, y), (x + w, y + h), (255, 0, 0), 2)
    cv2.putText(image_rgb, f"({x}, {y})", (x, y - 10),
                cv2.FONT_HERSHEY_SIMPLEX, 0.5, (255, 0, 0), 2)

# 显示结果
plt.figure(figsize=(10, 5))
plt.imshow(image_rgb)
plt.axis("off")
plt.show()

# 输出红色小球的坐标
print("检测到的红色小球边界框坐标 (x, y, width, height):", bounding_boxes)

```

![](D:\vscode\ros\1.png)

![](D:\vscode\ros\2.png)

## TASK2

使用了yolo5.v7，完成识别，模型为yolov5s.pt

![](D:\vscode\ros\3.png)