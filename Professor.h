#ifndef PROFESSOR_H
#define PROFESSOR_H
#include <string>
#include <iostream>

//#include "Exam.h"
class Exam;

#include "Person.h"
class Professor : virtual public Person {
private:
    std::string lastName;    // Призвище
    std::string firstName;   // Ім'я
    std::string middleName;  // По батькові
    std::string education;   // Освіта
    std::string department;  
    int experience;           // Досвід (в роках)

public:
    // Конструктор
    Professor() : lastName(""), firstName(""), middleName(""), education(""), experience(0) {};

    Professor(std::string firstName, std::string lastName) : firstName(firstName), lastName(lastName) {
        middleName = "";
        education = " ";
        experience = 0;
    }
    Professor(std::string department, int experience) : department(department), experience(experience) {}

    void showInfo() const override; 

    virtual ~Professor() {
        std::cout << "Professor destructor\n";
    }

    // Методи для встановлення даних
    void setLastName(const std::string& lastName);
    void setFirstName(const std::string& firstName);
    void setMiddleName(const std::string& middleName);
    void setEducation(const std::string& education);
    void setExperience(int experience);

    // Методи для зчитування даних
    std::string getLastName() const;
    std::string getFirstName() const;
    std::string getMiddleName() const;
    std::string getEducation() const;
    int getExperience() const;

    // Метод, який приймає об'єкт Exam за посиланням
    void evaluateExam(Exam& exam); // Логіку реалізуєте самостійно

    void reviewAppeals(Exam& exam);

    void Write(const std::string& filename) const override {

    }

    void Read(const std::string& filename) override {

    }
};

#endif // PROFESSOR_H
