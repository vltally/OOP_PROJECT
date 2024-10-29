#ifndef EXAM_H
#define EXAM_H

#include <iostream>
#include <string>
#include <vector>
#include "Mark.h"

class Applicant;

class Exam {
protected:
    int maxScore;
    double avg;
    int minScore;
    std::vector<Mark> applicants; // Масив абітурієнтів з оцінками

public:
    std::string subject;
    std::string teacher;

    // Конструктори
    Exam();
    Exam(std::string subject);
    Exam(std::string subject, int maxScore, int minScore);

    Exam(std::string subject, std::string teacher, int maxScore, int minScore, double avg);
    // Методи
    void setScoreForApplicant();           // Встановлює оцінку абітурієнту
    int getApplicantScore(int index);      // Повертає оцінку абітурієнта
    void showApplicants();                 // Виводить список абітурієнтів з оцінками
    void showApplicantsGrades();
    void addApplicantsExam(std::vector<Mark> applicants);
    std::vector<Mark> returnApplicants();

    double calculateAverageScore();


};

#endif // EXAM_H
