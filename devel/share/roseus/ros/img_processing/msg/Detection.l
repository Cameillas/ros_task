;; Auto-generated. Do not edit!


(when (boundp 'img_processing::Detection)
  (if (not (find-package "IMG_PROCESSING"))
    (make-package "IMG_PROCESSING"))
  (shadow 'Detection (find-package "IMG_PROCESSING")))
(unless (find-package "IMG_PROCESSING::DETECTION")
  (make-package "IMG_PROCESSING::DETECTION"))

(in-package "ROS")
;;//! \htmlinclude Detection.msg.html


(defclass img_processing::Detection
  :super ros::object
  :slots (_class_name _confidence _x _y _width _height ))

(defmethod img_processing::Detection
  (:init
   (&key
    ((:class_name __class_name) "")
    ((:confidence __confidence) 0.0)
    ((:x __x) 0)
    ((:y __y) 0)
    ((:width __width) 0)
    ((:height __height) 0)
    )
   (send-super :init)
   (setq _class_name (string __class_name))
   (setq _confidence (float __confidence))
   (setq _x (round __x))
   (setq _y (round __y))
   (setq _width (round __width))
   (setq _height (round __height))
   self)
  (:class_name
   (&optional __class_name)
   (if __class_name (setq _class_name __class_name)) _class_name)
  (:confidence
   (&optional __confidence)
   (if __confidence (setq _confidence __confidence)) _confidence)
  (:x
   (&optional __x)
   (if __x (setq _x __x)) _x)
  (:y
   (&optional __y)
   (if __y (setq _y __y)) _y)
  (:width
   (&optional __width)
   (if __width (setq _width __width)) _width)
  (:height
   (&optional __height)
   (if __height (setq _height __height)) _height)
  (:serialization-length
   ()
   (+
    ;; string _class_name
    4 (length _class_name)
    ;; float32 _confidence
    4
    ;; int32 _x
    4
    ;; int32 _y
    4
    ;; int32 _width
    4
    ;; int32 _height
    4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; string _class_name
       (write-long (length _class_name) s) (princ _class_name s)
     ;; float32 _confidence
       (sys::poke _confidence (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; int32 _x
       (write-long _x s)
     ;; int32 _y
       (write-long _y s)
     ;; int32 _width
       (write-long _width s)
     ;; int32 _height
       (write-long _height s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; string _class_name
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _class_name (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;; float32 _confidence
     (setq _confidence (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; int32 _x
     (setq _x (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; int32 _y
     (setq _y (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; int32 _width
     (setq _width (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; int32 _height
     (setq _height (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;;
   self)
  )

(setf (get img_processing::Detection :md5sum-) "acd10d3642cc6879056ec548696e61d3")
(setf (get img_processing::Detection :datatype-) "img_processing/Detection")
(setf (get img_processing::Detection :definition-)
      "string class_name
float32 confidence
int32 x
int32 y
int32 width
int32 height

")



(provide :img_processing/Detection "acd10d3642cc6879056ec548696e61d3")


