#include <iostream>
#include <fstream>
#include <stack>
#include <vector>
#include <string>

// Функция для разделения состава на два стека в зависимости от типа вагонов
void splitTrain(std::vector<int>& train, std::stack<int>& stack1, std::stack<int>& stack2) {
    for (int car : train) {
        if (car % 2 == 0) {
            stack1.push(car);
        }
        else {
            stack2.push(car);
        }
    }
}

// Функция для чтения вагонов из файла
void readFromFile(const std::string& filename, std::vector<int>& train) {
    std::ifstream infile(filename);
    int car;
    while (infile >> car) {
        train.push_back(car);
    }
}

// Функция для чтения вагонов с клавиатуры
void readFromKeyboard(std::vector<int>& train) {
    int n, car;
    std::cout << "Введите количество вагонов: ";
    std::cin >> n;
    for (int i = 0; i < n; ++i) {
        std::cout << "Введите тип вагона (целое число): ";
        std::cin >> car;
        train.push_back(car);
    }
}

// Функция для вывода содержимого стека
void printStack(std::stack<int>& stack) {
    while (!stack.empty()) {
        std::cout << stack.top() << " ";
        stack.pop();
    }
    std::cout << std::endl;
}

int main() {
    std::vector<int> train;
    std::stack<int> stack1;
    std::stack<int> stack2;
    int choice;

    std::cout << "Выберите метод ввода:\n1. С клавиатуры\n2. Из файла\n";
    std::cin >> choice;

    if (choice == 1) {
        readFromKeyboard(train);
    }
    else if (choice == 2) {
        std::string filename;
        std::cout << "Введите имя файла: ";
        std::cin >> filename;
        readFromFile(filename, train);
    }
    else {
        std::cerr << "Неправильный выбор" << std::endl;
        return 1;
    }

    splitTrain(train, stack1, stack2);

    std::cout << "Стек 1 (четные вагоны): ";
    printStack(stack1);
    std::cout << "Стек 2 (нечетные вагоны): ";
    printStack(stack2);

    return 0;
}
