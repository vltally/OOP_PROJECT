#include <vector>
#include <algorithm> // Для std::sort
#include <iostream>
#include "Applicant.h"
#include "Exam.h"
#include "Professor.h"
#include "Faculty.h"
#include "GraduatedApplicant.h"
#include "OnlineExam.h"
#include "CombinedExam.h"

void checkEligibility(const Applicant& applicant) {
    if (applicant.age >= 18) {
        std::cout << applicant.name << " " << applicant.surname
            << " має право на вступ.\n";
    }
    else {
        std::cout << applicant.name << " " << applicant.surname
            << " ме має права на вступ.\n";
    }
}

void checkEligibility(const Applicant* applicant) {
    if (applicant->age >= 18) {
        std::cout << applicant->name << " " << applicant->surname
            << " має право на вступ.\n";
    }
    else {
        std::cout << applicant->name << " " << applicant->surname
            << " не має права на вступ.\n";
    }
}

Applicant createDefaultApplicant() {
    Applicant applicant("Іван", "Петренко", 18, 101, "Чоловік", "Контракт", "Денна", "Група 3");

    applicant.showInfo();

    return applicant;
}
void main() {
   
    PublicGraduatedApplicant pubGrad("Іван", "Петренко", 25, 1, "Бакалавр");
    pubGrad.showInfo();  // Працює - метод public в базовому класі
    pubGrad.getName();   // Працює - метод public в базовому класі
    pubGrad.group = "КН-11"; // Працює - поле public в базовому класі

    // Protected успадкування
    ProtectedGraduatedApplicant protGrad("Марія", "Іваненко", 23, 2, "Магістр");
    // protGrad.showInfo();  // Помилка компіляції - метод став protected
    // protGrad.getName();   // Помилка компіляції - метод став protected
    // protGrad.group = "КН-12"; // Помилка компіляції - поле стало protected

    // Private успадкування
    PrivateGraduatedApplicant privGrad("Петро", "Сидоренко", 27, 3, 5);
    // privGrad.showInfo();  // Помилка компіляції - метод став private
    // privGrad.getName();   // Помилка компіляції - метод став private
    // privGrad.group = "КН-13"; // Помилка компіляції - поле стало private

    //----------------------

    // Створення об'єкта OnlineExam з передачею параметрів
    OnlineExam onlineExam("Mathematics", "Dr. Brown", 100, 50, 75.5, "Zoom", true);

    // Виклик методу для демонстрації деталей іспиту
    onlineExam.showOnlineDetails();

    CombinedExam combinedExam;
    combinedExam.sayHello();


    std::cout << "---------------\n";


    CombinedExam* exam = new CombinedExam();

    std::cout << "--\n";

    delete exam;


    std::cout << "\n-----------------------------\n";
    Applicant applicant1("Ivan", "Ivanov", 20, 1, "Male", "Contract A", "Full-time", "Group A");
    Applicant applicant2("Oksana", "Petrova", 22, 2, "Female", "Contract B", "Part-time", "Group B");

    // Крок 2: Створення іспитів
    OnlineExam onlineExam11("Math", "Zoom", true);
    OfflineExam offlineExam11("History", "Room 101", "A1");
    CombinedExam combinedExam11("Physics", "Zoom", true);
    CombinedExam combinedExam12("Physics", "Khnu", "F2");

    // Крок 3: Додавання абітурієнтів до іспитів
    onlineExam11.addApplicantsExam({ Mark(applicant1, 0), Mark(applicant2, 0) });
    offlineExam11.addApplicantsExam({ Mark(applicant1, 0), Mark(applicant2, 0) });
    combinedExam11.addApplicantsExam({ Mark(applicant1, 0), Mark(applicant2, 0) });


    std::cout << "\n";
    // Крок 4: Встановлення оцінок
    onlineExam11.setScoreForApplicant();
    offlineExam11.setScoreForApplicant();
    combinedExam11.setScoreForApplicant();

    // Крок 5: Виведення інформації про абітурієнтів та їх оцінки
    std::cout << "\nOnline Exam Results:\n";
    onlineExam11.showApplicantsGrades();

    std::cout << "\nOffline Exam Results:\n";
    offlineExam11.showApplicantsGrades();

    std::cout << "\nCombined Exam Results:\n";
    combinedExam11.showApplicantsGrades();
    system("pause");
}
