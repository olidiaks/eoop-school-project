//
// Created by olidiaks on 4/18/26.
//

#include "Assigment_graded.h"

int Assigment_graded::counter = 0;

Assigment_graded::Assigment_graded(const Assigment &assigment) : assigment(assigment) {
    grade = 0;
    id = ++counter;
    is_graded = false;
}

Assigment_graded::Assigment_graded(const Assigment &assigment, const int grade) : assigment(assigment),
                                                                            grade(grade) {
    is_graded = true;
    id = ++counter;
}

Assigment_graded::Assigment_graded(const Assigment_graded &other) : assigment(other.assigment),
                                                                    grade(other.grade), id(other.id),
                                                                    is_graded(other.is_graded) {
}

Assigment_graded::Assigment_graded(Assigment_graded &&other) noexcept : assigment(other.assigment),
                                                                        grade(other.grade), id(other.id),
                                                                        is_graded(other.is_graded) {
}

Assigment_graded & Assigment_graded::operator=(const Assigment_graded &other) {
    if (this == &other)
        return *this;
    assigment = other.assigment;
    grade = other.grade;
    id = other.id;
    is_graded = other.is_graded;
    return *this;
}

Assigment_graded & Assigment_graded::operator=(Assigment_graded &&other) noexcept {
    if (this == &other)
        return *this;
    assigment = std::move(other.assigment);
    grade = other.grade;
    id = other.id;
    is_graded = other.is_graded;
    return *this;
}


int Assigment_graded::get_grade() const {
    return grade;
}

void Assigment_graded::set_grade(const int grade) {
    this->grade = grade;
}

Assigment Assigment_graded::get_assigment() const {
    return assigment;
}

int Assigment_graded::get_id() const {
    return id;
}

bool operator==(const Assigment_graded &lhs, const Assigment_graded &rhs) {
    return lhs.id == rhs.id
           && lhs.assigment == rhs.assigment
           && lhs.grade == rhs.grade
           && lhs.is_graded == rhs.is_graded;
}

bool operator!=(const Assigment_graded &lhs, const Assigment_graded &rhs) {
    return !(lhs == rhs);
}

std::ostream &operator<<(std::ostream &os, const Assigment_graded &obj) {
    return os
           << "id: " << obj.id
           << " is_graded: " << obj.is_graded
           << " grade: " << obj.grade
           << " assigment: " << obj.assigment;
}

