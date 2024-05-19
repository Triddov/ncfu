#include <iostream>
#include <fstream>
#include <cctype>

int main() {
    std::ifstream inputFile("input.txt");
    if (!inputFile) {
        std::cerr << "Error open input.txt file" << std::endl;
        return 1;
    }

    std::ofstream outputFile("output.txt");
    if (!outputFile) {
        std::cerr << "Error create output.txt file" << std::endl;
        inputFile.close();
        return 1;
    }

    char letter;
    while (inputFile.get(letter)) {
        outputFile.put(std::toupper(static_cast<unsigned char>(letter)));
    }

    inputFile.close();
    outputFile.close();

    std::cout << "All letters have been replaced in output.txt file" << std::endl;

    return 0;
}