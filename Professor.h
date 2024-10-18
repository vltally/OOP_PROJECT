#ifndef PROFESSOR_H
#define PROFESSOR_H
#include <string>

#include "Exam.h"
class Professor {
private:
    std::string lastName;    // Призвище
    std::string firstName;   // Ім'я
    std::string middleName;  // По батькові
    std::string education;    // Освіта
    int experience;           // Досвід (в роках)

public:
    // Конструктор
    Professor();
    Professor(std::string firstName, std::string lastName) : firstName(firstName), lastName(lastName) {
        middleName = "";
        education = " ";
        experience = 0;
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
};

#endif // PROFESSOR_H
