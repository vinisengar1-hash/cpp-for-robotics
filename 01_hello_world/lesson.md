# Lesson 1: Hello World & Compiling

## The big difference from GDScript

In Godot, you write a `.gd` file and the engine reads and runs it on the spot —
that's called an **interpreted** language. C++ doesn't work that way: you write
a `.cpp` file, run it through a **compiler**, which translates it into an actual
native executable (a `.exe` on Windows) — a completely separate file full of raw
machine instructions. Only *then* can you run it. This "compile, then run" cycle
is exactly what happens with real FRC robot code: your C++ gets compiled into a
program that gets deployed to run directly on the robot's controller (the
roboRIO).

## Anatomy of a C++ program

```cpp
#include <iostream>

int main() {
    std::cout << "Hello, robot!" << std::endl;
    return 0;
}
```

- `#include <iostream>` — pulls in the input/output library so you can print
  text. C++ has almost no built-in commands; nearly everything comes from
  libraries you explicitly include.
- `int main() { ... }` — every C++ program has exactly one `main` function; it's
  where the program starts running. The `int` means it returns a whole number to
  the operating system when it finishes (0 conventionally means "success").
- `std::cout << "..." << std::endl;` — prints text. `std::cout` is "the console
  output stream," `<<` sends things into it, and `std::endl` ends the line.
  `std::` means "this comes from the standard library."
- **Every statement ends in a semicolon `;`.** GDScript uses newlines/indentation
  to separate statements; C++ doesn't care about whitespace at all — it only
  cares about semicolons and curly braces `{ }`. Forgetting a semicolon is the
  single most common beginner error and will stop the whole thing from
  compiling.

## Compiling

If you're using an online compiler (godbolt.org, onlinegdb.com), just paste the
code and hit run. If you've installed a local compiler (see the main README),
from a terminal in this folder:

    g++ -std=c++17 -o exercise exercise.cpp
    ./exercise

The first line compiles `exercise.cpp` into a program named `exercise`; the
second line actually runs it.

## Your exercise

Open `exercise.cpp` and follow the `// TODO` comments.
