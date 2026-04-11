//
// Created by olidiaks on 10.04.2026.
//

#ifndef PROJECT_CLASS_H
#define PROJECT_CLASS_H
#include <ostream>

#include "Student.h"
#include "Teacher.h"


class Class {
private:
    int id;
    int numberOfStudents;
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
    Student students[25];
    std::ostream & list_students(std::ostream &os);

public:
    Class(const int id, Teacher *const math_teacher, Teacher *const english_teacher, Teacher *const polish_teacher,
          Teacher *const history_teacher, Teacher *const biology_teacher, Teacher *const physics_teacher,
          Teacher *const chemistry_teacher, Teacher *const geography_teacher, Teacher *const computer_science_teacher,
          Teacher *const physical_education_teacher, Teacher *const super_vising_teacher);

    Class(const Class &other);

    Class(Class &&other) noexcept;

    Class & operator=(const Class &other);

    Class & operator=(Class &&other) noexcept;

    void add_student(Student student);

    bool remove_student(const int &id) const;

    [[nodiscard]] bool is_student_in_class(const int &id) const;

    void print_students() const;

    std::string & format_students () const;

    void print_teachers() const;

    Student & get_student(const int &id) const;

    [[nodiscard]] int get_students_avarage_grade() const;

    friend bool operator==(const Class &lhs, const Class &rhs);

    friend bool operator!=(const Class &lhs, const Class &rhs);

    friend std::ostream & operator<<(std::ostream &os, const Class &obj);

    friend void swap(Class &lhs, Class &rhs) noexcept;

    friend std::istream & operator>>(std::istream &is, Class &obj);

    [[nodiscard]] int get_number_of_students() const;

    void set_number_of_students(const int number_of_students);

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
};




#endif //PROJECT_CLASS_H
