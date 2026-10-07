#include "controller_node.hpp"
#include <cmath>

double CatchController::euclidean( turtlesim::msg::Pose& my_pose , turtle_interfaces::msg::Turtle& second_pose )
{
    double dx = my_pose.x - second_pose.x;
    double dy = my_pose.y - second_pose.y;
    return std::sqrt( (dx*dx) + (dy*dy) );
}

void CatchController::call_kill_service(std::string name)
{
    if (!kill_client_->wait_for_service(std::chrono::milliseconds(500)))
    {
        RCLCPP_ERROR( this->get_logger() , "Server is not available!");
        rclcpp::shutdown();
        return;
    }
    auto request = std::make_shared<turtlesim::srv::Kill::Request>();
    request->name = name;

    kill_client_ ->async_send_request(request , [this ,name](rclcpp::Client<turtlesim::srv::Kill>::SharedFuture future){
        auto response = future.get();
        RCLCPP_INFO( this->get_logger() , "%s has been killed." , name.c_str());
    });
}

void CatchController::call_clear_service()
{
    if (!clear_client_->wait_for_service(std::chrono::milliseconds(500))) {
        return;
    }
    auto request = std::make_shared<std_srvs::srv::Empty::Request>();
    clear_client_->async_send_request(request);
}

void CatchController::publish_cmd_vel(double& dy , double& dx , double& distance)
{
    auto target_angel = std::atan2( dy , dx );
    auto angel_error =  target_angel - my_pose_.theta;
    auto accurate_angel = std::atan2(std::sin(angel_error) , std::cos(angel_error));

    geometry_msgs::msg::Twist cmd_vel;

    cmd_vel.angular.z = 6.0 * accurate_angel;
    cmd_vel.linear.x = std::abs(accurate_angel < 0.05 ) ? catch_speed_ * distance : 0.0;

    cmd_vel_publisher_->publish(cmd_vel);
}

void CatchController::main_controller_callback()
{
    if ( turtles_.empty()){
        return;
    }
    auto nearest_turtle = std::min_element( turtles_.begin() , turtles_.end() , [this](auto a , auto b){
        return euclidean( my_pose_ , a.second) < euclidean(my_pose_ , b.second);
    });
    
    double dx = (nearest_turtle->second.x - my_pose_.x);
    double dy = (nearest_turtle->second.y - my_pose_.y);
    double distance = std::sqrt((dx*dx) + (dy*dy));

    if(distance < 0.5){
        call_kill_service(nearest_turtle->first);
        turtles_.erase(nearest_turtle);
        call_clear_service();
        return;
    }
    publish_cmd_vel(dy , dx , distance);
}

int main( int argc , char * argv[])
{
    rclcpp::init(argc , argv);
    rclcpp::spin(std::make_shared<CatchController>());
    rclcpp::shutdown();
}