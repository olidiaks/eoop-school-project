//
// Created by olidiaks on 10.04.2026.
//

#ifndef PROJECT_CLASS_H
#define PROJECT_CLASS_H
#include <vector>
#include <ostream>

#include "Student.h"
#include "Teacher.h"


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

    int find_student_index(const int &id) const;

public:
    Class(Teacher &math_teacher, Teacher &english_teacher, Teacher &polish_teacher,
        Teacher &history_teacher, Teacher &biology_teacher, Teacher &physics_teacher, Teacher &chemistry_teacher,
        Teacher &geography_teacher, Teacher &computer_science_teacher, Teacher &physical_education_teacher,
        Teacher &super_vising_teacher);

    Class(const Class &other);

    Class(Class &&other) noexcept;

    Class & operator=(const Class &other);

    Class & operator=(Class &&other) noexcept;

    void add_student(const Student &student);

    void add_student(const std::string &first_name, const std::string &last_name, const std::string &email,
            const int &day, const int &month, const int &year);

    bool remove_student(const int &id);

    [[nodiscard]] bool is_student_in_class(const int &id) const;

    void print_students() const;

    void print_teachers() const;

    const Student &get_student(const int &id) const;

    [[nodiscard]] int get_average_grade_of_clas_from_subject(const Subject &subject) const;

    friend bool operator==(const Class &lhs, const Class &rhs);

    friend bool operator!=(const Class &lhs, const Class &rhs);

    friend std::ostream & operator<<(std::ostream &os, const Class &obj);

    friend void swap(Class &lhs, Class &rhs) noexcept;

    friend std::istream & operator>>(std::istream &is, Class &obj);

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

    [[nodiscard]] float get_average_grade() const;

    [[nodiscard]] float get_average_grade_from_subject(const std::string &subject) const;

    [[nodiscard]] unsigned long get_count_of_students() const;

    [[nodiscard]] int get_sum_of_grades_from_subject(const Subject &subject) const;

    [[nodiscard]] int get_count_of_grades_from_subject(const Subject &subject) const;

    [[nodiscard]] float get_average_grade_of_class();
};

std::ostream & operator<<(std::ostream & os, const std::vector<Student> & students);



#endif //PROJECT_CLASS_H
