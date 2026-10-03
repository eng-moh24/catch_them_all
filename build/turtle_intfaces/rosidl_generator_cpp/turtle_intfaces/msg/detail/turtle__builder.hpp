// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from turtle_intfaces:msg/Turtle.idl
// generated code does not contain a copyright notice

#ifndef TURTLE_INTFACES__MSG__DETAIL__TURTLE__BUILDER_HPP_
#define TURTLE_INTFACES__MSG__DETAIL__TURTLE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "turtle_intfaces/msg/detail/turtle__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace turtle_intfaces
{

namespace msg
{

namespace builder
{

class Init_Turtle_theta
{
public:
  explicit Init_Turtle_theta(::turtle_intfaces::msg::Turtle & msg)
  : msg_(msg)
  {}
  ::turtle_intfaces::msg::Turtle theta(::turtle_intfaces::msg::Turtle::_theta_type arg)
  {
    msg_.theta = std::move(arg);
    return std::move(msg_);
  }

private:
  ::turtle_intfaces::msg::Turtle msg_;
};

class Init_Turtle_y
{
public:
  explicit Init_Turtle_y(::turtle_intfaces::msg::Turtle & msg)
  : msg_(msg)
  {}
  Init_Turtle_theta y(::turtle_intfaces::msg::Turtle::_y_type arg)
  {
    msg_.y = std::move(arg);
    return Init_Turtle_theta(msg_);
  }

private:
  ::turtle_intfaces::msg::Turtle msg_;
};

class Init_Turtle_x
{
public:
  explicit Init_Turtle_x(::turtle_intfaces::msg::Turtle & msg)
  : msg_(msg)
  {}
  Init_Turtle_y x(::turtle_intfaces::msg::Turtle::_x_type arg)
  {
    msg_.x = std::move(arg);
    return Init_Turtle_y(msg_);
  }

private:
  ::turtle_intfaces::msg::Turtle msg_;
};

class Init_Turtle_turtle_name
{
public:
  Init_Turtle_turtle_name()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Turtle_x turtle_name(::turtle_intfaces::msg::Turtle::_turtle_name_type arg)
  {
    msg_.turtle_name = std::move(arg);
    return Init_Turtle_x(msg_);
  }

private:
  ::turtle_intfaces::msg::Turtle msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::turtle_intfaces::msg::Turtle>()
{
  return turtle_intfaces::msg::builder::Init_Turtle_turtle_name();
}

}  // namespace turtle_intfaces

#endif  // TURTLE_INTFACES__MSG__DETAIL__TURTLE__BUILDER_HPP_
