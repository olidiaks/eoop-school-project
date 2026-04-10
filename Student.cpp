//
// Created by olidiaks on 10.04.2026.
//

#include "Student.h"

Student::Student(const std::string &first_name, const std::string &last_name, const int student_id, const int age): firstName(first_name),
    lastName(last_name),
    studentID(student_id),
    age(age) {
    studentsCount ++;
}

std::string Student::first_name() const {
    return firstName;
}

void Student::set_first_name(const std::string &first_name) {
    firstName = first_name;
}

std::string Student::get_last_name() const {
    return lastName;
}

void Student::set_last_name(const std::string &last_name) {
    lastName = last_name;
}

int Student::get_student_id() const {
    return studentID;
}

void Student::set_student_id(int student_id) {
    studentID = student_id;
}

int Student::get_age() const {
    return age;
}

void Student::set_age(int age) {
    this->age = age;
}

