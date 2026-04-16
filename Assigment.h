//
// Created by olidiaks on 4/16/26.
//

#ifndef PROJECT_ASSIGMENT_H
#define PROJECT_ASSIGMENT_H
#include <ostream>
#include <string>


class Assigment {
private:
    int id;
    std::string name;
    std::string description;
    int grade;

public:
    [[nodiscard]] Assigment(const int id, const std::string &name, const std::string &description, const int grade);

    Assigment(const Assigment &other);

    Assigment(Assigment &&other) noexcept;

    Assigment &operator=(const Assigment &other);

    Assigment &operator=(Assigment &&other) noexcept;

    friend bool operator==(const Assigment &lhs, const Assigment &rhs);

    friend bool operator!=(const Assigment &lhs, const Assigment &rhs);

    friend std::ostream &operator<<(std::ostream &os, const Assigment &obj);

    friend void swap(Assigment &lhs, Assigment &rhs) noexcept;

    [[nodiscard]] int get_id() const;

    [[nodiscard]] std::string get_name() const;

    void set_name(const std::string &name);

    [[nodiscard]] std::string get_description() const;

    void set_description(const std::string &description);

    [[nodiscard]] int get_grade() const;

    void set_grade(const int grade);
};


#endif //PROJECT_ASSIGMENT_H
