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
    std::string subject;
    static int counter;

public:
    Assigment(const std::string &name, const std::string &description, const std::string &subject);

    Assigment(const Assigment &other);

    Assigment(Assigment &&other) noexcept;

    Assigment & operator=(const Assigment &other);

    Assigment & operator=(Assigment &&other) noexcept;

    [[nodiscard]] int get_id() const;

    [[nodiscard]] std::string get_subject() const;

    [[nodiscard]] std::string get_name() const;

    void set_name(const std::string &name);

    [[nodiscard]] std::string get_description() const;

    void set_description(const std::string &description);

    friend bool operator==(const Assigment &lhs, const Assigment &rhs);

    friend bool operator!=(const Assigment &lhs, const Assigment &rhs);

    friend std::ostream & operator<<(std::ostream &os, const Assigment &obj);

    friend void swap(Assigment &lhs, Assigment &rhs) noexcept;

};


#endif //PROJECT_ASSIGMENT_H
