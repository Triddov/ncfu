#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>

// Шаблонный класс A, использующий std::vector в качестве серверного класса
template <typename T>
class A {
private:
    std::vector<T> data;

public:
    // Добавление элемента
    void Add(const T& value) {
        data.push_back(value);
    }

    // Получение элемента по индексу с проверкой границ
    T Get(size_t index) const {
        if (index >= data.size()) {
            throw std::out_of_range("Index out of range");
        }
        return data[index];
    }

    // Получение размера вектора
    size_t Size() const {
        return data.size();
    }

    // Удаление элемента по индексу с проверкой границ
    void Remove(size_t index) {
        if (index >= data.size()) {
            throw std::out_of_range("Index out of range");
        }
        data.erase(data.begin() + index);
    }
};

// Тестирование шаблонного класса A в функции main
int main() {
    try {
        // Создание объектов класса A для разных типов
        A<int> intContainer;
        A<double> doubleContainer;
        A<std::string> stringContainer;

        // Добавление элементов
        intContainer.Add(1);
        intContainer.Add(2);
        intContainer.Add(3);

        doubleContainer.Add(1.1);
        doubleContainer.Add(2.2);
        doubleContainer.Add(3.3);

        stringContainer.Add("Hello");
        stringContainer.Add("World");
        stringContainer.Add("!");

        // Получение элементов и вывод
        std::cout << "Int container elements:" << std::endl;
        for (size_t i = 0; i < intContainer.Size(); ++i) {
            std::cout << intContainer.Get(i) << std::endl;
        }

        std::cout << "Double container elements:" << std::endl;
        for (size_t i = 0; i < doubleContainer.Size(); ++i) {
            std::cout << doubleContainer.Get(i) << std::endl;
        }

        std::cout << "String container elements:" << std::endl;
        for (size_t i = 0; i < stringContainer.Size(); ++i) {
            std::cout << stringContainer.Get(i) << std::endl;
        }

        // Попытка получения элемента с неверным индексом
        std::cout << "Attempting to get element at invalid index:" << std::endl;
        std::cout << intContainer.Get(10) << std::endl;  // Это вызовет исключение

    }
    catch (const std::out_of_range& e) {
        std::cerr << "Caught an out_of_range exception: " << e.what() << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "Caught an exception: " << e.what() << std::endl;
    }

    return 0;
}
