//
// Created by olidiaks on 10.04.2026.
//

#include "Student.h"

void Student::initGrades() {
    throw std::runtime_error("Not implemented");
}

int Student::get_math_grade() const {
    return mathGrade;
}

void Student::set_math_grade(const int math_grade) {
    mathGrade = math_grade;
}

int Student::get_english_grade() const {
    return englishGrade;
}

void Student::set_english_grade(const int english_grade) {
    englishGrade = english_grade;
}

int Student::get_polish_grade() const {
    return polishGrade;
}

void Student::set_polish_grade(const int polish_grade) {
    polishGrade = polish_grade;
}

int Student::get_history_grade() const {
    return historyGrade;
}

void Student::set_history_grade(const int history_grade) {
    historyGrade = history_grade;
}

int Student::get_biology_grade() const {
    return biologyGrade;
}

void Student::set_biology_grade(const int biology_grade) {
    biologyGrade = biology_grade;
}

int Student::get_physics_grade() const {
    return physicsGrade;
}

void Student::set_physics_grade(const int physics_grade) {
    physicsGrade = physics_grade;
}

int Student::get_chemistry_grade() const {
    return chemistryGrade;
}

void Student::set_chemistry_grade(const int chemistry_grade) {
    chemistryGrade = chemistry_grade;
}

int Student::get_geography_grade() const {
    return geographyGrade;
}

void Student::set_geography_grade(const int geography_grade) {
    geographyGrade = geography_grade;
}

int Student::get_computer_science_grade() const {
    return computerScienceGrade;
}

void Student::set_computer_science_grade(const int computer_science_grade) {
    computerScienceGrade = computer_science_grade;
}

int Student::get_physical_education_grade() const {
    return physicalEducationGrade;
}

void Student::set_physical_education_grade(const int physical_education_grade) {
    physicalEducationGrade = physical_education_grade;
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

int Student::get_average_grade() const {
    throw std::runtime_error("Not implemented");
}
