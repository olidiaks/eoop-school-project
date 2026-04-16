//
// Created by olidiaks on 4/16/26.
//

#include "Subject.h"

Subject::Subject(const int id, const std::string &name, Teacher &teacher) : id(id),
                                                                            name(name),
                                                                            teacher(teacher) {
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

bool operator==(const Subject &lhs, const Subject &rhs) {
    return lhs.id == rhs.id
           && lhs.name == rhs.name
           && lhs.teacher == rhs.teacher
           && lhs.assigments == rhs.assigments;
}

bool operator!=(const Subject &lhs, const Subject &rhs) {
    return !(lhs == rhs);
}
