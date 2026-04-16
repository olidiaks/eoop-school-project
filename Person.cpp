//
// Created by olidiaks on 4/11/26.
//

#include "Person.h"


Person::Person() {
    id = -1;
    firstName = "";
    lastName = "";
    email = "";
    birthDate = 0;
}

Person::Person(const int &id, const std::string &first_name, const std::string &last_name, const std::string &email,
               const time_t birth_date) : id(id),
                                          firstName(first_name),
                                          lastName(last_name),
                                          email(email),
                                          birthDate(birth_date) {
}

Person::Person(const int &id, const std::string &first_name, const std::string &last_name, const std::string &email,
               const int &day, const int &month, const int &year) {
    throw std::runtime_error("Not implemented yet.");
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

int Person::get_day_of_birth() const {
    return localtime(&birthDate)->tm_mday;
}

int Person::get_month_of_birth() const {
    return localtime(&birthDate)->tm_mon + 1;
}

int Person::get_year_of_birth() const {
    return localtime(&birthDate)->tm_year + 1900;
}

std::string Person::get_email() const {
    return email;
}

void Person::set_email(const std::string &email) {
    this->email = email;
}

Person::Person(const Person &other) : id(other.id),
                                      firstName(other.firstName),
                                      lastName(other.lastName),
                                      email(other.email),
                                      birthDate(other.birthDate) {
}

Person::Person(Person &&other) noexcept : id(other.id),
                                          firstName(std::move(other.firstName)),
                                          lastName(std::move(other.lastName)),
                                          email(std::move(other.email)),
                                          birthDate(other.birthDate) {
}

Person &Person::operator=(const Person &other) {
    if (this == &other)
        return *this;
    id = other.id;
    firstName = other.firstName;
    lastName = other.lastName;
    email = other.email;
    birthDate = other.birthDate;
    return *this;
}

Person &Person::operator=(Person &&other) noexcept {
    if (this == &other)
        return *this;
    id = other.id;
    firstName = std::move(other.firstName);
    lastName = std::move(other.lastName);
    email = std::move(other.email);
    birthDate = other.birthDate;
    return *this;
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

std::ostream &operator<<(std::ostream &os, const Person &obj) {
    return os
           << "id: " << obj.id
           << " firstName: " << obj.firstName
           << " lastName: " << obj.lastName
           << " email: " << obj.email
           << " age: " << obj.get_age()
           << "Date of birth: " << obj.get_day_of_birth()
           << "." << obj.get_month_of_birth()
           << "." << obj.get_year_of_birth();
}
