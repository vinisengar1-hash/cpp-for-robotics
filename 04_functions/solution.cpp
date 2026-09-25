#include <iostream>

double clampMotorPower(double power) {
    if (power > 1.0) {
        return 1.0;
    }
    if (power < -1.0) {
        return -1.0;
    }
    return power;
}

void resetEncoder(int &count) {
    count = 0;
}

int main() {
    double tooHigh = 1.8;
    double tooLow = -2.5;
    double justRight = 0.4;

    std::cout << "Clamped tooHigh: " << clampMotorPower(tooHigh) << std::endl;
    std::cout << "Clamped tooLow: " << clampMotorPower(tooLow) << std::endl;
    std::cout << "Clamped justRight: " << clampMotorPower(justRight) << std::endl;

    int encoderCount = 42;
    std::cout << "Before reset: " << encoderCount << std::endl;

    resetEncoder(encoderCount);
    std::cout << "After reset: " << encoderCount << std::endl;

    return 0;
}
