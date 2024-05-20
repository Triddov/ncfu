#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstring>  // Для strncpy_s

// Определение структуры данных MyData
struct MyData {
    int id;
    float value;
    char name[20];

    MyData(int i = 0, float v = 0.0, const char* n = "") : id(i), value(v) {
        strncpy_s(name, n, sizeof(name) - 1);
        name[sizeof(name) - 1] = '\0'; // Безопасное завершение строки
    }
};

// Класс CFile, инкапсулирующий основные операции с файлами
class CFile {
protected:
    std::fstream file;

public:
    bool Open(const std::string& filename, std::ios::openmode mode) {
        file.open(filename, mode);
        return file.is_open();
    }

    void Close() {
        if (file.is_open()) {
            file.close();
        }
    }

    void Seek(std::streampos position) {
        if (file.is_open()) {
            file.seekg(position);
            file.seekp(position);
        }
    }

    std::streampos GetPosition() {
        if (file.is_open()) {
            return file.tellg();
        }
        return -1;
    }

    std::streampos GetLength() {
        if (file.is_open()) {
            std::streampos current_pos = file.tellg();
            file.seekg(0, std::ios::end);
            std::streampos length = file.tellg();
            file.seekg(current_pos);
            return length;
        }
        return -1;
    }

    bool Read(char* buffer, std::streamsize size) {
        if (file.is_open()) {
            file.read(buffer, size);
            return file.good();
        }
        return false;
    }

    bool Write(const char* buffer, std::streamsize size) {
        if (file.is_open()) {
            file.write(buffer, size);
            return file.good();
        }
        return false;
    }
};

// Производный класс CMyDataFile
class CMyDataFile : public CFile {
public:
    bool WriteHeader(const std::string& header) {
        if (file.is_open()) {
            file.seekp(0, std::ios::beg);
            file.write(header.c_str(), header.size());
            return file.good();
        }
        return false;
    }

    bool ReadHeader(std::string& header, std::streamsize size) {
        if (file.is_open()) {
            header.resize(size);
            file.seekg(0, std::ios::beg);
            file.read(&header[0], size);
            return file.good();
        }
        return false;
    }

    bool WriteData(const MyData& data) {
        if (file.is_open()) {
            file.write(reinterpret_cast<const char*>(&data), sizeof(MyData));
            return file.good();
        }
        return false;
    }

    bool ReadData(MyData& data) {
        if (file.is_open()) {
            file.read(reinterpret_cast<char*>(&data), sizeof(MyData));
            return file.good();
        }
        return false;
    }
};

int main() {
    CMyDataFile myFile;
    std::string filename = "datafile.txt";

    // Открытие файла для записи
    if (myFile.Open(filename, std::ios::out | std::ios::binary)) {
        std::string header = "MyDataFileHeader";
        myFile.WriteHeader(header);

        MyData data(1, 23.5, "Example");
        myFile.WriteData(data);
        myFile.Close();
    }

    // Открытие файла для чтения
    if (myFile.Open(filename, std::ios::in | std::ios::binary)) {
        std::string header;
        myFile.ReadHeader(header, 15);  // Считываем заголовок размером 15 байт
        std::cout << "Header: " << header << std::endl;

        MyData data;
        myFile.ReadData(data);
        std::cout << "Data - ID: " << data.id << ", Value: " << data.value << ", Name: " << data.name << std::endl;
        myFile.Close();
    }

    return 0;
}
