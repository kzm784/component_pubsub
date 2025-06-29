from launch import LaunchDescription
from launch_ros.actions import ComposableNodeContainer
from launch_ros.descriptions import ComposableNode

def generate_launch_description():
    container = ComposableNodeContainer(
        name='component_pubsub_container',
        namespace='component_pubsub',
        package='rclcpp_components',
        executable='component_container',
        output='screen',
        composable_node_descriptions=[
            getSimpleTalkerComponent(),
            getSimpleListenerComponent(),
        ]
    )

    return LaunchDescription([container])

def getSimpleTalkerComponent():
    return ComposableNode(
        package='component_pubsub',
        plugin='component_pubsub::SimpleTalker',
        name='simple_talker',
        namespace='component_pubsub',
        remappings=[('/chatter', '/chatter')],
        extra_arguments=[{'use_intra_process_comms': True}]
    )

def getSimpleListenerComponent():
    return ComposableNode(
        package='component_pubsub',
        plugin='component_pubsub::SimpleListener',
        name='simple_listener',
        namespace='component_pubsub',
        remappings=[('/chatter', '/chatter')],
        extra_arguments=[{'use_intra_process_comms': True}]
    )