//
// Created by olidiaks on 4/16/26.
//

#include "Assigment.h"

Assigment::Assigment(const int id, const std::string &name, const std::string &description, const int grade) : id(id),
    name(name),
    description(description),
    grade(grade) {
}

Assigment::Assigment(const Assigment &other) : id(other.id),
                                               name(other.name),
                                               description(other.description),
                                               grade(other.grade) {
}

Assigment::Assigment(Assigment &&other) noexcept : id(other.id),
                                                   name(std::move(other.name)),
                                                   description(std::move(other.description)),
                                                   grade(other.grade) {
}

Assigment &Assigment::operator=(const Assigment &other) {
    if (this == &other)
        return *this;
    id = other.id;
    name = other.name;
    description = other.description;
    grade = other.grade;
    return *this;
}

Assigment &Assigment::operator=(Assigment &&other) noexcept {
    if (this == &other)
        return *this;
    id = other.id;
    name = std::move(other.name);
    description = std::move(other.description);
    grade = other.grade;
    return *this;
}

int Assigment::get_id() const {
    return id;
}

std::string Assigment::get_name() const {
    return name;
}

void Assigment::set_name(const std::string &name) {
    this->name = name;
}

std::string Assigment::get_description() const {
    return description;
}

void Assigment::set_description(const std::string &description) {
    this->description = description;
}

int Assigment::get_grade() const {
    return grade;
}

void Assigment::set_grade(const int &grade) {
    this->grade = grade;
}

bool operator==(const Assigment &lhs, const Assigment &rhs) {
    return lhs.id == rhs.id
           && lhs.name == rhs.name
           && lhs.description == rhs.description
           && lhs.grade == rhs.grade;
}

bool operator!=(const Assigment &lhs, const Assigment &rhs) {
    return !(lhs == rhs);
}

std::ostream &operator<<(std::ostream &os, const Assigment &obj) {
    return os
           << "id: " << obj.id
           << " name: " << obj.name
           << " description: " << obj.description
           << " grade: " << obj.grade;
}

void swap(Assigment &lhs, Assigment &rhs) noexcept {
    using std::swap;
    swap(lhs.id, rhs.id);
    swap(lhs.name, rhs.name);
    swap(lhs.description, rhs.description);
    swap(lhs.grade, rhs.grade);
}
