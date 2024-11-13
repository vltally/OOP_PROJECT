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
    // ������������
    Admin();
    Admin(const std::string& username, const std::string& password);

    // ³�������� ������� ��� ������ ����������
    void showInfo() const override;

    // ������ ��� ��������� �������� �������
    void setUsername(const std::string& username);
    void setPassword(const std::string& password);
    std::string getUsername() const;
    std::string getPassword() const;

    // ������ ��� ��������� ��������
    void addApplicant(Applicant& applicant);    // ������ �������� �� �������
    void removeApplicant(Applicant& applicant); // �������� �������� �� �������

    void addProfessor(Professor& professor);    // ������ ��������� �� �������
    void removeProfessor(Professor& professor); // �������� ��������� �� �������

    void createExam(Exam& exam);     // �������� �����
    void deleteExam(Exam& exam);     // �������� �����

    void manageFaculty(Faculty& faculty); // �������� ������������

    void Write(const std::string& filename) const override {
        
    }

    void Read(const std::string& filename) override {
       
    }
    // �����/������� ����� � �����
    //void writeToFile(const std::string& filename); // ����� ����� ������������ � ����
    //void readFromFile(const std::string& filename); // ������� ����� ������������ � �����


};