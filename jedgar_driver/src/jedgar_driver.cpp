#include <controller_manager/controller_manager.h>

#include "jedgar_driver/JedgarInterface.h"

int main(int argc, char **argv) {
    ros::init(argc, argv, "jedgar_driver");

    JedgarInterface interface;
    controller_manager::ControllerManager cm(&interface);

    ros::Time then = ros::Time::now();
    ros::Rate rate(50.0);

    while (ros::ok()) {
        const ros::Time now = ros::Time::now();

        interface.read();
        cm.update(now, now - then);
        interface.write();

        then = now;
        rate.sleep();
    }
}

