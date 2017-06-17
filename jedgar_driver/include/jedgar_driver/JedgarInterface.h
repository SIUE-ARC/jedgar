#ifndef JEDGAR_INTERFACE_H
#define JEDGAR_INTREFACE_H

#include <hardware_interface/joint_command_interface.h>
#include <hardware_interface/joint_state_interface.h>
#include <hardware_interface/robot_hw.h>

#include "jedgar_driver/Serializer.h"

class JedgarInterface : public hardware_interface::RobotHW {
public:
    JedgarInterface(std::string port, int baud, int timeout);
    ~JedgarInterface();

    void read();
    void write();

private:
    Serializer serializer;

    hardware_interface::JointStateInterface stateInterface;
    hardware_interface::VelocityJointInterface velocityCommandInterface;

    double pos[2];
    double vel[2];
    double eff[2];
    double moveAt[2];
};

#endif

