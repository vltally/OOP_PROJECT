#include "Exam.h"
#include "Applicant.h"
#include <iostream>

Exam::Exam() : subject("Unknown"), maxScore(100), minScore(0), avg(0.0) {}

Exam::Exam(std::string subject) : subject(subject), maxScore(100), minScore(0), avg(0.0) {}

Exam::Exam(std::string subject, int maxScore, int minScore)
    : subject(subject), maxScore(maxScore), minScore(minScore), avg(0.0) {}

void Exam::setScoreForApplicant() {
    for (auto& applicant : applicants) {
        std::cout << "Enter score for " << applicant.getApplicant().getName() << ": ";
        int score;
        std::cin >> score;
        applicant.setMark(score);
    }
}

int Exam::getApplicantScore(int index) {
    return (index >= 0 && index < applicants.size()) ? applicants[index].getMark() : -1;
}

void Exam::showApplicants() {
    for (auto& applicant : applicants) {
        applicant.getApplicant().showInfo();
        std::cout << "Score: " << applicant.getMark() << "\n";
    }
}

void Exam::showApplicantsGrades() {
    for (auto& applicant : applicants) {
        std::cout << applicant.getApplicant().getSurname() << " Score: " << applicant.getMark() << "\n";
    }
}

std::vector<Mark> Exam::returnApplicants() {
    return applicants;
}

void Exam::addApplicantsExam(std::vector<Mark> applicants) {
    this->applicants = applicants;
}

double Exam::calculateAverageScore() {
    if (!applicants.empty()) {
        int totalScore = 0;
        for (auto& applicant : applicants) {
            totalScore += applicant.getMark();
        }
        avg = static_cast<double>(totalScore) / applicants.size();
    }
    else {
        avg = 0;
    }
    return avg;
}

Exam::Exam(std::string subject, std::string teacher, int maxScore, int minScore, double avg)
    : subject(subject), teacher(teacher), maxScore(maxScore), minScore(minScore), avg(avg) {}

