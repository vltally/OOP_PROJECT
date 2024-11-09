#include <string>
#include "Person.h"
#include "Applicant.h"
#include "Professor.h"
#include "Exam.h"
#include "Faculty.h"


class Admin : public Person {
private:
    std::string username;
    std::string password;

public:
    // Конструктори
    Admin();
    Admin(const std::string& username, const std::string& password);

    // Віртуальна функція для виводу інформації
    void showInfo() const override;

    // Методи для керування обліковим записом
    void setUsername(const std::string& username);
    void setPassword(const std::string& password);
    std::string getUsername() const;
    std::string getPassword() const;

    // Методи для управління системою
    void addApplicant(Applicant& applicant);    // Додати абітурієнта до системи
    void removeApplicant(Applicant& applicant); // Видалити абітурієнта із системи

    void addProfessor(Professor& professor);    // Додати викладача до системи
    void removeProfessor(Professor& professor); // Видалити викладача із системи

    void createExam(Exam& exam);     // Створити іспит
    void deleteExam(Exam& exam);     // Видалити іспит

    void manageFaculty(Faculty& faculty); // Керувати факультетами

    void Write(const std::string& filename) const override {
        
    }

    void Read(const std::string& filename) override {
       
    }
    // Запис/читання даних з файлів
    //void writeToFile(const std::string& filename); // Запис даних адміністратора в файл
    //void readFromFile(const std::string& filename); // Читання даних адміністратора з файлу


};