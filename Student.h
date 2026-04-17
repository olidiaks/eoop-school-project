//
// Created by olidiaks on 10.04.2026.
//

#ifndef PROJECT_STUDENT_H
#define PROJECT_STUDENT_H

#include <list>
#include <ostream>

#include "Assigment.h"
#include "Person.h"


class Student : public Person {
private:
        std::list<Assigment> mathAssignments;
        std::list<Assigment> englishAssignments;
        std::list<Assigment> polishAssignments;
        std::list<Assigment> historyAssignments;
        std::list<Assigment> biologyAssignments;
        std::list<Assigment> physicsAssignments;
        std::list<Assigment> chemistryAssignments;
        std::list<Assigment> geographyAssignments;
        std::list<Assigment> computerScienceAssignments;
        std::list<Assigment> physicalEducationAssignments;

    void initGrades();

public:
    Student(const int &id, const std::string &first_name, const std::string &last_name, const std::string &email,
            const time_t birth_date);

    Student(const int &id, const std::string &first_name, const std::string &last_name, const std::string &email,
            const int &day, const int &month, const int &year);

        [[nodiscard]] float get_average_grade() const;
};

#endif //PROJECT_STUDENT_H
