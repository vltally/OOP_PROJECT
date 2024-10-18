// Applicant.cpp
#include <iostream>
#include <fstream>
#include <algorithm> 
#include <vector>
#include "Applicant.h"
#include "Exam.h"
#include "Faculty.h"
#include "Mark.h"

int Applicant::applicantCount = 0;

int Applicant::getApplicantCount() {
    return applicantCount;
}

// Конструктори Applicant
Applicant::Applicant()
    : name("Невідомо"), surname("Невідомо"), gender("Стать"), age(0), facultyId(0),
    contract("Немає"), form("Денна"), group("Немає") {
    applicantCount++;
}

Applicant::Applicant(std::string name, std::string surname, int age, int facultyId,
    std::string gender, std::string contract, std::string form, std::string group)
    : name(name), surname(surname), gender(gender), age(age), facultyId(facultyId),
    contract(contract), form(form), group(group) {
    applicantCount++;
}


Applicant::Applicant(int age, std::string surname) : age(age), surname(surname) {
    applicantCount++;
}

// Методи Applicant
void Applicant::showInfo() const {
    std::cout << "Вступник: " << name << " " << surname << ", Вік: " << age
        << ", Стать: " << gender << ", Факультет ID: " << facultyId
        << ", Контактна інформація: " << contract << ", Форма начання: " << form
        << ", Група: " << group << "\n";
}

std::string Applicant::getName() const {
    return name;
}

std::string Applicant::getSurname() const {
    return surname;
}

void Applicant::writeToFile(const std::string& filename) {
    std::ofstream file(filename);
    if (file.is_open()) {
        file << name << " " << surname << " " << age << " " << gender << " "
            << facultyId << " " << contract << " " << form << " " << group << "\n";
        file.close();
    }
    else {
        std::cerr << "Unable to open file for writing: " << filename << "\n";
    }
}

void Applicant::readFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (file.is_open()) {
        file >> name >> surname >> age >> gender >> facultyId >> contract >> form >> group;
        file.close();
    }
    else {
        std::cerr << "Unable to open file for reading: " << filename << "\n";
    }
}

//void Applicant::applyForExam(Exam& exam) {
//    int score = 0; // Початкова оцінка
//    exam.addApplicant(*this, score);
//}

void Applicant::applyForFaculty(Faculty& faculty) {
    int score = 0;
    bool isAppeal = 0;
    Mark mark(*this, score, isAppeal); // Створюємо об'єкт класу Mark
    faculty.addApplicant(mark); // Передаємо об'єкт Mark у метод addApplicant
}

void Applicant::appealForMark(Exam& exam) {
    std::vector<Mark> marks = exam.returnApplicants();
    bool found = false;

    // Шукаємо оцінку, яка належить цьому студенту
    for (auto& mark : marks) {
        std::string tmpName = mark.getApplicant().getName();
        std::string tmpSurname = mark.getApplicant().getSurname();
        if (tmpName == this->name &&
            tmpSurname == this->surname) {

            // Якщо оцінка знайдена, виставляємо статус апеляції
            std::cout << "Found exam for: " << mark.getApplicant().getName()
                << " " << mark.getApplicant().getSurname()
                << " with score: " << mark.getMark() << "\n";

            mark.setAppealStatus(true);
            
            std::cout << "Appeal has been submitted.\n";
            found = true;
            break;
        }
    }
    
    exam.addApplicantsExam(marks);

    if (!found) {
        std::cout << "No exam found for this applicant.\n";
    }
}

