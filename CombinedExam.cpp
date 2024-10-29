#include "CombinedExam.h"
#include <iostream>


CombinedExam::CombinedExam(std::string subject, std::string teacher, int maxScore, int minScore, double avg,
    std::string platform, bool requiresWebcam, std::string location, std::string seatNumber)
    : OnlineExam(subject, teacher, maxScore, minScore, avg, platform, requiresWebcam),
    OfflineExam(subject, location, seatNumber) {}


void CombinedExam::showCombinedDetails() {
    showOnlineDetails();
    showOfflineDetails();
}
