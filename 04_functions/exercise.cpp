#include <iostream>

// TODO 1: Write a function `clampMotorPower` that takes a double `power` and
//         returns it clamped between -1.0 and 1.0 (return -1.0 if lower,
//         1.0 if higher, otherwise return power unchanged).
double clampMotorPower(double motorPower){
    if (motorPower>1.0){
        return 1.0;
    }else if (motorPower<-1.0){
        return -1.0;
    }else{
        return motorPower;
    }
}

// TODO 2: Write a function `resetEncoder` that takes an int BY REFERENCE
//         (hint: int &count) and sets it to 0.

void resetEncoder(int &count){
         count = 0;
    }
int main() {
    double tooHigh = 1.8;
    double tooLow = -2.5;
    double justRight = 0.4;

    // TODO 3: Print the result of calling clampMotorPower on all three
    //         values above.
    std::cout<<clampMotorPower(tooHigh)<<std::endl;
    std::cout<<clampMotorPower(tooLow)<<std::endl;
    std::cout<<clampMotorPower(justRight)<<std::endl;

    int encoderCount = 42;
    std::cout << "Before reset: " << encoderCount << std::endl;

    // TODO 4: Call resetEncoder on encoderCount, then print it again —
    //         it should now be 0.
   
    resetEncoder(encoderCount);
    std::cout << "After reset: " << encoderCount << std::endl;
    return 0;
}

