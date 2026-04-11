//
// Created by olidiaks on 4/11/26.
//

#include "Person.h"


Person::Person(const int &id, const std::string &first_name, const std::string &last_name, const std::string &email, const int &day, const int &month, const int &year) {
}

std::string Person::get_first_name() const {
    return firstName;
}

void Person::set_first_name(const std::string &first_name) {
    firstName = first_name;
}

std::string Person::get_last_name() const {
    return lastName;
}

void Person::set_last_name(const std::string &last_name) {
    lastName = last_name;
}

int Person::get_id() const {
    return id;
}

time_t Person::get_birth_date() const {
    return birthDate;
}

int Person::get_age() const {
}

bool operator==(const Person &lhs, const Person &rhs) {
    return lhs.id == rhs.id
           && lhs.firstName == rhs.firstName
           && lhs.lastName == rhs.lastName
           && lhs.email == rhs.email
           && lhs.birthDate == rhs.birthDate;
}

bool operator!=(const Person &lhs, const Person &rhs) {
    return !(lhs == rhs);
}

std::ostream & operator<<(std::ostream &os, const Person &obj) {
    return os
           << "id: " << obj.id
           << " firstName: " << obj.firstName
           << " lastName: " << obj.lastName
           << " email: " << obj.email
           << " birthDate: " << obj.birthDate;
}
