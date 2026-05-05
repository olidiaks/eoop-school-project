//
// Created by olidiaks on 10.04.2026.
//

#ifndef PROJECT_SCHOOL_H
#define PROJECT_SCHOOL_H
#include <list>
#include <ostream>

#include "Class.h"
#include "Teacher.h"


/**
 * @brief Represents a School entity containing teachers, classes, and school-specific properties.
 */
class School {
private:
    std::list<Teacher> mathTeachers;
    std::list<Teacher> englishTeachers;
    std::list<Teacher> polishTeachers;
    std::list<Teacher> historyTeachers;
    std::list<Teacher> biologyTeachers;
    std::list<Teacher> physicsTeachers;
    std::list<Teacher> chemistryTeachers;
    std::list<Teacher> geographyTeachers;
    std::list<Teacher> computerScienceTeachers;
    std::list<Teacher> physicalEducationTeachers;
    std::list<Teacher> superVisingTeachers;
    std::list<Class> classes;
    std::string name;

    /**
     * @brief Generates a string representation of the School instance.
     *
     * This method provides a detailed description of the School object, including its teachers,
     * classes, and other relevant properties.
     *
     * @return A string containing a formatted representation of the School.
     * @throw std::runtime_error if the method is not implemented.
     */
    [[nodiscard]] std::string print() const;

    /**
     * @brief Finds and returns a reference to a teacher with the specified ID.
     *
     * Searches through all available teacher lists categorized by subject areas.
     * Throws an exception if no teacher with the given ID is found.
     *
     * @param id The unique identifier of the teacher to locate.
     * @return A reference to the Teacher object with the specified ID.
     * @throws std::runtime_error If no teacher with the given ID is found.
     */
    [[nodiscard]] Teacher & find_teacher(int id);

    /**
     * @brief Finds and returns a reference to a teacher based on their first and last name.
     *
     * This method searches through various lists of teachers within the school, including
     * teachers for different subjects, to locate the teacher with the specified first and
     * last name.
     *
     * @param first_name The first name of the teacher to locate.
     * @param last_name The last name of the teacher to locate.
     * @return A reference to the teacher with the matching first and last name.
     * @throws std::runtime_error If no teacher with the specified name is found.
     */
    [[nodiscard]] Teacher & find_teacher(const std::string &first_name, const std::string &last_name);

    /**
     * @brief Constructs a new instance of the School class with default empty teacher and class lists.
     *
     * Initializes the School object, creating empty lists for teachers categorized by their subjects,
     * as well as an empty list for classes. This allows for the addition of teachers and classes after
     * the construction of the School instance.
     */
public:
    School();

    /**
     * @brief Constructs a School object with a specified set of teachers, classes, and the school's name.
     *
     * @param math_teachers List of math teachers associated with the school.
     * @param english_teachers List of English teachers associated with the school.
     * @param polish_teachers List of Polish teachers associated with the school.
     * @param history_teachers List of history teachers associated with the school.
     * @param biology_teachers List of biology teachers associated with the school.
     * @param physics_teachers List of physics teachers associated with the school.
     * @param chemistry_teachers List of chemistry teachers associated with the school.
     * @param geography_teachers List of geography teachers associated with the school.
     * @param computer_science_teachers List of computer science teachers associated with the school.
     * @param physical_education_teachers List of physical education teachers associated with the school.
     * @param super_vising_teachers List of teachers responsible for supervising activities in the school.
     * @param classes List of classes offered by the school.
     * @param school_name Name of the school.
     */
    School(const std::list<Teacher> &math_teachers, const std::list<Teacher> &english_teachers,
           const std::list<Teacher> &polish_teachers, const std::list<Teacher> &history_teachers,
           const std::list<Teacher> &biology_teachers, const std::list<Teacher> &physics_teachers,
           const std::list<Teacher> &chemistry_teachers, const std::list<Teacher> &geography_teachers,
           const std::list<Teacher> &computer_science_teachers, const std::list<Teacher> &physical_education_teachers,
           const std::list<Teacher> &super_vising_teachers, const std::list<Class> &classes,
           const std::string &school_name);

    /**
     * @brief Copy constructor for the School class that creates a new School instance
     *        by copying the properties from another School instance.
     *
     * @param other Reference to another School object from which properties are copied.
     * @return A new instance of the School class with the same data as the input object.
     */
    School(const School &other);

    /**
     * @brief Move constructor for the School class. Transfers ownership of resources from the provided object.
     *
     * @param other The School object to move from. After the move, the state of the source object becomes undefined.
     */
    School(School &&other) noexcept;

    /**
     * @brief Assigns the contents of one School object to another.
     *
     * Performs a deep copy of all properties from the specified School object
     * to the current instance, ensuring that the existing data in the current
     * instance is fully replaced.
     *
     * @param other The School object to copy from.
     * @return A reference to the current School object after assignment.
     */
    School &operator=(const School &other);

    /**
     * @brief Implements the move assignment operator for the School class.
     *
     * Transfers ownership of all the resources and properties from another instance of School to the current instance,
     * ensuring no resource duplication or leaks. Clears the other instance's resources.
     *
     * @param other The School instance being moved from. After the operation, it will contain no valid resources.
     * @return A reference to the current School instance after the move assignment operation.
     */
    School &operator=(School &&other) noexcept;

    /**
     * @brief Compares two School objects for equality.
     *
     * This operator checks if all the teachers, classes, and the name of
     * the two School instances are equal.
     *
     * @param lhs The first School instance to compare.
     * @param rhs The second School instance to compare.
     * @return true if all corresponding members of the two School instances are equal, false otherwise.
     */
    bool operator==(const School &rhs) const;

    /**
     * @brief Compares two School objects for inequality.
     *
     * @param lhs The first School object to compare.
     * @param rhs The second School object to compare.
     * @return True if the School objects are not equal, false otherwise.
     */
    bool operator!=(const School &rhs) const;

    /**
     * @brief Outputs the string representation of a School object to the specified output stream.
     *
     * @param os The output stream where the object's data will be written.
     * @param obj The School object to be converted to a string and written to the output stream.
     * @return A reference to the output stream after the School object's string representation is written.
     */
    friend std::ostream &operator<<(std::ostream &os, const School &obj);

    /**
     * @brief Exchanges the contents of two School objects.
     *
     * The method swaps all properties of the two School instances,
     * including teacher lists for various subjects, classes, and the school name,
     * ensuring their states are fully exchanged.
     *
     * @param lhs The first School instance to be swapped.
     * @param rhs The second School instance to be swapped.
     */
    friend void swap(School &lhs, School &rhs) noexcept;

    /**
     * @brief Retrieves a list of mathematics teachers associated with the school.
     *
     * @return A list of Teacher objects representing the mathematics teachers.
     */
    [[nodiscard]] std::list<Teacher> get_math_teachers() const;

    /**
     * @brief Sets the list of math teachers for the school.
     * @param math_teachers A list of Teacher objects representing the math teachers.
     */
    void set_math_teachers(const std::list<Teacher> &math_teachers);

    /**
     * @brief Retrieves the list of English teachers in the school.
     *
     * @return A list of teachers who teach English.
     */
    [[nodiscard]] std::list<Teacher> get_english_teachers() const;

    /**
     * @brief Sets the list of English teachers for the school.
     *
     * @param english_teachers A list of teachers specializing in English to be assigned to the school.
     */
    void set_english_teachers(const std::list<Teacher> &english_teachers);

    /**
     * @brief Retrieves a list of Polish teachers associated with the school.
     * @return A list of teachers who teach the Polish language.
     */
    [[nodiscard]] std::list<Teacher> get_polish_teachers() const;

    /**
     * @brief Sets the list of Polish teachers for the school.
     * @param polish_teachers A list of Teacher objects representing the Polish teachers to be assigned.
     */
    void set_polish_teachers(const std::list<Teacher> &polish_teachers);

    /**
     * @brief Retrieves the list of history teachers associated with the school.
     * @return A list of Teacher objects representing the history teachers.
     */
    [[nodiscard]] std::list<Teacher> get_history_teachers() const;

    /**
     * @brief Sets the list of history teachers for the school.
     * @param history_teachers A list of Teacher objects representing the history teachers to be assigned to the school.
     */
    void set_history_teachers(const std::list<Teacher> &history_teachers);

    /**
     * @brief Retrieves the list of biology teachers associated with the school.
     * @return A list of Teacher objects representing the biology teachers.
     */
    [[nodiscard]] std::list<Teacher> get_biology_teachers() const;

    /**
     * @brief Sets the list of biology teachers for the school.
     *
     * @param biology_teachers A list of Teacher objects representing the biology teachers.
     */
    void set_biology_teachers(const std::list<Teacher> &biology_teachers);

    /**
     * @brief Retrieves the list of physics teachers associated with the school.
     *
     * @return A list of teachers specializing in physics.
     */
    [[nodiscard]] std::list<Teacher> get_physics_teachers() const;

    /**
     * @brief Sets the list of physics teachers for the school.
     * @param physics_teachers The list of teachers specializing in physics to be assigned to the school.
     */
    void set_physics_teachers(const std::list<Teacher> &physics_teachers);

    /**
     * @brief Retrieves the list of chemistry teachers associated with the school.
     * @return A list of teachers specializing in chemistry.
     */
    [[nodiscard]] std::list<Teacher> get_chemistry_teachers() const;

    /**
     * @brief Sets the list of chemistry teachers for the school.
     * @param chemistry_teachers A list of Teacher objects representing the chemistry teachers to be assigned to the school.
     */
    void set_chemistry_teachers(const std::list<Teacher> &chemistry_teachers);

    /**
     * @brief Retrieves the list of geography teachers associated with the school.
     *
     * @return A list of Teacher objects representing the geography teachers.
     */
    [[nodiscard]] std::list<Teacher> get_geography_teachers() const;

    /**
     * @brief Sets the geography teachers for the school.
     * @param geography_teachers A list of Teacher objects representing the geography teachers to be assigned.
     */
    void set_geography_teachers(const std::list<Teacher> &geography_teachers);

    /**
     * @brief Retrieves the list of teachers specializing in computer science.
     *
     * @return A list of teachers who teach computer science in the school.
     */
    [[nodiscard]] std::list<Teacher> get_computer_science_teachers() const;

    /**
     * @brief Sets the list of computer science teachers for the school.
     * @param computer_science_teachers A list of Teacher objects representing computer science teachers to be assigned to the school.
     */
    void set_computer_science_teachers(const std::list<Teacher> &computer_science_teachers);

    /**
     * @brief Retrieves the list of physical education teachers in the school.
     *
     * @return A list of teachers specializing in physical education.
     */
    [[nodiscard]] std::list<Teacher> get_physical_education_teachers() const;

    /**
     * @brief Sets the list of physical education teachers for the school.
     * @param physical_education_teachers A list of teachers assigned to teach physical education.
     */
    void set_physical_education_teachers(const std::list<Teacher> &physical_education_teachers);

    /**
     * @brief Retrieves the list of supervising teachers associated with the school.
     *
     * @return A list of teachers who act as supervisors.
     */
    [[nodiscard]] std::list<Teacher> get_super_vising_teachers() const;

    /**
     * @brief Sets the list of supervising teachers for the school.
     * @param super_vising_teachers A list of Teacher objects representing the supervising teachers.
     */
    void set_super_vising_teachers(const std::list<Teacher> &super_vising_teachers);

    /**
     * @brief Retrieves the list of classes associated with the school.
     * @return A list containing the classes of the school.
     */
    [[nodiscard]] std::list<Class> get_classes() const;

    /**
     * @brief Sets the list of classes for the School.
     * @param classes A list of Class objects to be associated with the School.
     */
    void set_classes(const std::list<Class> &classes);

    /**
     * @brief Calculates the average grade of students taught by a specific teacher.
     * @param id The unique identifier of the teacher whose students' average grades are to be calculated.
     * @return The average grade of the students taught by the specified teacher.
     * @throws std::runtime_error If the method is not implemented or cannot retrieve the data.
     */
    [[nodiscard]] float get_average_students_grades_of_teacher(const int &id) const;

    /**
     * @brief Retrieves the name of the school.
     * @return The name of the school as a string.
     */
    [[nodiscard]] std::string get_name() const;

    /**
     * @brief Sets the name of the school.
     * @param name The name to assign to the school.
     */
    void set_name(const std::string &name);

    /**
     * @brief Initiates a new school year for all classes within the school.
     */
    void new_school_year();

    /**
     * @brief Adds a class to the list of classes in the school.
     * @param class_to_add The class object to be added to the school.
     */
    void add_class(const Class &class_to_add);

    /**
     * @brief Adds a new class to the school with specified teachers, year, section, and students.
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
     * @param super_vising_teacher The teacher supervising the class.
     * @param year The year the class is associated with.
     * @param letter The section or identifier of the class.
     * @param students A vector containing the students belonging to the class.
     */
    void add_class(Teacher &math_teacher, Teacher &english_teacher, Teacher &polish_teacher,
                   Teacher &history_teacher, Teacher &biology_teacher, Teacher &physics_teacher,
                   Teacher &chemistry_teacher,
                   Teacher &geography_teacher, Teacher &computer_science_teacher, Teacher &physical_education_teacher,
                   Teacher &super_vising_teacher, int year, char letter, const std::vector<Student> &students);

    /**
     * @brief Adds a new class to the school, associating subject-specific teachers, a supervising teacher,
     *        a letter identifier, and a list of students.
     *
     * @param math_teacher The teacher responsible for teaching mathematics.
     * @param english_teacher The teacher responsible for teaching English.
     * @param polish_teacher The teacher responsible for teaching Polish language.
     * @param history_teacher The teacher responsible for teaching history.
     * @param biology_teacher The teacher responsible for teaching biology.
     * @param physics_teacher The teacher responsible for teaching physics.
     * @param chemistry_teacher The teacher responsible for teaching chemistry.
     * @param geography_teacher The teacher responsible for teaching geography.
     * @param computer_science_teacher The teacher responsible for teaching computer science.
     * @param physical_education_teacher The teacher responsible for teaching physical education.
     * @param super_vising_teacher The teacher supervising the class.
     * @param letter A character representing the class identifier (e.g., 'A', 'B').
     * @param students A vector containing students who are part of the class.
     */
    void add_class(Teacher &math_teacher, Teacher &english_teacher, Teacher &polish_teacher,
                   Teacher &history_teacher, Teacher &biology_teacher, Teacher &physics_teacher,
                   Teacher &chemistry_teacher,
                   Teacher &geography_teacher, Teacher &computer_science_teacher, Teacher &physical_education_teacher,
                   Teacher &super_vising_teacher, char letter, std::vector<Student> &students);

    /**
     * @brief Adds a new class to the school, assigning teachers, students, and specific properties to the class.
     *
     * @param math_teacher The teacher responsible for math classes.
     * @param english_teacher The teacher responsible for English classes.
     * @param polish_teacher The teacher responsible for Polish language classes.
     * @param history_teacher The teacher responsible for history classes.
     * @param biology_teacher The teacher responsible for biology classes.
     * @param physics_teacher The teacher responsible for physics classes.
     * @param chemistry_teacher The teacher responsible for chemistry classes.
     * @param geography_teacher The teacher responsible for geography classes.
     * @param computer_science_teacher The teacher responsible for computer science classes.
     * @param physical_education_teacher The teacher responsible for physical education classes.
     * @param super_vising_teacher The class's supervising teacher.
     * @param letter The letter identifier of the class.
     * @param students A list of students assigned to the class.
     * @param is_graduated Indicates whether the class has graduated.
     */
    void add_class( Teacher &math_teacher,  Teacher &english_teacher,  Teacher &polish_teacher,
                    Teacher &history_teacher,  Teacher &biology_teacher,  Teacher &physics_teacher,
                    Teacher &chemistry_teacher,
                    Teacher &geography_teacher,  Teacher &computer_science_teacher,  Teacher &physical_education_teacher,
                    Teacher &super_vising_teacher, char letter,  std::vector<Student> &students, bool is_graduated);

    /**
     * @brief Removes a class from the school based on the specified year and letter.
     * @param year The year of the class to be removed.
     * @param letter The letter identifier of the class to be removed.
     */
    void remove_class(int year, char letter);

    /**
     * @brief Adds a teacher to the list corresponding to their subject specialization within the school.
     *
     * This function organizes teachers into subject-specific groups based on the subject they teach,
     * enabling easy management of staff across different disciplines.
     *
     * @param teacher The teacher to be hired, whose subject specialization determines the group they are added to.
     */
    void hire_teacher(Teacher &teacher);

    /**
     * @brief Hires a new teacher and assigns them to a specific subject department.
     *
     * This method creates a teacher with the provided attributes and assigns them
     * to the relevant subject category based on the given subject. If the subject
     * is set to `None`, the teacher is not assigned to any department.
     *
     * @param first_name The first name of the teacher.
     * @param last_name The last name of the teacher.
     * @param email The email address of the teacher.
     * @param day The day of the teacher's date of birth.
     * @param month The month of the teacher's date of birth.
     * @param year The year of the teacher's date of birth.
     * @param salary The salary of the teacher.
     * @param subject The subject that the teacher specializes in and will teach.
     */
    void hire_teacher(const std::string &first_name, const std::string &last_name, const std::string &email,
                      const int &day, const int &month, const int &year, const int salary, const Subject &subject);

    /**
     * @brief Removes a teacher from the school by their unique identifier.
     * @param id The unique identifier of the teacher to be removed.
     */
    void fire_teacher(const int &id);

    /**
     * @brief Removes a teacher from the school based on their first and last name.
     * @param firstname The first name of the teacher to be removed.
     * @param lastname The last name of the teacher to be removed.
     */
    void fire_teacher(const std::string & firstname, const std::string & lastname);
};


#endif //PROJECT_SCHOOL_H
