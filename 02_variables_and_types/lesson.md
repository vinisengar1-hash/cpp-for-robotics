# Lesson 2: Variables & Types

## Static typing (the biggest mental shift from GDScript)

In GDScript you can write `var x = 5` and later `x = "hello"` — the variable's
type can change. C++ is **statically typed**: every variable has one fixed type,
declared up front, forever.

```cpp
int motorCount = 4;        // a whole number
double batteryVoltage = 12.6;   // a decimal number
bool isEnabled = true;     // true or false
char firstLetter = 'A';    // a single character (single quotes!)
std::string robotName = "Bumblebot"; // text (needs #include <string>, double quotes)
```

Common types you'll actually use:

| Type | Holds | Example |
|---|---|---|
| `int` | whole numbers | `-3`, `0`, `42` |
| `double` | decimal numbers | `3.14`, `-0.5` |
| `bool` | true/false | `true`, `false` |
| `std::string` | text | `"hello"` |

Robotics-specific reasoning for why this matters: a motor's power is a `double`
between `-1.0` and `1.0`. A digital sensor reading (like a limit switch) is a
`bool`. An encoder tick count is an `int`. Getting the type right isn't
pedantry — the compiler uses it to catch real mistakes (like accidentally
treating a switch state as a motor power) *before* the robot ever moves.

## `const`

```cpp
const double MAX_MOTOR_POWER = 1.0;
```

`const` means "this can never be reassigned after it's set." Use it for values
that should never change while the program runs — like safety limits. If you
try to reassign a `const` later, the compiler refuses to build the program at
all, which is exactly the point: it turns a possible robot-breaking mistake
into a compile error you see immediately.

## `auto` (a small convenience)

```cpp
auto speed = 0.75; // compiler figures out this is a double
```

`auto` lets the compiler infer the type from what you assign. It's still
static typing — the type is fixed the moment the line runs — you're just not
typing it out. Use it when the type is obvious from context.

## Printing multiple things

```cpp
std::cout << "Voltage: " << batteryVoltage << " isEnabled: " << isEnabled << std::endl;
```

You can chain as many `<<` as you want on one line.

## Your exercise

Open `exercise.cpp` and follow the `// TODO` comments.
