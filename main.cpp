#include <vector>
#include <algorithm> // Для std::sort
#include <iostream>
#include "Applicant.h"
#include "Exam.h"
#include "Professor.h"
#include "Faculty.h"

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
    //// 6. Створення 5 об'єктів у статичній пам'яті
    //Applicant applicant1("John", "Doe", 18, 1);
    //Applicant applicant2("Jane", "Smith", 19, 2);
    //Applicant applicant3("Alice", "Johnson", 20, 3);
    //Applicant applicant4("Bob", "Brown", 21, 4);
    //Applicant applicant5("Charlie", "Davis", 22, 5);
    //// 6. Створення 5 об'єктів у динамічній пам'яті за допомогою звичайних покажчиків
    //Applicant* applicant6 = new Applicant("Emily", "Clark", 23, 6);
    //Applicant* applicant7 = new Applicant("Frank", "Lewis", 24, 7);
    //Applicant* applicant8 = new Applicant("Grace", "Miller", 25, 8);
    //Applicant* applicant9 = new Applicant("Henry", "Taylor", 26, 9);
    //Applicant* applicant10 = new Applicant("Ivy", "Wilson", 27, 10);
    //// 3. Зв'язок об'єктів Applicant і Exam через масив абітурієнтів у класі Exam
    //Exam math("Mathematics", 100, false);
    //// 4. Додавання абітурієнтів на іспит разом з оцінками (використання методів класу Exam)
    //math.addApplicant(applicant1, 85);
    //math.addApplicant(applicant2, 90);
    //math.addApplicant(applicant3, 75);
    //math.addApplicant(applicant4, 60);
    //math.addApplicant(applicant5, 95);
    //// 5. Методи для запису та читання з файлу
    //applicant1.writeToFile("applicant1.txt"); // Записуємо абітурієнта у файл
    //Applicant newApplicant;
    //newApplicant.readFromFile("applicant1.txt"); // Читаємо абітурієнта з файлу
    //newApplicant.showInfo(); // Виводимо інформацію про прочитаного абітурієнта
    //// 7. Створення двох масивів об'єктів
    //std::vector<Applicant> applicantsStatic = { applicant1, applicant2, applicant3, applicant4, applicant5 };
    //std::vector<Applicant*> applicantsDynamic = { applicant6, applicant7, applicant8, applicant9, applicant10 };
    //// 8. Робота з об'єктами в масивах
    //std::cout << "\nStatic Applicants:\n";
    //for (const auto& applicant : applicantsStatic) {
    //    applicant.showInfo(); // Виводимо інформацію про абітурієнтів зі статичної пам'яті
    //}
    //std::cout << "\nDynamic Applicants:\n";
    //for (const auto& applicant : applicantsDynamic) {
    //    applicant->showInfo(); // Виводимо інформацію про абітурієнтів з динамічної пам'яті
    //}
    //// 9. Використання методів класів
    //std::cout << "\nExam Applicants and Scores:\n";
    //math.showApplicants(); // Показуємо абітурієнтів та їх оцінки
    //// 10. Взаємодія двох об'єктів — апеляція та перегляд оцінок
    //std::cout << "\nReviewing Exam (Appeal):\n";
    //math.reviewExam(5); // Підвищуємо оцінки на 5 балів (наприклад, апеляція)
    //math.showApplicants(); // Виводимо результати після апеляції
    //// 11. Використання покажчика на екземпляр класу
    //Applicant* ptrApplicant = &applicant1;  // Покажчик на абітурієнта
    //ptrApplicant->showInfo();  // Виклик методу через покажчик
    //// 12. Виділення динамічної пам'яті та сортування
    //int size = 5;
    //int* scores = new int[size] { 85, 90, 75, 60, 95 }; // Виділення пам'яті під оцінки
    //std::cout << "\nScores before sorting:\n";
    //for (int i = 0; i < size; ++i) {
    //    std::cout << scores[i] << " ";
    //}
    //std::cout << "\n";
    //std::sort(scores, scores + size); // Сортуємо оцінки
    //std::cout << "Scores after sorting:\n";
    //for (int i = 0; i < size; ++i) {
    //    std::cout << scores[i] << " ";
    //}
    //std::cout << "\n";
    //delete[] scores; // Звільняємо пам'ять
    //// Звільняємо пам'ять для динамічних об'єктів
    //delete applicant6;
    //delete applicant7;
    //delete applicant8;
    //delete applicant9;
    //delete applicant10;
    

    //-----------------------------------------------------------------------------------------------------------

    Faculty faculty1;
    Faculty* faculty2 = new Faculty("Факультет інформаційних технологій", 1, 2);
    Faculty faculty3 = faculty1;

    delete faculty2;

    Applicant applicant1("Віталік", "Колєсніков", 18, 101);
    Applicant applicant2("Володимир", "Котюк", 17, 102);

    // Виведення інформації про абітурієнтів
    applicant1.showInfo();
    applicant2.showInfo();

    // Виклик статичного методу для отримання кількості абітурієнтів
    std::cout << "Загальна кількість вступників: " << Applicant::getApplicantCount() << "\n";

    checkEligibility(applicant1);
    checkEligibility(&applicant2);

    Applicant func_applicant = createDefaultApplicant();



    // Простий конструктор (за замовчуванням)
    Applicant applicant3("Ярослав", "Березніцький", 22, 104);

    // Скорочений спосіб створення об'єкта
  
    Applicant applicant5;
    
    // Явний конструктор
    Applicant applicant7(8, "Hello");
    // Applicant applicant8 = { 30, "Hello" }; //C++ copy-list-initialization не может использовать конструктор, помеченный как



    Applicant staticApplicant("Charlie", "Brown", 18, 105);
    staticApplicant.showInfo();

    // Динамічне створення об'єкта
    Applicant* dynamicApplicant = new Applicant("Dana", "White", 21, 106);
    dynamicApplicant->showInfo();

    // Масив об'єктів, створений у статичній пам'яті
    Applicant applicantsArray[2] = {
        {"Eve", "Black", 19, 107},
        {"Frank", "Green", 23, 108}
    };
    /*applicantsArray[0].showInfo();
    applicantsArray[1].showInfo();*/
    
    // Масив об'єктів, створений у динамічній пам'яті
    Applicant* dynamicArray = new Applicant[2]{
        {"Grace", "Hopper", 24, 109},
        {"Henry", "Ford", 20, 110}
    };
   /* dynamicArray[0].showInfo();
    dynamicArray[1].showInfo();*/

    // Очищення динамічної пам'яті
    delete dynamicApplicant;
    delete[] dynamicArray; 

    std::cout << "-----------------------------\n";

    Faculty faculty("Інформаційні технолонії", 1, 4);


    Applicant applicant11("Ярослав", "Березніцький", 22, 122);
    Applicant applicant12("Володимир", "Котюк", 18, 122);
    Applicant applicant13("Олександр", "Шевченко", 20, 122);
    Applicant applicant14("Ірина", "Мельник", 21, 122);
    Applicant applicant15("Дмитро", "Кравченко", 19, 122);
    Applicant applicant16("Світлана", "Тарасенко", 23, 122);
    Applicant applicant17("Анна", "Громова", 24, 122);

    applicant11.applyForFaculty(faculty);
    applicant12.applyForFaculty(faculty);
    applicant13.applyForFaculty(faculty);
    applicant14.applyForFaculty(faculty);
    applicant15.applyForFaculty(faculty);
    applicant16.applyForFaculty(faculty);
    applicant17.applyForFaculty(faculty);
    
    Exam exam("Фізика");
    Professor professor11("Антон", "Сівко");
    
    exam.addApplicantsExam(faculty.getApplicants());
    professor11.evaluateExam(exam);
    exam.showApplicantsGrades();
    faculty.setAvg(exam.calculateAverageScore());
    faculty.addApplicantsFaculty(exam.returnApplicants());
    faculty.filterApplicants();
    std::cout << "------------------------------\n";
    std::cout << "Квота: " << faculty.getQuota() << " Середній бал: " << faculty.getAvg() << "\n";
    std::cout << "------------------------------\n";
    faculty.showApplicantsPass();
 


    applicant11.appealForMark(exam);
    
    applicant12.appealForMark(exam);

    
    
    professor11.reviewAppeals(exam);

    exam.showApplicantsGrades();
    faculty.setAvg(exam.calculateAverageScore());
    faculty.addApplicantsFaculty(exam.returnApplicants());
    faculty.filterApplicants();


    std::cout << "------------------------------\n";
    std::cout << "Квота: " << faculty.getQuota() << " Середній бал: " << faculty.getAvg() << "\n";
    std::cout << "------------------------------\n";
    faculty.showApplicantsPass();


    //professor11.reviewAppeals();


   // std::cout << "------------------------------\n";
   // exam.showApplicantsGrades();

    Exam onlineExam("Фізика", true);
    applicant11.applyForFaculty(faculty);
    applicant12.applyForFaculty(faculty);
    applicant13.applyForFaculty(faculty);
    applicant14.applyForFaculty(faculty);

    onlineExam.setScoreForApplicant();

    system("pause");
}
