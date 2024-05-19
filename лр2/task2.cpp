#include <iostream>
#include <fstream>

double sumPositiveNumbers(const std::string& filename) {
    std::ifstream inputFile(filename);
    if (!inputFile) {
        std::cerr << "Error file open" << filename << std::endl;
        return 1;
    }

    double number;
    double positiveSum = 0.0;

    while (inputFile >> number) {
        if (number > 0) {
            positiveSum += number;
        }
    }

    inputFile.close();
    return positiveSum;
}

int main() {
    std::string file1 = "a1.txt";
    std::string file2 = "a2.txt";

    double sum1 = sumPositiveNumbers(file1);
    double sum2 = sumPositiveNumbers(file2);

    double totalSum = sum1 + sum2;

    std::cout << "Sum positive numbers of both files :" << totalSum << std::endl;

    return 0;
}
