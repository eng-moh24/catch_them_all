// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from turtle_intfaces:msg/Turtle.idl
// generated code does not contain a copyright notice
#include "turtle_intfaces/msg/detail/turtle__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `turtle_name`
#include "rosidl_runtime_c/string_functions.h"

bool
turtle_intfaces__msg__Turtle__init(turtle_intfaces__msg__Turtle * msg)
{
  if (!msg) {
    return false;
  }
  // turtle_name
  if (!rosidl_runtime_c__String__init(&msg->turtle_name)) {
    turtle_intfaces__msg__Turtle__fini(msg);
    return false;
  }
  // x
  // y
  // theta
  return true;
}

void
turtle_intfaces__msg__Turtle__fini(turtle_intfaces__msg__Turtle * msg)
{
  if (!msg) {
    return;
  }
  // turtle_name
  rosidl_runtime_c__String__fini(&msg->turtle_name);
  // x
  // y
  // theta
}

bool
turtle_intfaces__msg__Turtle__are_equal(const turtle_intfaces__msg__Turtle * lhs, const turtle_intfaces__msg__Turtle * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // turtle_name
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->turtle_name), &(rhs->turtle_name)))
  {
    return false;
  }
  // x
  if (lhs->x != rhs->x) {
    return false;
  }
  // y
  if (lhs->y != rhs->y) {
    return false;
  }
  // theta
  if (lhs->theta != rhs->theta) {
    return false;
  }
  return true;
}

bool
turtle_intfaces__msg__Turtle__copy(
  const turtle_intfaces__msg__Turtle * input,
  turtle_intfaces__msg__Turtle * output)
{
  if (!input || !output) {
    return false;
  }
  // turtle_name
  if (!rosidl_runtime_c__String__copy(
      &(input->turtle_name), &(output->turtle_name)))
  {
    return false;
  }
  // x
  output->x = input->x;
  // y
  output->y = input->y;
  // theta
  output->theta = input->theta;
  return true;
}

turtle_intfaces__msg__Turtle *
turtle_intfaces__msg__Turtle__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  turtle_intfaces__msg__Turtle * msg = (turtle_intfaces__msg__Turtle *)allocator.allocate(sizeof(turtle_intfaces__msg__Turtle), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(turtle_intfaces__msg__Turtle));
  bool success = turtle_intfaces__msg__Turtle__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
turtle_intfaces__msg__Turtle__destroy(turtle_intfaces__msg__Turtle * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    turtle_intfaces__msg__Turtle__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
turtle_intfaces__msg__Turtle__Sequence__init(turtle_intfaces__msg__Turtle__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  turtle_intfaces__msg__Turtle * data = NULL;

  if (size) {
    data = (turtle_intfaces__msg__Turtle *)allocator.zero_allocate(size, sizeof(turtle_intfaces__msg__Turtle), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = turtle_intfaces__msg__Turtle__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        turtle_intfaces__msg__Turtle__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
turtle_intfaces__msg__Turtle__Sequence__fini(turtle_intfaces__msg__Turtle__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      turtle_intfaces__msg__Turtle__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

turtle_intfaces__msg__Turtle__Sequence *
turtle_intfaces__msg__Turtle__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  turtle_intfaces__msg__Turtle__Sequence * array = (turtle_intfaces__msg__Turtle__Sequence *)allocator.allocate(sizeof(turtle_intfaces__msg__Turtle__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = turtle_intfaces__msg__Turtle__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
turtle_intfaces__msg__Turtle__Sequence__destroy(turtle_intfaces__msg__Turtle__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    turtle_intfaces__msg__Turtle__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
turtle_intfaces__msg__Turtle__Sequence__are_equal(const turtle_intfaces__msg__Turtle__Sequence * lhs, const turtle_intfaces__msg__Turtle__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!turtle_intfaces__msg__Turtle__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
turtle_intfaces__msg__Turtle__Sequence__copy(
  const turtle_intfaces__msg__Turtle__Sequence * input,
  turtle_intfaces__msg__Turtle__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(turtle_intfaces__msg__Turtle);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    turtle_intfaces__msg__Turtle * data =
      (turtle_intfaces__msg__Turtle *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!turtle_intfaces__msg__Turtle__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          turtle_intfaces__msg__Turtle__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!turtle_intfaces__msg__Turtle__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
