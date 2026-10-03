#include "spawn_manager.hpp"
#include <random>


void SpawnSystem::spawn_requst()
{ 
  if(!spawn_client_->wait_for_service(1s)){
    RCLCPP_WARN(this -> get_logger() , "SERVER IS NOT AVAILABLE");
    return;
  }
  std::random_device device;
  std::mt19937 mt(device());
  std::uniform_real_distribution<float> dist( 1.0f , 10.0f);

  auto request = std::make_shared<turtlesim::srv::Spawn::Request>();
  request->x = dist(mt);
  request->y = dist(mt);

  spawn_client_->async_send_request(request , [this , request](rclcpp::Client<turtlesim::srv::Spawn>::SharedFuture future){
    auto response = future.get();

    msg_.turtle_name = response->name;
    msg_.x = request->x;
    msg_.y = request->y;

    turtles_publisher_->publish(msg_);
  });
}


int main(int argc, char * argv[])
{
  rclcpp::init(argc , argv);
  rclcpp::spin(std::make_shared<SpawnSystem>());
  rclcpp::shutdown();
  
  return 0;
}
