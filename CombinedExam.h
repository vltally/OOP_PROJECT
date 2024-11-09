#ifndef COMBINEDEXAM_H
#define COMBINEDEXAM_H

#include "OnlineExam.h"
#include "OfflineExam.h"

class CombinedExam : public OnlineExam, public OfflineExam {
public:
    CombinedExam() {
        std::cout << "Combined constructor ";
    }

    CombinedExam(std::string subject, std::string teacher, int maxScore, int minScore, double avg,
        std::string platform, bool requiresWebcam, std::string location, std::string seatNumber);

    CombinedExam(std::string subject, std::string platform, bool requiresWebcam) : OnlineExam(platform, requiresWebcam) {};

    CombinedExam(std::string subject, std::string location, std::string seatNumber) : OfflineExam(location, seatNumber)  {};
    void showCombinedDetails();

    using OnlineExam::sayHello;

    ~CombinedExam() {
        std::cout << "Combined destructor ";
    }

    using Exam::addApplicantsExam;
    using Exam::setScoreForApplicant;
    using Exam::showApplicantsGrades;



};


#endif // COMBINEDEXAM_H
