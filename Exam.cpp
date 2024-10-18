#include <vector>
#include "Exam.h"
#include "Applicant.h"
#include <fstream>
#include <utility>
#include <algorithm>

// Конструктори Exam
Exam::Exam() : subject("Unknown"), maxScore(100), isOnline(false) {}

Exam::Exam(std::string subject)
    : subject(subject) {}

Exam::Exam(std::string subject, bool isOnline): subject(subject), isOnline(isOnline) {}

// Методи Exam
//void Exam::addApplicant(const Applicant& applicant, int score) {
//    applicants.push_back(std::make_pair(applicant, score));
//}

void Exam::setScoreForApplicant() {
    // Перебираємо кожного абітурієнта
    for (auto& applicant : applicants) {
        Applicant currentApplicant = applicant.getApplicant(); // Отримуємо абітурієнта
        std::cout << "Прізвище: " << currentApplicant.getSurname() << ", Ім'я: " << currentApplicant.getName() << "\n";

        int score;
        std::cout << "Введіть оцінку для " << currentApplicant.getName() << " " << currentApplicant.getSurname() << ": ";
        std::cin >> score; // Запитуємо оцінку у користувача

        applicant.setMark(score);

    }
}



int Exam::getApplicantScore(int index)  {
    if (index >= 0 && index < applicants.size()) {
        return applicants[index].getMark();   // Оцінка зберігається в парі
    }
    return -1; // Повертаємо помилкове значення, якщо індекс некоректний
}

void Exam::showApplicants() {
    for (auto& applicant : applicants) {
        applicant.getApplicant().showInfo();   // Виводимо інформацію про абітурієнта
        std::cout << "Score: " << applicant.getMark()<< "\n";  // Виводимо оцінку
    }
}

void Exam::showApplicantsGrades() {
    for (auto& applicantPair : applicants) {
         // Виводимо інформацію про абітурієнта
        std::cout << applicantPair.getApplicant().getSurname() << " " << "Score: " << applicantPair.getMark() << "\n";  // Виводимо оцінку
    }
}

std::vector<Mark> Exam::returnApplicants(){
    return applicants;
}

void Exam::addApplicantsExam(std::vector<Mark> applicants) {
    this->applicants = applicants;
}

double Exam::calculateAverageScore() {
    if (!applicants.empty()) {
        // Повертаємо 0, якщо немає абітурієнтів


        int totalScore = 0;
        for (auto& applicant : applicants) {
            totalScore += applicant.getMark(); // Додаємо оцінку до загальної суми
        }

        avg = static_cast<float>(totalScore) / applicants.size(); // Обчислюємо середнє
    }
    else avg = 0;

    return avg;
}




//void Exam::addApplicant(Applicant& applicant, int score) {
//    applicants.emplace_back(applicant, score);
//    std::sort(applicants.begin(), applicants.end(),
//        [](const std::pair<Applicant, int>& a, const std::pair<Applicant, int>& b) {
//            return a.first.getSurname() < b.first.getSurname();
//        });
//}

//void Exam::reviewExam() {
//    std::cout << "Reviewing exam for subject: " << subject << "\n";
//}
//
//void Exam::reviewExam(int additionalScore) {
//    for (auto& applicantPair : applicants) {
//        applicantPair.second += additionalScore;  // Підвищуємо оцінку
//    }
//}


