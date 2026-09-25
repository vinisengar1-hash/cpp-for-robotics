#include <iostream>

// TODO 1: Write a function `doubleValue` that takes a `double*` parameter
//         named `value`, and sets the number it points to to twice itself.
//         (hint: *value = *value * 2.0;)


int main() {
    int encoderCount = 42;

    // TODO 2: Declare a pointer `int* countPointer` that points to encoderCount.

    // TODO 3: Print *countPointer (should print 42).

    // TODO 4: Through the pointer, set encoderCount's value to 100
    //         (hint: *countPointer = 100;), then print encoderCount directly
    //         to confirm it changed.

    double motorPower = 0.3;

    // TODO 5: Call doubleValue on motorPower (remember: you need to pass
    //         &motorPower, since the function wants an address).

    // TODO 6: Print motorPower — it should now be 0.6.

    int* maybeCount = nullptr;

    // TODO 7: Write an if/else that checks whether maybeCount is nullptr:
    //         if it's null, print "no value yet"; otherwise print *maybeCount.

    return 0;
}
