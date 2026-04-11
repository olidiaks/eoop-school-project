//
// Created by olidiaks on 10.04.2026.
//

#include "Teacher.h"

Teacher::Teacher(const int &id, const std::string &first_name, const std::string &last_name, const std::string &email,
    const time_t birth_date, const int salary, const std::string &subject): Person(id, first_name, last_name, email, birth_date),
                                                                            salary(salary),
                                                                            subject(subject) {
}

Teacher::Teacher(const int &id, const std::string &first_name, const std::string &last_name, const std::string &email,
    const int &day, const int &month, const int &year, const int salary, const std::string &subject): Person(id, first_name, last_name, email, day, month, year),
    salary(salary),
    subject(subject) {
}

std::string Teacher::get_subject() const {
    return subject;
}

int Teacher::get_salary() const {
    return salary;
}

void Teacher::set_salary(const int salary) {
    this->salary = salary;
}

std::ostream & operator<<(std::ostream &os, const Teacher &obj) {
    return os
           << static_cast<const Person &>(obj)
           << " salary: " << obj.salary
           << " subject: " << obj.subject;
}

bool operator==(const Teacher &lhs, const Teacher &rhs) {
    return static_cast<const Person &>(lhs) == static_cast<const Person &>(rhs)
           && lhs.salary == rhs.salary
           && lhs.subject == rhs.subject;
}
