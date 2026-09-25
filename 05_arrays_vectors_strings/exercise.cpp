#include <iostream>
#include <vector>
#include <string>

int main() {
    // TODO 1: Create a std::vector<double> called sensorReadings, empty at first.
    std::vector <double> sensorReadings;
    // TODO 2: push_back these five values onto it, one at a time: 3.2, 3.5,
    //         3.1, 3.6, 3.4
    sensorReadings.push_back(3.2);
    sensorReadings.push_back(3.5);
    sensorReadings.push_back(3.1);
    sensorReadings.push_back(3.6);
    sensorReadings.push_back(3.4);
    // TODO 3: Using a range-based for loop, sum all the readings into a
    //
    double total = 0.0;
    for (double counter : sensorReadings){ 
        total += counter;
    }
    // TODO 4: Compute average = total / sensorReadings.size(), and print
    //         "Average: " followed by average.
    double average = total/sensorReadings.size();
    std::cout<<average<<std::endl;
    std::string teamName = "Team";
    std::string teamNumber = "1234";

    // TODO 5: Build fullName by concatenating teamName + " " + teamNumber,
    //         print fullName and its .length().
    std::string fullName = teamName + " " + teamNumber;
    std::cout<<fullName<<std::endl;
    std::cout<<fullName.length()<<std::endl;
    return 0;
}
