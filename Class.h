//
// Created by olidiaks on 10.04.2026.
//

#ifndef PROJECT_CLASS_H
#define PROJECT_CLASS_H
#include "Student.h"
#include "Teacher.h"


class Class {
public:

int get_class_id() const;

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

};


#endif //PROJECT_CLASS_H