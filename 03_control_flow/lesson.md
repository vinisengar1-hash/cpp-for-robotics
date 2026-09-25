# Lesson 3: Control Flow

This one is the closest to GDScript — the logic is nearly identical, just with
different punctuation.

## if / else if / else

```cpp
double batteryVoltage = 11.2;

if (batteryVoltage < 11.0) {
    std::cout << "CRITICAL: brownout risk, disable robot!" << std::endl;
} else if (batteryVoltage < 12.0) {
    std::cout << "WARNING: battery getting low." << std::endl;
} else {
    std::cout << "Battery OK." << std::endl;
}
```

Notes vs. GDScript:
- Conditions go in `( )`.
- Bodies go in `{ }` — not indentation. (Indentation is still good style, but
  the compiler ignores it entirely; only the braces matter.)
- Comparison operators are the same: `<`, `>`, `<=`, `>=`, `==`, `!=`.
- Logical operators are different: `&&` (and), `||` (or), `!` (not) — GDScript
  also accepts these, but C++ *only* accepts these (no `and`/`or`/`not`
  keywords in standard C++... actually it technically has alternative
  spellings, but almost nobody uses them — stick to `&&` `||` `!`).

## while loop

```cpp
int cyclesRemaining = 5;
while (cyclesRemaining > 0) {
    std::cout << "Cycles remaining: " << cyclesRemaining << std::endl;
    cyclesRemaining = cyclesRemaining - 1; // or: cyclesRemaining--;
}
```

## for loop

```cpp
for (int i = 1; i <= 10; i++) {
    std::cout << "Test cycle " << i << std::endl;
}
```

The three parts inside `( )`, separated by semicolons: **start** (`int i = 1`),
**keep going while this is true** (`i <= 10`), **do this after each loop**
(`i++`, meaning "add 1 to i"). This is the classic "counting loop" shape you'll
see constantly in robot code (e.g. looping over 4 swerve modules, `for (int i =
0; i < 4; i++)`).

## break and continue

```cpp
for (int i = 1; i <= 10; i++) {
    if (i == 5) {
        continue; // skip the rest of this loop iteration, go to next i
    }
    if (i == 8) {
        break; // exit the loop entirely, right now
    }
    std::cout << i << std::endl;
}
```

This prints 1,2,3,4 (skips 5 via `continue`), 6,7, then stops entirely at 8
(via `break`) — so 9 and 10 never print.

## Your exercise

Open `exercise.cpp` and follow the `// TODO` comments.
