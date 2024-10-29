// OnlineExam.h
#ifndef ONLINEEXAM_H
#define ONLINEEXAM_H

#include "Exam.h"

class OnlineExam : public Exam {
private:
    std::string platform;
    bool requiresWebcam;

public:
    // Конструктор з передачею параметрів базовому класу
    OnlineExam(std::string subject, std::string teacher, int maxScore, int minScore, double avg,
        std::string platform, bool requiresWebcam);
    OnlineExam() {
        std::cout << "Online constructor ";
    };

    OnlineExam(std::string platform, bool requiredWebcam) {};
    
    OnlineExam(std::string subject, std::string platform, bool requiredWebcam)
        : Exam(subject), platform(platform), requiresWebcam(requiredWebcam) {};

    ~OnlineExam() {
        std::cout << "Online destructor ";
    };
    void showOnlineDetails();

    void sayHello();
};

#endif // ONLINEEXAM_H
