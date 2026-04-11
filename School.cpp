//
// Created by olidiaks on 10.04.2026.
//

#include "School.h"

std::string School::print() const {
    throw std::runtime_error("Not implemented");
}

School::School() {
    mathTeachers = {};
    englishTeachers = {};
    polishTeachers = {};
    historyTeachers = {};
    biologyTeachers = {};
    physicsTeachers = {};
    chemistryTeachers = {};
    geographyTeachers = {};
    computerScienceTeachers = {};
    physicalEducationTeachers = {};
    superVisingTeachers = {};
    classes = {};
}

School::School(const std::list<Teacher> &math_teachers, const std::list<Teacher> &english_teachers,
               const std::list<Teacher> &polish_teachers, const std::list<Teacher> &history_teachers,
               const std::list<Teacher> &biology_teachers, const std::list<Teacher> &physics_teachers,
               const std::list<Teacher> &chemistry_teachers, const std::list<Teacher> &geography_teachers,
               const std::list<Teacher> &computer_science_teachers, const std::list<Teacher> &physical_education_teachers,
               const std::list<Teacher> &super_vising_teachers, const std::list<Class> &classes): mathTeachers(math_teachers),
                                                                                                  englishTeachers(english_teachers),
                                                                                                  polishTeachers(polish_teachers),
                                                                                                  historyTeachers(history_teachers),
                                                                                                  biologyTeachers(biology_teachers),
                                                                                                  physicsTeachers(physics_teachers),
                                                                                                  chemistryTeachers(chemistry_teachers),
                                                                                                  geographyTeachers(geography_teachers),
                                                                                                  computerScienceTeachers(computer_science_teachers),
                                                                                                  physicalEducationTeachers(physical_education_teachers),
                                                                                                  superVisingTeachers(super_vising_teachers),
                                                                                                  classes(classes) {
}

School::School(const School &other): mathTeachers(other.mathTeachers),
                                     englishTeachers(other.englishTeachers),
                                     polishTeachers(other.polishTeachers),
                                     historyTeachers(other.historyTeachers),
                                     biologyTeachers(other.biologyTeachers),
                                     physicsTeachers(other.physicsTeachers),
                                     chemistryTeachers(other.chemistryTeachers),
                                     geographyTeachers(other.geographyTeachers),
                                     computerScienceTeachers(other.computerScienceTeachers),
                                     physicalEducationTeachers(other.physicalEducationTeachers),
                                     superVisingTeachers(other.superVisingTeachers),
                                     classes(other.classes) {
}

School::School(School &&other) noexcept: mathTeachers(std::move(other.mathTeachers)),
                                         englishTeachers(std::move(other.englishTeachers)),
                                         polishTeachers(std::move(other.polishTeachers)),
                                         historyTeachers(std::move(other.historyTeachers)),
                                         biologyTeachers(std::move(other.biologyTeachers)),
                                         physicsTeachers(std::move(other.physicsTeachers)),
                                         chemistryTeachers(std::move(other.chemistryTeachers)),
                                         geographyTeachers(std::move(other.geographyTeachers)),
                                         computerScienceTeachers(std::move(other.computerScienceTeachers)),
                                         physicalEducationTeachers(std::move(other.physicalEducationTeachers)),
                                         superVisingTeachers(std::move(other.superVisingTeachers)),
                                         classes(std::move(other.classes)) {
}

School & School::operator=(const School &other) {
    if (this == &other)
        return *this;
    mathTeachers = other.mathTeachers;
    englishTeachers = other.englishTeachers;
    polishTeachers = other.polishTeachers;
    historyTeachers = other.historyTeachers;
    biologyTeachers = other.biologyTeachers;
    physicsTeachers = other.physicsTeachers;
    chemistryTeachers = other.chemistryTeachers;
    geographyTeachers = other.geographyTeachers;
    computerScienceTeachers = other.computerScienceTeachers;
    physicalEducationTeachers = other.physicalEducationTeachers;
    superVisingTeachers = other.superVisingTeachers;
    classes = other.classes;
    return *this;
}

School & School::operator=(School &&other) noexcept {
    if (this == &other)
        return *this;
    mathTeachers = std::move(other.mathTeachers);
    englishTeachers = std::move(other.englishTeachers);
    polishTeachers = std::move(other.polishTeachers);
    historyTeachers = std::move(other.historyTeachers);
    biologyTeachers = std::move(other.biologyTeachers);
    physicsTeachers = std::move(other.physicsTeachers);
    chemistryTeachers = std::move(other.chemistryTeachers);
    geographyTeachers = std::move(other.geographyTeachers);
    computerScienceTeachers = std::move(other.computerScienceTeachers);
    physicalEducationTeachers = std::move(other.physicalEducationTeachers);
    superVisingTeachers = std::move(other.superVisingTeachers);
    classes = std::move(other.classes);
    return *this;
}

bool operator==(const School &lhs, const School &rhs) {
    return lhs.mathTeachers == rhs.mathTeachers
           && lhs.englishTeachers == rhs.englishTeachers
           && lhs.polishTeachers == rhs.polishTeachers
           && lhs.historyTeachers == rhs.historyTeachers
           && lhs.biologyTeachers == rhs.biologyTeachers
           && lhs.physicsTeachers == rhs.physicsTeachers
           && lhs.chemistryTeachers == rhs.chemistryTeachers
           && lhs.geographyTeachers == rhs.geographyTeachers
           && lhs.computerScienceTeachers == rhs.computerScienceTeachers
           && lhs.physicalEducationTeachers == rhs.physicalEducationTeachers
           && lhs.superVisingTeachers == rhs.superVisingTeachers
           && lhs.classes == rhs.classes;
}

bool operator!=(const School &lhs, const School &rhs) {
    return !(lhs == rhs);
}

std::ostream & operator<<(std::ostream &os, const School &obj) {
    return os
           << obj.print();
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
