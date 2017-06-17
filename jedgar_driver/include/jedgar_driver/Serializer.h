#ifndef SERIALIZER_H
#define SERIALIZER_H

#include <serial/serial.h>

#include <string>

class Serializer {
public:
    Serializer(std::string port, int baud, int timeout);

    void setVelocity(double leftVel, double rightVel);
    void getVelocity(double &leftVel, double &rightVel);
    void getPosition(double &leftPos, double &rightPos);
    void stop();

private:
    serial::Serial serialPort;
};

#endif

