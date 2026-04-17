//
// Created by olidiaks on 4/16/26.
//

#include "Subject.h"

int Subject::counter = 0;

Subject::Subject(const std::string &name, Teacher &teacher) :
                                                                            name(name),
                                                                            teacher(teacher) {
    id = ++counter;
    assigments.clear();
}

Subject::Subject(const Subject &other) : id(other.id),
                                         name(other.name),
                                         teacher(other.teacher),
                                         assigments(other.assigments) {
}

Subject::Subject(Subject &&other) noexcept : id(other.id),
                                             name(std::move(other.name)),
                                             teacher(other.teacher),
                                             assigments(std::move(other.assigments)) {
}

Subject &Subject::operator=(const Subject &other) {
    if (this == &other)
        return *this;
    id = other.id;
    name = other.name;
    teacher = other.teacher;
    assigments = other.assigments;
    return *this;
}

Subject &Subject::operator=(Subject &&other) noexcept {
    if (this == &other)
        return *this;
    id = other.id;
    name = std::move(other.name);
    teacher = other.teacher;
    assigments = std::move(other.assigments);
    return *this;
}

int Subject::get_id() const {
    return id;
}

std::string Subject::get_name() const {
    return name;
}

void Subject::set_name(const std::string &name) {
    this->name = name;
}

Teacher Subject::get_teacher() const {
    return teacher;
}

void Subject::set_teacher(const Teacher &teacher) {
    this->teacher = teacher;
}

std::list<Assigment> Subject::get_assigments() const {
    return assigments;
}

void Subject::set_assigments(const std::list<Assigment> &assigments) {
    this->assigments = assigments;
}

bool operator==(const Subject &lhs, const Subject &rhs) {
    return lhs.id == rhs.id
           && lhs.name == rhs.name
           && lhs.teacher == rhs.teacher
           && lhs.assigments == rhs.assigments;
}

bool operator!=(const Subject &lhs, const Subject &rhs) {
    return !(lhs == rhs);
}

std::ostream &operator<<(std::ostream &os, const Subject &obj) {
    return os
           << "id: " << obj.id
           << " name: " << obj.name
           << " teacher: " << obj.teacher
           << " assigments: " << obj.assigments.size();
}

void swap(Subject &lhs, Subject &rhs) noexcept {
    using std::swap;
    swap(lhs.id, rhs.id);
    swap(lhs.name, rhs.name);
    swap(lhs.teacher, rhs.teacher);
    swap(lhs.assigments, rhs.assigments);
}
