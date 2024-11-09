#include "Admin.h"
#include <iostream>
#include <fstream>

// Ініціалізація конструктора за замовчуванням
Admin::Admin() : username("admin"), password("password") {}

// Ініціалізація конструктора з параметрами
Admin::Admin(const std::string& username, const std::string& password)
    : username(username), password(password) {}

// Метод для виводу інформації про адміністратора
void Admin::showInfo() const {
    std::cout << "Admin Username: " << username << "\n";
}

// Методи для керування обліковим записом
void Admin::setUsername(const std::string& username) {
    this->username = username;
}

void Admin::setPassword(const std::string& password) {
    this->password = password;
}

std::string Admin::getUsername() const {
    return username;
}

std::string Admin::getPassword() const {
    return password;
}

// Додавання абітурієнта
void Admin::addApplicant(Applicant& applicant) {
    // Логіка додавання абітурієнта до системи
    std::cout << "Applicant " << applicant.getName() << " " << applicant.getSurname() << " added.\n";
}

// Видалення абітурієнта
void Admin::removeApplicant(Applicant& applicant) {
    // Логіка видалення абітурієнта з системи
    std::cout << "Applicant " << applicant.getName() << " " << applicant.getSurname() << " removed.\n";
}

// Додавання викладача
void Admin::addProfessor(Professor& professor) {
    // Логіка додавання викладача до системи
    std::cout << "Professor " << professor.getFirstName() << " " << professor.getLastName() << " added.\n";
}

// Видалення викладача
void Admin::removeProfessor(Professor& professor) {
    // Логіка видалення викладача з системи
    std::cout << "Professor " << professor.getFirstName() << " " << professor.getLastName() << " removed.\n";
}

// Створення іспиту
void Admin::createExam(Exam& exam) {
    // Логіка створення іспиту
    std::cout << "Exam created.\n";
}

// Видалення іспиту
void Admin::deleteExam(Exam& exam) {
    // Логіка видалення іспиту
    std::cout << "Exam deleted.\n";
}

// Управління факультетом
void Admin::manageFaculty(Faculty& faculty) {
    // Логіка керування факультетом
    std::cout << "Managing faculty.\n";
}


// Запис даних адміністратора в файл