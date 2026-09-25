# C++ for Robotics

A hands-on path from "I've never written C++" to "I can read and extend real FRC robot code."

## Why this exists

Most FIRST Robotics Competition (FRC) teams write robot code in C++ or Java using
**WPILib**, the standard robotics framework. This course does NOT teach WPILib
directly — that needs the real toolchain (or at least the simulator) installed,
which is a heavy install you don't need yet. Instead, it teaches the C++ language
fundamentals that WPILib code is built out of: types, functions, pointers/references,
and especially classes and inheritance, since WPILib's "command-based" framework is
just C++ classes inheriting from base classes it provides.

By the end of lesson 8, real WPILib code like this should be readable, not magic:

    class Drivetrain : public frc2::SubsystemBase {
     public:
      void Drive(double forward, double turn);
     private:
      frc::PWMSparkMax m_left{0};
      frc::PWMSparkMax m_right{1};
    };

That's a class, inheriting from a base class, with private member objects and a
public method — exactly what lessons 7 and 8 cover.

## How this is organized

Eight lessons, each its own folder, meant to be done in order (each one leans on
the last):

    01_hello_world
    02_variables_and_types
    03_control_flow
    04_functions
    05_arrays_vectors_strings
    06_pointers_and_references   <- the hard one, budget extra time
    07_structs_and_classes
    08_inheritance_and_polymorphism

Each folder has three files:

- `lesson.md` — the explanation, plus a "why this matters for robotics" note
- `exercise.cpp` — starter code with `// TODO` markers for you to fill in yourself
- `solution.cpp` — a reference answer, meant for *after* you've genuinely tried

## Getting a compiler

You need something that turns a `.cpp` file into a program you can actually run.
Right now you don't have one installed (no g++, no MSVC, WSL isn't set up) — pick
one of these:

**Zero-install, use this today:** paste any `exercise.cpp` into
https://godbolt.org or https://www.onlinegdb.com/online_c++_compiler and run it
there in the browser. No setup, works immediately.

**Proper local setup, do this once you're a few lessons in:** install
[MSYS2](https://www.msys2.org/), then from the "MSYS2 UCRT64" terminal it installs
run:

    pacman -S mingw-w64-ucrt-x86_64-gcc

Add `C:\msys64\ucrt64\bin` to your Windows PATH (search "Edit the system
environment variables" → Environment Variables → Path → New), open a *new*
terminal, and from inside a lesson folder:

    g++ -std=c++17 -o exercise exercise.cpp
    ./exercise

**Eventually, for actual FRC work:** install the
[WPILib installer](https://docs.wpilib.org/en/stable/docs/zero-to-robot/step-2/wpilib-setup.html) —
it bundles VS Code, the compiler, and everything needed to build and simulate real
robot code. Don't bother with this until you're comfortable through lesson 8; it's
a much heavier install than the language itself needs.

## Pace

This is dense material, especially lessons 6-8. One lesson every day or two,
actually typing the exercise yourself instead of copy-pasting the solution, is a
realistic pace before tryouts. If pointers (lesson 6) trip you up for a while,
that's completely normal — it trips up everyone coming from a language like
GDScript, Python, or Java, none of which expose raw memory addresses the way C++
does.
