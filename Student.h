//
// Created by olidiaks on 10.04.2026.
//

#ifndef PROJECT_STUDENT_H
#define PROJECT_STUDENT_H

#include <list>
#include <map>
#include <ostream>
#include <vector>

#include "Assignment.h"
#include "Person.h"
#include "Subject.h"


/**
 * Overloads the operator for performing a specific operation on the object.
 *
 * @param other The object to be used in the operation with the current instance.
 * @return A new object representing the result of the operation.
 */
std::ostream & operator<<(std::ostream & os, const std::vector<Assignment> & assignment_list);

/**
 * Represents a student with associated attributes and behaviors.
 *
 * This class is designed to model a student entity in a system. It provides
 * functionality for managing and accessing student-related data such as
 * name, ID, and other relevant properties.
 *
 * Use this class to represent individual students in applications such as
 * school systems, learning platforms, or student management tools.
 */
class Student : public Person {
private:
    std::map<Subject, std::vector<Assignment>> assignments;

    /**
     * Computes the average grade from a list of graded assignments.
     *
     * @param assignments A list of graded assignments, each containing grade information.
     * @return The calculated average grade as a floating-point value.
     */
    [[nodiscard]] static float get_average_grades_from_subject(const std::list<Assignment> &assignments);

    /**
     * Constructs a Student object with the given personal details.
     *
     * @param first_name The first name of the student.
     * @param last_name The last name of the student.
     * @param email The email address of the student.
     * @param birth_date The birth date of the student represented as a time_t object.
     */
public:
    Student(const std::string &first_name, const std::string &last_name, const std::string &email,
            const time_t birth_date);

    /**
     * Constructs a Student object with the given personal details.
     *
     * @param first_name The first name of the student.
     * @param last_name The last name of the student.
     * @param email The email address of the student.
     * @param day The day of the student's birth date.
     * @param month The month of the student's birth date.
     * @param year The year of the student's birth date.
     */
    Student(const std::string &first_name, const std::string &last_name, const std::string &email,
            const int &day, const int &month, const int &year);

    /**
     * Calculates and retrieves the overall average grade of the student
     * across all subjects.
     *
     * @return The average grade as a floating-point number representing
     *         the mean of all graded assignments across all subjects.
     */
    [[nodiscard]] float get_average_grade() const;

    /**
     * Computes the sum of all grades obtained by the student in the specified subject.
     *
     * @param subject The subject for which the total sum of grades is to be calculated.
     * @return The total sum of grades as an integer for the specified subject. If no grades
     *         are present for the given subject, the result will be zero.
     */
    [[nodiscard]] int get_sum_of_grades_from_students_subjects(const Subject &subject) const;

    /**
     * Retrieves the count of graded assignments the student has for a specific subject.
     *
     * @param subject The subject for which the count of graded assignments is to be retrieved.
     * @return The number of graded assignments associated with the specified subject as an integer.
     *         If no assignments exist for the given subject, the result will be zero.
     */
    [[nodiscard]] int get_count_of_grades_from_students_subjects(const Subject &subject) const;

    /**
     * Computes and retrieves the average grade from the student's graded math assignments.
     *
     * @return The average grade of math assignments as a floating-point value.
     *         If no graded math assignments are present, the result will be zero.
     */
    [[nodiscard]] float get_average_grade_from_math() const;

    /**
     * Computes and retrieves the average grade from the student's graded English assignments.
     *
     * @return The average grade of English assignments as a floating-point value. If no graded English
     *         assignments are present, the result will be zero.
     */
    [[nodiscard]] float get_average_grade_from_english() const;

    /**
     * Computes and retrieves the average grade from the student's graded Polish assignments.
     *
     * @return The average grade of Polish assignments as a floating-point value.
     *         If no graded Polish assignments are present, the result will be zero.
     */
    [[nodiscard]] float get_average_grade_from_polish() const;

    /**
     * Computes and retrieves the average grade from the student's graded history assignments.
     *
     * @return The average grade of history assignments as a floating-point value.
     *         If no graded history assignments are present, the result will be zero.
     */
    [[nodiscard]] float get_average_grade_from_history() const;

    /**
     * Calculates and retrieves the average grade from biology assignments for the student.
     *
     * @return The average grade of the student in biology.
     */
    [[nodiscard]] float get_average_grade_from_biology() const;

    /**
     * Computes and retrieves the average grade for physics assignments.
     *
     * @return The average grade of the physics assignments as a floating-point value.
     */
    [[nodiscard]] float get_average_grade_from_physics() const;

    /**
     * Retrieves the average grade obtained by the student in chemistry assignments.
     *
     * @return The average grade for chemistry assignments as a floating-point value.
     */
    [[nodiscard]] float get_average_grade_from_chemistry() const;

    /**
     * Calculates and retrieves the average grade for geography assignments.
     *
     * @return The average grade as a floating-point number for geography assignments.
     */
    [[nodiscard]] float get_average_grade_from_geography() const;

    /**
     * Retrieves the average grade achieved by the student in computer science assignments.
     *
     * @return The average grade of the student in computer science as a floating-point number.
     */
    [[nodiscard]] float get_average_grade_from_computer_science() const;

    /**
     * Retrieves the average grade achieved by the student in physical education.
     *
     * @return The average grade computed from all physical education assignments.
     */
    [[nodiscard]] float get_average_grade_from_physical_education() const;

    /**
     * Adds an assignment related to a specific subject to the student's record.
     *
     * @param subject The subject associated with the assignment.
     * @param assigment The assignment to be added for the student.
     */
    void add_assignment(const Subject &subject, const Assignment &assigment);

    void add_assignment(const Subject &subject, const Assignment &assignment, int grade);

    /**
     * Adds an assignment to the student for a specific subject.
     *
     * @param subject The subject associated with the assignment.
     * @param name The name of the assignment.
     * @param description A brief description of the assignment.
     */
    void add_assignment(const Subject &subject, const std::string &name, const std::string &description);

    void add_assignment(const Subject &subject, const std::string &name, const std::string &description, int grade);

    /**
     * Compares two Student objects for equality.
     *
     * @param lhs The first Student object to compare.
     * @param rhs The second Student object to compare.
     * @return true if all corresponding data members of the two Student objects
     *         are equal; otherwise, false.
     */
    bool operator==(const Student &rhs) const;

    /**
     * Compares two Student objects to determine if they are not equal.
     *
     * @param lhs The first Student object to compare.
     * @param rhs The second Student object to compare.
     * @return True if the two Student objects are not equal, otherwise false.
     */
    bool operator!=(const Student &rhs) const;

    /**
     * Overloads the operator to perform a specific operation between two objects.
     *
     * @param other The object to be combined with the current instance in the operation.
     * @return The result of the operation as a new object.
     */
    friend std::ostream & operator<<(std::ostream &os, const Student &obj);

    /**
     * Retrieves the list of assignments associated with a specific subject.
     *
     * @param subject The subject for which assignments need to be retrieved.
     * @return A constant reference to a vector containing the assignments for the provided subject.
     */
    [[nodiscard]] const std::vector<Assignment> & get_assignments_from_subject(const Subject &subject) const;
};



#endif //PROJECT_STUDENT_H
