#include "Classes.h"
#include <vector>
#include <algorithm> // Для std::sort

int main() {
    // 6. Створення 5 об'єктів у статичній пам'яті
    Applicant applicant1("John", "Doe", 18, 1);
    Applicant applicant2("Jane", "Smith", 19, 2);
    Applicant applicant3("Alice", "Johnson", 20, 3);
    Applicant applicant4("Bob", "Brown", 21, 4);
    Applicant applicant5("Charlie", "Davis", 22, 5);

    // 6. Створення 5 об'єктів у динамічній пам'яті за допомогою звичайних покажчиків
    Applicant* applicant6 = new Applicant("Emily", "Clark", 23, 6);
    Applicant* applicant7 = new Applicant("Frank", "Lewis", 24, 7);
    Applicant* applicant8 = new Applicant("Grace", "Miller", 25, 8);
    Applicant* applicant9 = new Applicant("Henry", "Taylor", 26, 9);
    Applicant* applicant10 = new Applicant("Ivy", "Wilson", 27, 10);

  
    // 3. Зв'язок об'єктів Applicant і Exam через масив абітурієнтів у класі Exam
    Exam math("Mathematics", 100, false);

    // 4. Додавання абітурієнтів на іспит разом з оцінками (використання методів класу Exam)
    math.addApplicant(applicant1, 85);
    math.addApplicant(applicant2, 90);
    math.addApplicant(applicant3, 75);
    math.addApplicant(applicant4, 60);
    math.addApplicant(applicant5, 95);

    // 5. Методи для запису та читання з файлу
    applicant1.writeToFile("applicant1.txt"); // Записуємо абітурієнта у файл
    Applicant newApplicant;
    newApplicant.readFromFile("applicant1.txt"); // Читаємо абітурієнта з файлу
    newApplicant.showInfo(); // Виводимо інформацію про прочитаного абітурієнта

    // 7. Створення двох масивів об'єктів
    std::vector<Applicant> applicantsStatic = { applicant1, applicant2, applicant3, applicant4, applicant5 };
    std::vector<Applicant*> applicantsDynamic = { applicant6, applicant7, applicant8, applicant9, applicant10 };

    // 8. Робота з об'єктами в масивах
    std::cout << "\nStatic Applicants:\n";
    for (const auto& applicant : applicantsStatic) {
        applicant.showInfo(); // Виводимо інформацію про абітурієнтів зі статичної пам'яті
    }

    std::cout << "\nDynamic Applicants:\n";
    for (const auto& applicant : applicantsDynamic) {
        applicant->showInfo(); // Виводимо інформацію про абітурієнтів з динамічної пам'яті
    }

    // 9. Використання методів класів
    std::cout << "\nExam Applicants and Scores:\n";
    math.showApplicants(); // Показуємо абітурієнтів та їх оцінки

    // 10. Взаємодія двох об'єктів — апеляція та перегляд оцінок
    std::cout << "\nReviewing Exam (Appeal):\n";
    math.reviewExam(5); // Підвищуємо оцінки на 5 балів (наприклад, апеляція)
    math.showApplicants(); // Виводимо результати після апеляції

    // 11. Використання покажчика на екземпляр класу
    Applicant* ptrApplicant = &applicant1;  // Покажчик на абітурієнта
    ptrApplicant->showInfo();  // Виклик методу через покажчик

    // 12. Виділення динамічної пам'яті та сортування
    int size = 5;
    int* scores = new int[size] { 85, 90, 75, 60, 95 }; // Виділення пам'яті під оцінки

    std::cout << "\nScores before sorting:\n";
    for (int i = 0; i < size; ++i) {
        std::cout << scores[i] << " ";
    }
    std::cout << "\n";

    std::sort(scores, scores + size); // Сортуємо оцінки

    std::cout << "Scores after sorting:\n";
    for (int i = 0; i < size; ++i) {
        std::cout << scores[i] << " ";
    }
    std::cout << "\n";

    delete[] scores; // Звільняємо пам'ять

    // Звільняємо пам'ять для динамічних об'єктів
    delete applicant6;
    delete applicant7;
    delete applicant8;
    delete applicant9;
    delete applicant10;

    system("pause");
    return 0;
}
