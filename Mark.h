#ifndef MARK_H
#define MARK_H

#include "Applicant.h"

class Mark {
private:
    Applicant applicant;    // Об'єкт абітурієнта
    int mark;              // Оцінка
    bool appealStatus;     // Статус апеляції (true - апеляція подана, false - ні)

public:

    Mark() {};
    // Конструктор
    Mark(Applicant& applicant, int mark, bool appealStatus )
        : applicant(applicant), mark(mark), appealStatus(appealStatus = false) {}

    // Методи доступу
    const Applicant& getApplicant()  const { return applicant; }
     int getMark() const { return mark; }
    bool getAppealStatus()  { return appealStatus; }

    // Метод для зміни статусу апеляції
    void setAppealStatus(bool status) { appealStatus = status; }
    void setMark(int mark) { this->mark = mark; }

    // Можливо, ви захочете додати інші методи для роботи з оцінками або абітурієнтами
};

#endif // MARK_H