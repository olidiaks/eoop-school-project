//
// Created by olidiaks on 4/18/26.
//

#ifndef EOOP_SCHOOL_PROJECT_ASSIGEMNT_GRADED_H
#define EOOP_SCHOOL_PROJECT_ASSIGEMNT_GRADED_H
#include <ostream>

#include "Assigment.h"


class Assigment_graded {
private:
    static int counter;
    int id;
    Assigment assigment;
    int grade;
    bool is_graded;

public:
    Assigment_graded(const Assigment &assigment);

    Assigment_graded(const Assigment &assigment, const int grade);

    Assigment_graded(const Assigment_graded &other);

    Assigment_graded(Assigment_graded &&other) noexcept;

    Assigment_graded & operator=(const Assigment_graded &other);

    Assigment_graded & operator=(Assigment_graded &&other) noexcept;

    [[nodiscard]] int get_grade() const;

    void set_grade(const int grade);

    [[nodiscard]] Assigment get_assigment() const;

    [[nodiscard]] int get_id() const;

    friend bool operator==(const Assigment_graded &lhs, const Assigment_graded &rhs);

    friend bool operator!=(const Assigment_graded &lhs, const Assigment_graded &rhs);

    friend std::ostream & operator<<(std::ostream &os, const Assigment_graded &obj);
};



#endif //EOOP_SCHOOL_PROJECT_ASSIGEMNT_GRADED_H
