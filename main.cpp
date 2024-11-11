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
#include "CustomClass.h"
#include "CustomType.h"
#include <list>
#include <deque>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <functional>
#include <numeric>


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
    
    // 1.1 Vector
    std::vector<int> vec1 = { 1, 2, 3 };
    vec1.push_back(4);
    vec1.pop_back();
    vec1.at(1) = 10;

    std::cout << "Vector: ";
    for (int elem : vec1) std::cout << elem << " ";
    std::cout << std::endl;

    // 1.2 List
    std::list<int> list1 = { 1, 2, 3 };
    list1.push_front(0);
    list1.push_back(4);
    list1.remove(2);

    std::cout << "List: ";
    for (int elem : list1) std::cout << elem << " ";
    std::cout << std::endl;

    // 1.3 Deque
    std::deque<int> deque1 = { 1, 2, 3 };
    deque1.push_front(0);
    deque1.push_back(4);
    deque1.pop_front();

    std::cout << "Deque: ";
    for (int elem : deque1) std::cout << elem << " ";
    std::cout << std::endl;

    // 1.4 Set
    std::set<int> set1 = { 3, 1, 4, 2 };
    set1.insert(5);
    set1.erase(1);

    std::cout << "Set: ";
    for (int elem : set1) std::cout << elem << " ";
    std::cout << std::endl;

    // 1.5 Multiset
    std::multiset<int> multiset1 = { 1, 2, 2, 3 };
    multiset1.insert(2);
    multiset1.erase(2);

    std::cout << "Multiset: ";
    for (int elem : multiset1) std::cout << elem << " ";
    std::cout << std::endl;

    // 1.6 Map
    std::map<int, std::string> map1;
    map1[1] = "One";
    map1[2] = "Two";
    map1.erase(1);

    std::cout << "Map: ";
    for (auto it = map1.begin(); it != map1.end(); ++it) {
        std::cout << "{" << it->first << ", " << it->second << "} ";
    }
    std::cout << std::endl;

    // 1.7 Multimap
    std::multimap<int, std::string> multimap1;
    multimap1.insert({ 1, "One" });
    multimap1.insert({ 1, "Another One" });

    std::cout << "Multimap: ";
    for (auto it = multimap1.begin(); it != multimap1.end(); ++it) {
        std::cout << "{" << it->first << ", " << it->second << "} ";
    }
    std::cout << std::endl;

    // 1.8 Stack
    std::stack<int> stack1;
    stack1.push(1);
    stack1.push(2);
    stack1.pop();

    std::cout << "Stack top: " << stack1.top() << std::endl;

    // 1.9 Queue
    std::queue<int> queue1;
    queue1.push(1);
    queue1.push(2);
    queue1.pop();

    std::cout << "Queue front: " << queue1.front() << std::endl;

    // 1.10 Priority Queue
    std::priority_queue<int> priorityQueue1;
    priorityQueue1.push(1);
    priorityQueue1.push(3);
    priorityQueue1.push(2);
    priorityQueue1.pop();

    std::cout << "Priority queue top: " << priorityQueue1.top() << std::endl;

    // Vector for iterators and algorithms examples
    std::vector<int> vec2 = { 1, 2, 3, 4 };

    // 2.3 Односпрямований ітератор
    std::cout << "Vector with forward iterator: ";
    for (auto it = vec2.begin(); it != vec2.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // 2.4 Двонаправлений ітератор
    std::list<int> list2 = { 1, 2, 3, 4 };
    std::cout << "List with reverse iterator: ";
    for (auto it = list2.rbegin(); it != list2.rend(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // 2.5 Ітератор довільного доступу
    vec2[2] = 10;
    std::cout << "Vector after index access: ";
    for (int elem : vec2) std::cout << elem << " ";
    std::cout << std::endl;

    // Vector for algorithms examples
    std::vector<int> vec3 = { 1, 3, 5, 4, 2 };

    // Алгоритм сортування
    std::sort(vec3.begin(), vec3.end());
    std::cout << "Sorted vector: ";
    for (int elem : vec3) std::cout << elem << " ";
    std::cout << std::endl;

    // Алгоритм для обернення порядку елементів
    std::reverse(vec3.begin(), vec3.end());
    std::cout << "Reversed vector: ";
    for (int elem : vec3) std::cout << elem << " ";
    std::cout << std::endl;


    system("pause");
}
