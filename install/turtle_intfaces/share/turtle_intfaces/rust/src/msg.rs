#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};



// Corresponds to turtle_intfaces__msg__Turtle

// This struct is not documented.
#[allow(missing_docs)]

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Turtle {

    // This member is not documented.
    #[allow(missing_docs)]
    pub turtle_name: std::string::String,


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
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::Turtle::default())
  }
}

impl rosidl_runtime_rs::Message for Turtle {
  type RmwMsg = super::msg::rmw::Turtle;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        turtle_name: msg.turtle_name.as_str().into(),
        x: msg.x,
        y: msg.y,
        theta: msg.theta,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        turtle_name: msg.turtle_name.as_str().into(),
      x: msg.x,
      y: msg.y,
      theta: msg.theta,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      turtle_name: msg.turtle_name.to_string(),
      x: msg.x,
      y: msg.y,
      theta: msg.theta,
    }
  }
}


