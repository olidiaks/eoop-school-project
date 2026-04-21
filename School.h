//
// Created by olidiaks on 10.04.2026.
//

#ifndef PROJECT_SCHOOL_H
#define PROJECT_SCHOOL_H
#include <list>
#include <ostream>

#include "Class.h"
#include "Teacher.h"


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
    [[nodiscard]] std::string print() const;

public:
    School();
     School(const std::list<Teacher> &math_teachers, const std::list<Teacher> &english_teachers,
        const std::list<Teacher> &polish_teachers, const std::list<Teacher> &history_teachers,
        const std::list<Teacher> &biology_teachers, const std::list<Teacher> &physics_teachers,
        const std::list<Teacher> &chemistry_teachers, const std::list<Teacher> &geography_teachers,
        const std::list<Teacher> &computer_science_teachers, const std::list<Teacher> &physical_education_teachers,
        const std::list<Teacher> &super_vising_teachers, const std::list<Class> &classes,
        const std::string &school_name);

    School(const School &other);

    School(School &&other) noexcept;

    School & operator=(const School &other);

    School & operator=(School &&other) noexcept;

    friend bool operator==(const School &lhs, const School &rhs);

    friend bool operator!=(const School &lhs, const School &rhs);

    friend std::ostream & operator<<(std::ostream &os, const School &obj);

    friend void swap(School &lhs, School &rhs) noexcept;

    [[nodiscard]] std::list<Teacher> get_math_teachers() const;

    void set_math_teachers(const std::list<Teacher> &math_teachers);

    [[nodiscard]] std::list<Teacher> get_english_teachers() const;

    void set_english_teachers(const std::list<Teacher> &english_teachers);

    [[nodiscard]] std::list<Teacher> get_polish_teachers() const;

    void set_polish_teachers(const std::list<Teacher> &polish_teachers);

    [[nodiscard]] std::list<Teacher> get_history_teachers() const;

    void set_history_teachers(const std::list<Teacher> &history_teachers);

    [[nodiscard]] std::list<Teacher> get_biology_teachers() const;

    void set_biology_teachers(const std::list<Teacher> &biology_teachers);

    [[nodiscard]] std::list<Teacher> get_physics_teachers() const;

    void set_physics_teachers(const std::list<Teacher> &physics_teachers);

    [[nodiscard]] std::list<Teacher> get_chemistry_teachers() const;

    void set_chemistry_teachers(const std::list<Teacher> &chemistry_teachers);

    [[nodiscard]] std::list<Teacher> get_geography_teachers() const;

    void set_geography_teachers(const std::list<Teacher> &geography_teachers);

    [[nodiscard]] std::list<Teacher> get_computer_science_teachers() const;

    void set_computer_science_teachers(const std::list<Teacher> &computer_science_teachers);

    [[nodiscard]] std::list<Teacher> get_physical_education_teachers() const;

    void set_physical_education_teachers(const std::list<Teacher> &physical_education_teachers);

    [[nodiscard]] std::list<Teacher> get_super_vising_teachers() const;

    void set_super_vising_teachers(const std::list<Teacher> &super_vising_teachers);

    [[nodiscard]] std::list<Class> get_classes() const;

    void set_classes(const std::list<Class> &classes);

    [[nodiscard]] float get_average_students_grades_of_teacher(const int &id) const;

    [[nodiscard]] std::string get_name() const;

    void set_name(const std::string &name);
};


#endif //PROJECT_SCHOOL_H