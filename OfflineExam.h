#ifndef OFFLINEEXAM_H
#define OFFLINEEXAM_H

#include "Exam.h"

class OfflineExam : public Exam {
private:
    std::string location;
    std::string seatNumber;



public:
    
    void showOfflineDetails();

    void sayHello();

    OfflineExam() {
        std::cout << "Offline constructor ";
    
    };

    ~OfflineExam() {
        std::cout << "Offline destructor ";
    }
    
    OfflineExam(std::string place, std::string seatNumber);

    OfflineExam(std::string subject, std::string place, std::string seatNumber): Exam(subject), location(place), seatNumber(seatNumber) {};


    using Exam::showApplicantsGrades;
};

#endif // OFFLINEEXAM_H
