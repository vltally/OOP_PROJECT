#include <Windows.h>
#include <vector>
#include <algorithm> // Для std::sort
#include <iostream>
#include "Person.h"
#include "Applicant.h"
#include "Exam.h"
#include "Professor.h"
#include "Faculty.h"
#include "OnlineExam.h"
#include "Assistant.h"
#include <locale>
#include "Admin.h"

void mainMenu();
void createApplicant();
void deleteApplicantByCriteria();
void viewApplicants();

std::vector<Applicant*> applicants;

void mainMenu() {
    int choice;
    do {
        std::cout << "\n===== Меню =====\n";
        std::cout << "1. Створити об'єкт Applicant\n";
        std::cout << "2. Видалити об'єкт за критерієм\n";
        std::cout << "3. Переглянути всі об'єкти Applicant\n";
        std::cout << "4. Вийти\n";
        std::cout << "Оберіть опцію: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            createApplicant();
            break;
        case 2:
            deleteApplicantByCriteria();
            break;
        case 3:
            viewApplicants();
            break;
        case 4:
            std::cout << "Вихід з програми...\n";
            break;
        default:
            std::cout << "Невірний вибір. Спробуйте ще раз.\n";
        }
    } while (choice != 4);

    // Очищення динамічних об'єктів перед виходом
    for (Applicant* applicant : applicants) {
        delete applicant;
    }
    applicants.clear();
}

void createApplicant() {
    std::string name, surname;
    int age, facultyId;

    std::cout << "Введіть ім'я: ";
    std::cin >> name;
    std::cout << "Введіть прізвище: ";
    std::cin >> surname;
    std::cout << "Введіть вік: ";
    std::cin >> age;
    std::cout << "Введіть ID факультету: ";
    std::cin >> facultyId;

    try {
        Applicant* newApplicant = new Applicant(name, surname, age, facultyId);
        applicants.push_back(newApplicant);
        std::cout << "Об'єкт створено.\n";
    }
    catch (const std::bad_alloc& e) {
        std::cerr << "Помилка виділення пам'яті: " << e.what() << "\n";
    }
}

void deleteApplicantByCriteria() {
    std::string surnameCriteria;
    std::cout << "Введіть прізвище для видалення об'єкта: ";
    std::cin >> surnameCriteria;

    auto it = std::remove_if(applicants.begin(), applicants.end(),
        [&surnameCriteria](Applicant* applicant) {
            return applicant->getSurname() == surnameCriteria;
        });

    if (it != applicants.end()) {
        for (auto itr = it; itr != applicants.end(); ++itr) {
            delete* itr;
        }
        applicants.erase(it, applicants.end());
        std::cout << "Об'єкти видалено за критерієм прізвища.\n";
    }
    else {
        std::cout << "Об'єкт з таким прізвищем не знайдено.\n";
    }
}

void viewApplicants() {
    if (applicants.empty()) {
        std::cout << "Список порожній.\n";
    }
    else {
        std::cout << "===== Список Applicant =====\n";
        for (const Applicant* applicant : applicants) {
            applicant->showInfo();
        }
    }
}




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

std::vector<Person*> people;

void createObjects() {
    try {
        // Динамічне створення об'єктів Applicant з обробкою std::bad_alloc
        for (int i = 0; i < 5; ++i) {
            people.push_back(new Applicant());
        }

        // Динамічне створення об'єктів Instructor з обробкою std::bad_alloc
        for (int i = 0; i < 5; ++i) {
            people.push_back(new Assistant());
        }

        // Демонстрація ручного винятку
        if (people.size() > 10) {
            throw std::runtime_error("Exceeded object limit for demonstration.");
        }

    }
    catch (const std::bad_alloc&) {
        std::cerr << "Memory allocation failed." << std::endl;
    }
    catch (const std::runtime_error& e) {
        std::cerr << "Runtime error: " << e.what() << std::endl;
    }
    catch (...) {
        std::cerr << "An unexpected error occurred during object creation." << std::endl;
    }
}

void cleanup() {
    for (auto person : people) delete person;
    people.clear();
}

std::vector<Person*> dynamicPeople;

void Service_Static(Applicant staticApplicants[], int& size, int criterion) {
    try {
        bool found = false;
        // Видаляємо об'єкти з масиву за певним критерієм (наприклад, за віком)
        for (int i = 0; i < size; ++i) {
            if (staticApplicants[i].getAge() == criterion) {
                // Зміщуємо елементи вліво для видалення
                for (int j = i; j < size - 1; ++j) {
                    staticApplicants[j] = staticApplicants[j + 1];
                }
                size--;  // Зменшуємо розмір
                found = true;
                std::cout << "Removed Applicant with age: " << criterion << std::endl;
                break;
            }
        }
        if (!found) {
            throw std::runtime_error("No Applicant found with the given age.");
        }
    }
    catch (const std::runtime_error& e) {
        std::cerr << "Error in Service_Static: " << e.what() << std::endl;
    }
}

void Service_Dynamic(std::vector<Person*>& dynamicPeople, int criterion) {
    try {
        bool found = false;
        // Видаляємо динамічний об'єкт за певним критерієм (наприклад, за віком)
        for (auto it = dynamicPeople.begin(); it != dynamicPeople.end(); ++it) {
            Applicant* applicant = dynamic_cast<Applicant*>(*it);
            if (applicant && applicant->getAge() == criterion) {
                delete* it;  // Видаляємо об'єкт з пам'яті
                dynamicPeople.erase(it);  // Видаляємо з вектору
                found = true;
                std::cout << "Removed dynamic Applicant with age: " << criterion << std::endl;
                break;
            }
        }
        if (!found) {
            throw std::runtime_error("No dynamic Applicant found with the given age.");
        }
    }
    catch (const std::bad_alloc&) {
        std::cerr << "Memory allocation failed while deleting dynamic objects." << std::endl;
        throw;  // Перевидаємо виключення для подальшої обробки
    }
    catch (const std::runtime_error& e) {
        std::cerr << "Error in Service_Dynamic: " << e.what() << std::endl;
    }
    catch (...) {
        std::cerr << "An unexpected error occurred while deleting dynamic objects." << std::endl;
    }
}

void Service(Person* person, const std::string& filename) {
    try {
        // Записуємо об'єкт у файл
        person->Write(filename);
        std::cout << "Data written to file successfully." << std::endl;

        // Читаємо об'єкт з файлу
        person->Read(filename);
        std::cout << "Data read from file: ";
        person->showInfo();
    }
    catch (const std::ios_base::failure& e) {
        std::cerr << "I/O Exception in Service: " << e.what() << std::endl;
    }
    catch (const std::bad_alloc& e) {
        std::cerr << "Memory Allocation Failure in Service: " << e.what() << std::endl;
    }
    catch (const std::invalid_argument& e) {
        std::cerr << "Invalid Argument Error in Service: " << e.what() << std::endl;
    }
    catch (const std::runtime_error& e) {
        std::cerr << "Runtime Error in Service: " << e.what() << std::endl;
    }
    catch (...) {
        std::cerr << "An unexpected error occurred in Service." << std::endl;
    }
}

void main() {
    std::locale::global(std::locale("en_US.UTF-8"));

   // setlocale(LC_CTYPE, "ukr");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Person* person = new Assistant();
    delete person;


    std::cout << "----------\n";

    //Person* person1 = new Applicant();
    //delete person1;


    try {
        // Створення статичних об'єктів
        Applicant staticApplicants[5] = {
            Applicant("1", 1), Applicant("2", 1),
            Applicant("3", 1), Applicant("4", 1),
            Applicant("5", 1)
        };

        Assistant staticInstructors[5] = {
            Assistant(), Assistant(),
            Assistant(), Assistant(),
            Assistant()
        };

        // Створення динамічних об'єктів
        createObjects();
    }
    catch (const std::exception& e) {
        std::cerr << "Exception in main: " << e.what() << std::endl;
    }
    catch (...) {
        std::cerr << "Unknown exception in main." << std::endl;
    }

    // Очищення динамічних об'єктів
    cleanup();

    std::cout << "---------------------------------------------------\n";
    try {
        // Створення статичних об'єктів
        Applicant staticApplicants[5] = {
            Applicant("Static Applicant 1", 22),
            Applicant("Static Applicant 2", 23),
            Applicant("Static Applicant 3", 22),
            Applicant("Static Applicant 4", 24),
            Applicant("Static Applicant 5", 21)
        };
        int staticSize = 5;

        // Створення динамічних об'єктів
        dynamicPeople.push_back(new Applicant("Dynamic Applicant 1", 22));
        dynamicPeople.push_back(new Applicant("Dynamic Applicant 2", 23));
        dynamicPeople.push_back(new Applicant("Dynamic Applicant 3", 22));
        dynamicPeople.push_back(new Applicant("Dynamic Applicant 4", 25));
        dynamicPeople.push_back(new Applicant("Dynamic Applicant 5", 21));

        // Демонстрація видалення об'єктів за віком 22 для статичних та динамічних об'єктів
        Service_Static(staticApplicants, staticSize, 22);  // Статичні об'єкти
        Service_Dynamic(dynamicPeople, 22);  // Динамічні об'єкти

        // Виведення результатів
        std::cout << "Remaining Static Applicants: " << staticSize << std::endl;
        std::cout << "Remaining Dynamic Applicants: " << dynamicPeople.size() << std::endl;

    }
    catch (const std::exception& e) {
        std::cerr << "Exception in main: " << e.what() << std::endl;
    }
    catch (...) {
        std::cerr << "Unknown exception in main." << std::endl;
    }

    // Очищення пам'яті для динамічних об'єктів
    for (auto person : dynamicPeople) {
        delete person;
    }
    dynamicPeople.clear();



    std::cout << "------------------------------------\n";

    std::string filename = "Hello";

    try {
        // Створюємо об'єкт Applicant
        Applicant applicant("John Doe", 25);

        // Викликаємо Service для обробки
        Service(&applicant, filename);
    }
    catch (const std::exception& e) {
        std::cerr << "Exception in main: " << e.what() << std::endl;
    }
    catch (...) {
        std::cerr << "Unknown exception in main." << std::endl;
    }


    Applicant a1("John Doe", 25);
    Applicant a2("Jane Smith", 22);
    Applicant::viewAllApplicants();


    mainMenu();

    Person* person11 = new Assistant();
    person11->showInfo();
    delete person11;

    Person* person12 = new Applicant();
    person12->showInfo();
    delete person12;
    Person* person13 = new Professor();
    person13->showInfo();
    delete person13;

    system("pause");
}
