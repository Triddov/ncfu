#include <iostream>
#include <fstream>
#include <cctype>

int main() {
    std::ifstream inputFile("f.txt");
    if (!inputFile) {
        std::cerr << "Error open f.txt file" << std::endl;
        return 1;
    }

    char ch;
    long long product = 1;
    bool hasNumber = false;

    while (inputFile.get(ch)) {
        if (std::isdigit(static_cast<char>(ch))) {
            product *= (ch - '0');
            hasNumber = true;
        }
    }

    inputFile.close();

    if (hasNumber) {
        std::cout << "Mult numbers - " << product << std::endl;
    }
    else {
        std::cout << "File haven`t numbers" << std::endl;
    }

    return 0;
}
