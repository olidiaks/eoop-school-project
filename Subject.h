//
// Created by olidiaks on 4/21/26.
//

#ifndef EOOP_SCHOOL_PROJECT_SUBJECT_H
#define EOOP_SCHOOL_PROJECT_SUBJECT_H
#include <ostream>


enum class Subject {
    None,
    Math,
    English,
    Polish,
    History,
    Biology,
    Physics,
    Chemistry,
    Geography,
    ComputerScience,
    PhysicalEducation,
};

const char *to_string(Subject e);
std::ostream & operator<<(std::ostream &os, Subject subject);


#endif //EOOP_SCHOOL_PROJECT_SUBJECT_H
