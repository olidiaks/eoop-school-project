//
// Created by olidiaks on 10.04.2026.
//

#ifndef PROJECT_STUDENT_H
#define PROJECT_STUDENT_H

#include <list>
#include <vector>
#include <ostream>

#include "Assigment.h"
#include "Assigment_graded.h"
#include "Person.h"


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

std::ostream & operator<<(std::ostream & os, const std::list<Assigment_graded> & assignment_list);

class Student : public Person {
private:
    std::list<Assigment_graded> mathAssignments;
    std::list<Assigment_graded> englishAssignments;
    std::list<Assigment_graded> polishAssignments;
    std::list<Assigment_graded> historyAssignments;
    std::list<Assigment_graded> biologyAssignments;
    std::list<Assigment_graded> physicsAssignments;
    std::list<Assigment_graded> chemistryAssignments;
    std::list<Assigment_graded> geographyAssignments;
    std::list<Assigment_graded> computerScienceAssignments;
    std::list<Assigment_graded> physicalEducationAssignments;

    [[nodiscard]] static float get_average_grades_from_subject(const std::list<Assigment_graded> &assignments);

public:
    Student(const std::string &first_name, const std::string &last_name, const std::string &email,
            const time_t birth_date);

    Student(const std::string &first_name, const std::string &last_name, const std::string &email,
            const int &day, const int &month, const int &year);

    [[nodiscard]] float get_average_grade() const;

    [[nodiscard]] const std::list<Assigment_graded> &get_assignments_from_subject(const Subject &subject) const;

    [[nodiscard]] int get_sum_of_grades_from_students_subjects(const Subject &subject) const;

    int get_count_of_grades_from_students_subjects(const Subject &subject) const;

    [[nodiscard]] float get_average_grade_from_math() const;

    [[nodiscard]] float get_average_grade_from_english() const;

    [[nodiscard]] float get_average_grade_from_polish() const;

    [[nodiscard]] float get_average_grade_from_history() const;

    [[nodiscard]] float get_average_grade_from_biology() const;

    [[nodiscard]] float get_average_grade_from_physics() const;

    [[nodiscard]] float get_average_grade_from_chemistry() const;

    [[nodiscard]] float get_average_grade_from_geography() const;

    [[nodiscard]] float get_average_grade_from_computer_science() const;

    [[nodiscard]] float get_average_grade_from_physical_education() const;

    void add_assignment(const Subject &subject, const Assigment &assigment);

    void add_assignment(const Subject &subject, const std::string &name, const std::string &description);

    void add_assignment(const Subject &subject, const Assigment &assigment, int grade);

    void add_assignment(const Subject &subject, const Assigment_graded &assigment);

    void add_assignment(const Subject &subject, Assigment_graded &assigment_graded, const int grade);

    [[nodiscard]] const std::list<Assigment_graded> & get_math_assignments() const;

    [[nodiscard]] const std::list<Assigment_graded> & get_english_assignments() const;

    [[nodiscard]] const std::list<Assigment_graded> & get_polish_assignments() const;

    [[nodiscard]] const std::list<Assigment_graded> & get_history_assignments() const;

    [[nodiscard]] const std::list<Assigment_graded> & get_biology_assignments() const;

    [[nodiscard]] const std::list<Assigment_graded> & get_physics_assignments() const;

    [[nodiscard]] const std::list<Assigment_graded> & get_chemistry_assignments() const;

    [[nodiscard]] const std::list<Assigment_graded> & get_geography_assignments() const;

    [[nodiscard]] const std::list<Assigment_graded> & get_computer_science_assignments() const;

    [[nodiscard]] const std::list<Assigment_graded> & get_physical_education_assignments() const;

    friend bool operator==(const Student &lhs, const Student &rhs);

    friend bool operator!=(const Student &lhs, const Student &rhs);

    friend std::ostream & operator<<(std::ostream &os, const Student &obj);

    friend std::ostream & stream_assignments(std::ostream & os, const Subject &subject, const Student &obj);
};

std::ostream & operator<<(std::ostream &os, Subject subject);

#endif //PROJECT_STUDENT_H
