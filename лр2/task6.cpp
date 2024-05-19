#include <iostream>
#include <fstream>
#include <vector>

struct Student {
    char surname[50];
    char initials[5];
    int groupNumber;
    int grades[3];
    double scholarship;
};

void writeStudentsToFile(const std::string& filename, const std::vector<Student>& students) {
    std::ofstream outFile(filename, std::ios::binary);
    if (!outFile) {
        std::cerr << "Ошибка открытия файла для записи." << std::endl;
        return;
    }

    for (const auto& student : students) {
        outFile.write(reinterpret_cast<const char*>(&student), sizeof(Student));
    }

    outFile.close();
}

std::vector<Student> readStudentsFromFile(const std::string& filename) {
    std::vector<Student> students;
    std::ifstream inFile(filename, std::ios::binary);
    if (!inFile) {
        std::cerr << "Ошибка открытия файла для чтения." << std::endl;
        return students;
    }

    Student student;
    while (inFile.read(reinterpret_cast<char*>(&student), sizeof(Student))) {
        students.push_back(student);
    }

    inFile.close();
    return students;
}

void printStudent(const Student& student) {
    std::cout << "surname: " << student.surname << std::endl;
    std::cout << "initials: " << student.initials << std::endl;
    std::cout << "number of group: " << student.groupNumber << std::endl;
    std::cout << "grades: " << student.grades[0] << ", " << student.grades[1] << ", " << student.grades[2] << std::endl;
    std::cout << "scholarship: " << student.scholarship << std::endl;
    std::cout << "----------------------------------------" << std::endl;
}

void printStudentsWithPositiveGrades(const std::vector<Student>& students) {
    for (const auto& student : students) {
        bool allPositive = true;
        for (int grade : student.grades) {
            if (grade <= 0) {
                allPositive = false;
                break;
            }
        }

        if (allPositive) {
            printStudent(student);
        }
    }
}

int main() {
    // Пример данных студентов
    std::vector<Student> students = {
        {"Ivanov", "I.I.", 101, {85, 90, 78}, 5000.0},
        {"Petrov", "P.P.", 102, {60, 70, 80}, 4500.0},
        {"Sidorov", "S.S.", 103, {0, 95, 85}, 4700.0},
        {"Kuznetsov", "K.K.", 104, {90, 95, 100}, 5200.0}
    };

    std::string filename = "students.bin";

    // Запись данных студентов в бинарный файл
    writeStudentsToFile(filename, students);

    // Чтение данных студентов из бинарного файла
    std::vector<Student> readStudents = readStudentsFromFile(filename);

    // Вывод студентов с положительными оценками по всем предметам
    std::cout << "Students with additional benefits in all subjects : " << std::endl;
    printStudentsWithPositiveGrades(readStudents);

    return 0;
}
