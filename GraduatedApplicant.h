#ifndef GRADUATED_APPLICANT_H
#define GRADUATED_APPLICANT_H

#include "Applicant.h"
#include <string>

// Public успадкування - всі публічні члени залишаються публічними
class PublicGraduatedApplicant : public Applicant {
private:
    std::string previousEducation;
public:
    PublicGraduatedApplicant(std::string name, std::string surname, int age,
        int facultyId, std::string prevEdu)
        : Applicant(name, surname, age, facultyId) {
        previousEducation = prevEdu;
    }
};

// Protected успадкування - публічні члени стають захищеними
class ProtectedGraduatedApplicant : protected Applicant {
private:
    std::string diplomaType;
public:
    ProtectedGraduatedApplicant(std::string name, std::string surname, int age,
        int facultyId, std::string diploma)
        : Applicant(name, surname, age, facultyId) {
        diplomaType = diploma;
    }

    void showInformation() {
        showInfo();
    }
};

// Private успадкування - публічні члени стають приватними
class PrivateGraduatedApplicant : private Applicant {
private:
    int yearsOfExperience;
public:
    PrivateGraduatedApplicant(std::string name, std::string surname, int age,
        int facultyId, int experience)
        : Applicant(name, surname, age, facultyId) {
        yearsOfExperience = experience;
    }
};



#endif