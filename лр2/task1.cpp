#include <iostream>
#include <fstream>

int main() {
    std::ifstream inputFile("a.txt");
    if (!inputFile) {
        std::cerr << "Open error a.txt file" << std::endl;
        return 1;
    }

    double number;
    int positiveCount = 0;
    int negativeCount = 0;

    while (inputFile >> number) {
        if (number > 0) {
            positiveCount++;
        }
        else if (number < 0) {
            negativeCount++;
        }
    }

    inputFile.close();

    std::cout << "quantity positive numbers: " << positiveCount << std::endl;
    std::cout << "quantity negative numbers: " << negativeCount << std::endl;

    return 0;
}