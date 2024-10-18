#ifndef EXAM_H
#define EXAM_H


#include <iostream>
#include <string>
#include <utility>  
#include <vector>
#include "Mark.h"

class Applicant;

class Exam {
private:
    // Приватні поля
    int maxScore;
    double avg;
    int minScore;
    bool isOnline;
    std::vector<Mark> applicants;        // Масив абітурієнтів з оцінками

public:
    std::string subject;
    std::string teacher;
    std::string type;
    // Конструктори
    Exam();
    Exam(std::string subject);
    Exam(std::string subject, bool isOnline);

    // Методи
   // void addApplicant(const Applicant& applicant, int score); // Додає абітурієнта та його оцінку
    void setScoreForApplicant();          // Встановлює оцінку абітурієнту
    int getApplicantScore(int index) ;                   // Повертає оцінку абітурієнта
    void showApplicants() ;                              // Виводить список абітурієнтів з оцінками
    void showApplicantsGrades() ;
    void addApplicantsExam(std::vector<Mark> applicants);
    std::vector<Mark> returnApplicants();

    double calculateAverageScore();

   
    //void addApplicant(Applicant& applicant, int score);


    // Перевантажені методи
    //void reviewExam();                                        // Перегляд іспиту
    //void reviewExam(int additionalScore);                     // Перегляд іспиту з можливим підвищенням оцінки
};



#endif // EXAM_H

