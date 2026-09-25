#include <iostream>
#include <vector>
#include <string>

int main() {
    std::vector<double> sensorReadings;
    sensorReadings.push_back(3.2);
    sensorReadings.push_back(3.5);
    sensorReadings.push_back(3.1);
    sensorReadings.push_back(3.6);
    sensorReadings.push_back(3.4);

    double total = 0.0;
    for (double reading : sensorReadings) {
        total += reading;
    }
    double average = total / sensorReadings.size();
    std::cout << "Average: " << average << std::endl;

    std::string teamName = "Team";
    std::string teamNumber = "1234";
    std::string fullName = teamName + " " + teamNumber;
    std::cout << fullName << " has length " << fullName.length() << std::endl;

    return 0;
}
