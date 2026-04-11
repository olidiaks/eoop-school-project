//
// Created by olidiaks on 10.04.2026.
//

#ifndef PROJECT_STUDENT_H
#define PROJECT_STUDENT_H

#include <ostream>

#include "Person.h"


class Student : public Person {
private:
    int mathGrade;
    int englishGrade;
    int polishGrade;
    int historyGrade;
    int biologyGrade;
    int physicsGrade;
    int chemistryGrade;
    int geographyGrade;
    int computerScienceGrade;
    int physicalEducationGrade;
    void initGrades();

public:
    Student(const int &id, const std::string &first_name, const std::string &last_name, const std::string &email,
        const time_t birth_date)
        : Person(id, first_name, last_name, email, birth_date) {
        initGrades();
    }

    Student(const int &id, const std::string &first_name, const std::string &last_name, const std::string &email,
        const int &day, const int &month, const int &year)
        : Person(id, first_name, last_name, email, day, month, year) {
        initGrades();
    }

    Student(const int &id, const std::string &first_name, const std::string &last_name, const std::string &email,
        const time_t birth_date, const int math_grade, const int english_grade, const int polish_grade,
        const int history_grade, const int biology_grade, const int physics_grade, const int chemistry_grade,
        const int geography_grade, const int computer_science_grade, const int physical_education_grade)
        : Person(id, first_name, last_name, email, birth_date),
          mathGrade(math_grade),
          englishGrade(english_grade),
          polishGrade(polish_grade),
          historyGrade(history_grade),
          biologyGrade(biology_grade),
          physicsGrade(physics_grade),
          chemistryGrade(chemistry_grade),
          geographyGrade(geography_grade),
          computerScienceGrade(computer_science_grade),
          physicalEducationGrade(physical_education_grade) {
    }

    Student(const int &id, const std::string &first_name, const std::string &last_name, const std::string &email,
        const int &day, const int &month, const int &year, const int math_grade, const int english_grade,
        const int polish_grade, const int history_grade, const int biology_grade, const int physics_grade,
        const int chemistry_grade, const int geography_grade, const int computer_science_grade,
        const int physical_education_grade)
        : Person(id, first_name, last_name, email, day, month, year),
          mathGrade(math_grade),
          englishGrade(english_grade),
          polishGrade(polish_grade),
          historyGrade(history_grade),
          biologyGrade(biology_grade),
          physicsGrade(physics_grade),
          chemistryGrade(chemistry_grade),
          geographyGrade(geography_grade),
          computerScienceGrade(computer_science_grade),
          physicalEducationGrade(physical_education_grade) {
    }

    [[nodiscard]] int get_math_grade() const;

    void set_math_grade(const int math_grade);

    [[nodiscard]] int get_english_grade() const;

    void set_english_grade(const int english_grade);

    [[nodiscard]] int get_polish_grade() const;

    void set_polish_grade(const int polish_grade);

    [[nodiscard]] int get_history_grade() const;

    void set_history_grade(const int history_grade);

    [[nodiscard]] int get_biology_grade() const;

    void set_biology_grade(const int biology_grade);

    [[nodiscard]] int get_physics_grade() const;

    void set_physics_grade(const int physics_grade);

    [[nodiscard]] int get_chemistry_grade() const;

    void set_chemistry_grade(const int chemistry_grade);

    [[nodiscard]] int get_geography_grade() const;

    void set_geography_grade(const int geography_grade);

    [[nodiscard]] int get_computer_science_grade() const;

    void set_computer_science_grade(const int computer_science_grade);

    [[nodiscard]] int get_physical_education_grade() const;

    void set_physical_education_grade(const int physical_education_grade);

    friend std::ostream & operator<<(std::ostream &os, const Student &obj);

    friend bool operator==(const Student &lhs, const Student &rhs);

    friend bool operator!=(const Student &lhs, const Student &rhs);

    Student(const Student &other);

    Student(Student &&other) noexcept;

    Student & operator=(const Student &other);


    Student & operator=(Student &&other) noexcept;

    int get_average_grade() const;
};

#endif //PROJECT_STUDENT_H