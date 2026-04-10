//
// Created by olidiaks on 10.04.2026.
//

#include "Class.h"

Class::Class(const int class_id, Teacher * const match_teacher, Teacher * const english_teacher,
    Teacher * const polish_teacher, Teacher * const history_teacher, Teacher * const biology_teacher,
    Teacher * const physics_teacher, Teacher * const chemistry_teacher, Teacher * const geography_teacher,
    Teacher * const computer_science_teacher, Teacher * const physical_education_teacher,
    Teacher * const super_vising_teacher): classId(class_id),
                                           matchTeacher(match_teacher),
                                           englishTeacher(english_teacher),
                                           polishTeacher(polish_teacher),
                                           historyTeacher(history_teacher),
                                           biologyTeacher(biology_teacher),
                                           physicsTeacher(physics_teacher),
                                           chemistryTeacher(chemistry_teacher),
                                           geographyTeacher(geography_teacher),
                                           computerScienceTeacher(computer_science_teacher),
                                           physicalEducationTeacher(physical_education_teacher),
                                           superVisingTeacher(super_vising_teacher) {
}

void Class::set_match_teacher(Teacher * const match_teacher) {
    matchTeacher = match_teacher;
}

Teacher * Class::get_english_teacher() const {
    return englishTeacher;
}

void Class::set_english_teacher(Teacher * const english_teacher) {
    englishTeacher = english_teacher;
}

Teacher * Class::get_polish_teacher() const {
    return polishTeacher;
}

void Class::set_polish_teacher(Teacher * const polish_teacher) {
    polishTeacher = polish_teacher;
}

Teacher * Class::get_history_teacher() const {
    return historyTeacher;
}

void Class::set_history_teacher(Teacher * const history_teacher) {
    historyTeacher = history_teacher;
}

Teacher * Class::get_biology_teacher() const {
    return biologyTeacher;
}

void Class::set_biology_teacher(Teacher * const biology_teacher) {
    biologyTeacher = biology_teacher;
}

Teacher * Class::get_physics_teacher() const {
    return physicsTeacher;
}

void Class::set_physics_teacher(Teacher * const physics_teacher) {
    physicsTeacher = physics_teacher;
}

Teacher * Class::get_chemistry_teacher() const {
    return chemistryTeacher;
}

void Class::set_chemistry_teacher(Teacher * const chemistry_teacher) {
    chemistryTeacher = chemistry_teacher;
}

Teacher * Class::get_geography_teacher() const {
    return geographyTeacher;
}

void Class::set_geography_teacher(Teacher * const geography_teacher) {
    geographyTeacher = geography_teacher;
}

Teacher * Class::get_computer_science_teacher() const {
    return computerScienceTeacher;
}

void Class::set_computer_science_teacher(Teacher * const computer_science_teacher) {
    computerScienceTeacher = computer_science_teacher;
}

Teacher * Class::get_physical_education_teacher() const {
    return physicalEducationTeacher;
}

void Class::set_physical_education_teacher(Teacher * const physical_education_teacher) {
    physicalEducationTeacher = physical_education_teacher;
}

Teacher * Class::get_super_vising_teacher() const {
    return superVisingTeacher;
}

void Class::set_super_vising_teacher(Teacher * const super_vising_teacher) {
    superVisingTeacher = super_vising_teacher;
}
