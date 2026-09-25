# Lesson 8: Inheritance & Polymorphism

This is the lesson that connects everything to real WPILib code. Real FRC
robot code has a "scheduler" that, every ~20 milliseconds, loops over *every*
subsystem on the robot and calls a `Periodic()` method on each one — the
drivetrain updates its motors, the arm checks its position, the shooter reads
its sensor, all through the exact same loop. This lesson builds a small,
from-scratch version of that pattern so the real thing is recognizable later.

## Inheritance: "is-a" relationships

```cpp
class Subsystem {
public:
    virtual void Periodic() {
        std::cout << "Generic subsystem doing nothing." << std::endl;
    }
};

class Drivetrain : public Subsystem {
public:
    void Periodic() override {
        std::cout << "Drivetrain: updating motor outputs." << std::endl;
    }
};
```

`class Drivetrain : public Subsystem` means "a `Drivetrain` **is a**
`Subsystem`, plus whatever extra it adds." It automatically gets everything
`Subsystem` has, and can override specific behavior.

## `virtual` and `override` — why they matter

```cpp
Subsystem* mySubsystem = new Drivetrain();
mySubsystem->Periodic(); // prints "Drivetrain: updating motor outputs."
```

Without the `virtual` keyword on the base class's `Periodic()`, this would
print the generic `Subsystem` message instead — even though `mySubsystem`
actually points to a `Drivetrain`! `virtual` tells C++: "figure out which
version to call based on the object's *real* type at runtime, not just the
type of the pointer." This is called **polymorphism** — one pointer type
(`Subsystem*`) can refer to many different actual subclasses, and calling a
virtual function always does the right, specific thing for whatever object is
actually there.

`override` on the derived class's version isn't strictly required, but always
write it — it tells the compiler "I intend to override a virtual function
from the base class," and the compiler will error if you got the function
signature wrong (e.g. a typo), instead of silently creating an unrelated new
function. Free safety net, always use it.

## Pure virtual functions: forcing subclasses to implement something

```cpp
class Subsystem {
public:
    virtual void Periodic() = 0; // "= 0" means: no default implementation,
                                  // every subclass MUST provide one
};
```

A class with a pure virtual function (`= 0`) is called **abstract** — you
can't create a plain `Subsystem` directly anymore (`Subsystem s;` won't
compile), only subclasses that actually implement `Periodic()`. This matches
WPILib exactly: you never create a raw `SubsystemBase`, you always make your
own subsystem class that inherits from it.

## Putting it together: the scheduler pattern

```cpp
#include <vector>

int main() {
    Drivetrain drivetrain;
    Arm arm;

    std::vector<Subsystem*> subsystems;
    subsystems.push_back(&drivetrain);
    subsystems.push_back(&arm);

    for (Subsystem* subsystem : subsystems) {
        subsystem->Periodic(); // calls the RIGHT version for each one
    }
}
```

That loop — a `std::vector` of base-class pointers, looping through and
calling one virtual method — is, structurally, exactly what the real WPILib
scheduler does with every subsystem on an actual robot, every 20ms, for the
entire match.

## Your exercise

Open `exercise.cpp` and follow the `// TODO` comments.
