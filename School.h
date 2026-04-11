//
// Created by olidiaks on 10.04.2026.
//

#ifndef PROJECT_SCHOOL_H
#define PROJECT_SCHOOL_H
#include <list>

#include "Class.h"
#include "Teacher.h"


class School {
private:
    std::list<Teacher> mathTeachers;
    std::list<Teacher> englishTeachers;
    std::list<Teacher> polishTeachers;
    std::list<Teacher> historyTeachers;
    std::list<Teacher> biologyTeachers;
    std::list<Teacher> physicsTeachers;
    std::list<Teacher> chemistryTeachers;
    std::list<Teacher> geographyTeachers;
    std::list<Teacher> computerScienceTeachers;
    std::list<Teacher> physicalEducationTeachers;
    std::list<Teacher> superVisingTeachers;
    std::list<Class> classes;

};


#endif //PROJECT_SCHOOL_H