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

    void print_teachers() const;

    Student & get_student(const int &id) const;

    [[nodiscard]] int get_students_avarage_grade() const;

    friend bool operator==(const Class &lhs, const Class &rhs);

    friend bool operator!=(const Class &lhs, const Class &rhs);

    friend std::ostream & operator<<(std::ostream &os, const Class &obj);

    friend void swap(Class &lhs, Class &rhs) noexcept;

    friend std::istream & operator>>(std::istream &is, Class &obj);
};




#endif //PROJECT_CLASS_H
