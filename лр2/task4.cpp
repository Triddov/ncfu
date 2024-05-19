#include <iostream>
#include <fstream>

int main() {
    std::ofstream positiveFile("positive.txt");
    std::ofstream negativeFile("negative.txt");

    if (!positiveFile or !negativeFile) {
        std::cerr << "Error create file" << std::endl;
        return 1;
    }

    double number;
    std::cout << "Enter numbers(0 - finish):\n" << std::endl;

    while (true) {
        std::cin >> number;
        if (number == 0) {
            break;
        }

        if (number > 0) {
            positiveFile << number << std::endl;
        }
        else if (number < 0) {
            negativeFile << number << std::endl;
        }
    }

    positiveFile.close();
    negativeFile.close();

    std::cout << "Done" << std::endl;

    return 0;
}
