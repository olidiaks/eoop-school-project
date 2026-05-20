//
// Created by olidiaks on 10.04.2026.
//

#include "School.h"

#include <algorithm>



School::School() = default;

const Teacher &School::find_teacher(int id) const {
    for (auto & [subject,department] : teachers) {
        for (const Teacher &teacher : department) {
            if (teacher.get_id() == id) {
                return teacher;
            }
        }
    }
    throw std::runtime_error("Teacher with id " + std::to_string(id) + " not found");
}

const Teacher &School::find_teacher(const std::string &first_name, const std::string &last_name) const {
    for (auto & [subject, department] : teachers) {
        for (auto & teacher : department) {
            if (teacher.get_first_name() == first_name && teacher.get_last_name() == last_name) {
                return teacher;
            }
        }
    }
    throw std::runtime_error("Teacher " + first_name + " " + last_name + " not found");
}



School::School(const School &other) : teachers(other.teachers),
                                      name(other.name),
                                      classes(other.classes) {
}

School::School(School &&other) noexcept : teachers(std::move(other.teachers)),
                                          classes(std::move(other.classes)),
                                          name(other.name) {
}

School &School::operator=(const School &other) {
    if (this == &other)
        return *this;
    teachers = other.teachers;
    classes = other.classes;
    name = other.name;
    return *this;
}

School &School::operator=(School &&other) noexcept {
    if (this == &other)
        return *this;
    teachers = std::move(other.teachers);
    classes = std::move(other.classes);
    name = std::move(other.name);
    return *this;
}

bool School::operator==(const School &obj) const{
    return teachers == obj.teachers
           && classes == obj.classes
           && name == obj.name;
}

bool School::operator!=(const School &rhs) const {
    return !(*this == rhs);
}



std::ostream & operator<<(std::ostream &os, const School &obj) {
    return os
           << "teachers: " << obj.teachers
           << " classes: " << obj.classes
           << " name: " << obj.name;
}

void School::swap(School &obj) noexcept {
    using std::swap;
    swap(teachers, obj.teachers);
    swap(classes, obj.classes);
    swap(name, obj.name);
}

std::list<Class> &School::get_classes() {
    return classes;
}

void School::set_classes(const std::list<Class> &classes) {
    this->classes = classes;
}

float School::get_average_students_grades_of_teacher(const int &id) const {
    unsigned long count = 0;
    unsigned long sum = 0;

    const Teacher &teacher = find_teacher(id);
    for (auto &i : classes) {
        if (i.is_teacher_teaching(teacher)) {
            for (auto &student : i.get_students()) {
                sum += student.get_average_grade();
                count++;
            }
        }
    }
    return count == 0 ? 0 : static_cast<float>(sum) / count;
}

float School::get_average_grade_of_school() const {
    unsigned long count = 0;
    unsigned long sum = 0;

    for (auto &i : classes) {
        for (auto &student : i.get_students()) {
            sum += student.get_sum_of_grades_from_all_subjects();
            count += student.get_count_of_grades_from_all_subjects();
        }
    }

    return count == 0 ? 0 : static_cast<float>(sum) / count;
}

std::string School::get_name() const {
    return name;
}

void School::set_name(const std::string &name) {
    this->name = name;
}

void School::new_school_year() {
    for (auto &i: classes) {
        i.new_school_year();
    }
}

void School::add_class(const Class &class_to_add) {
    classes.push_back(class_to_add);
}

void School::add_class(const std::vector<Teacher> &teachers,
                       Teacher &super_vising_teacher, int year, char letter, const std::vector<Student> &students) {
    std::map<Subject, const Teacher&> teachers_map;
    for (const auto &teacher : teachers) {
        teachers_map.emplace(teacher.get_subject(), teacher);
    }
    classes.emplace_back(year, letter, super_vising_teacher, teachers_map, students);
}

void School::add_class(const Teacher &super_vising_teacher, const std::map<Subject, const Teacher &> &teachers, char letter,
                       std::vector<Student> &students) {
    classes.emplace_back(letter, super_vising_teacher, teachers, students);
}

Class &School::add_class(const Teacher &super_vising_teacher, const std::map<Subject, const Teacher &> &teachers, char letter) {
    classes.emplace_back(letter, super_vising_teacher, teachers);
    return classes.back();
}

Class &School::add_class(const Teacher &super_vising_teacher, const std::vector<Student> &students, char letter) {
    classes.emplace_back(letter, super_vising_teacher, students);
    return classes.back();
}

Class &School::add_class(const Teacher &super_vising_teacher, char letter) {
    classes.emplace_back(letter, super_vising_teacher);
    return classes.back();
}


void School::remove_class(int year, char letter) {
    auto it = std::ranges::find_if(classes, [year, letter](const Class &c) {
        return c.get_year() == year && c.get_letter() == letter;
    });
    if (it != classes.end()) {
        classes.erase(it);
    }
}

void School::hire_teacher(const Teacher &teacher) {
    const Subject &subject = teacher.get_subject();
    teachers[subject].push_back(teacher);
}

void School::hire_teacher(const std::string &first_name, const std::string &last_name, const std::string &email,
                          const int &day, const int &month, const int &year, const int salary, const Subject &subject) {
   teachers[subject].emplace_back(first_name, last_name, email, day, month, year, salary, subject);
}

bool School::fire_teacher(const int &id) {
    for (auto &[subject, i_teachers]: teachers) {
        for (auto it = i_teachers.begin(); it != i_teachers.end(); ++it) {
            if (it->get_id() == id) {
                i_teachers.erase(it);
                if (i_teachers.empty()) {
                    teachers.erase(subject);
                }
                return true;
            }
        }
    }
    return false;
}

int School::fire_teacher(const std::string &firstname, const std::string &lastname) {
    int total_removed = 0;
    for (auto it = teachers.begin(); it != teachers.end(); ) {
        std::vector<Teacher> & teacher_vec = it->second;
        auto removed = std::erase_if(teacher_vec, [&firstname, &lastname](const Teacher& t) {
            return t.get_first_name() == firstname && t.get_last_name() == lastname;
        });
        total_removed += removed;
        if (teacher_vec.empty()) {
            it = teachers.erase(it);
        } else {
            ++it;
        }
    }
    return total_removed;
}

std::ostream & operator<<(std::ostream &os, const std::map<Subject, std::vector<Teacher>> &map) {
    os << "Teachers: " << std::endl;
    for (const auto &teacher: map) {
        os << "Subject:" << teacher.first << std::endl
        << "Teacher: " << teacher.second << std::endl;
    }
    return os;
}
