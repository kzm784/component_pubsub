#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/string.hpp>

using std::placeholders::_1;

namespace component_pubsub
{

class SimpleListener : public rclcpp::Node
{
    public:
        SimpleListener(const rclcpp::NodeOptions & options) : Node("simple_listener", options)
        {
            subscription_ = this->create_subscription<std_msgs::msg::String>(
                "chatter", 10, std::bind(&SimpleListener::CallBack, this, _1)
            );
        }

    private:
        void CallBack(const std_msgs::msg::String::SharedPtr msg) const
        {
            RCLCPP_INFO(this->get_logger(), "subscribe: %s", msg->data.c_str());
        }

        rclcpp::Subscription<std_msgs::msg::String>::SharedPtr subscription_;
};

} // namespace component_pobsub

#include <rclcpp_components/register_node_macro.hpp>
RCLCPP_COMPONENTS_REGISTER_NODE(component_pubsub::SimpleListener)