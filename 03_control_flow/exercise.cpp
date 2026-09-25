#include <iostream>

int main() {
    double batteryVoltage = 11.2;

    // TODO 1: Write an if/else-if/else chain:
    //   - if batteryVoltage < 11.0, print "CRITICAL: brownout risk!"
    //   - else if batteryVoltage < 12.0, print "WARNING: battery low."
    //   - else print "Battery OK."
    if (batteryVoltage<11.0) {
        std::cout<<"CRITICAL: brownout risk!"<<std::endl;
    }else if (batteryVoltage<12.0){
        std::cout<<"WARNING: battery low."<<std::endl;
    }else{
        std::cout<<"Battery OK."<<std::endl;
    }
    // TODO 2: Write a for loop from 1 to 10 (inclusive) that:
    //   - skips printing when i == 5 (use continue)
    //   - stops the loop entirely when i == 8 (use break)
    //   - otherwise prints "Test cycle " followed by i
    for (int i = 1;i<11;i++){
        if (i == 5){
            continue;
        }
        if (i==8){
            break;
        }
        std::cout<< "Test cycle "<<i<<std::endl;
    }
    return 0;
}
