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
    [[nodiscard]] int get_sum_of_grades_from_subjects(const Subject &subject) const;

    /**
     * Retrieves the count of graded assignments the student has for a specific subject.
     *
     * @param subject The subject for which the count of graded assignments is to be retrieved.
     * @return The number of graded assignments associated with the specified subject as an integer.
     *         If no assignments exist for the given subject, the result will be zero.
     */
    [[nodiscard]] unsigned long get_count_of_grades_from_students_subjects(const Subject &subject) const;

    /**
     * Calculates the average grade of the student for the specified subject.
     *
     * @param subject The subject for which the average grade is to be calculated.
     * @return The average grade of the student for the given subject.
     */
    [[nodiscard]] float get_average_grade_from_subject(const Subject &subject) const;

    /**
     * Adds an assignment related to a specific subject to the student's record.
     *
     * @param subject The subject associated with the assignment.
     * @param assigment The assignment to be added for the student.
     */
    void add_assignment(const Subject &subject, const Assignment &assigment);

    /**
     * Adds a graded assignment for the specified subject to the student's record.
     *
     * @param subject The subject to which the assignment belongs.
     * @param assignment The assignment details without a grade.
     * @param grade The grade to be assigned to the assignment.
     */
    void add_assignment(const Subject &subject, const Assignment &assignment, int grade);

    /**
     * Adds an assignment to the student for a specific subject.
     *
     * @param subject The subject associated with the assignment.
     * @param name The name of the assignment.
     * @param description A brief description of the assignment.
     */
    void add_assignment(const Subject &subject, const std::string &name, const std::string &description);

    /**
     * Adds a new assignment to the student's record for a specific subject.
     *
     * @param subject The subject to which the assignment belongs.
     * @param name The name of the assignment.
     * @param description A brief description of the assignment.
     * @param grade The grade achieved for the assignment.
     */
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

    /**
     * Retrieves the total count of grades across all assignments for the student.
     *
     * @return The total number of grades recorded for the student.
     */
    unsigned long get_count_of_grades_from_all_subjects() const;

    /**
     * Calculates the total sum of grades across all subjects for the student.
     *
     * @return The total sum of grades as an unsigned long.
     */
    unsigned long get_sum_of_grades_from_all_subjects() const;
};



#endif //PROJECT_STUDENT_H
