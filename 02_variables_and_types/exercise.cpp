#include <iostream>
#include <string>

int main() {
    // TODO 1: Declare a `std::string` called robotName, set to any name you like.
    std::string robotName = "funkybot";
    // TODO 2: Declare a `double` called batteryVoltage, set to 12.6.
    double batteryVoltage = 12.6;
    // TODO 3: Declare an `int` called motorCount, set to 4.
    int motorCount = 4;
    // TODO 4: Declare a `bool` called isEnabled, set to true.
    bool isEnabled = true;
    // TODO 5: Declare a `const double` called MAX_MOTOR_POWER, set to 1.0.
    const double MAX_MOTOR_POWER = 1.0;
    // TODO 6: Print all five values, each on its own line, with a label,
    //         e.g. "Robot name: Bumblebot"
    std::cout<<"Robot Name:"<< robotName<<std::endl;
    std::cout<<"Battery Voltage:"<< batteryVoltage<<std::endl;
    std::cout<<"Motor Count:"<< motorCount<<std::endl;
    std::cout<<"isEnabled:"<< isEnabled<<std::endl;
    std::cout<<"Max motor power:"<< MAX_MOTOR_POWER<<std::endl;

    return 0;
}
