#include <rclcpp/rclcpp.hpp>
#include "turtle_interfaces/msg/turtle.hpp"
#include <turtlesim/srv/spawn.hpp>
using namespace std::chrono_literals;


class SpawnSystem : public rclcpp::Node
{
  public:
  SpawnSystem() : Node("SpawnerNode")
  {
    this->declare_parameter("respawn_time" , 2.0);
    double time_cycle = this->get_parameter("respawn_time").as_double();

    turtles_publisher_ = this->create_publisher<turtle_interfaces::msg::Turtle>( "turtles" , 10);

    spawn_client_ = this->create_client<turtlesim::srv::Spawn>("spawn");

    timer_ = this->create_wall_timer( std::chrono::duration<double>(time_cycle) , std::bind(&SpawnSystem::spawn_requst , this));
  }

  private:
  rclcpp::Publisher<turtle_interfaces::msg::Turtle>::SharedPtr turtles_publisher_;
  rclcpp::Client<turtlesim::srv::Spawn>::SharedPtr spawn_client_;
  rclcpp::TimerBase::SharedPtr timer_;
  turtle_interfaces::msg::Turtle msg_;
  

  void spawn_requst();
};
