//
// Created by olidiaks on 4/11/26.
//

#ifndef PROJECT_PERSON_H
#define PROJECT_PERSON_H
#include <ostream>
#include <string>


class Person {
private:
    int id;
    std::string firstName;
    std::string lastName;
    std::string email;
    time_t birthDate;

public:
    Person();

    Person(const int &id, const std::string &first_name, const std::string &last_name, const std::string &email,
           const time_t birth_date);

    Person(const int &id, const std::string &first_name, const std::string &last_name, const std::string &email, const int &day, const int &month, const int &year);

    [[nodiscard]] std::string get_first_name() const;

    void set_first_name(const std::string &first_name);

    [[nodiscard]] std::string get_last_name() const;

    void set_last_name(const std::string &last_name);

    [[nodiscard]] int get_id() const;

    [[nodiscard]] time_t get_birth_date() const;

    [[nodiscard]] int get_age() const;

    [[nodiscard]] int get_day_of_birth() const;

    [[nodiscard]] int get_month_of_birth() const;

    [[nodiscard]] int get_year_of_birth() const;

    [[nodiscard]] std::string get_email() const;

    void set_email(const std::string &email);


    friend bool operator==(const Person &lhs, const Person &rhs);

    friend bool operator!=(const Person &lhs, const Person &rhs);

    friend std::ostream & operator<<(std::ostream &os, const Person &obj);

    Person(const Person &other);

    Person(Person &&other) noexcept;

    Person & operator=(const Person &other);

    Person & operator=(Person &&other) noexcept;
};


#endif //PROJECT_PERSON_H
