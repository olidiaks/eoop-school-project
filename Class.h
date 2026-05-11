//
// Created by olidiaks on 10.04.2026.
//

#ifndef PROJECT_CLASS_H
#define PROJECT_CLASS_H
#include <vector>
#include <ostream>

#include "Student.h"
#include "Teacher.h"


/**
 * @class Class
 * @brief Manages a classroom, its students, teachers, and assignments.
 */
class Class {
private:
    int id;
    std::map<Subject,Teacher&> teachers;
    std::vector<Student> students;
    const Teacher &supervising_teacher;
    static int counter;

    bool isClassGraduated;
    int year;
    char letter;

    /**
     * @brief Checks if a specific teacher is assigned to the class.
     * @param teacher The teacher to check for assignment.
     * @return True if the teacher is assigned to the class, otherwise false.
     */
    [[nodiscard]] bool is_teacher_assigned(const Teacher &teacher) const;

    /**
     * @brief Checks if a given student is assigned to the class.
     *
     * @param student The student to check for assignment in the class.
     * @return true if the student is assigned to the class, false otherwise.
     */
    [[nodiscard]] bool is_student_assigned(const Student &student) const;

    /**
     * @brief Checks whether a student with specific identifying details is assigned to the class.
     *
     * @param firstname The first name of the student.
     * @param last_name The last name of the student.
     * @param email The email address of the student.
     * @param day The day of birth of the student.
     * @param month The month of birth of the student.
     * @param year The year of birth of the student.
     * @return True if a student matching the specified details is assigned to the class, false otherwise.
     */
    bool is_student_assigned(const std::string & firstname, const std::string & last_name, const std::string & email, int day, int month, int year);

    /**
     * @brief Finds the index of a student in the class by their unique ID.
     *
     * This method iterates through the list of students, comparing the provided ID
     * with the IDs of the students in the class. If a matching ID is found, the
     * index of that student is returned. Otherwise, the method returns -1.
     *
     * @param id The unique identifier of the student to find.
     * @return The index of the student in the list if found, or -1 if no student
     *         with the given ID exists.
     */
    int find_student_index(const int &id) const;

public:
    /**
     * @brief Constructs a Class instance with a specified year and letter.
     *
     * @param supervisingTeacher is a reference to supervising teacher.
     * @param year The academic year of the class.
     * @param letter The letter representing the class section.
     */
    Class(const Teacher & supervisingTeacher,int year, char letter);

    /**
     * @brief Copy constructor for the Class object.
     *
     * Creates a new instance of the Class object by performing a deep copy
     * of the provided Class instance.
     *
     * @param other The Class instance to copy from.
     * @return A new Class object initialized with the values from the provided object.
     */
    Class(const Class &other);

    /**
     * @brief Move constructor for the Class object.
     *
     * Transfers ownership of the resources and state from the given object to this instance.
     *
     * @param other The Class object to be moved from. After the operation, the `other` object
     *              may no longer be in a valid state.
     */
    Class(Class &&other) noexcept;

    /**
     * @brief Overloads the assignment operator for the Class object.
     *        Copies all attributes from the given Class object into this object.
     *
     * @param other The Class object from which data will be copied.
     * @return A reference to this Class object after assignment.
     */
    Class & operator=(const Class &other);

    /**
     * @brief Move assignment operator for the Class class.
     *
     * Transfers ownership of all members from another Class instance to this instance,
     * effectively moving its state while ensuring proper resource management.
     *
     * @param other The Class instance to move from.
     * @return A reference to the current Class instance after the assignment.
     */
    Class & operator=(Class &&other) noexcept;

    /**
     * @brief Checks if the class has graduated.
     * @return True if the class has graduated, false otherwise.
     */
    [[nodiscard]] bool is_class_graduated() const;

    /**
     * @brief Retrieves the year associated with the class.
     * @return The year of the class as an integer.
     */
    [[nodiscard]] int get_year() const;

    /**
     * @brief Retrieves the letter associated with the class.
     * @return The letter representing the class.
     */
    [[nodiscard]] char get_letter() const;

    /**
     * @brief Adds a student to the class.
     * @param student The student to be added to the class.
     */
    bool add_student(const Student &student);

        /**
     * @brief Adds a new student to the class roster.
     *
     * @param first_name The first name of the student.
     * @param last_name The last name of the student.
     * @param email The email address of the student.
     * @param day The day of the student's birth date.
     * @param month The month of the student's birth date.
     * @param year The year of the student's birth date.
     */
    bool add_student(const std::string &first_name, const std::string &last_name, const std::string &email,
                     const int &day, const int &month, const int &year);

    /**
     * @brief Removes a student from the class based on their unique ID.
     * @param id The unique identifier of the student to be removed.
     * @return True if the student was found and successfully removed, false otherwise.
     */
    bool remove_student(const int &id);

    /**
     * @brief Checks if a student with the given ID is in the class.
     * @param id The ID of the student to search for.
     * @return True if the student is in the class, false otherwise.
     */
    [[nodiscard]] bool is_student_in_class(const int &id) const;

    /**
     * @brief Outputs the list of students to the standard output.
     *
     * This method retrieves and displays the list of students
     * managed by the class.
     */
    void print_students() const;

    /**
     * @brief Outputs the list of teachers associated with the class.
     *
     * This method prints the names of all teachers for various subjects
     * and the supervising teacher to the standard output.
     * It provides an overview of all teaching staff assigned to the class
     * along with their roles.
     */
    void print_teachers() const;

    /**
     * @brief Retrieves a student by their unique identifier.
     * @param id The unique identifier of the student to retrieve.
     * @return A constant reference to the student associated with the given identifier.
     * @throws std::runtime_error If no student with the specified identifier is found.
     */
    const Student &get_student(const int &id) const;

    /**
     * @brief Retrieves the list of students associated with the class.
     * @return A reference to a vector containing the students in the class.
     */
    std::vector<Student> &get_students();

    /**
     * @brief Retrieves the list of students associated with the class.
     * @return A reference to a vector containing the students in the class.
     */
    const std::vector<Student> &get_students() const;

    /**
     * @brief Calculates the average grade of the class for a given subject.
     * @param subject The subject for which the average grade is calculated.
     * @return The average grade for the specified subject. Returns 0 if no grades are available.
     */
    [[nodiscard]] int get_average_grade_of_clas_from_subject(const Subject &subject) const;

    /**
     * @brief Compares two Class objects for equality.
     *
     * This operator checks whether two Class objects are equal by comparing all of their properties
     * including their students, identifiers, teachers of various subjects, graduation status, and
     * class year information.
     *
     * @param lhs The first Class object to compare.
     * @param rhs The second Class object to compare.
     * @return true if the two Class objects are equivalent; false otherwise.
     */
      bool operator==(const Class &rhs) const;

    /**
     * @brief Compares two Class objects for inequality.
     *
     * This operator checks if two Class objects are not equivalent
     * by negating the result of the equality comparison between them.
     *
     * @param lhs The first Class object to compare.
     * @param rhs The second Class object to compare.
     * @return True if the objects are not equal, otherwise false.
     */
    bool operator!=(const Class &rhs) const;

    /**
     * @brief Overloads the stream insertion operator to output the details of a Class object.
     *
     * This function provides a formatted representation of the Class object,
     * including its identifier, year, letter, graduation status, teachers, and student details.
     *
     * @param os The output stream to which the Class object is written.
     * @param obj A reference to the Class object to be output.
     * @return A reference to the output stream, allowing for chaining of stream operations.
     */
    friend std::ostream & operator<<(std::ostream &os, const Class &obj);

    /**
     * @brief Exchanges the contents of two Class objects.
     *
     * This function swaps all the member variables of two Class instances. It ensures
     * that all associated data, such as teachers, students, and class identifiers, are fully exchanged.
     *
     * @param lhs A reference to the first Class object.
     * @param rhs A reference to the second Class object.
     */
    friend void swap(Class &lhs, Class &rhs) noexcept;

    /**
     * @brief Retrieves the unique identifier of the class.
     * @return The identifier of the class as an integer.
     */
    [[nodiscard]] int get_id() const;

    /**
     * @brief Retrieves the total number of students in the class.
     * @return The count of students as an unsigned long.
     */
    [[nodiscard]] unsigned long get_count_of_students() const;

    /**
     * @brief Calculates the total sum of grades for a given subject across all students in the class.
     * @param subject The subject for which the grades are to be summed.
     * @return The sum of all grades for the specified subject across all students.
     */
    [[nodiscard]] int get_sum_of_grades_from_subject(const Subject &subject) const;

    /**
     * @brief Calculates the total number of grades for a specific subject across all students in the class.
     * @param subject The subject for which the grades are counted.
     * @return The total count of grades for the specified subject.
     */
    [[nodiscard]] int get_count_of_grades_from_subject(const Subject &subject) const;

    /**
     * @brief Calculates the average grade of the class across all subjects and students.
     */
    [[nodiscard]] float get_average_grade_of_class();

    /**
     * @brief Assigns a new assignment to all students in the class for a specific subject.
     * @param subject The subject associated with the assignment.
     * @param assigment The assignment to be added for the subject.
     */
    void add_assignment(const Subject &subject, const Assignment &assigment);

    /**
     * @brief Adds a new assignment to all students in the class.
     * @param subject The subject associated with the assignment.
     * @param name The name of the assignment.
     * @param description A brief description of the assignment.
     */
    void add_assignment(const Subject &subject, const std::string &name, const std::string &description);

    /**
     * @brief Adds an assignment with a specified grade to all students in the class for a given subject.
     * @param subject The subject associated with the assignment.
     * @param assignment The assignment to be assigned to each student.
     * @param grade The grade to be associated with the assignment.
     */
    void add_assignment(const Subject &subject, const Assignment &assignment, int grade);

    /**
     * @brief Adds an assignment to all students in the class.
     *
     * @param subject The subject associated with the assignment.
     * @param name The name of the assignment.
     * @param description A brief description of the assignment.
     * @param grade The grade or score associated with the assignment.
     */
    void add_assignment(const Subject &subject, const std::string &name, const std::string &description, int grade);

    /**
     * @brief Adds a teacher to the class.
     * @param teacher A reference to the Teacher object to be added.
     */
    bool add_teacher(const Teacher &teacher);

    /**
     * @brief Removes a teacher from the class by their unique ID.
     *
     * This method iterates through the list of teachers and removes the teacher
     * whose ID matches the provided value.
     *
     * @param id A reference to the unique ID of the teacher to be removed.
     * @return true if a teacher with the specified ID was found and removed, false otherwise.
     */
    bool remove_teacher(const int &id);

    bool remove_teacher(const Teacher &teacher);

    /**
     * @brief Advances the class to the next school year.
     *
     * Updates the current year of the class. If the class reaches the fifth year,
     * it resets the year to an initial state and marks the class as graduated.
     */
    void new_school_year();
};

/**
 * @brief Overloads the stream insertion operator to output a list of students.
 *
 * This method writes the details of each student in the given vector to the specified
 * output stream, with each student's details separated by a newline.
 *
 * @param os The output stream to write to.
 * @param students A vector containing the students to output.
 * @return A reference to the output stream after the students have been written to it.
 */
std::ostream & operator<<(std::ostream & os, const std::vector<Student> & students);

/**
 * @brief Overloads an operator to define custom behavior for a specific operation.
 *
 * This method writes the details of each class in the given list to the specified
 * output stream, with each student's details separated by a newline.
 *
 * @param os The output stream to write to.
 * @param classes A list containing the Classes to output.
 * @return A reference to the output stream after the students have been written to it.
 */
std::ostream & operator<<(std::ostream & os, const std::list<Class> & classes);

/**
 * @brief Overloads the stream insertion operator to output a vector of Teacher objects.
 *
 * @param os The output stream where the formatted data will be written.
 * @param vector The vector of Teacher objects to be written to the output stream.
 * @return A reference to the output stream after writing the data.
 */
std::ostream & operator<<(std::ostream & os, const std::vector<Teacher> & vector);



#endif //PROJECT_CLASS_H
