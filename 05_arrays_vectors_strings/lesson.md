# Lesson 5: Arrays, std::vector & std::string

## C-style arrays (know they exist, mostly avoid them)

```cpp
double motorPowers[4] = {0.5, -0.3, 0.8, 0.0};
std::cout << motorPowers[0] << std::endl; // 0.5, indexing starts at 0
```

Fixed size, decided at compile time, and C++ does **not** stop you from reading
or writing past the end (`motorPowers[10]` compiles fine and corrupts memory
instead of erroring). This is a real, famous source of bugs. Good news: modern
C++ gives you a much safer alternative for almost everything.

## std::vector — the one you'll actually use

```cpp
#include <vector>

std::vector<double> sensorReadings; // starts empty
sensorReadings.push_back(3.2);
sensorReadings.push_back(3.5);
sensorReadings.push_back(3.1);

std::cout << "Count: " << sensorReadings.size() << std::endl; // 3
std::cout << "First: " << sensorReadings[0] << std::endl;     // 3.2
```

`std::vector<double>` is a list of `double`s that can grow (`push_back` adds
one to the end) and knows its own length (`.size()`). This is the workhorse
container in real C++ robot code — anywhere you'd reach for an array in
GDScript, reach for `std::vector` in C++.

## Range-based for loop

```cpp
double total = 0.0;
for (double reading : sensorReadings) {
    total += reading; // shorthand for total = total + reading;
}
double average = total / sensorReadings.size();
```

Read `for (double reading : sensorReadings)` as "for each `double` in
`sensorReadings`, call it `reading`, and run this block." Much closer to
GDScript's `for x in list:` than the counting `for (int i = 0; ...)` from
lesson 3 — use this style whenever you don't actually need the index number.

## std::string

```cpp
#include <string>

std::string teamName = "Team";
std::string teamNumber = "1234";
std::string fullName = teamName + " " + teamNumber; // "Team 1234"
std::cout << fullName.length() << std::endl; // 9
```

`+` concatenates strings, `.length()` gives the character count. Strings are
just another container really — you can even index into one with `[]` to get
a single `char`.

## Your exercise

Open `exercise.cpp` and follow the `// TODO` comments.
