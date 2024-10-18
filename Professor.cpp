#include "Professor.h"
#include "Exam.h"
#include "Applicant.h"

// Конструктор
Professor::Professor() : lastName(""), firstName(""), middleName(""), education(""), experience(0) {}

// Методи для встановлення даних
void Professor::setLastName(const std::string& lastName) { this->lastName = lastName; }
void Professor::setFirstName(const std::string& firstName) { this->firstName = firstName; }
void Professor::setMiddleName(const std::string& middleName) { this->middleName = middleName; }
void Professor::setEducation(const std::string& education) { this->education = education; }
void Professor::setExperience(int experience) { this->experience = experience; }

// Методи для зчитування даних
std::string Professor::getLastName() const { return lastName; }
std::string Professor::getFirstName() const { return firstName; }
std::string Professor::getMiddleName() const { return middleName; }
std::string Professor::getEducation() const { return education; }
int Professor::getExperience() const { return experience; }




void Professor::evaluateExam(Exam& exam) {
    exam.setScoreForApplicant();
}

void Professor::reviewAppeals(Exam& exam) {

    std::vector<Mark>& marks = exam.returnApplicants();
    std::cout << "Marks with appeals:\n";
    for (Mark& mark : marks) {
        if (mark.getAppealStatus()) { // Якщо isAppealed == 1
            // Виведення інформації про студента, який подав апеляцію
            std::cout << "Applicant: " << mark.getApplicant().getName() << " "
                << mark.getApplicant().getSurname() << "\n";
            std::cout << "Current score: " << mark.getMark() << "\n";

            // Питання про нову оцінку
            int newScore;
            std::cout << "Введіть нову оцінку (-1 щоб залишити стару): ";
            std::cin >> newScore;

            // Якщо нова оцінка не -1, оновлюємо бал
            if (newScore != -1) {
                mark.setMark(newScore); // Оновлення оцінки
                std::cout << "Оцінка оновлена" << newScore << "\n";
            }
            else {
                std::cout << "Оцінка залишається старою.\n";
            }

            // Очищаємо апеляцію після перегляду
            mark.setAppealStatus(false);
        }
    }

    exam.addApplicantsExam(marks);
}
