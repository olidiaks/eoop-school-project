//
// Created by olidiaks on 10.04.2026.
//

#include "Student.h"


Student::Student(const std::string &first_name, const std::string &last_name, const std::string &email,
                 const int &day, const int &month, const int &year
) : Person(first_name, last_name, email, day, month, year) {
}


float Student::get_average_grades_from_subject(const std::list<Assigment> &assignments) {
    float sum = 0;
    int count = 0;

    for (auto &assignment : assignments) {
        sum += assignment.get_grade();
        count++;
    }

    return sum / count;
}

Student::Student(const std::string &first_name, const std::string &last_name, const std::string &email,
                 const time_t birth_date
) : Person(first_name, last_name, email, birth_date) {
}

float Student::get_average_grade() const {
    throw std::runtime_error("Not implemented");
}

float Student::get_average_grade_from_math() const {
    return get_average_;
}

float Student::get_average_grade_from_english() const {
}

float Student::get_average_grade_from_polish() const {
}

float Student::get_average_grade_from_history() const {
}

float Student::get_average_grade_from_biology() const {
}

float Student::get_average_grade_from_phisics() const {
}

float Student::get_average_grade_from_chemistry() const {
}

float Student::get_average_grade_from_geography() const {
}

float Student::get_average_grade_from_computer_science() const {
}

float Student::get_average_grade_from_physical_education() const {
}

