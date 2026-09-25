#include <iostream>
#include <vector>

class Subsystem {
public:
    // TODO 1: Declare a pure virtual function `void Periodic()`.
    //         (hint: virtual void Periodic() = 0;)
};

class Drivetrain : public Subsystem {
public:
    // TODO 2: Override Periodic() to print "Drivetrain: updating motor outputs."
};

class Arm : public Subsystem {
public:
    // TODO 3: Override Periodic() to print "Arm: holding position."
};

int main() {
    Drivetrain drivetrain;
    Arm arm;

    // TODO 4: Create a std::vector<Subsystem*> called subsystems.

    // TODO 5: push_back &drivetrain and &arm onto it.

    // TODO 6: Loop over subsystems with a range-based for loop
    //         (for (Subsystem* subsystem : subsystems)) and call
    //         subsystem->Periodic() on each one.

    return 0;
}
