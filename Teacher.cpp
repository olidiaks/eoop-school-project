//
// Created by olidiaks on 10.04.2026.
//

#include "Teacher.h"

#include <iostream>

Teacher::Teacher(const std::string &first_name, const std::string &last_name, const std::string &email,
                 const time_t birth_date, const int salary, const Subject &subject): Person(first_name, last_name, email, birth_date),
                                                                                         salary(salary),
                                                                                         subject(subject) {
}

Teacher::Teacher(const std::string &first_name, const std::string &last_name, const std::string &email,
    const int &day, const int &month, const int &year, const int salary, const Subject &subject): Person(first_name, last_name, email, day, month, year),
    salary(salary),
    subject(subject) {
}

const Subject &Teacher::get_subject() const {
    return subject;
}

int Teacher::get_salary() const {
    return salary;
}

void Teacher::set_salary(const int salary) {
    this->salary = salary;
}

Teacher::Teacher(const Teacher &other): Person(other),
                                        salary(other.salary),
                                        subject(other.subject) {
}

Teacher::Teacher(Teacher &&other) noexcept: Person(std::move(other)),
                                            salary(other.salary),
                                            subject(std::move(other.subject)) {
}

Teacher & Teacher::operator=(const Teacher &other) {
    if (this == &other)
        return *this;
    Person::operator =(other);
    salary = other.salary;
    subject = other.subject;
    return *this;
}

Teacher & Teacher::operator=(Teacher &&other) noexcept {
    if (this == &other)
        return *this;
    Person::operator =(std::move(other));
    salary = other.salary;
    subject = std::move(other.subject);
    return *this;
}

Teacher::Teacher() : Person(){
    salary = 0;
    subject = Subject::None;
}

std::ostream & operator<<(std::ostream &os, const std::list<Teacher> &Teacher) {
    for (const auto &teacher: Teacher) {
        os << teacher << std::endl;
    }
    return os;
}


std::ostream & operator<<(std::ostream &os, const Teacher &obj) {
    return os
           << static_cast<const Person &>(obj)
           << " salary: " << obj.salary
           << " subject: " << obj.subject;
}

bool Teacher::operator==(const Teacher &rhs) const {
    return static_cast<const Person &>(*this) == static_cast<const Person &>(rhs)
           && salary == rhs.salary
           && subject == rhs.subject;
}

bool Teacher::operator!=(const Teacher &rhs) const {
    return !(*this == rhs);
}

void swap(Teacher &lhs, Teacher &rhs) noexcept {
    using std::swap;
    swap(static_cast<Person &>(lhs), static_cast<Person &>(rhs));
    swap(lhs.salary, rhs.salary);
    swap(lhs.subject, rhs.subject);
}
