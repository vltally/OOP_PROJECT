// OnlineExam.cpp
#include "OnlineExam.h"
#include <iostream>

OnlineExam::OnlineExam(std::string subject, std::string teacher, int maxScore, int minScore, double avg,
    std::string platform, bool requiresWebcam)
    : Exam(subject, teacher, maxScore, minScore, avg), // Виклик конструктора базового класу
    platform(platform), requiresWebcam(requiresWebcam) {}

void OnlineExam::showOnlineDetails() {
    std::cout << "Online Exam Details:\n"
        << "Subject: " << subject << "\n"
        << "Teacher: " << teacher << "\n"
        << "Max Score: " << maxScore << "\n"
        << "Min Score: " << minScore << "\n"
        << "Average: " << avg << "\n"
        << "Platform: " << platform << "\n"
        << "Webcam Required: " << (requiresWebcam ? "Yes" : "No") << "\n";
}

void OnlineExam::sayHello() {
    std::cout << "Online Hello\n";
}

