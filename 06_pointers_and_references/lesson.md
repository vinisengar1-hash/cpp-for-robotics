# Lesson 6: Pointers & References

Budget extra time for this one. It's the single biggest thing GDScript (and
Python, and Java) hide from you completely, and it trips up everyone at
first. Take it slow.

## What a pointer actually is

Every variable lives somewhere in your computer's memory, at some address.
A **pointer** is just a variable whose value *is* that address — it "points
to" where another variable lives, instead of holding a value directly.

```cpp
int encoderCount = 42;
int* countPointer = &encoderCount; // & here means "address of"
```

- `int*` — "a pointer to an int" (the type of the variable itself)
- `&encoderCount` — "the memory address of encoderCount"

**Important disambiguation:** you saw `&` in lesson 4 too (`int &count` in a
function parameter), meaning "reference." This is a *different* use of the
same symbol:
- `&` **in front of a type** (`int &count`) → "this is a reference"
- `&` **in front of a variable, used as a value** (`&encoderCount`) → "give me
  the address of this variable"

C++ reuses `&` for two related-but-different jobs. It's confusing at first;
everyone has to just memorize which is which by context.

## Dereferencing with `*`

```cpp
int encoderCount = 42;
int* countPointer = &encoderCount;

std::cout << countPointer << std::endl;   // prints a memory address (garbage-looking hex number)
std::cout << *countPointer << std::endl;  // prints 42 — the VALUE stored at that address

*countPointer = 100; // changes encoderCount itself, through the pointer!
std::cout << encoderCount << std::endl;   // prints 100
```

`*` in front of a pointer variable means "go to the address this pointer
holds, and give/set the value that's actually there." This is called
**dereferencing**.

(Yes, `*` also has this "different meaning depending on where it appears"
problem too: `int* p` declares a pointer, `*p` dereferences one. Same symbol,
context tells you which.)

## Pointers as function parameters

```cpp
void doublePointer(double* value) {
    *value = *value * 2.0;
}

int main() {
    double motorPower = 0.3;
    doublePointer(&motorPower);
    std::cout << motorPower << std::endl; // 0.6
}
```

This does the *same job* as a reference parameter from lesson 4
(`resetEncoder(int &count)`) — letting a function modify the caller's
variable. The difference: a reference (`&count`) must always point to
something real and can never be reassigned to point elsewhere. A pointer can
be `nullptr` (points to nothing) and can be reassigned to point at different
things over its lifetime.

## nullptr — a pointer that points to nothing

```cpp
int* maybeCount = nullptr;

if (maybeCount != nullptr) {
    std::cout << *maybeCount << std::endl;
} else {
    std::cout << "no value yet" << std::endl;
}
```

**Always check for `nullptr` before dereferencing a pointer that might be
empty.** Dereferencing a null pointer (`*maybeCount` when it's `nullptr`) is
one of the most common ways to crash a C++ program.

## Why robotics code uses pointers at all

A motor controller, or a sensor, represents one real, physical object
plugged into the robot — it doesn't make sense to "copy" it the way you'd
copy an `int`. Real WPILib code usually holds these through **smart
pointers** — `std::unique_ptr<Motor>` — a wrapper around a raw pointer that
automatically cleans up the object when it's no longer needed, so you get
the "points to one real thing" behavior of a pointer without manually
managing memory yourself (no manual `new`/`delete`, which is the old, more
error-prone C++ style). You don't need to master smart pointers today — just
recognize the shape when you see `std::unique_ptr<SomeType>` in real code: it
behaves like a pointer (`->` to access members, can be checked against
`nullptr`), and owns/manages one specific object.

## Your exercise

Open `exercise.cpp` and follow the `// TODO` comments.
