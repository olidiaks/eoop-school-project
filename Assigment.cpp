//
// Created by olidiaks on 4/16/26.
//

#include "Assigment.h"

int Assigment::counter = 0;


Assigment::Assigment(const std::string &name, const std::string &description, const std::string &subject): name(name),
    description(description),
    subject(subject) {
    id = ++counter;
}


Assigment::Assigment(const Assigment &other): id(other.id),
                                              name(other.name),
                                              description(other.description),
                                              subject(other.subject) {
}

Assigment::Assigment(Assigment &&other) noexcept: id(other.id),
                                                  name(std::move(other.name)),
                                                  description(std::move(other.description)),
                                                  subject(std::move(other.subject)) {
}

Assigment & Assigment::operator=(const Assigment &other) {
    if (this == &other)
        return *this;
    id = other.id;
    name = other.name;
    description = other.description;
    subject = other.subject;
    return *this;
}

Assigment & Assigment::operator=(Assigment &&other) noexcept {
    if (this == &other)
        return *this;
    id = other.id;
    name = std::move(other.name);
    description = std::move(other.description);
    subject = std::move(other.subject);
    return *this;
}

int Assigment::get_id() const {
    return id;
}

std::string Assigment::get_subject() const {
    return subject;
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

bool Assigment::operator==(const Assigment &rhs) const {
    return id == rhs.id
           && name == rhs.name
           && description == rhs.description
           && subject == rhs.subject;
}

bool Assigment::operator!=(const Assigment &rhs) const {
    return !(*this == rhs);
}

std::ostream & operator<<(std::ostream &os, const Assigment &obj) {
    return os
           << "id: " << obj.id
           << " name: " << obj.name
           << " description: " << obj.description
           << " subject: " << obj.subject;
}

void swap(Assigment &lhs, Assigment &rhs) noexcept {
    using std::swap;
    swap(lhs.id, rhs.id);
    swap(lhs.name, rhs.name);
    swap(lhs.description, rhs.description);
    swap(lhs.subject, rhs.subject);
}

