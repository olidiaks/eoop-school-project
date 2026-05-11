//
// Created by olidiaks on 10.04.2026.
//

#include "School.h"

#include <algorithm>



School::School() = default;


School::School(const School &other) : teachers(other.teachers),
                                      name(other.name),
                                      classes(other.classes) {
}

School::School(School &&other) noexcept : teachers(std::move(other.teachers)),
                                          classes(std::move(other.classes)),
                                          name(other.name) {
}

School &School::operator=(const School &other) {
    if (this == &other)
        return *this;
    teachers = other.teachers;
    classes = other.classes;
    name = other.name;
    return *this;
}

School &School::operator=(School &&other) noexcept {
    if (this == &other)
        return *this;
    teachers = std::move(other.teachers);
    classes = std::move(other.classes);
    name = std::move(other.name);
    return *this;
}

bool School::operator==(const School &obj) const{
    return teachers == obj.teachers
           && classes == obj.classes
           && name == obj.name;
}

bool School::operator!=(const School &rhs) const {
    return !(*this == rhs);
}



std::ostream & operator<<(std::ostream &os, const School &obj) {
    return os
           << "teachers: " << obj.teachers
           << " classes: " << obj.classes
           << " name: " << obj.name;
}

void swap(School &lhs, School &rhs) noexcept {
    using std::swap;
    swap(lhs.mathTeachers, rhs.mathTeachers);
    swap(lhs.englishTeachers, rhs.englishTeachers);
    swap(lhs.polishTeachers, rhs.polishTeachers);
    swap(lhs.historyTeachers, rhs.historyTeachers);
    swap(lhs.biologyTeachers, rhs.biologyTeachers);
    swap(lhs.physicsTeachers, rhs.physicsTeachers);
    swap(lhs.chemistryTeachers, rhs.chemistryTeachers);
    swap(lhs.geographyTeachers, rhs.geographyTeachers);
    swap(lhs.computerScienceTeachers, rhs.computerScienceTeachers);
    swap(lhs.physicalEducationTeachers, rhs.physicalEducationTeachers);
    swap(lhs.superVisingTeachers, rhs.superVisingTeachers);
    swap(lhs.classes, rhs.classes);
    swap(lhs.name, rhs.name);
}

std::list<Teacher> School::get_math_teachers() const {
    return mathTeachers;
}

void School::set_math_teachers(const std::list<Teacher> &math_teachers) {
    mathTeachers = math_teachers;
}

std::list<Teacher> School::get_english_teachers() const {
    return englishTeachers;
}

void School::set_english_teachers(const std::list<Teacher> &english_teachers) {
    englishTeachers = english_teachers;
}

std::list<Teacher> School::get_polish_teachers() const {
    return polishTeachers;
}

void School::set_polish_teachers(const std::list<Teacher> &polish_teachers) {
    polishTeachers = polish_teachers;
}

std::list<Teacher> School::get_history_teachers() const {
    return historyTeachers;
}

void School::set_history_teachers(const std::list<Teacher> &history_teachers) {
    historyTeachers = history_teachers;
}

std::list<Teacher> School::get_biology_teachers() const {
    return biologyTeachers;
}

void School::set_biology_teachers(const std::list<Teacher> &biology_teachers) {
    biologyTeachers = biology_teachers;
}

std::list<Teacher> School::get_physics_teachers() const {
    return physicsTeachers;
}

void School::set_physics_teachers(const std::list<Teacher> &physics_teachers) {
    physicsTeachers = physics_teachers;
}

std::list<Teacher> School::get_chemistry_teachers() const {
    return chemistryTeachers;
}

void School::set_chemistry_teachers(const std::list<Teacher> &chemistry_teachers) {
    chemistryTeachers = chemistry_teachers;
}

std::list<Teacher> School::get_geography_teachers() const {
    return geographyTeachers;
}

void School::set_geography_teachers(const std::list<Teacher> &geography_teachers) {
    geographyTeachers = geography_teachers;
}

std::list<Teacher> School::get_computer_science_teachers() const {
    return computerScienceTeachers;
}

void School::set_computer_science_teachers(const std::list<Teacher> &computer_science_teachers) {
    computerScienceTeachers = computer_science_teachers;
}

std::list<Teacher> School::get_physical_education_teachers() const {
    return physicalEducationTeachers;
}

void School::set_physical_education_teachers(const std::list<Teacher> &physical_education_teachers) {
    physicalEducationTeachers = physical_education_teachers;
}

std::list<Teacher> School::get_super_vising_teachers() const {
    return superVisingTeachers;
}

void School::set_super_vising_teachers(const std::list<Teacher> &super_vising_teachers) {
    superVisingTeachers = super_vising_teachers;
}

std::list<Class> School::get_classes() const {
    return classes;
}

void School::set_classes(const std::list<Class> &classes) {
    this->classes = classes;
}

float School::get_average_students_grades_of_teacher(const int &id) const {
    throw std::runtime_error("Not implemented");
}

std::string School::get_name() const {
    return name;
}

void School::set_name(const std::string &name) {
    this->name = name;
}

void School::new_school_year() {
    for (auto &i: classes) {
        i.new_school_year();
    }
}

void School::add_class(const Class &class_to_add) {
    classes.push_back(class_to_add);
}


void School::add_class(const Teacher &super_vising_teacher, const std::map<Subject, Teacher &> &teachers, char letter,
    std::vector<Student> &students) {
    classes.emplace_back(letter, super_vising_teacher, teachers, students);
}

Class &School::add_class(const Teacher &super_vising_teacher, const std::map<Subject, Teacher &> &teachers, char letter) {
    classes.emplace_back(letter, super_vising_teacher, teachers);
    return classes.back();
}

Class &School::add_class(const Teacher &super_vising_teacher, const std::vector<Student> &students, char letter) {
    classes.emplace_back(letter, super_vising_teacher, students);
    return classes.back();
}

void School::remove_class(int year, char letter) {
    auto it = std::ranges::find_if(classes, [year, letter](const Class &c) {
        return c.get_year() == year && c.get_letter() == letter;
    });
    if (it != classes.end()) {
        classes.erase(it);
    }
}

void School::hire_teacher(Teacher &teacher) {
    switch (teacher.get_subject()) {
        case Subject::Math:
            mathTeachers.push_back(teacher);
            break;
        case Subject::English:
            englishTeachers.push_back(teacher);
            break;
        case Subject::Polish:
            polishTeachers.push_back(teacher);
            break;
        case Subject::None:
            break;
        case Subject::History:
            historyTeachers.push_back(teacher);
            break;
        case Subject::Biology:
            biologyTeachers.push_back(teacher);
            break;
        case Subject::Physics:
            physicsTeachers.push_back(teacher);
            break;
        case Subject::Chemistry:
            chemistryTeachers.push_back(teacher);
            break;
        case Subject::Geography:
            geographyTeachers.push_back(teacher);
            break;
        case Subject::ComputerScience:
            computerScienceTeachers.push_back(teacher);
            break;
        case Subject::PhysicalEducation:
            physicalEducationTeachers.push_back(teacher);
            break;
    }
}

void School::hire_teacher(const std::string &first_name, const std::string &last_name, const std::string &email,
                          const int &day, const int &month, const int &year, const int salary, const Subject &subject) {
    switch (subject) {
        case Subject::None:
            break;
        case Subject::Math:
            mathTeachers.emplace_back(first_name, last_name, email, day, month, year, salary, subject);
            break;
        case Subject::English:
            englishTeachers.emplace_back(first_name, last_name, email, day, month, year, salary, subject);
            break;
        case Subject::Polish:
            polishTeachers.emplace_back(first_name, last_name, email, day, month, year, salary, subject);
            break;
        case Subject::History:
            historyTeachers.emplace_back(first_name, last_name, email, day, month, year, salary, subject);
            break;
        case Subject::Biology:
            biologyTeachers.emplace_back(first_name, last_name, email, day, month, year, salary, subject);
            break;
        case Subject::Physics:
            physicsTeachers.emplace_back(first_name, last_name, email, day, month, year, salary, subject);
            break;
        case Subject::Chemistry:
            chemistryTeachers.emplace_back(first_name, last_name, email, day, month, year, salary, subject);
            break;
        case Subject::Geography:
            geographyTeachers.emplace_back(first_name, last_name, email, day, month, year, salary, subject);
            break;
        case Subject::ComputerScience:
            computerScienceTeachers.emplace_back(first_name, last_name, email, day, month, year, salary, subject);
            break;
        case Subject::PhysicalEducation:
            physicalEducationTeachers.emplace_back(first_name, last_name, email, day, month, year, salary, subject);
            break;
    }
}

void School::fire_teacher(const int &id) {
    Teacher p;
    swap(find_teacher(id), p);
}

void School::fire_teacher(const std::string &firstname, const std::string &lastname) {
    Teacher p;
    swap(find_teacher(firstname, lastname), p);
}
