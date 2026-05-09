//
// Created by olidiaks on 10.04.2026.
//

#include "Class.h"

#include <iostream>

int Class::counter = 0;

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

Class::Class(const Class &other) : id(other.id),
                                   mathTeacher(other.mathTeacher),
                                   englishTeacher(other.englishTeacher),
                                   polishTeacher(other.polishTeacher),
                                   historyTeacher(other.historyTeacher),
                                   biologyTeacher(other.biologyTeacher),
                                   physicsTeacher(other.physicsTeacher),
                                   chemistryTeacher(other.chemistryTeacher),
                                   geographyTeacher(other.geographyTeacher),
                                   computerScienceTeacher(other.computerScienceTeacher),
                                   physicalEducationTeacher(other.physicalEducationTeacher),
                                   superVisingTeacher(other.superVisingTeacher),
                                   students(other.students), isClassGraduated(other.isClassGraduated), year(other.year),
                                   letter(other.letter) {
}

Class::Class(Class &&other) noexcept : id(other.id),
                                       mathTeacher(other.mathTeacher),
                                       englishTeacher(other.englishTeacher),
                                       polishTeacher(other.polishTeacher),
                                       historyTeacher(other.historyTeacher),
                                       biologyTeacher(other.biologyTeacher),
                                       physicsTeacher(other.physicsTeacher),
                                       chemistryTeacher(other.chemistryTeacher),
                                       geographyTeacher(other.geographyTeacher),
                                       computerScienceTeacher(other.computerScienceTeacher),
                                       physicalEducationTeacher(other.physicalEducationTeacher),
                                       superVisingTeacher(other.superVisingTeacher),
                                       students(std::move(other.students)), isClassGraduated(other.isClassGraduated),
                                       year(other.year), letter(other.letter) {
}

Class &Class::operator=(const Class &other) {
    if (this == &other)
        return *this;
    id = other.id;
    mathTeacher = other.mathTeacher;
    englishTeacher = other.englishTeacher;
    polishTeacher = other.polishTeacher;
    historyTeacher = other.historyTeacher;
    biologyTeacher = other.biologyTeacher;
    physicsTeacher = other.physicsTeacher;
    chemistryTeacher = other.chemistryTeacher;
    geographyTeacher = other.geographyTeacher;
    computerScienceTeacher = other.computerScienceTeacher;
    physicalEducationTeacher = other.physicalEducationTeacher;
    superVisingTeacher = other.superVisingTeacher;
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
    mathTeacher = other.mathTeacher;
    englishTeacher = other.englishTeacher;
    polishTeacher = other.polishTeacher;
    historyTeacher = other.historyTeacher;
    biologyTeacher = other.biologyTeacher;
    physicsTeacher = other.physicsTeacher;
    chemistryTeacher = other.chemistryTeacher;
    geographyTeacher = other.geographyTeacher;
    computerScienceTeacher = other.computerScienceTeacher;
    physicalEducationTeacher = other.physicalEducationTeacher;
    superVisingTeacher = other.superVisingTeacher;
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

void Class::add_student(const Student &student) {
    students.push_back(student);
}

void Class::add_student(const std::string &first_name, const std::string &last_name, const std::string &email,
                        const int &day, const int &month, const int &year) {
    students.emplace_back(first_name, last_name, email, day, month, year);
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

void Class::print_teachers() const {
    std::cout << " mathTeacher: " << mathTeacher
            << " englishTeacher: " << englishTeacher
            << " polishTeacher: " << polishTeacher
            << " historyTeacher: " << historyTeacher
            << " biologyTeacher: " << biologyTeacher
            << " physicsTeacher: " << physicsTeacher
            << " chemistryTeacher: " << chemistryTeacher
            << " geographyTeacher: " << geographyTeacher
            << " computerScienceTeacher: " << computerScienceTeacher
            << " physicalEducationTeacher: " << physicalEducationTeacher
            << " superVisingTeacher: " << superVisingTeacher << std::endl;
}

const Student &Class::get_student(const int &id) const {
    int student_index = find_student_index(id);
    if (student_index == -1) {
        throw std::runtime_error("Student with id " + std::to_string(id) + " not found");
    }
    return students.at(student_index);
}

const std::vector<Student> &Class::get_students() const{
    return students;
}

int Class::get_average_grade_of_clas_from_subject(const Subject &subject) const {
    int sum = 0;
    int count = 0;
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
           && mathTeacher == rhs.mathTeacher
           && englishTeacher == rhs.englishTeacher
           && polishTeacher == rhs.polishTeacher
           && historyTeacher == rhs.historyTeacher
           && biologyTeacher == rhs.biologyTeacher
           && physicsTeacher == rhs.physicsTeacher
           && chemistryTeacher == rhs.chemistryTeacher
           && geographyTeacher == rhs.geographyTeacher
           && computerScienceTeacher == rhs.computerScienceTeacher
           && physicalEducationTeacher == rhs.physicalEducationTeacher
           && superVisingTeacher == rhs.superVisingTeacher
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
    int count = 0;

    for (const auto &student: students) {
        count += student.get_count_of_grades_from_students_subjects(subject);
    }

    return count;
}

float Class::get_average_grade_of_class() {
    int count = 0;
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

void Class::add_teacher(const Teacher &teacher) {
    teachers.push_back(teacher);
}

void Class::add_teacher(const std::string &first_name, const std::string &last_name, const std::string &email,
    const int &day, const int &month, const int &year, const Subject &subject, int salary) {
    teachers.emplace_back(first_name, last_name, email, day, month, year, salary, subject);
}

void Class::new_school_year() {
    if (++year == 5) {
        year = -1;
        isClassGraduated = true;
    }
}



bool Class::operator!=(const Class &rhs) const {
    return !(*this == rhs);
}


std::ostream &operator<<(std::ostream &os, const std::vector<Student> &students) {
    for (const Student &student: students) {
        os << student << std::endl;
    }
    return os;
}

std::ostream & operator<<(std::ostream &os, const std::list<Class> &classes) {
    for (const Class &class_ : classes) {
        os << class_ << std::endl;
    }
    return os;
}

std::ostream &operator<<(std::ostream &os, const Class &obj) {
    return os
           << "id: " << obj.id
           << " year: " << obj.year
           << " letter: " << obj.letter
           << " isClassGraduated: " << obj.isClassGraduated
           << " mathTeacher: " << obj.mathTeacher
           << " englishTeacher: " << obj.englishTeacher
           << " polishTeacher: " << obj.polishTeacher
           << " historyTeacher: " << obj.historyTeacher
           << " biologyTeacher: " << obj.biologyTeacher
           << " physicsTeacher: " << obj.physicsTeacher
           << " chemistryTeacher: " << obj.chemistryTeacher
           << " geographyTeacher: " << obj.geographyTeacher
           << " computerScienceTeacher: " << obj.computerScienceTeacher
           << " physicalEducationTeacher: " << obj.physicalEducationTeacher
           << " superVisingTeacher: " << obj.superVisingTeacher
           << " students: " << obj.students;
}

void swap(Class &lhs, Class &rhs) noexcept {
    using std::swap;
    swap(lhs.id, rhs.id);
    swap(lhs.mathTeacher, rhs.mathTeacher);
    swap(lhs.englishTeacher, rhs.englishTeacher);
    swap(lhs.polishTeacher, rhs.polishTeacher);
    swap(lhs.historyTeacher, rhs.historyTeacher);
    swap(lhs.biologyTeacher, rhs.biologyTeacher);
    swap(lhs.physicsTeacher, rhs.physicsTeacher);
    swap(lhs.chemistryTeacher, rhs.chemistryTeacher);
    swap(lhs.geographyTeacher, rhs.geographyTeacher);
    swap(lhs.computerScienceTeacher, rhs.computerScienceTeacher);
    swap(lhs.physicalEducationTeacher, rhs.physicalEducationTeacher);
    swap(lhs.superVisingTeacher, rhs.superVisingTeacher);
    swap(lhs.students, rhs.students);
    swap(lhs.isClassGraduated, rhs.isClassGraduated);
    swap(lhs.year, rhs.year);
    swap(lhs.letter, rhs.letter);
}
