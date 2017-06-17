#include "jedgar_driver/JedgarInterface.h"

JedgarInterface::JedgarInterface(std::string port, int baud, int timeout) : serializer(port, baud, timeout) {
    // Setup ros_control interfaces
    // Left state
    hardware_interface::JointStateHandle leftStateHandle("left_wheel_joint", pos + 0, vel + 0, eff + 0);
    stateInterface.registerHandle(leftStateHandle);

    // Left command
    hardware_interface::JointHandle leftCommandHandle(leftStateHandle, moveAt + 0);
    velocityCommandInterface.registerHandle(leftCommandHandle);

    // Right state
    hardware_interface::JointStateHandle rightStateHandle("right_wheel_joint", pos + 1, vel + 1, eff + 1);
    stateInterface.registerHandle(rightStateHandle);

    // Right command
    hardware_interface::JointHandle rightCommandHandle(rightStateHandle, moveAt + 1);
    velocityCommandInterface.registerHandle(rightCommandHandle);

    // Register interfaces
    registerInterface(&stateInterface);
    registerInterface(&velocityCommandInterface);

    // TODO Initalize communication with the serializer
}


JedgarInterface::~JedgarInterface() {
    // Shutdown motors
    serializer.stop();
}

void JedgarInterface::read() {
    // Read the current state of the motors into pos, vel, eff
    serializer.getPosition(pos[0], pos[1]);
    serializer.getVelocity(vel[0], vel[1]);
    eff[0] = 0; eff[1] = 0;
}

void JedgarInterface::write() {
    // Write the velocity commanded by moveAt to the motors
    serializer.setVelocity(moveAt[0], moveAt[1]);
}

