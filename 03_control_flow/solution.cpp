#include <iostream>

int main() {
    double batteryVoltage = 11.2;

    if (batteryVoltage < 11.0) {
        std::cout << "CRITICAL: brownout risk!" << std::endl;
    } else if (batteryVoltage < 12.0) {
        std::cout << "WARNING: battery low." << std::endl;
    } else {
        std::cout << "Battery OK." << std::endl;
    }

    for (int i = 1; i <= 10; i++) {
        if (i == 5) {
            continue;
        }
        if (i == 8) {
            break;
        }
        std::cout << "Test cycle " << i << std::endl;
    }

    return 0;
}
