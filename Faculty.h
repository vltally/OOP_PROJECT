#include <utility>
#include <vector>
#include <string>
#include "Applicant.h";
#include "Mark.h"

class Faculty {
private:
    std::string name;
    int id;
    int quota;
    float avg;
    std::vector<Mark> applicants;
    std::vector<Mark> applicantPass;


public:
    // Конструктори
    // Конструктори
    Faculty() : applicants(), applicantPass() {}
    Faculty(std::string facultyName, int facultyId, int quota) :
        name(facultyName), id(facultyId), quota(quota), avg(0), applicants(), applicantPass() {}
    Faculty(const Faculty& other) :
        name(other.name), id(other.id), quota(other.quota), avg(other.avg), applicants(other.applicants), applicantPass(other.applicantPass) {}

    ~Faculty(void);
  
    void addApplicant(Mark applicant);
    // Методи для встановлення значень
    void setAvg(float avg);
    void setName(const std::string& facultyName);
    void setId(int facultyId);
    void setQuota(int quota);

    // Методи для зчитування значень
    std::string getName() const;
    int getId() const;
    float getAvg();
    int getQuota();

    std::vector<Mark> getApplicants() {
        return applicants; 
    };


    void filterApplicants();

    void showApplicantsPass() const ;

    void addApplicantsFaculty(std::vector<Mark> applicants);
};