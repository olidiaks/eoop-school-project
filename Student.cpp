//
// Created by olidiaks on 10.04.2026.
//

#include "Student.h"

void Student::initGrades() {
    throw std::runtime_error("Not implemented");
}


Student::Student(const int &id, const std::string &first_name, const std::string &last_name, const std::string &email,
                 const int &day, const int &month, const int &year): Person(id, first_name, last_name, email, day, month, year) {
    initGrades();
}

Student::Student(const float math_grade, const float english_grade, const float polish_grade, const float history_grade,
    const float biology_grade, const float physics_grade, const float chemistry_grade, const float geography_grade,
    const float computer_science_grade, const float physical_education_grade): mathGrade(math_grade),
                                                                               englishGrade(english_grade),
                                                                               polishGrade(polish_grade),
                                                                               historyGrade(history_grade),
                                                                               biologyGrade(biology_grade),
                                                                               physicsGrade(physics_grade),
                                                                               chemistryGrade(chemistry_grade),
                                                                               geographyGrade(geography_grade),
                                                                               computerScienceGrade(computer_science_grade),
                                                                               physicalEducationGrade(physical_education_grade) {
}

Student::Student(const int &id, const std::string &first_name, const std::string &last_name, const std::string &email,
    const time_t birth_date, const float math_grade, const float english_grade, const float polish_grade,
    const float history_grade, const float biology_grade, const float physics_grade, const float chemistry_grade,
    const float geography_grade, const float computer_science_grade, const float physical_education_grade): Person(id, first_name, last_name, email, birth_date),
    mathGrade(math_grade),
    englishGrade(english_grade),
    polishGrade(polish_grade),
    historyGrade(history_grade),
    biologyGrade(biology_grade),
    physicsGrade(physics_grade),
    chemistryGrade(chemistry_grade),
    geographyGrade(geography_grade),
    computerScienceGrade(computer_science_grade),
    physicalEducationGrade(physical_education_grade) {
}

Student::Student(const int &id, const std::string &first_name, const std::string &last_name, const std::string &email,
    const int &day, const int &month, const int &year, const float math_grade, const float english_grade,
    const float polish_grade, const float history_grade, const float biology_grade, const float physics_grade,
    const float chemistry_grade, const float geography_grade, const float computer_science_grade,
    const float physical_education_grade): Person(id, first_name, last_name, email, day, month, year),
                                           mathGrade(math_grade),
                                           englishGrade(english_grade),
                                           polishGrade(polish_grade),
                                           historyGrade(history_grade),
                                           biologyGrade(biology_grade),
                                           physicsGrade(physics_grade),
                                           chemistryGrade(chemistry_grade),
                                           geographyGrade(geography_grade),
                                           computerScienceGrade(computer_science_grade),
                                           physicalEducationGrade(physical_education_grade) {
}

Student::Student(const Person &other, const float math_grade, const float english_grade, const float polish_grade,
    const float history_grade, const float biology_grade, const float physics_grade, const float chemistry_grade,
    const float geography_grade, const float computer_science_grade, const float physical_education_grade): Person(other),
    mathGrade(math_grade),
    englishGrade(english_grade),
    polishGrade(polish_grade),
    historyGrade(history_grade),
    biologyGrade(biology_grade),
    physicsGrade(physics_grade),
    chemistryGrade(chemistry_grade),
    geographyGrade(geography_grade),
    computerScienceGrade(computer_science_grade),
    physicalEducationGrade(physical_education_grade) {
}

Student::Student(Person &&other, const float math_grade, const float english_grade, const float polish_grade,
    const float history_grade, const float biology_grade, const float physics_grade, const float chemistry_grade,
    const float geography_grade, const float computer_science_grade, const float physical_education_grade): Person(other),
    mathGrade(math_grade),
    englishGrade(english_grade),
    polishGrade(polish_grade),
    historyGrade(history_grade),
    biologyGrade(biology_grade),
    physicsGrade(physics_grade),
    chemistryGrade(chemistry_grade),
    geographyGrade(geography_grade),
    computerScienceGrade(computer_science_grade),
    physicalEducationGrade(physical_education_grade) {
}

float Student::get_math_grade() const {
    return mathGrade;
}

void Student::set_math_grade(const float math_grade) {
    mathGrade = math_grade;
}

float Student::get_english_grade() const {
    return englishGrade;
}

void Student::set_english_grade(const float english_grade) {
    englishGrade = english_grade;
}

float Student::get_polish_grade() const {
    return polishGrade;
}

void Student::set_polish_grade(const float polish_grade) {
    polishGrade = polish_grade;
}

float Student::get_history_grade() const {
    return historyGrade;
}

void Student::set_history_grade(const float history_grade) {
    historyGrade = history_grade;
}

float Student::get_biology_grade() const {
    return biologyGrade;
}

void Student::set_biology_grade(const float biology_grade) {
    biologyGrade = biology_grade;
}

float Student::get_physics_grade() const {
    return physicsGrade;
}

void Student::set_physics_grade(const float physics_grade) {
    physicsGrade = physics_grade;
}

float Student::get_chemistry_grade() const {
    return chemistryGrade;
}

void Student::set_chemistry_grade(const float chemistry_grade) {
    chemistryGrade = chemistry_grade;
}

float Student::get_geography_grade() const {
    return geographyGrade;
}

void Student::set_geography_grade(const float geography_grade) {
    geographyGrade = geography_grade;
}

float Student::get_computer_science_grade() const {
    return computerScienceGrade;
}

void Student::set_computer_science_grade(const float computer_science_grade) {
    computerScienceGrade = computer_science_grade;
}

float Student::get_physical_education_grade() const {
    return physicalEducationGrade;
}

void Student::set_physical_education_grade(const float physical_education_grade) {
    physicalEducationGrade = physical_education_grade;
}

Student::Student() : Person(){
    initGrades();

}

std::ostream & operator<<(std::ostream &os, const Student &obj) {
    return os
           << static_cast<const Person &>(obj)
           << " mathGrade: " << obj.mathGrade
           << " englishGrade: " << obj.englishGrade
           << " polishGrade: " << obj.polishGrade
           << " historyGrade: " << obj.historyGrade
           << " biologyGrade: " << obj.biologyGrade
           << " physicsGrade: " << obj.physicsGrade
           << " chemistryGrade: " << obj.chemistryGrade
           << " geographyGrade: " << obj.geographyGrade
           << " computerScienceGrade: " << obj.computerScienceGrade
           << " physicalEducationGrade: " << obj.physicalEducationGrade;
}

bool operator==(const Student &lhs, const Student &rhs) {
    return static_cast<const Person &>(lhs) == static_cast<const Person &>(rhs)
           && lhs.mathGrade == rhs.mathGrade
           && lhs.englishGrade == rhs.englishGrade
           && lhs.polishGrade == rhs.polishGrade
           && lhs.historyGrade == rhs.historyGrade
           && lhs.biologyGrade == rhs.biologyGrade
           && lhs.physicsGrade == rhs.physicsGrade
           && lhs.chemistryGrade == rhs.chemistryGrade
           && lhs.geographyGrade == rhs.geographyGrade
           && lhs.computerScienceGrade == rhs.computerScienceGrade
           && lhs.physicalEducationGrade == rhs.physicalEducationGrade;
}

bool operator!=(const Student &lhs, const Student &rhs) {
    return !(lhs == rhs);
}

Student::Student(const Student &other): Person(other),
                                        mathGrade(other.mathGrade),
                                        englishGrade(other.englishGrade),
                                        polishGrade(other.polishGrade),
                                        historyGrade(other.historyGrade),
                                        biologyGrade(other.biologyGrade),
                                        physicsGrade(other.physicsGrade),
                                        chemistryGrade(other.chemistryGrade),
                                        geographyGrade(other.geographyGrade),
                                        computerScienceGrade(other.computerScienceGrade),
                                        physicalEducationGrade(other.physicalEducationGrade) {
}

Student::Student(Student &&other) noexcept: Person(std::move(other)),
                                            mathGrade(other.mathGrade),
                                            englishGrade(other.englishGrade),
                                            polishGrade(other.polishGrade),
                                            historyGrade(other.historyGrade),
                                            biologyGrade(other.biologyGrade),
                                            physicsGrade(other.physicsGrade),
                                            chemistryGrade(other.chemistryGrade),
                                            geographyGrade(other.geographyGrade),
                                            computerScienceGrade(other.computerScienceGrade),
                                            physicalEducationGrade(other.physicalEducationGrade) {
}

Student & Student::operator=(const Student &other) {
    if (this == &other)
        return *this;
    Person::operator =(other);
    mathGrade = other.mathGrade;
    englishGrade = other.englishGrade;
    polishGrade = other.polishGrade;
    historyGrade = other.historyGrade;
    biologyGrade = other.biologyGrade;
    physicsGrade = other.physicsGrade;
    chemistryGrade = other.chemistryGrade;
    geographyGrade = other.geographyGrade;
    computerScienceGrade = other.computerScienceGrade;
    physicalEducationGrade = other.physicalEducationGrade;
    return *this;
}

Student & Student::operator=(Student &&other) noexcept {
    if (this == &other)
        return *this;
    Person::operator =(std::move(other));
    mathGrade = other.mathGrade;
    englishGrade = other.englishGrade;
    polishGrade = other.polishGrade;
    historyGrade = other.historyGrade;
    biologyGrade = other.biologyGrade;
    physicsGrade = other.physicsGrade;
    chemistryGrade = other.chemistryGrade;
    geographyGrade = other.geographyGrade;
    computerScienceGrade = other.computerScienceGrade;
    physicalEducationGrade = other.physicalEducationGrade;
    return *this;
}

float Student::get_average_grade() const {
    throw std::runtime_error("Not implemented");
}
