#include "jedgar_driver/Serializer.h"

Serializer::Serializer(std::string port, int baud, int timeout)
    : serialPort(port, baud, serial::Timeout::simpleTimeout(timeout)) {}

void Serializer::setVelocity(double leftSpeed, double rightSpeed) {
    // TODO Serial communication
}

void Serializer::getVelocity(double &leftVel, double &rightVel) {
    // TODO Serial communication
}

void Serializer::getPosition(double &leftPos, double &rightPos) {
    // TODO Serial communication
}

void Serializer::stop() {
    // TODO Serial communication
}

