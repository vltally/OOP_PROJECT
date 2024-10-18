// Applicant.h
#ifndef APPLICANT_H
#define APPLICANT_H

//#include "Exam.h"
#include <string>

class Applicant;
class Faculty;
class Exam;

class Applicant {
private:
    std::string name;          // Приватні поля
    std::string surname;
    std::string gender;
    int age;
    int facultyId;

public:
    std::string contract;
    std::string form;
    std::string group;

    static int applicantCount;

    static int getApplicantCount();


    // Конструктори
    //Applicant() = default;
    Applicant();
    Applicant(std::string name, std::string surname, int age, int facultyId,
        std::string gender = "Не вказано", std::string contract = "Не визначений",
        std::string form = "Денна", std::string group = "Невідомо");
    explicit Applicant(int age, std::string surname);
    


    // Методи
    void showInfo() const;                            // Виводить інформацію про абітурієнта

    // Методи для роботи з файлами
    void writeToFile(const std::string& filename);    // Запис в файл
    void readFromFile(const std::string& filename);   // Читання з файлу

    friend void checkEligibility(const Applicant&);
    friend void checkEligibility(const Applicant*);

    void applyForFaculty(Faculty& faculty);

    std::string getName() const;
    std::string getSurname() const;

    void appealForMark(Exam& exam);
    
    
};

#endif // APPLICANT_H
