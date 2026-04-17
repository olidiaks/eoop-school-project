//
// Created by olidiaks on 10.04.2026.
//

#ifndef PROJECT_TEACHER_H
#define PROJECT_TEACHER_H
#include <ostream>
#include <string>

#include "Person.h"


class Teacher : public Person {
private:
    int salary;
    std::string subject;

public:
    friend std::ostream & operator<<(std::ostream &os, const Teacher &obj);

    friend bool operator==(const Teacher &lhs, const Teacher &rhs);

    friend bool operator!=(const Teacher &lhs, const Teacher &rhs);

    Teacher(const std::string &first_name, const std::string &last_name, const std::string &email,
            const time_t birth_date, const int salary, const std::string &subject);

    Teacher(const std::string &first_name, const std::string &last_name, const std::string &email,
            const int &day, const int &month, const int &year, const int salary, const std::string &subject);

    [[nodiscard]] std::string get_subject() const;

    [[nodiscard]] int get_salary() const;

    void set_salary(const int salary);

    Teacher(const Teacher &other);

    Teacher(Teacher &&other) noexcept;

    Teacher & operator=(const Teacher &other);

    Teacher & operator=(Teacher &&other) noexcept;

    Teacher();
};


#endif //PROJECT_TEACHER_H