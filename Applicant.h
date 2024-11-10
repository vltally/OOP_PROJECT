// Applicant.h
#ifndef APPLICANT_H
#define APPLICANT_H

#include <string>
#include "Person.h"
#include <iostream>
#include <fstream>
#include <vector>


class Faculty;
class Exam;

class Applicant : virtual public Person {
private:
    std::string name;          // Приватні поля
    std::string surname;
    std::string gender;
    int age;
    int facultyId;
    static std::vector<Applicant*> applicants;  // Статичний контейнер для збереження об'єктів
protected:
    std::string contract;
    std::string form;
public:
    std::string group;

    static int applicantCount;

    static int getApplicantCount();

    virtual ~Applicant() {
        std::cout << "Applicant destructor\n";
        auto it = std::find(applicants.begin(), applicants.end(), this);
        if (it != applicants.end()) {
            applicants.erase(it);
        }
    }

    // Конструктори
    //Applicant() = default;
    Applicant() : Person(), name("Name"), surname("Surname"), age(12), facultyId(3) {
        applicants.push_back(this);  // Додаємо вказівник на новий об'єкт у контейнер
    };
    Applicant(std::string name, std::string surname, int age, int facultyId,
        std::string gender = "Не вказано", std::string contract = "Не визначений",
        std::string form = "Денна", std::string group = "Невідомо");
    explicit Applicant(int age, std::string surname);
    Applicant(std::string name , int age )
        : name(name), age(age) {
        applicants.push_back(this);
    }


    // Методи
    void showInfo() const override;                            // Виводить інформацію про абітурієнта

    // Методи для роботи з файлами
    void writeToFile(const std::string& filename);    // Запис в файл
    void readFromFile(const std::string& filename);   // Читання з файлу

    friend void checkEligibility(const Applicant&);
    friend void checkEligibility(const Applicant*);

    void applyForFaculty(Faculty& faculty);

    std::string getName() const;
    std::string getSurname() const;

    int getAge() const {
        return age;
    }
    void appealForMark(Exam& exam);
    
    void Write(const std::string& filename) const override {
        try {
            std::ofstream outFile(filename, std::ios::binary | std::ios::app);
            if (!outFile) {
                throw std::ios_base::failure("Error opening file for writing.");
            }

            // Записуємо розмір і сам рядок імені
            size_t nameSize = name.size();
            outFile.write(reinterpret_cast<const char*>(&nameSize), sizeof(nameSize));
            outFile.write(name.c_str(), nameSize);

            // Записуємо вік
            outFile.write(reinterpret_cast<const char*>(&age), sizeof(age));

            outFile.close();
        }
        catch (const std::ios_base::failure& e) {
            std::cerr << "File Write Error: " << e.what() << std::endl;
            throw;
        }
    }

    void Read(const std::string& filename) override {
        try {
            std::ifstream inFile(filename, std::ios::binary);
            if (!inFile) {
                throw std::ios_base::failure("Error opening file for reading.");
            }

            // Зчитуємо розмір і сам рядок імені
            size_t nameSize;
            inFile.read(reinterpret_cast<char*>(&nameSize), sizeof(nameSize));

            char* nameBuffer = new char[nameSize + 1];
            inFile.read(nameBuffer, nameSize);
            nameBuffer[nameSize] = '\0';
            name = nameBuffer;
            delete[] nameBuffer;

            // Зчитуємо вік
            inFile.read(reinterpret_cast<char*>(&age), sizeof(age));

            inFile.close();
        }
        catch (const std::ios_base::failure& e) {
            std::cerr << "File Read Error: " << e.what() << std::endl;
            throw;
        }
        catch (const std::bad_alloc& e) {
            std::cerr << "Memory Allocation Failure in Read: " << e.what() << std::endl;
            throw;
        }
    }

    static void viewAllApplicants() {
        std::cout << "List of all applicants:" << std::endl;
        for (const auto& applicant : applicants) {
            applicant->showInfo();
        }
    }

    Applicant(int age) : age(age) {}

    // Префіксне перевантаження оператора ++
    Applicant& operator++() {
        ++age;
        return *this;
    }

    // Постфіксне перевантаження оператора ++
    Applicant operator++(int) {
        Applicant temp = *this;
        ++(*this);  // Викликаємо префіксну версію
        return temp;
    }

    // Префіксне перевантаження оператора --
    Applicant& operator--() {
        --age;
        return *this;
    }

    // Постфіксне перевантаження оператора --
    Applicant operator--(int) {
        Applicant temp = *this;
        --(*this);  // Викликаємо префіксну версію
        return temp;
    }

    Applicant operator+(const Applicant& other) {
        return Applicant(this->age + other.age);
    }

    // Перевантаження оператора -
    Applicant operator-(const Applicant& other) {
        return Applicant(this->age - other.age);
    }
    
    int operator*(const Applicant& other) {
        return this->age * other.age;
    }

    // Перевантаження оператора =
    Applicant& operator=(const Applicant& other) {
        if (this != &other) {
            age = other.age;
        }
        return *this;
    }

    // Перевантаження оператора +=
    Applicant& operator+=(const Applicant& other) {
        this->age += other.age;
        return *this;
    }

    // Перевантаження оператора -=
    Applicant& operator-=(const Applicant& other) {
        this->age -= other.age;
        return *this;
    }

    // Перевантаження оператора *=
    Applicant& operator*=(const Applicant& other) {
        this->age *= other.age;
        return *this;
    }

    // Перевантаження оператора []
    int operator[](int index) {
        if (index == 0) return age;
        return -1;  // Для простоти
    }

    template <typename T> void setAge(T newAge) {
        age = static_cast<int>(newAge);
    }
};

#endif // APPLICANT_H
