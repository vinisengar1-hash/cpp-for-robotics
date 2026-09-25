#include <iostream>
#include <vector>

class Subsystem {
public:
    virtual void Periodic() = 0;
};

class Drivetrain : public Subsystem {
public:
    void Periodic() override {
        std::cout << "Drivetrain: updating motor outputs." << std::endl;
    }
};

class Arm : public Subsystem {
public:
    void Periodic() override {
        std::cout << "Arm: holding position." << std::endl;
    }
};

int main() {
    Drivetrain drivetrain;
    Arm arm;

    std::vector<Subsystem*> subsystems;
    subsystems.push_back(&drivetrain);
    subsystems.push_back(&arm);

    for (Subsystem* subsystem : subsystems) {
        subsystem->Periodic();
    }

    return 0;
}
