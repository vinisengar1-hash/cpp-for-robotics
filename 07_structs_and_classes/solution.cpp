#include <iostream>

class Motor {
public:
    Motor() {
        power = 0.0;
    }

    void SetPower(double newPower) {
        if (newPower > 1.0) {
            newPower = 1.0;
        }
        if (newPower < -1.0) {
            newPower = -1.0;
        }
        power = newPower;
    }

    double GetPower() const {
        return power;
    }

private:
    double power;
};

int main() {
    Motor leftMotor;
    Motor rightMotor;

    leftMotor.SetPower(0.5);
    rightMotor.SetPower(1.8);

    std::cout << "Left motor power: " << leftMotor.GetPower() << std::endl;
    std::cout << "Right motor power: " << rightMotor.GetPower() << std::endl;

    return 0;
}
