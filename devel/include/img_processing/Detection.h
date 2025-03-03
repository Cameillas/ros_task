// Generated by gencpp from file img_processing/Detection.msg
// DO NOT EDIT!


#ifndef IMG_PROCESSING_MESSAGE_DETECTION_H
#define IMG_PROCESSING_MESSAGE_DETECTION_H


#include <string>
#include <vector>
#include <memory>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace img_processing
{
template <class ContainerAllocator>
struct Detection_
{
  typedef Detection_<ContainerAllocator> Type;

  Detection_()
    : class_name()
    , confidence(0.0)
    , x(0)
    , y(0)
    , width(0)
    , height(0)  {
    }
  Detection_(const ContainerAllocator& _alloc)
    : class_name(_alloc)
    , confidence(0.0)
    , x(0)
    , y(0)
    , width(0)
    , height(0)  {
  (void)_alloc;
    }



   typedef std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> _class_name_type;
  _class_name_type class_name;

   typedef float _confidence_type;
  _confidence_type confidence;

   typedef int32_t _x_type;
  _x_type x;

   typedef int32_t _y_type;
  _y_type y;

   typedef int32_t _width_type;
  _width_type width;

   typedef int32_t _height_type;
  _height_type height;





  typedef boost::shared_ptr< ::img_processing::Detection_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::img_processing::Detection_<ContainerAllocator> const> ConstPtr;

}; // struct Detection_

typedef ::img_processing::Detection_<std::allocator<void> > Detection;

typedef boost::shared_ptr< ::img_processing::Detection > DetectionPtr;
typedef boost::shared_ptr< ::img_processing::Detection const> DetectionConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::img_processing::Detection_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::img_processing::Detection_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::img_processing::Detection_<ContainerAllocator1> & lhs, const ::img_processing::Detection_<ContainerAllocator2> & rhs)
{
  return lhs.class_name == rhs.class_name &&
    lhs.confidence == rhs.confidence &&
    lhs.x == rhs.x &&
    lhs.y == rhs.y &&
    lhs.width == rhs.width &&
    lhs.height == rhs.height;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::img_processing::Detection_<ContainerAllocator1> & lhs, const ::img_processing::Detection_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace img_processing

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsMessage< ::img_processing::Detection_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::img_processing::Detection_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::img_processing::Detection_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::img_processing::Detection_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::img_processing::Detection_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::img_processing::Detection_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::img_processing::Detection_<ContainerAllocator> >
{
  static const char* value()
  {
    return "acd10d3642cc6879056ec548696e61d3";
  }

  static const char* value(const ::img_processing::Detection_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xacd10d3642cc6879ULL;
  static const uint64_t static_value2 = 0x056ec548696e61d3ULL;
};

template<class ContainerAllocator>
struct DataType< ::img_processing::Detection_<ContainerAllocator> >
{
  static const char* value()
  {
    return "img_processing/Detection";
  }

  static const char* value(const ::img_processing::Detection_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::img_processing::Detection_<ContainerAllocator> >
{
  static const char* value()
  {
    return "string class_name\n"
"float32 confidence\n"
"int32 x\n"
"int32 y\n"
"int32 width\n"
"int32 height\n"
;
  }

  static const char* value(const ::img_processing::Detection_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::img_processing::Detection_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.class_name);
      stream.next(m.confidence);
      stream.next(m.x);
      stream.next(m.y);
      stream.next(m.width);
      stream.next(m.height);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct Detection_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::img_processing::Detection_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::img_processing::Detection_<ContainerAllocator>& v)
  {
    s << indent << "class_name: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>>::stream(s, indent + "  ", v.class_name);
    s << indent << "confidence: ";
    Printer<float>::stream(s, indent + "  ", v.confidence);
    s << indent << "x: ";
    Printer<int32_t>::stream(s, indent + "  ", v.x);
    s << indent << "y: ";
    Printer<int32_t>::stream(s, indent + "  ", v.y);
    s << indent << "width: ";
    Printer<int32_t>::stream(s, indent + "  ", v.width);
    s << indent << "height: ";
    Printer<int32_t>::stream(s, indent + "  ", v.height);
  }
};

} // namespace message_operations
} // namespace ros

#endif // IMG_PROCESSING_MESSAGE_DETECTION_H
