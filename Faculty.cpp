// Faculty.cpp
#include "Faculty.h"
#include "Mark.h"
#include <vector>
#include <iostream>
#include <utility>
#include <algorithm>
#include "Applicant.h"



void Faculty::addApplicant(Mark applicant) {
    applicants.push_back(applicant);

    // Сортуємо за прізвищем абітурієнта
    std::sort(applicants.begin(), applicants.end(),
        [](Mark a, Mark b) {
            // Використання метода getApplicant() та getSurname() для порівняння
            return a.getApplicant().getSurname() < b.getApplicant().getSurname();
        });
}


// Конструктор копіювання
//Faculty::Faculty(const Faculty& other)
//    : name(other.name), id(other.id) {
//    std::cout << "Викликаний конструктор копіювання\n";
//}

Faculty::~Faculty(void) {
    std::cout << "Викликаний деструктор\n";
}

// Методи для встановлення значень
void Faculty::setName(const std::string& facultyName) {
    name = facultyName;
}

void Faculty::setAvg(const float avg) {
    this->avg = avg;
}




float Faculty::getAvg(){
    return avg;
}
void Faculty::setId(int facultyId) {
    id = facultyId;
}

// Методи для зчитування значень
std::string Faculty::getName() const {
    return name;
}

int Faculty::getId() const {
    return id;
}

int Faculty::getQuota(){
    return quota;
}







void Faculty::filterApplicants() {
    applicantPass.clear();
    for (const auto& applicant : applicants) {
        if (applicant.getMark() > avg) {
            applicantPass.push_back(applicant);
        }
    }
    std::sort(applicantPass.begin(), applicantPass.end(),
        [](Mark a,Mark b) {
            return a.getMark() > b.getMark();
        });
    if (applicantPass.size() > quota) {
        applicantPass.resize(quota);
    } 
}


void Faculty::showApplicantsPass() const {
    for (const auto& applicant : applicantPass) {
        std::cout << applicant.getApplicant().getSurname() << " Score: " << applicant.getMark() << "\n";
    }
}

void Faculty::addApplicantsFaculty(std::vector<Mark> applicants){
    this->applicants = applicants;
}