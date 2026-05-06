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
    Teacher &mathTeacher;
    Teacher &englishTeacher;
    Teacher &polishTeacher;
    Teacher &historyTeacher;
    Teacher &biologyTeacher;
    Teacher &physicsTeacher;
    Teacher &chemistryTeacher;
    Teacher &geographyTeacher;
    Teacher &computerScienceTeacher;
    Teacher &physicalEducationTeacher;
    Teacher &superVisingTeacher;
    std::vector<Student> students;
    static int counter;

    bool isClassGraduated;
    int year;
    char letter;

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

    /**
     * @brief Constructs a Class object with a full set of teachers, year, and letter designation.
     *
     * Initializes the Class object with the provided teachers for different subjects,
     * along with the academic year and letter designation. Also assigns a unique ID
     * to the class and initializes it as not graduated.
     *
     * @param math_teacher The teacher responsible for mathematics.
     * @param english_teacher The teacher responsible for English.
     * @param polish_teacher The teacher responsible for Polish.
     * @param history_teacher The teacher responsible for history.
     * @param biology_teacher The teacher responsible for biology.
     * @param physics_teacher The teacher responsible for physics.
     * @param chemistry_teacher The teacher responsible for chemistry.
     * @param geography_teacher The teacher responsible for geography.
     * @param computer_science_teacher The teacher responsible for computer science.
     * @param physical_education_teacher The teacher responsible for physical education.
     * @param super_vising_teacher The teacher assigned as the supervising teacher for the class.
     * @param year The year the class belongs to.
     * @param letter The letter designation of the class.
     */
public:
    Class(Teacher &math_teacher, Teacher &english_teacher, Teacher &polish_teacher,
        Teacher &history_teacher, Teacher &biology_teacher, Teacher &physics_teacher, Teacher &chemistry_teacher,
        Teacher &geography_teacher, Teacher &computer_science_teacher, Teacher &physical_education_teacher,
        Teacher &super_vising_teacher, int year, char letter);

    /**
     * @brief Constructs a Class object with assigned teachers, students, year, and letter.
     *
     * @param math_teacher Reference to the math teacher for the class.
     * @param english_teacher Reference to the English teacher for the class.
     * @param polish_teacher Reference to the Polish teacher for the class.
     * @param history_teacher Reference to the history teacher for the class.
     * @param biology_teacher Reference to the biology teacher for the class.
     * @param physics_teacher Reference to the physics teacher for the class.
     * @param chemistry_teacher Reference to the chemistry teacher for the class.
     * @param geography_teacher Reference to the geography teacher for the class.
     * @param computer_science_teacher Reference to the computer science teacher for the class.
     * @param physical_education_teacher Reference to the physical education teacher for the class.
     * @param super_vising_teacher Reference to the supervising teacher responsible for the class.
     * @param students Vector containing the list of students in the class.
     * @param year The academic year of the class.
     * @param letter The letter identifier for the class (e.g., 'A', 'B').
     */
    Class(Teacher &math_teacher, Teacher &english_teacher, Teacher &polish_teacher, Teacher &history_teacher,
          Teacher &biology_teacher, Teacher &physics_teacher, Teacher &chemistry_teacher, Teacher &geography_teacher,
          Teacher &computer_science_teacher, Teacher &physical_education_teacher, Teacher &super_vising_teacher,
          const std::vector<Student> &students, int year, char letter);

    /**
     * @brief Constructs a new Class object with the specified teachers, students, and class identifier.
     *
     * @param math_teacher Reference to the math teacher assigned to the class.
     * @param english_teacher Reference to the English teacher assigned to the class.
     * @param polish_teacher Reference to the Polish teacher assigned to the class.
     * @param history_teacher Reference to the history teacher assigned to the class.
     * @param biology_teacher Reference to the biology teacher assigned to the class.
     * @param physics_teacher Reference to the physics teacher assigned to the class.
     * @param chemistry_teacher Reference to the chemistry teacher assigned to the class.
     * @param geography_teacher Reference to the geography teacher assigned to the class.
     * @param computer_science_teacher Reference to the computer science teacher assigned to the class.
     * @param physical_education_teacher Reference to the physical education teacher assigned to the class.
     * @param super_vising_teacher Reference to the supervising teacher assigned to the class.
     * @param students Vector of students assigned to this class.
     * @param letter The identifying letter for the class (e.g., 'A', 'B').
     */
    Class(Teacher &math_teacher, Teacher &english_teacher, Teacher &polish_teacher, Teacher &history_teacher,
          Teacher &biology_teacher, Teacher &physics_teacher, Teacher &chemistry_teacher, Teacher &geography_teacher,
          Teacher &computer_science_teacher, Teacher &physical_education_teacher, Teacher &super_vising_teacher,
          const std::vector<Student> &students, char letter);

    /**
     * @brief Constructs a Class object with specified teachers and graduation status.
     *
     * @param math_teacher The teacher responsible for teaching mathematics.
     * @param english_teacher The teacher responsible for teaching English.
     * @param polish_teacher The teacher responsible for teaching Polish.
     * @param history_teacher The teacher responsible for teaching history.
     * @param biology_teacher The teacher responsible for teaching biology.
     * @param physics_teacher The teacher responsible for teaching physics.
     * @param chemistry_teacher The teacher responsible for teaching chemistry.
     * @param geography_teacher The teacher responsible for teaching geography.
     * @param computer_science_teacher The teacher responsible for teaching computer science.
     * @param physical_education_teacher The teacher responsible for teaching physical education.
     * @param super_vising_teacher The teacher responsible for supervising the class.
     * @param is_class_graduated Indicates whether the class has graduated.
     */
    Class(Teacher &math_teacher, Teacher &english_teacher, Teacher &polish_teacher, Teacher &history_teacher,
          Teacher &biology_teacher, Teacher &physics_teacher, Teacher &chemistry_teacher, Teacher &geography_teacher,
          Teacher &computer_science_teacher, Teacher &physical_education_teacher, Teacher &super_vising_teacher,
          bool is_class_graduated);

    /**
     * @brief Constructs a Class object with associated teachers and a class identifier.
     *
     * This constructor initializes a Class instance by assigning the provided teachers to their respective subjects
     * and setting the class's letter identifier. It also initializes the class's ID, sets its year to 1, and marks it as not graduated.
     *
     * @param math_teacher Reference to the teacher responsible for math.
     * @param english_teacher Reference to the teacher responsible for English.
     * @param polish_teacher Reference to the teacher responsible for Polish.
     * @param history_teacher Reference to the teacher responsible for history.
     * @param biology_teacher Reference to the teacher responsible for biology.
     * @param physics_teacher Reference to the teacher responsible for physics.
     * @param chemistry_teacher Reference to the teacher responsible for chemistry.
     * @param geography_teacher Reference to the teacher responsible for geography.
     * @param computer_science_teacher Reference to the teacher responsible for computer science.
     * @param physical_education_teacher Reference to the teacher responsible for physical education.
     * @param super_vising_teacher Reference to the teacher responsible for supervising the class.
     * @param letter Character denoting the class's unique letter identifier.
     */
    Class(Teacher &math_teacher, Teacher &english_teacher, Teacher &polish_teacher, Teacher &history_teacher,
          Teacher &biology_teacher, Teacher &physics_teacher, Teacher &chemistry_teacher, Teacher &geography_teacher,
          Teacher &computer_science_teacher, Teacher &physical_education_teacher, Teacher &super_vising_teacher,
          const char letter);

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
     * @brief Constructs a new Class object with assigned teachers, students, and a class letter.
     *
     * @param math_teacher              Reference to the math teacher assigned to the class.
     * @param english_teacher           Reference to the English teacher assigned to the class.
     * @param polish_teacher            Reference to the Polish teacher assigned to the class.
     * @param history_teacher           Reference to the history teacher assigned to the class.
     * @param biology_teacher           Reference to the biology teacher assigned to the class.
     * @param physics_teacher           Reference to the physics teacher assigned to the class.
     * @param chemistry_teacher         Reference to the chemistry teacher assigned to the class.
     * @param geography_teacher         Reference to the geography teacher assigned to the class.
     * @param computer_science_teacher  Reference to the computer science teacher assigned to the class.
     * @param physical_education_teacher Reference to the physical education teacher assigned to the class.
     * @param super_vising_teacher      Reference to the supervising teacher assigned to manage the class.
     * @param students                  Reference to a vector containing the list of students in the class.
     * @param letter                    Character representing the letter identifier of the class.
     *
     * @return A newly constructed Class object.
     */
    Class( Teacher & math_teacher,  Teacher & english_teacher,  Teacher & polish_teacher,  Teacher & history_teacher,  Teacher & biology_teacher,  Teacher & physics_teacher,  Teacher & chemistry_teacher,
           Teacher & geography_teacher,  Teacher & computer_science_teacher,  Teacher & physical_education_teacher,  Teacher & super_vising_teacher,  std::vector<Student> & students, char letter);

    /**
     * @brief Constructs an instance of the Class object with specified teachers, students, graduation status, and identifier.
     *
     * @param math_teacher Reference to the assigned math teacher.
     * @param english_teacher Reference to the assigned English teacher.
     * @param polish_teacher Reference to the assigned Polish teacher.
     * @param history_teacher Reference to the assigned history teacher.
     * @param biology_teacher Reference to the assigned biology teacher.
     * @param physics_teacher Reference to the assigned physics teacher.
     * @param chemistry_teacher Reference to the assigned chemistry teacher.
     * @param geography_teacher Reference to the assigned geography teacher.
     * @param computer_science_teacher Reference to the assigned computer science teacher.
     * @param physical_education_teacher Reference to the assigned physical education teacher.
     * @param super_vising_teacher Reference to the supervising teacher of the class.
     * @param students List of students in the class.
     * @param is_class_graduated Indicates whether the class has graduated.
     * @param letter The letter identifier of the class.
     *
     * @return None.
     */
    Class(Teacher &math_teacher, Teacher &english_teacher, Teacher &polish_teacher, Teacher &history_teacher,
          Teacher &biology_teacher, Teacher &physics_teacher, Teacher &chemistry_teacher, Teacher &geography_teacher,
          Teacher &computer_science_teacher, Teacher &physical_education_teacher, Teacher &super_vising_teacher,
          const std::vector<Student> &students, bool is_class_graduated, char letter);

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
    void add_student(const Student &student);

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
    void add_student(const std::string &first_name, const std::string &last_name, const std::string &email,
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
     * @brief Retrieves the math teacher associated with the class.
     * @return The math teacher of the class.
     */
    [[nodiscard]] Teacher get_math_teacher() const;

    /**
     * @brief Sets the math teacher for the class.
     * @param math_teacher A reference to the Teacher object to be assigned as the math teacher.
     */
    void set_math_teacher(const Teacher &math_teacher);

    /**
     * @brief Retrieves the English teacher assigned to the class.
     * @return The English teacher of the class as a Teacher object.
     */
    [[nodiscard]] Teacher get_english_teacher() const;

    /**
     * @brief Sets the English teacher for the class.
     * @param english_teacher A reference to the Teacher object to be assigned as the English teacher.
     */
    void set_english_teacher(const Teacher &english_teacher);

    /**
     * @brief Retrieves the Polish teacher assigned to the class.
     * @return The Polish teacher associated with the class.
     */
    [[nodiscard]] Teacher get_polish_teacher() const;

    /**
     * @brief Sets the Polish teacher for the class.
     * @param polish_teacher The teacher to be assigned as the Polish teacher.
     */
    void set_polish_teacher(const Teacher &polish_teacher);

    /**
     * @brief Retrieves the history teacher assigned to the class.
     * @return The teacher responsible for teaching history in the class.
     */
    [[nodiscard]] Teacher get_history_teacher() const;

    /**
     * @brief Sets the history teacher for the class.
     * @param history_teacher The teacher to be assigned as the history teacher.
     */
    void set_history_teacher(const Teacher &history_teacher);

    /**
     * @brief Retrieves the biology teacher assigned to the class.
     * @return The teacher object representing the biology teacher.
     */
    [[nodiscard]] Teacher get_biology_teacher() const;

    /**
     * @brief Sets the biology teacher for the class.
     * @param biology_teacher The Teacher object representing the biology teacher to be assigned.
     */
    void set_biology_teacher(const Teacher &biology_teacher);

    /**
     * @brief Retrieves the physics teacher of the class.
     * @return The physics teacher associated with the class.
     */
    [[nodiscard]] Teacher get_physics_teacher() const;

    /**
     * @brief Assigns a physics teacher to the class.
     * @param physics_teacher The Teacher object representing the physics teacher to be assigned.
     */
    void set_physics_teacher(const Teacher &physics_teacher);

    /**
     * @brief Retrieves the chemistry teacher for the class.
     * @return The teacher assigned to chemistry for this class.
     */
    [[nodiscard]] Teacher get_chemistry_teacher() const;

    /**
     * @brief Sets the chemistry teacher for the class.
     * @param chemistry_teacher A reference to the Teacher object to be assigned as the chemistry teacher.
     */
    void set_chemistry_teacher(const Teacher &chemistry_teacher);

    /**
     * @brief Retrieves the geography teacher associated with the class.
     * @return The teacher responsible for teaching geography.
     */
    [[nodiscard]] Teacher get_geography_teacher() const;

    /**
     * @brief Sets the geography teacher for the class.
     * @param geography_teacher The teacher object to be assigned as the geography teacher.
     */
    void set_geography_teacher(const Teacher &geography_teacher);

    /**
     * @brief Retrieves the computer science teacher for the class.
     * @return The teacher assigned to computer science in the class.
     */
    [[nodiscard]] Teacher get_computer_science_teacher() const;

    /**
     * @brief Sets the computer science teacher for the class.
     * @param computer_science_teacher The Teacher object representing the computer science teacher to be assigned.
     */
    void set_computer_science_teacher(const Teacher &computer_science_teacher);

    /**
     * @brief Retrieves the physical education teacher of the class.
     * @return The teacher assigned to physical education.
     */
    [[nodiscard]] Teacher get_physical_education_teacher() const;

    /**
     * @brief Sets the physical education teacher for the class.
     * @param physical_education_teacher The teacher to assign as the physical education teacher.
     */
    void set_physical_education_teacher(const Teacher &physical_education_teacher);

    /**
     * @brief Retrieves the supervising teacher of the class.
     * @return The teacher supervising the class.
     */
    [[nodiscard]] Teacher get_super_vising_teacher() const;

    /**
     * @brief Sets the supervising teacher for the class.
     * @param super_vising_teacher A reference to the Teacher object to be assigned as the supervising teacher.
     */
    void set_super_vising_teacher(const Teacher &super_vising_teacher);

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
    void add_assignment(const Subject &subject, const Assigment &assigment);

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
    void add_assignment(const Subject &subject, const Assigment &assigment, int grade);

    /**
     * @brief Adds a graded assignment for all students in the class.
     * @param subject The subject associated with the assignment.
     * @param assigment The graded assignment to be added for each student.
     */
    void add_assignment(const Subject &subject, const Assigment_graded &assigment);

    /**
     * @brief Adds a graded assignment for all students in the class.
     * @param subject The subject associated with the assignment.
     * @param assigment_graded The graded assignment to be added.
     * @param grade The grade assigned to the assignment.
     */
    void add_assignment(const Subject &subject, Assigment_graded &assigment_graded, const int grade);

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



#endif //PROJECT_CLASS_H
