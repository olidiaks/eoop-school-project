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

Class::Class(Teacher &math_teacher, Teacher &english_teacher, Teacher &polish_teacher,
             Teacher &history_teacher, Teacher &biology_teacher, Teacher &physics_teacher, Teacher &chemistry_teacher,
             Teacher &geography_teacher, Teacher &computer_science_teacher, Teacher &physical_education_teacher,
             Teacher &super_vising_teacher, int year, char letter) : mathTeacher(math_teacher),
                                                                     englishTeacher(english_teacher),
                                                                     polishTeacher(polish_teacher),
                                                                     historyTeacher(history_teacher),
                                                                     biologyTeacher(biology_teacher),
                                                                     physicsTeacher(physics_teacher),
                                                                     chemistryTeacher(chemistry_teacher),
                                                                     geographyTeacher(geography_teacher),
                                                                     computerScienceTeacher(computer_science_teacher),
                                                                     physicalEducationTeacher(
                                                                         physical_education_teacher),
                                                                     superVisingTeacher(super_vising_teacher),
                                                                     year(year), letter(letter),
                                                                     isClassGraduated(false) {
    id = ++counter;
}

Class::Class(Teacher &math_teacher, Teacher &english_teacher, Teacher &polish_teacher, Teacher &history_teacher,
             Teacher &biology_teacher, Teacher &physics_teacher, Teacher &chemistry_teacher, Teacher &geography_teacher,
             Teacher &computer_science_teacher, Teacher &physical_education_teacher, Teacher &super_vising_teacher,
             const bool is_class_graduated) : mathTeacher(math_teacher),
                                              englishTeacher(english_teacher),
                                              polishTeacher(polish_teacher),
                                              historyTeacher(history_teacher),
                                              biologyTeacher(biology_teacher),
                                              physicsTeacher(physics_teacher),
                                              chemistryTeacher(chemistry_teacher),
                                              geographyTeacher(geography_teacher),
                                              computerScienceTeacher(computer_science_teacher),
                                              physicalEducationTeacher(physical_education_teacher),
                                              superVisingTeacher(super_vising_teacher),
                                              isClassGraduated(is_class_graduated), year(-1), letter('\0') {
}

Class::Class(Teacher &math_teacher, Teacher &english_teacher, Teacher &polish_teacher, Teacher &history_teacher,
             Teacher &biology_teacher, Teacher &physics_teacher, Teacher &chemistry_teacher, Teacher &geography_teacher,
             Teacher &computer_science_teacher, Teacher &physical_education_teacher, Teacher &super_vising_teacher,
             const char letter) : mathTeacher(math_teacher),
                                  englishTeacher(english_teacher),
                                  polishTeacher(polish_teacher),
                                  historyTeacher(history_teacher),
                                  biologyTeacher(biology_teacher),
                                  physicsTeacher(physics_teacher),
                                  chemistryTeacher(chemistry_teacher),
                                  geographyTeacher(geography_teacher),
                                  computerScienceTeacher(computer_science_teacher),
                                  physicalEducationTeacher(physical_education_teacher),
                                  superVisingTeacher(super_vising_teacher),
                                  letter(letter) {
    id = ++counter;
    year = 1;
    isClassGraduated = false;
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

bool Class::is_is_class_graduated() const {
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

int Class::get_average_grade_of_clas_from_subject(const Subject &subject) const {
    int sum = 0;
    int count = 0;
    for (const auto &student: students) {
        sum += student.get_sum_of_grades_from_students_subjects(subject);
        count += student.get_count_of_grades_from_students_subjects(subject);
    }

    if (count == 0) {
        return 0;
    }

    return sum / count;
}

Teacher Class::get_math_teacher() const {
    return mathTeacher;
}

void Class::set_math_teacher(const Teacher &math_teacher) {
    mathTeacher = math_teacher;
}

Teacher Class::get_english_teacher() const {
    return englishTeacher;
}

void Class::set_english_teacher(const Teacher &english_teacher) {
    englishTeacher = english_teacher;
}

Teacher Class::get_polish_teacher() const {
    return polishTeacher;
}

void Class::set_polish_teacher(const Teacher &polish_teacher) {
    polishTeacher = polish_teacher;
}

Teacher Class::get_history_teacher() const {
    return historyTeacher;
}

void Class::set_history_teacher(const Teacher &history_teacher) {
    historyTeacher = history_teacher;
}

Teacher Class::get_biology_teacher() const {
    return biologyTeacher;
}

void Class::set_biology_teacher(const Teacher &biology_teacher) {
    biologyTeacher = biology_teacher;
}

Teacher Class::get_physics_teacher() const {
    return physicsTeacher;
}

void Class::set_physics_teacher(const Teacher &physics_teacher) {
    physicsTeacher = physics_teacher;
}

Teacher Class::get_chemistry_teacher() const {
    return chemistryTeacher;
}

void Class::set_chemistry_teacher(const Teacher &chemistry_teacher) {
    chemistryTeacher = chemistry_teacher;
}

Teacher Class::get_geography_teacher() const {
    return geographyTeacher;
}

void Class::set_geography_teacher(const Teacher &geography_teacher) {
    geographyTeacher = geography_teacher;
}

Teacher Class::get_computer_science_teacher() const {
    return computerScienceTeacher;
}

void Class::set_computer_science_teacher(const Teacher &computer_science_teacher) {
    computerScienceTeacher = computer_science_teacher;
}

Teacher Class::get_physical_education_teacher() const {
    return physicalEducationTeacher;
}

void Class::set_physical_education_teacher(const Teacher &physical_education_teacher) {
    physicalEducationTeacher = physical_education_teacher;
}

Teacher Class::get_super_vising_teacher() const {
    return superVisingTeacher;
}

void Class::set_super_vising_teacher(const Teacher &super_vising_teacher) {
    superVisingTeacher = super_vising_teacher;
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
        sum += student.get_sum_of_grades_from_students_subjects(subject);
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
            sum += student.get_sum_of_grades_from_students_subjects(subject);
            count += student.get_count_of_grades_from_students_subjects(subject);
        }
    }

    if (count == 0) {
        return 0;
    }

    return sum / count;
}

void Class::add_assignment(const Subject &subject, const Assigment &assigment) {
    for (auto &student: students) {
        student.add_assignment(subject, assigment);
    }
}

void Class::add_assignment(const Subject &subject, const std::string &name, const std::string &description) {
    for (auto &student: students) {
        student.add_assignment(subject, name, description);
    }
}

void Class::add_assignment(const Subject &subject, const Assigment &assigment, int grade) {
    for (auto &student: students) {
        student.add_assignment(subject, assigment, grade);
    }
}

void Class::add_assignment(const Subject &subject, const Assigment_graded &assigment) {
    for (auto &student: students) {
        student.add_assignment(subject, assigment);
    }
}

void Class::add_assignment(const Subject &subject, Assigment_graded &assigment_graded, const int grade) {
    for (auto &student: students) {
        student.add_assignment(subject, assigment_graded, grade);
    }
}

void Class::new_school_year() {
    if (year++ == 5) {
        year = -1;
        isClassGraduated = true;
    }
}


bool operator==(const Class &lhs, const Class &rhs) {
    for (const auto &student: lhs.students) {
        bool is_equal = false;
        for (const auto &other_student: rhs.students) {
            if (student == other_student) {
                is_equal = true;
            }
        }
        if (!is_equal) {
            return false;
        }
    }
    return lhs.id == rhs.id
           && lhs.mathTeacher == rhs.mathTeacher
           && lhs.englishTeacher == rhs.englishTeacher
           && lhs.polishTeacher == rhs.polishTeacher
           && lhs.historyTeacher == rhs.historyTeacher
           && lhs.biologyTeacher == rhs.biologyTeacher
           && lhs.physicsTeacher == rhs.physicsTeacher
           && lhs.chemistryTeacher == rhs.chemistryTeacher
           && lhs.geographyTeacher == rhs.geographyTeacher
           && lhs.computerScienceTeacher == rhs.computerScienceTeacher
           && lhs.physicalEducationTeacher == rhs.physicalEducationTeacher
           && lhs.superVisingTeacher == rhs.superVisingTeacher
           && lhs.isClassGraduated == rhs.isClassGraduated
           && lhs.year == rhs.year
           && lhs.letter == rhs.letter;;
}

bool operator!=(const Class &lhs, const Class &rhs) {
    return !(lhs == rhs);
}


std::ostream &operator<<(std::ostream &os, const std::vector<Student> &students) {
    for (const Student &student: students) {
        os << student << std::endl;
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
