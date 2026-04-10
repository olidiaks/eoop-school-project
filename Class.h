//
// Created by olidiaks on 10.04.2026.
//

#ifndef PROJECT_CLASS_H
#define PROJECT_CLASS_H
#include "Student.h"
#include "Teacher.h"


class Class {
private:
    int classId;
    static int classCount;
    Teacher *matchTeacher;
    Teacher *englishTeacher;
    Teacher *polishTeacher;
    Teacher *historyTeacher;
    Teacher *biologyTeacher;
    Teacher *physicsTeacher;
    Teacher *chemistryTeacher;
    Teacher *geographyTeacher;
    Teacher *computerScienceTeacher;
    Teacher *physicalEducationTeacher;
    Teacher *superVisingTeacher;
    Student students[25];

public:
    Class(const int class_id, Teacher * const match_teacher, Teacher * const english_teacher,
    Teacher * const polish_teacher, Teacher * const history_teacher, Teacher * const biology_teacher,
        Teacher * const physics_teacher, Teacher * const chemistry_teacher, Teacher * const geography_teacher,
        Teacher * const computer_science_teacher, Teacher * const physical_education_teacher,
        Teacher * const super_vising_teacher);

    int get_class_id() const {
        return classId;
    }
 Teacher * get_match_teacher() const {
        return matchTeacher;
    }

    void set_match_teacher(Teacher * const match_teacher) {
        matchTeacher = match_teacher;
    }

    Teacher * get_english_teacher() const {
        return englishTeacher;
    }

    void set_english_teacher(Teacher * const english_teacher) {
        englishTeacher = english_teacher;
    }

    Teacher * get_polish_teacher() const {
        return polishTeacher;
    }

    void set_polish_teacher(Teacher * const polish_teacher) {
        polishTeacher = polish_teacher;
    }

    Teacher * get_history_teacher() const {
        return historyTeacher;
    }

    void set_history_teacher(Teacher * const history_teacher) {
        historyTeacher = history_teacher;
    }

    Teacher * get_biology_teacher() const {
        return biologyTeacher;
    }

    void set_biology_teacher(Teacher * const biology_teacher) {
        biologyTeacher = biology_teacher;
    }

    Teacher * get_physics_teacher() const {
        return physicsTeacher;
    }

    void set_physics_teacher(Teacher * const physics_teacher) {
        physicsTeacher = physics_teacher;
    }

    Teacher * get_chemistry_teacher() const {
        return chemistryTeacher;
    }

    void set_chemistry_teacher(Teacher * const chemistry_teacher) {
        chemistryTeacher = chemistry_teacher;
    }

    Teacher * get_geography_teacher() const {
        return geographyTeacher;
    }

    void set_geography_teacher(Teacher * const geography_teacher) {
        geographyTeacher = geography_teacher;
    }

    Teacher * get_computer_science_teacher() const {
        return computerScienceTeacher;
    }

    void set_computer_science_teacher(Teacher * const computer_science_teacher) {
        computerScienceTeacher = computer_science_teacher;
    }

    Teacher * get_physical_education_teacher() const {
        return physicalEducationTeacher;
    }

    void set_physical_education_teacher(Teacher * const physical_education_teacher) {
        physicalEducationTeacher = physical_education_teacher;
    }

    Teacher * get_super_vising_teacher() const {
        return superVisingTeacher;
    }

    void set_super_vising_teacher(Teacher * const super_vising_teacher) {
        superVisingTeacher = super_vising_teacher;
    }
};


#endif //PROJECT_CLASS_H