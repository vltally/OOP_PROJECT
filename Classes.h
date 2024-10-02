#include <iostream>
#include <string>
#include <vector>
#include <utility>  // Для std::pair

class Applicant; // Forward declaration

class Exam {
private:
    // Приватні поля
    int maxScore;
    double avgScore;
    int minScore;
    bool isOnline;
    std::vector<std::pair<Applicant, int>> applicants;        // Масив абітурієнтів з оцінками

public:
    std::string subject;
    std::string teacher;
    std::string type;
    // Конструктори
    Exam();
    Exam(std::string subject, int maxScore, bool isOnline);

    // Методи
    void addApplicant(const Applicant& applicant, int score); // Додає абітурієнта та його оцінку
    void setScoreForApplicant(int index, int score);          // Встановлює оцінку абітурієнту
    int getApplicantScore(int index) const;                   // Повертає оцінку абітурієнта
    void showApplicants() const;                              // Виводить список абітурієнтів з оцінками

    // Перевантажені методи
    void reviewExam();                                        // Перегляд іспиту
    void reviewExam(int additionalScore);                     // Перегляд іспиту з можливим підвищенням оцінки
};



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

    // Конструктори
    Applicant();
    Applicant(std::string name, std::string surname, int age, int facultyId);

    // Методи
    void showInfo() const;                            // Виводить інформацію про абітурієнта

    // Методи для роботи з файлами
    void writeToFile(const std::string& filename);    // Запис в файл
    void readFromFile(const std::string& filename);   // Читання з файлу
};

