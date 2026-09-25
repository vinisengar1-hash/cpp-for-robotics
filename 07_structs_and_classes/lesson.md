# Lesson 7: Structs & Classes

## struct — a simple bundle of variables

```cpp
struct MotorState {
    double power;
    bool isEnabled;
};

MotorState leftMotor;
leftMotor.power = 0.5;
leftMotor.isEnabled = true;
```

A `struct` groups related variables ("members") under one name. Nothing more
than that — just a labeled bundle, accessed with `.`.

## class — a bundle of variables AND behavior

```cpp
class Motor {
public:
    Motor() {
        power = 0.0; // constructor: runs automatically when a Motor is created
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
```

```cpp
Motor leftMotor;
leftMotor.SetPower(1.8);              // gets clamped internally
std::cout << leftMotor.GetPower();    // prints 1.0
```

Pieces:
- **`public:` / `private:`** — `public` members can be accessed from outside
  the class (`leftMotor.SetPower(...)`); `private` members can only be
  touched from inside the class's own functions. `power` is private — nobody
  outside `Motor` can do `leftMotor.power = 999;` and bypass the clamp. This
  is **encapsulation**: hiding the raw data so the only way to change it is
  through functions that enforce the rules. This is exactly the clamp
  function from lesson 4, except now it's baked into the object itself so it
  can never be skipped.
- **Constructor** — `Motor()`, a function with the same name as the class and
  no return type, runs automatically the moment you create a `Motor`. Use it
  to set up sensible starting values.
- **`const` after a function's parameters** — `double GetPower() const`
  promises this function won't modify the object's members. It's a good habit
  for any "just reading a value" function, and the compiler will actually
  enforce the promise (it'll refuse to compile if you try to modify a member
  inside a `const` function).
- **`struct` vs `class`** — they're almost identical in C++; the only real
  difference is `struct` members are `public` by default, `class` members are
  `private` by default. Convention: use `struct` for simple data bundles with
  no real behavior, `class` for anything with methods enforcing rules.

## Why this matters for WPILib

Every piece of hardware on a real robot — a motor controller, a sensor, a
whole subsystem like a drivetrain — is represented as a class exactly like
this: private data (the actual hardware state/objects), public methods that
are the only sanctioned way to interact with it (`Drive(...)`, `Stop()`,
`GetDistance()`). You just built the exact shape of a WPILib subsystem, minus
the real hardware.

## Your exercise

Open `exercise.cpp` and follow the `// TODO` comments.
