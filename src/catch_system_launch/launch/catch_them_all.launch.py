from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        Node(
            package="turtlesim",
            executable="turtlesim_node",
            name="catchsim"
        ),
        Node(
            package="catch_system",
            executable="spawn_manager",
            name="spawn_manager"
        ),
        Node(
            package="catch_system",
            executable="controller_node",
            name="controller_node"
        )
    ])