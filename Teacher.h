//
// Created by olidiaks on 10.04.2026.
//

#ifndef PROJECT_TEACHER_H
#define PROJECT_TEACHER_H
#include <ostream>
#include <string>

#include "Person.h"
#include "Student.h"


/**
 * The Teacher class represents an individual who is responsible
 * for instructing and educating students in a specific subject or field.
 * This class holds details about the teacher such as their name, subject expertise,
 * and other relevant attributes that define their role.
 *
 * Responsibilities of this class may include managing course materials,
 * assigning and grading assessments, and maintaining a productive learning
 * environment for students.
 *
 * Attributes and methods provided by this class facilitate the representation
 * and manipulation of teacher-related data.
 */
class Teacher : public Person {
private:
    int salary;
    Subject subject;

public:

/**
 * The operator function provides a mechanism for overloading specific
 * operators in a class or structure. This allows customization of behavior
 * when using standard operators such as addition, subtraction, comparison,
 * or assignment with objects of the class.
 *
 * The implementation of this function should define the specific logic
 * that determines how the operator processes the operands and produces
 * the intended result.
 *
 * @param lhs The left-hand side operand involved in the operation.
 * @param rhs The right-hand side operand involved in the operation.
 * @return The result of the operation as determined by the implementation.
 */
    friend std::ostream & operator<<(std::ostream &os, const Teacher &obj);

    /**
     * Compares two Teacher objects for equality.
     * This operator checks whether the two Teacher instances are equivalent
     * based on their base class attributes and specific Teacher attributes.
     * Equality is determined by comparing the underlying Person attributes,
     * the salary, and the subject of the two Teacher objects.
     *
     * @param lhs The left-hand side Teacher object to be compared.
     * @param rhs The right-hand side Teacher object to be compared.
     * @return true if the two Teacher objects are equal; false otherwise.
     */
    friend bool operator==(const Teacher &lhs, const Teacher &rhs);

    /**
     * Compares two Teacher objects for inequality.
     * This operator determines whether the two Teacher instances
     * are not equivalent by negating the result of the equality comparison.
     * The comparison relies on the implementation of the equality operator (operator==).
     *
     * @param lhs The left-hand side Teacher object to be compared.
     * @param rhs The right-hand side Teacher object to be compared.
     * @return true if the two Teacher objects are not equal; false otherwise.
     */
    friend bool operator!=(const Teacher &lhs, const Teacher &rhs);

    /**
     * Constructs a Teacher object with the specified details.
     * This constructor initializes the Teacher instance by providing values
     * for the first name, last name, email, birth date, salary, and associated subject.
     * The Teacher class inherits from the Person class, so its base attributes are
     * also initialized using the provided parameters.
     *
     * @param first_name The first name of the teacher.
     * @param last_name The last name of the teacher.
     * @param email The email address of the teacher.
     * @param birth_date The birth date of the teacher, represented as a time_t value.
     * @param salary The monthly salary of the teacher.
     * @param subject The subject specialization of the teacher, represented as a Subject enumeration value.
     * @return None.
     */
    Teacher(const std::string &first_name, const std::string &last_name, const std::string &email,
            const time_t birth_date, const int salary, const Subject &subject);

    /**
     * Constructs a Teacher object with the specified attributes.
     * This constructor initializes the Teacher instance by setting
     * the first name, last name, email, birth date, salary, and subject specialization.
     * The base class Person is initialized with the provided personal details,
     * while the salary and subject are specific to the Teacher class.
     *
     * @param first_name The first name of the teacher.
     * @param last_name The last name of the teacher.
     * @param email The email address of the teacher.
     * @param day The day of the teacher's birth date.
     * @param month The month of the teacher's birth date.
     * @param year The year of the teacher's birth date.
     * @param salary The salary of the teacher.
     * @param subject The subject specialization of the teacher, represented as a Subject enumeration value.
     * @return None.
     */
    Teacher(const std::string &first_name, const std::string &last_name, const std::string &email,
            const int &day, const int &month, const int &year, const int salary, const Subject &subject);

    /**
     * Retrieves the subject specialization of the teacher.
     * The subject represents the area of expertise or field of study
     * that the teacher is qualified to teach, as defined by the Subject enumeration.
     *
     * @return A constant reference to the subject specialization of the teacher.
     */
    [[nodiscard]] const Subject & get_subject() const;

    /**
     * Retrieves the salary of the teacher.
     *
     * This method provides access to the salary attribute
     * associated with the teacher, representing their
     * current compensation in monetary terms.
     *
     * @return The salary of the teacher.
     */
    [[nodiscard]] int get_salary() const;

    /**
     * Sets the salary of the teacher.
     *
     * This method assigns the specified salary to the teacher, updating
     * their remuneration details within the system.
     *
     * @param salary The new salary amount to be assigned to the teacher.
     */
    void set_salary(const int salary);

    /**
     * Copy constructor for the Teacher class.
     * This constructor creates a new instance of the Teacher class
     * by copying the attributes from another Teacher object.
     *
     * @param other The Teacher object to copy from. The attributes of the
     *              provided teacher, such as salary and subject, are used
     *              to initialize the new instance.
     * @return A new instance of the Teacher class initialized with the
     *         attributes of the provided Teacher object.
     */
    Teacher(const Teacher &other);

    /**
     * Move constructor for the Teacher class.
     * Constructs a Teacher object by transferring the resources from another Teacher object.
     *
     * This constructor ensures efficient object initialization without creating unnecessary copies,
     * by transferring ownership of the attributes from the source object to the newly created object.
     *
     * @param other The Teacher object to be moved. After the move, the state of the source object
     *              is considered valid but unspecified.
     * @return A new Teacher object initialized with the transferred resources from the source object.
     */
    Teacher(Teacher &&other) noexcept;

    /**
     * Assigns the values of another Teacher object to the current object.
     * This operator performs a deep copy of all relevant member variables, including
     * inherited attributes and attributes specific to the Teacher class.
     *
     * @param other The Teacher object whose values will be assigned to the current object.
     * @return A reference to the current Teacher object after assignment.
     */
    Teacher & operator=(const Teacher &other);

    /**
     * Move assignment operator for the Teacher class.
     * This operator transfers the ownership of resources from the given
     * Teacher object to the current object, ensuring efficient reuse of
     * dynamically allocated memory and avoiding deep copies.
     *
     * @param other The Teacher object from which resources will be moved.
     *              Once moved, the state of the `other` object becomes
     *              unspecified but valid (typically a default-constructed state).
     * @return A reference to the current Teacher object after the assignment.
     */
    Teacher & operator=(Teacher &&other) noexcept;

    /**
     * Default constructor for the Teacher class.
     *
     * Initializes a new instance of the Teacher class with default values for
     * its attributes, including the base class initialization and relevant
     * teacher-specific properties such as salary and subject expertise.
     *
     * This constructor ensures that all member variables have initial values,
     * preparing the object for further configuration or use.
     *
     * @return A new instance of the Teacher class.
     */
    Teacher();

    /**
     * Exchanges the contents of two Teacher objects.
     * This function swaps all internal data of the provided Teacher
     * instances, including any inherited attributes and specific
     * member variables related to the Teacher class.
     * The operation is performed without throwing exceptions.
     *
     * @param lhs A reference to the first Teacher object to be swapped.
     * @param rhs A reference to the second Teacher object to be swapped.
     */
    friend void swap(Teacher &lhs, Teacher &rhs) noexcept;
};



#endif //PROJECT_TEACHER_H