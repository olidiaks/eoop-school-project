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

    Class(Teacher &math_teacher, Teacher &english_teacher, Teacher &polish_teacher, Teacher &history_teacher,
        Teacher &biology_teacher, Teacher &physics_teacher, Teacher &chemistry_teacher, Teacher &geography_teacher,
        Teacher &computer_science_teacher, Teacher &physical_education_teacher, Teacher &super_vising_teacher,
        const std::vector<Student> &students, int year, char letter);

    Class(Teacher &math_teacher, Teacher &english_teacher, Teacher &polish_teacher, Teacher &history_teacher,
        Teacher &biology_teacher, Teacher &physics_teacher, Teacher &chemistry_teacher, Teacher &geography_teacher,
        Teacher &computer_science_teacher, Teacher &physical_education_teacher, Teacher &super_vising_teacher,
        const std::vector<Student> &students, char letter);

    Class(Teacher &math_teacher, Teacher &english_teacher, Teacher &polish_teacher, Teacher &history_teacher,
          Teacher &biology_teacher, Teacher &physics_teacher, Teacher &chemistry_teacher, Teacher &geography_teacher,
          Teacher &computer_science_teacher, Teacher &physical_education_teacher, Teacher &super_vising_teacher,
          bool is_class_graduated);

    Class(Teacher &math_teacher, Teacher &english_teacher, Teacher &polish_teacher, Teacher &history_teacher,
        Teacher &biology_teacher, Teacher &physics_teacher, Teacher &chemistry_teacher, Teacher &geography_teacher,
        Teacher &computer_science_teacher, Teacher &physical_education_teacher, Teacher &super_vising_teacher,
        const char letter);

    Class(const Class &other);

    Class(Class &&other) noexcept;

    Class( Teacher & math_teacher,  Teacher & english_teacher,  Teacher & polish_teacher,  Teacher & history_teacher,  Teacher & biology_teacher,  Teacher & physics_teacher,  Teacher & chemistry_teacher,
           Teacher & geography_teacher,  Teacher & computer_science_teacher,  Teacher & physical_education_teacher,  Teacher & super_vising_teacher,  std::vector<Student> & students, char letter);

    Class(Teacher &math_teacher, Teacher &english_teacher, Teacher &polish_teacher, Teacher &history_teacher,
        Teacher &biology_teacher, Teacher &physics_teacher, Teacher &chemistry_teacher, Teacher &geography_teacher,
        Teacher &computer_science_teacher, Teacher &physical_education_teacher, Teacher &super_vising_teacher,
        const std::vector<Student> &students, bool is_class_graduated, char letter);

    Class & operator=(const Class &other);

    Class & operator=(Class &&other) noexcept;

    [[nodiscard]] bool is_is_class_graduated() const;

    [[nodiscard]] int get_year() const;

    [[nodiscard]] char get_letter() const;

    void add_student(const Student &student);

    void add_student(const std::string &first_name, const std::string &last_name, const std::string &email,
            const int &day, const int &month, const int &year);

    bool remove_student(const int &id);

    [[nodiscard]] bool is_student_in_class(const int &id) const;

    void print_students() const;

    void print_teachers() const;

    const Student &get_student(const int &id) const;

    std::vector<Student> &get_students();

    [[nodiscard]] int get_average_grade_of_clas_from_subject(const Subject &subject) const;

    friend bool operator==(const Class &lhs, const Class &rhs);

    friend bool operator!=(const Class &lhs, const Class &rhs);

    friend std::ostream & operator<<(std::ostream &os, const Class &obj);

    friend void swap(Class &lhs, Class &rhs) noexcept;

    [[nodiscard]] Teacher get_math_teacher() const;

    void set_math_teacher(const Teacher &math_teacher);

    [[nodiscard]] Teacher get_english_teacher() const;

    void set_english_teacher(const Teacher &english_teacher);

    [[nodiscard]] Teacher get_polish_teacher() const;

    void set_polish_teacher(const Teacher &polish_teacher);

    [[nodiscard]] Teacher get_history_teacher() const;

    void set_history_teacher(const Teacher &history_teacher);

    [[nodiscard]] Teacher get_biology_teacher() const;

    void set_biology_teacher(const Teacher &biology_teacher);

    [[nodiscard]] Teacher get_physics_teacher() const;

    void set_physics_teacher(const Teacher &physics_teacher);

    [[nodiscard]] Teacher get_chemistry_teacher() const;

    void set_chemistry_teacher(const Teacher &chemistry_teacher);

    [[nodiscard]] Teacher get_geography_teacher() const;

    void set_geography_teacher(const Teacher &geography_teacher);

    [[nodiscard]] Teacher get_computer_science_teacher() const;

    void set_computer_science_teacher(const Teacher &computer_science_teacher);

    [[nodiscard]] Teacher get_physical_education_teacher() const;

    void set_physical_education_teacher(const Teacher &physical_education_teacher);

    [[nodiscard]] Teacher get_super_vising_teacher() const;

    void set_super_vising_teacher(const Teacher &super_vising_teacher);

    [[nodiscard]] int get_id() const;

    [[nodiscard]] unsigned long get_count_of_students() const;

    [[nodiscard]] int get_sum_of_grades_from_subject(const Subject &subject) const;

    [[nodiscard]] int get_count_of_grades_from_subject(const Subject &subject) const;

    [[nodiscard]] float get_average_grade_of_class();

    void add_assignment(const Subject &subject, const Assigment &assigment);

    void add_assignment(const Subject &subject, const std::string &name, const std::string &description);

    void add_assignment(const Subject &subject, const Assigment &assigment, int grade);

    void add_assignment(const Subject &subject, const Assigment_graded &assigment);

    void add_assignment(const Subject &subject, Assigment_graded &assigment_graded, const int grade);

    void new_school_year();
};

std::ostream & operator<<(std::ostream & os, const std::vector<Student> & students);



#endif //PROJECT_CLASS_H
