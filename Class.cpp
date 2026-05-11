//
// Created by olidiaks on 10.04.2026.
//

#include "Class.h"

#include <algorithm>
#include <iostream>
#include <ranges>

int Class::counter = 0;

bool Class::is_teacher_assigned(const Teacher &teacher) const {
    Subject subject = teacher.get_subject();
    try {
        teachers.at(subject);
    } catch (std::out_of_range &e) {
        return false;
    }
    return true;
}

bool Class::is_student_assigned(const Student &student) const {
    return std::any_of(students.begin(), students.end(), [&](const Student &_student) {return _student == student;});
}

bool Class::is_student_assigned(const std::string &firstname, const std::string &last_name, const std::string &email,
    int day, int month, int year) {
    return std::any_of(students.begin(), students.end(),
                        [firstname, last_name, email, day, month, year](const Student &_student) {
                            return _student.get_first_name() == firstname && _student.get_last_name() == last_name && _student.get_email() == email && _student.get_day_of_birth() == day && _student.get_month_of_birth() == month && _student.get_year_of_birth() == year;
                        });
}

int Class::find_student_index(const int &id) const {
    int i = 0;
    for (const auto &student: students) {
        if (student.get_id() == id) {
            return i;
        }
        i++;
    }

    return -1;
}

Class::Class(const Teacher &supervisingTeacher, int year, char letter) : supervising_teacher(supervisingTeacher),
                                                                         isClassGraduated(false) {
    id = ++counter;
    this->year = year;
    this->letter = letter;
}

Class::Class(char letter, const Teacher &supervisingTeacher, const std::map<Subject, Teacher &> &teachers,
    const std::vector<Student> &students) : supervising_teacher(supervisingTeacher), letter(letter), year(1), isClassGraduated(false), teachers(teachers), students(students) {
    id = ++counter;
}

Class::Class(char letter, const Teacher &supervisingTeacher, const std::map<Subject, Teacher &> &teachers) : letter(letter), supervising_teacher(supervisingTeacher), teachers(teachers), year(1), isClassGraduated(false)  {
    id = ++counter;
}

Class::Class(Class &&other) noexcept : id(other.id), supervising_teacher(other.supervising_teacher),
                                       teachers(std::move(other.teachers)),
                                       students(std::move(other.students)), isClassGraduated(other.isClassGraduated),
                                       year(other.year), letter(other.letter) {
}

Class &Class::operator=(const Class &other) {
    if (this == &other)
        return *this;
    id = other.id;
    teachers = other.teachers;
    students = other.students;
    isClassGraduated = other.isClassGraduated;
    year = other.year;
    letter = other.letter;
    return *this;
}

Class &Class::operator=(Class &&other) noexcept {
    if (this == &other)
        return *this;
    id = other.id;
    teachers = std::move(other.teachers);
    students = std::move(other.students);
    isClassGraduated = other.isClassGraduated;
    year = other.year;
    letter = other.letter;
    return *this;
}

bool Class::is_class_graduated() const {
    return isClassGraduated;
}

int Class::get_year() const {
    return year;
}

char Class::get_letter() const {
    return letter;
}

bool Class::add_student(const Student &student) {
    if (is_student_assigned(student)) return false;
    students.push_back(student);
    return true;
}

bool Class::add_student(const std::string &first_name, const std::string &last_name, const std::string &email,
                        const int &day, const int &month, const int &year) {
    if (is_student_assigned(first_name, last_name, email, day, month, year)) return false;
    students.emplace_back(first_name, last_name, email, day, month, year);
    return true;
}

bool Class::remove_student(const int &id) {
    int student_index = find_student_index(id);
    if (student_index == -1) {
        return false;
    }
    students.erase(students.begin() + student_index);
    return true;
}

bool Class::is_student_in_class(const int &id) const {
    return find_student_index(id) != -1;
}

void Class::print_students() const {
    std::cout << students << std::endl;
}

std::ostream & operator<<(std::ostream & os, const std::vector<Teacher> & vector) {
    for (const Teacher & teacher: vector) {
        os << teacher.get_subject() << " teacher:" << std::endl << teacher << std::endl;
    }
    return os;
}

void Class::print_teachers() const {
    std::cout << teachers << std::endl;
}

const Student &Class::get_student(const int &id) const {
    int student_index = find_student_index(id);
    if (student_index == -1) {
        throw std::runtime_error("Student with id " + std::to_string(id) + " not found");
    }
    return students.at(student_index);
}

std::vector<Student> &Class::get_students() {
    return students;
}

const std::vector<Student> &Class::get_students() const{
    return students;
}

int Class::get_average_grade_of_clas_from_subject(const Subject &subject) const {
    int sum = 0;
    unsigned long count = 0;
    for (const auto &student: students) {
        sum += student.get_sum_of_grades_from_subjects(subject);
        count += student.get_count_of_grades_from_students_subjects(subject);
    }

    if (count == 0) {
        return 0;
    }

    return sum / count;
}

bool Class::operator==(const Class &rhs) const {
    bool is_equal = id == rhs.id
           && teachers == rhs.teachers
           && isClassGraduated == rhs.isClassGraduated
           && year == rhs.year
           && letter == rhs.letter;;;

    if (!is_equal) {
        return false;
    }

    for (const auto &student: students) {
        bool are_students_equal = false;
        for (const auto &other_student: rhs.students) {
            if (student == other_student) {
                are_students_equal = true;
            }
        }
        if (!are_students_equal) {
            return false;
        }
    }

    return true;
}

bool Class::operator!=(const Class &rhs) const {
    return !(*this == rhs);
}

std::ostream &operator<<(std::ostream &os, const std::map<Subject, Teacher &> &map) {
    os << "Teachers: " << std::endl;
    for (const auto &teacher: map) {
        os << "Subject:" << teacher.first << "Teacher: " << teacher.second << std::endl;
    }
    return os;
};

std::ostream &operator<<(std::ostream &os, const Class &obj) {
    return os
           << "id: " << obj.id << std::endl
           << " year: " << obj.year << std::endl
           << " letter: " << obj.letter << std::endl
           << " isClassGraduated: " << obj.isClassGraduated << std::endl
           << " teachers: " << obj.teachers
           << " students: " << obj.students;
}

void swap(Class &lhs, Class &rhs) noexcept {
    using std::swap;
    swap(lhs.id, rhs.id);
    swap(lhs.teachers, rhs.teachers);
    swap(lhs.students, rhs.students);
    swap(lhs.isClassGraduated, rhs.isClassGraduated);
    swap(lhs.year, rhs.year);
    swap(lhs.letter, rhs.letter);
}

int Class::get_id() const {
    return id;
}

unsigned long Class::get_count_of_students() const {
    return students.size();
}

int Class::get_sum_of_grades_from_subject(const Subject &subject) const {
    int sum = 0;

    for (const auto &student: students) {
        sum += student.get_sum_of_grades_from_subjects(subject);
    }

    return sum;
}

int Class::get_count_of_grades_from_subject(const Subject &subject) const {
    unsigned long count = 0;

    for (const auto &student: students) {
        count += student.get_count_of_grades_from_students_subjects(subject);
    }

    return count;
}

float Class::get_average_grade_of_class() const {
    unsigned long count = 0;
    int sum = 0;

    constexpr std::array<Subject, 10> subjects = {
        Subject::Biology, Subject::Chemistry, Subject::ComputerScience, Subject::English, Subject::Geography,
        Subject::History, Subject::Math, Subject::Physics, Subject::PhysicalEducation, Subject::Polish
    };

    for (const auto &student: students) {
        for (const auto &subject: subjects) {
            sum += student.get_sum_of_grades_from_subjects(subject);
            count += student.get_count_of_grades_from_students_subjects(subject);
        }
    }

    if (count == 0) {
        return 0;
    }

    return sum / count;
}

void Class::add_assignment(const Subject &subject, const Assignment &assigment) {
    for (auto &student: students) {
        student.add_assignment(subject, assigment);
    }
}

void Class::add_assignment(const Subject &subject, const std::string &name, const std::string &description) {
    for (auto &student: students) {
        student.add_assignment(subject, name, description);
    }
}

void Class::add_assignment(const Subject &subject, const Assignment &assignment, int grade) {
    for (auto &student: students) {
        student.add_assignment(subject, assignment, grade);
    }
}

void Class::add_assignment(const Subject &subject, const std::string &name, const std::string &description, int grade) {
    for (auto &student: students) {
        student.add_assignment(subject, name, description, grade);
    }
}

bool Class::add_teacher(const Teacher &teacher) {
    if (is_teacher_assigned(teacher)) return false;
    Subject subject = teacher.get_subject();
    teachers[subject] = teacher;
    return true;
}

bool Class::remove_teacher(const int &id) {
    if (teachers.empty()) return false;

    const auto it = teachers.begin();

    for (auto i = it; i != teachers.end(); ++i) {
        if (i->second.get_id() == id) {
            teachers.erase(i);
            return true;
        }
    }

    return false;
}

bool Class::remove_teacher(const Teacher &teacher) {
    if (teachers.empty()) return false;
    Subject subject = teacher.get_subject();
    if (teachers.erase(subject) > 0) return true;
    return false;
}

void Class::new_school_year() {
    if (++year == 5) {
        year = -1;
        isClassGraduated = true;
    }
}

std::vector<Subject> Class::get_subjects() const {
    std::vector<Subject> subjects;
    for (const auto &subject: teachers | std::views::keys) {
        subjects.push_back(subject);
    }
    return subjects;
}

std::ostream &operator<<(std::ostream &os, const std::vector<Student> &students) {
    for (const Student &student: students) {
        os << student << std::endl;
    }
    return os;
}

std::ostream &operator<<(std::ostream &os, const std::list<Class> &classes) {
    for (const Class &class_: classes) {
        os << class_ << std::endl;
    }
    return os;
}

std::ostream &operator<<(std::ostream &os, const std::vector<Teacher> &vector) {
    for (const Teacher &teacher: vector) {
        os << teacher.get_subject() << " teacher:" << std::endl << teacher << std::endl;
    }
    return os;
}
