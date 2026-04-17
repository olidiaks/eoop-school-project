//
// Created by olidiaks on 4/16/26.
//

#ifndef PROJECT_SUBJECT_H
#define PROJECT_SUBJECT_H
#include <list>
#include <ostream>
#include <string>

#include "Assigment.h"
#include "Teacher.h"


class Subject {
private:
    int id;
    std::string name;
    Teacher &teacher;
    std::list<Assigment> assigments;
    static int counter;

public:
    Subject(const std::string &name, Teacher &teacher);

    ~Subject() = default;

    Subject(const Subject &other);

    Subject(Subject &&other) noexcept;

    Subject &operator=(const Subject &other);

    Subject &operator=(Subject &&other) noexcept;

    friend bool operator==(const Subject &lhs, const Subject &rhs);

    friend bool operator!=(const Subject &lhs, const Subject &rhs);

    friend std::ostream &operator<<(std::ostream &os, const Subject &obj);

    friend void swap(Subject &lhs, Subject &rhs) noexcept;

    [[nodiscard]] int get_id() const;

    [[nodiscard]] std::string get_name() const;

    void set_name(const std::string &name);

    [[nodiscard]] Teacher get_teacher() const;

    void set_teacher(const Teacher &teacher);

    [[nodiscard]] std::list<Assigment> get_assigments() const;

    void set_assigments(const std::list<Assigment> &assigments);
};


#endif //PROJECT_SUBJECT_H
