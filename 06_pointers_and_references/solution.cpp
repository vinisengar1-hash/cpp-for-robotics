#include <iostream>

void doubleValue(double* value) {
    *value = *value * 2.0;
}

int main() {
    int encoderCount = 42;

    int* countPointer = &encoderCount;
    std::cout << *countPointer << std::endl; // 42

    *countPointer = 100;
    std::cout << encoderCount << std::endl; // 100

    double motorPower = 0.3;
    doubleValue(&motorPower);
    std::cout << motorPower << std::endl; // 0.6

    int* maybeCount = nullptr;
    if (maybeCount != nullptr) {
        std::cout << *maybeCount << std::endl;
    } else {
        std::cout << "no value yet" << std::endl;
    }

    return 0;
}
