//
// Created by olidiaks on 10.04.2026.
//

#include "Student.h"

void Student::initGrades() {
    throw std::runtime_error("Not implemented");
}


Student::Student(const int &id, const std::string &first_name, const std::string &last_name, const std::string &email,
                 const int &day, const int &month, const int &year
) : Person(id, first_name, last_name, email, day, month, year) {
    initGrades();
}

Student::Student(const int &id, const std::string &first_name, const std::string &last_name, const std::string &email,
                 const time_t birth_date
) : Person(id, first_name, last_name, email, birth_date) {
    initGrades();
}

float Student::get_average_grade() const {
    throw std::runtime_error("Not implemented");
}
