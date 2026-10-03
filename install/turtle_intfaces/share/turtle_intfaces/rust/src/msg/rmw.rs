#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};


#[link(name = "turtle_intfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__turtle_intfaces__msg__Turtle() -> *const std::ffi::c_void;
}

#[link(name = "turtle_intfaces__rosidl_generator_c")]
extern "C" {
    fn turtle_intfaces__msg__Turtle__init(msg: *mut Turtle) -> bool;
    fn turtle_intfaces__msg__Turtle__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<Turtle>, size: usize) -> bool;
    fn turtle_intfaces__msg__Turtle__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<Turtle>);
    fn turtle_intfaces__msg__Turtle__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<Turtle>, out_seq: *mut rosidl_runtime_rs::Sequence<Turtle>) -> bool;
}

// Corresponds to turtle_intfaces__msg__Turtle
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Turtle {

    // This member is not documented.
    #[allow(missing_docs)]
    pub turtle_name: rosidl_runtime_rs::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub x: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub y: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub theta: f64,

}



impl Default for Turtle {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !turtle_intfaces__msg__Turtle__init(&mut msg as *mut _) {
        panic!("Call to turtle_intfaces__msg__Turtle__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for Turtle {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { turtle_intfaces__msg__Turtle__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { turtle_intfaces__msg__Turtle__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { turtle_intfaces__msg__Turtle__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for Turtle {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for Turtle where Self: Sized {
  const TYPE_NAME: &'static str = "turtle_intfaces/msg/Turtle";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__turtle_intfaces__msg__Turtle() }
  }
}


