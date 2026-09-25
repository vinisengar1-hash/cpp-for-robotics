# Lesson 4: Functions

## Basic shape

```cpp
double clampMotorPower(double power) {
    if (power > 1.0) {
        return 1.0;
    }
    if (power < -1.0) {
        return -1.0;
    }
    return power;
}
```

`double clampMotorPower(double power)` reads as: "a function named
`clampMotorPower`, which takes one `double` parameter named `power`, and
returns a `double`." You call it like `clampMotorPower(1.5)`, which returns
`1.0`.

A function that returns nothing uses `void`:

```cpp
void printStatus(std::string message) {
    std::cout << "[STATUS] " << message << std::endl;
}
```

## Pass by value (the default — and a trap)

```cpp
void tryToReset(int count) {
    count = 0; // only changes the local copy!
}

int main() {
    int encoderCount = 42;
    tryToReset(encoderCount);
    std::cout << encoderCount << std::endl; // still prints 42!
}
```

By default, C++ **copies** the argument into the function's parameter. Changes
inside the function don't affect the original variable at all — `encoderCount`
is still `42` after the call. This is genuinely different from how you might
expect coming from GDScript, where passing an object lets you mutate it.

## Pass by reference (the fix)

```cpp
void resetEncoder(int &count) {
    count = 0; // this DOES change the caller's variable
}

int main() {
    int encoderCount = 42;
    resetEncoder(encoderCount);
    std::cout << encoderCount << std::endl; // prints 0
}
```

Adding `&` after the type in the parameter list (`int &count`) makes `count` a
**reference** to the caller's actual variable — not a copy. Whatever you do to
`count` inside the function happens to the original. This is how you write a
function that needs to modify something the caller owns (like resetting a
sensor, or updating a passed-in state struct) rather than just computing and
returning a new value.

Rule of thumb: use plain pass-by-value for inputs you just want to read, and
pass-by-reference (`&`) when the function needs to modify the caller's
variable directly.

## Your exercise

Open `exercise.cpp` and follow the `// TODO` comments.
