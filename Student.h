//
// Created by olidiaks on 10.04.2026.
//

#ifndef PROJECT_STUDENT_H
#define PROJECT_STUDENT_H
#include <string>


class Student {
private:
    std::string firstName;
    std::string lastName;
    int studentID;
    int age;
    static int studentsCount;
public:
    Student(const std::string &first_name, const std::string &last_name, const int student_id, const int age);

    std::string first_name() const;

    void set_first_name(const std::string &first_name);

    std::string get_last_name() const;

    void set_last_name(const std::string &last_name);

    int get_student_id() const;

    void set_student_id(int student_id);

    int get_age() const;

    void set_age(int age);
};


#endif //PROJECT_STUDENT_H