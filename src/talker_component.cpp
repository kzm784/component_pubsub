#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/string.hpp>

using namespace std::chrono_literals;

namespace component_pubsub
{

class SimpleTalker : public rclcpp::Node
{
    public:
        SimpleTalker(const rclcpp::NodeOptions & options) : Node("simple_talker", options)
        {
            publisher_ = this->create_publisher<std_msgs::msg::String>(
                "chatter", 10
            );
            
            timer_ = this->create_wall_timer(
                100ms, std::bind(&SimpleTalker::CallBack, this)
            );
        }

    private:
        void CallBack()
        {
            std_msgs::msg::String msg;
            msg.data = "Hello World!";
            RCLCPP_INFO(this->get_logger(), "publish: %s", msg.data.c_str());
            publisher_->publish(msg);
        }

        rclcpp::TimerBase::SharedPtr timer_;
        rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_;       
};

} // namespace component_pubsub

#include <rclcpp_components/register_node_macro.hpp>
RCLCPP_COMPONENTS_REGISTER_NODE(component_pubsub::SimpleTalker)