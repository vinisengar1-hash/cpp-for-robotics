#include <iostream>
#include <string>

int main() {
    std::string robotName = "Bumblebot";
    double batteryVoltage = 12.6;
    int motorCount = 4;
    bool isEnabled = true;
    const double MAX_MOTOR_POWER = 1.0;

    std::cout << "Robot name: " << robotName << std::endl;
    std::cout << "Battery voltage: " << batteryVoltage << std::endl;
    std::cout << "Motor count: " << motorCount << std::endl;
    std::cout << "Is enabled: " << isEnabled << std::endl;
    std::cout << "Max motor power: " << MAX_MOTOR_POWER << std::endl;

    return 0;
}
