//
// Created by olidiaks on 4/16/26.
//

#include "Assignment.h"

#include <algorithm>

int Assignment::counter = 0;


Assignment::Assignment(const std::string &name, const std::string &description, const std::string &subject): name(name),
    description(description),
    subject(subject) {
    id = ++counter;
    grade = 0;
}

Assignment::Assignment(const std::string &name, const std::string &description, const std::string &subject,
    const int grade): name(name),
                      description(description),
                      subject(subject),
                      grade(grade) {
    id = ++counter;
}



Assignment::Assignment(const Assignment &other): id(other.id),
                                              name(other.name),
                                              description(other.description),
                                              subject(other.subject),
                                              grade(other.grade)  {
}

Assignment::Assignment(Assignment &&other) noexcept: id(other.id),
                                                  name(std::move(other.name)),
                                                  description(std::move(other.description)),
                                                  subject(std::move(other.subject)),
                                                    grade(other.grade){
}

Assignment & Assignment::operator=(const Assignment &other) {
    if (this == &other)
        return *this;
    id = other.id;
    name = other.name;
    description = other.description;
    subject = other.subject;
    grade = other.grade;
    return *this;
}

Assignment & Assignment::operator=(Assignment &&other) noexcept {
    if (this == &other)
        return *this;
    id = other.id;
    name = std::move(other.name);
    description = std::move(other.description);
    subject = std::move(other.subject);
    grade = other.grade;
    return *this;
}

int Assignment::get_id() const {
    return id;
}

std::string Assignment::get_subject() const {
    return subject;
}

std::string Assignment::get_name() const {
    return name;
}

void Assignment::set_name(const std::string &name) {
    this->name = name;
}

std::string Assignment::get_description() const {
    return description;
}

void Assignment::set_description(const std::string &description) {
    this->description = description;
}

int Assignment::get_grade() const {
    return grade;
}

void Assignment::set_grade(const int grade) {
    this->grade = grade;
}

void Assignment::remove_grade() {
    this->grade = 0;
}

bool Assignment::is_assigment_graded() const {
    return this->grade != 0;
}

bool Assignment::operator==(const Assignment &rhs) const {
    return id == rhs.id
           && name == rhs.name
           && description == rhs.description
           && subject == rhs.subject;
}

bool Assignment::operator!=(const Assignment &rhs) const {
    return !(*this == rhs);
}

std::ostream & operator<<(std::ostream &os, const Assignment &obj) {
    return os
           << "id: " << obj.id
           << " name: " << obj.name
           << " description: " << obj.description
           << " subject: " << obj.subject
           << " grade: " << obj.grade;
}

void swap(Assignment &lhs, Assignment &rhs) noexcept {
    using std::swap;
    swap(lhs.id, rhs.id);
    swap(lhs.name, rhs.name);
    swap(lhs.description, rhs.description);
    swap(lhs.subject, rhs.subject);
    swap(lhs.grade, rhs.grade);
}

