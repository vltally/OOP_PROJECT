#include "Classes.h"
#include <fstream>

// Конструктори Exam
Exam::Exam() : subject("Unknown"), maxScore(100), isOnline(false) {}

Exam::Exam(std::string subject, int maxScore, bool isOnline)
    : subject(subject), maxScore(maxScore), isOnline(isOnline) {}

// Методи Exam
void Exam::addApplicant(const Applicant& applicant, int score) {
    applicants.push_back(std::make_pair(applicant, score));
}

void Exam::setScoreForApplicant(int index, int score) {
    if (index >= 0 && index < applicants.size()) {
        applicants[index].second = score;  // Оцінка зберігається в парі
    }
}

int Exam::getApplicantScore(int index) const {
    if (index >= 0 && index < applicants.size()) {
        return applicants[index].second;   // Оцінка зберігається в парі
    }
    return -1; // Повертаємо помилкове значення, якщо індекс некоректний
}

void Exam::showApplicants() const {
    for (const auto& applicantPair : applicants) {
        applicantPair.first.showInfo();   // Виводимо інформацію про абітурієнта
        std::cout << "Score: " << applicantPair.second << "\n";  // Виводимо оцінку
    }
}

void Exam::reviewExam() {
    std::cout << "Reviewing exam for subject: " << subject << "\n";
}

void Exam::reviewExam(int additionalScore) {
    for (auto& applicantPair : applicants) {
        applicantPair.second += additionalScore;  // Підвищуємо оцінку
    }
}


// Конструктори Applicant
Applicant::Applicant() : name("Unknown"), surname("Unknown"), age(0), facultyId(0) {}

Applicant::Applicant(std::string name, std::string surname, int age, int facultyId)
    : name(name), surname(surname), age(age), facultyId(facultyId) {}

// Методи Applicant
void Applicant::showInfo() const {
    std::cout << "Applicant: " << name << " " << surname << ", Age: " << age << ", Faculty ID: " << facultyId << "\n";
}

void Applicant::writeToFile(const std::string& filename) {
    std::ofstream file(filename);
    if (file.is_open()) {
        file << name << " " << surname << " " << age << " " << facultyId << "\n";
    }
    file.close();
}

void Applicant::readFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (file.is_open()) {
        file >> name >> surname >> age >> facultyId;
    }
    file.close();
}

