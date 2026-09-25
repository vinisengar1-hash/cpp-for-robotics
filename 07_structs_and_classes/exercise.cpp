#include <iostream>

class Motor {
public:
    // TODO 1: Write a constructor `Motor()` that sets `power` to 0.0.

    // TODO 2: Write `void SetPower(double newPower)` that clamps newPower
    //         between -1.0 and 1.0 (same logic as lesson 4's clampMotorPower)
    //         and stores the result into `power`.

    // TODO 3: Write `double GetPower() const` that returns `power`.

private:
    double power;
    // TODO 4: declare `double power;` here (it needs to exist as a member!)
};

int main() {
    Motor leftMotor;
    Motor rightMotor;

    leftMotor.SetPower(0.5);
    rightMotor.SetPower(1.8); // should get clamped to 1.0

    // TODO 5: Print leftMotor.GetPower() and rightMotor.GetPower().

    return 0;
}
