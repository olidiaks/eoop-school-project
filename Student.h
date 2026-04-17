//
// Created by olidiaks on 10.04.2026.
//

#ifndef PROJECT_STUDENT_H
#define PROJECT_STUDENT_H

#include <ostream>

#include "Person.h"


class Student : public Person {
private:
    float mathGrade;
    float englishGrade;
    float polishGrade;
    float historyGrade;
    float biologyGrade;
    float physicsGrade;
    float chemistryGrade;
    float geographyGrade;
    float computerScienceGrade;
    float physicalEducationGrade;

    void initGrades();

public:
    Student(const int &id, const std::string &first_name, const std::string &last_name, const std::string &email,
            const time_t birth_date);

    Student(const int &id, const std::string &first_name, const std::string &last_name, const std::string &email,
            const int &day, const int &month, const int &year);


    Student(const float math_grade, const float english_grade, const float polish_grade, const float history_grade,
            const float biology_grade, const float physics_grade, const float chemistry_grade,
            const float geography_grade,
            const float computer_science_grade, const float physical_education_grade);

    Student(const int &id, const std::string &first_name, const std::string &last_name, const std::string &email,
            const time_t birth_date, const float math_grade, const float english_grade, const float polish_grade,
            const float history_grade, const float biology_grade, const float physics_grade,
            const float chemistry_grade,
            const float geography_grade, const float computer_science_grade, const float physical_education_grade
    );

    Student(const int &id, const std::string &first_name, const std::string &last_name, const std::string &email,
            const int &day, const int &month, const int &year, const float math_grade, const float english_grade,
            const float polish_grade, const float history_grade, const float biology_grade, const float physics_grade,
            const float chemistry_grade, const float geography_grade, const float computer_science_grade,
            const float physical_education_grade);

    Student(const Person &other, const float math_grade, const float english_grade, const float polish_grade,
            const float history_grade, const float biology_grade, const float physics_grade,
            const float chemistry_grade,
            const float geography_grade, const float computer_science_grade, const float physical_education_grade);

    Student(Person &&other, const float math_grade, const float english_grade, const float polish_grade,
            const float history_grade, const float biology_grade, const float physics_grade,
            const float chemistry_grade,
            const float geography_grade, const float computer_science_grade, const float physical_education_grade
    );

    [[nodiscard]] float get_math_grade() const;

    void set_math_grade(const float math_grade);

    [[nodiscard]] float get_english_grade() const;

    void set_english_grade(const float english_grade);

    [[nodiscard]] float get_polish_grade() const;

    void set_polish_grade(const float polish_grade);

    [[nodiscard]] float get_history_grade() const;

    void set_history_grade(const float history_grade);

    [[nodiscard]] float get_biology_grade() const;

    void set_biology_grade(const float biology_grade);

    [[nodiscard]] float get_physics_grade() const;

    void set_physics_grade(const float physics_grade);

    [[nodiscard]] float get_chemistry_grade() const;

    void set_chemistry_grade(const float chemistry_grade);

    [[nodiscard]] float get_geography_grade() const;

    void set_geography_grade(const float geography_grade);

    [[nodiscard]] float get_computer_science_grade() const;

    void set_computer_science_grade(const float computer_science_grade);

    [[nodiscard]] float get_physical_education_grade() const;

    void set_physical_education_grade(const float physical_education_grade);

    friend std::ostream &operator<<(std::ostream &os, const Student &obj);

    friend bool operator==(const Student &lhs, const Student &rhs);

    friend bool operator!=(const Student &lhs, const Student &rhs);

    Student(const Student &other);

    Student(Student &&other) noexcept;

    Student &operator=(const Student &other);

    Student &operator=(Student &&other) noexcept;

    [[nodiscard]] float get_average_grade() const;
};

#endif //PROJECT_STUDENT_H
