// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from turtle_intfaces:msg/Turtle.idl
// generated code does not contain a copyright notice

#ifndef TURTLE_INTFACES__MSG__DETAIL__TURTLE__STRUCT_H_
#define TURTLE_INTFACES__MSG__DETAIL__TURTLE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'turtle_name'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/Turtle in the package turtle_intfaces.
typedef struct turtle_intfaces__msg__Turtle
{
  rosidl_runtime_c__String turtle_name;
  double x;
  double y;
  double theta;
} turtle_intfaces__msg__Turtle;

// Struct for a sequence of turtle_intfaces__msg__Turtle.
typedef struct turtle_intfaces__msg__Turtle__Sequence
{
  turtle_intfaces__msg__Turtle * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} turtle_intfaces__msg__Turtle__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // TURTLE_INTFACES__MSG__DETAIL__TURTLE__STRUCT_H_
