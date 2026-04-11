//
// Created by olidiaks on 4/11/26.
//

#ifndef PROJECT_PERSON_H
#define PROJECT_PERSON_H
#include <string>


class Person {
private:
    int id;
    std::string firstName;
    std::string lastName;
    time_t birthDate;

public:
    Person(const int &id, const std::string &first_name, const std::string &last_name, const time_t birth_date)
        : id(id),
          firstName(first_name),
          lastName(last_name),
          birthDate(birth_date){};

    Person (const int &id, const std::string &first_name, const std::string &last_name, int day, int month, int year);

    [[nodiscard]] std::string get_first_name() const;

    void set_first_name(const std::string &first_name);

    [[nodiscard]] std::string get_last_name() const;

    void set_last_name(const std::string &last_name);

    [[nodiscard]] int get_id() const;

    [[nodiscard]] time_t get_birth_date() const;

    [[nodiscard]] int get_age() const;
};



#endif //PROJECT_PERSON_H
