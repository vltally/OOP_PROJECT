#ifndef ASSISTANT_H
#define ASSISTANT_H

#include "Applicant.h"
#include "Professor.h"
#include <iostream>
#include "Person.h"

class Assistant : public Applicant, public Professor {
private:
    std::string assistantRole;

public:
    Assistant() : Person(), Applicant(), Professor(), assistantRole("") {};

    Assistant(std::string name, int age, std::string department, int experience, std::string role)
        : Person(), Applicant(name, age), Professor(department, experience), assistantRole(role) {}

    void showInfo() const override {
        Applicant::showInfo();
        Professor::showInfo();
        std::cout << "Role as Assistant: " << assistantRole << std::endl;
    }

    virtual ~Assistant() {
        std::cout << "Assistant destructor \n";
    }

    void Write(const std::string& filename) const override {
        std::cout << "Writing to file in Assistant class..." << std::endl;
        // Реалізація збереження
    }

    void Read(const std::string& filename) override {
        std::cout << "Read" << std::endl;
        // Реалізація збереження
    }

   

};

#endif // ASSISTANT_H