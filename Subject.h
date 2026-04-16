//
// Created by olidiaks on 4/16/26.
//

#ifndef PROJECT_SUBJECT_H
#define PROJECT_SUBJECT_H
#include <list>
#include <string>

#include "Assigment.h"
#include "Teacher.h"


class Subject {
private:
    int id;
    std::string name;
    Teacher &teacher;
    std::list<Assigment> assigments;

public:
    Subject(const int id, const std::string &name, Teacher &teacher);

    ~Subject() = default;

    Subject(const Subject &other);

    Subject(Subject &&other) noexcept;

    Subject &operator=(const Subject &other);

    Subject &operator=(Subject &&other) noexcept;

    friend bool operator==(const Subject &lhs, const Subject &rhs);

    friend bool operator!=(const Subject &lhs, const Subject &rhs);
};


#endif //PROJECT_SUBJECT_H
