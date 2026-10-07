#include <rclcpp/rclcpp.hpp>
#include <turtlesim/srv/kill.hpp>
#include <std_srvs/srv/empty.hpp>
#include <turtlesim/msg/pose.hpp>
#include <geometry_msgs/msg/twist.hpp>
#include "turtle_interfaces/msg/turtle.hpp"


class CatchController : public rclcpp::Node
{
    public:
    CatchController() : Node("ControllerNode")
    {
        this->declare_parameter("catch_speed" , 2.0);
        catch_speed_ = this->get_parameter("catch_speed").as_double();

        my_pose_subscriper_ = this->create_subscription<turtlesim::msg::Pose>("turtle1/pose" , 10 ,[this](const turtlesim::msg::Pose::SharedPtr msg){
            my_pose_ = *msg;
        });
        turtles_subscriper_ = this->create_subscription<turtle_interfaces::msg::Turtle>("turtles" , 10 , [this](const turtle_interfaces::msg::Turtle msg){
            turtles_.insert({ msg.turtle_name , msg});
        });

        cmd_vel_publisher_ = this->create_publisher<geometry_msgs::msg::Twist>("turtle1/cmd_vel" , 10);
        
        kill_client_ = this->create_client<turtlesim::srv::Kill>("kill");
        clear_client_ = this->create_client<std_srvs::srv::Empty>("clear");

        timer_ = this->create_wall_timer(std::chrono::milliseconds(100) ,
            std::bind(&CatchController::main_controller_callback , this));
    }

    private:
    turtlesim::msg::Pose my_pose_;
    std::map<std::string , turtle_interfaces::msg::Turtle> turtles_;
    double catch_speed_;

    rclcpp::TimerBase::SharedPtr timer_;
    rclcpp::Subscription<turtlesim::msg::Pose>::SharedPtr my_pose_subscriper_;
    rclcpp::Subscription<turtle_interfaces::msg::Turtle>::SharedPtr turtles_subscriper_;
    
    rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr cmd_vel_publisher_;
    rclcpp::Client<turtlesim::srv::Kill>::SharedPtr kill_client_;
    rclcpp::Client<std_srvs::srv::Empty>::SharedPtr clear_client_;   

    void call_kill_service(std::string name);
    void call_clear_service();
    void publish_cmd_vel(double& dy , double& dx , double& distance);
    void main_controller_callback();
    double euclidean( turtlesim::msg::Pose& my_pose , turtle_interfaces::msg::Turtle& second_pose );
};