//
// Created by olidiaks on 10.04.2026.
//

#include "Class.h"

#include <iostream>

std::ostream & Class::list_students(std::ostream &os) {
    throw std::runtime_error("Method not implemented");
    return os;
}

Class::Class(const int id, Teacher * const math_teacher, Teacher * const english_teacher,
             Teacher * const polish_teacher, Teacher * const history_teacher, Teacher * const biology_teacher,
             Teacher * const physics_teacher, Teacher * const chemistry_teacher, Teacher * const geography_teacher,
             Teacher * const computer_science_teacher, Teacher * const physical_education_teacher,
             Teacher * const super_vising_teacher): id(id),
                                                    mathTeacher(math_teacher),
                                                    englishTeacher(english_teacher),
                                                    polishTeacher(polish_teacher),
                                                    historyTeacher(history_teacher),
                                                    biologyTeacher(biology_teacher),
                                                    physicsTeacher(physics_teacher),
                                                    chemistryTeacher(chemistry_teacher),
                                                    geographyTeacher(geography_teacher),
                                                    computerScienceTeacher(computer_science_teacher),
                                                    physicalEducationTeacher(physical_education_teacher),
                                                    superVisingTeacher(super_vising_teacher) {
    numberOfStudents = 0;
}

Class::Class(const Class &other): id(other.id),
                                  numberOfStudents(other.numberOfStudents),
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
                                  superVisingTeacher(other.superVisingTeacher) {
}

Class::Class(Class &&other) noexcept: id(other.id),
                                      numberOfStudents(other.numberOfStudents),
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
                                      superVisingTeacher(other.superVisingTeacher) {
}

Class & Class::operator=(const Class &other) {
    if (this == &other)
        return *this;
    id = other.id;
    numberOfStudents = other.numberOfStudents;
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
    return *this;
}

Class & Class::operator=(Class &&other) noexcept {
    if (this == &other)
        return *this;
    id = other.id;
    numberOfStudents = other.numberOfStudents;
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
    return *this;
}

void Class::add_student(Student student) {
    throw std::runtime_error("Method not implemented");
}

bool Class::remove_student(const int &id) const {
    throw std::runtime_error("Method not implemented");
}

bool Class::is_student_in_class(const int &id) const {
    throw std::runtime_error("Method not implemented");
}

void Class::print_students() const {
    throw std::runtime_error("Method not implemented");
}

void Class::print_teachers() const {
    throw std::runtime_error("Method not implemented");
}

Student & Class::get_student(const int &id) const {
    throw std::runtime_error("Method not implemented");
}

int Class::get_students_avarage_grade() const {
    throw std::runtime_error("Method not implemented");
}

bool operator==(const Class &lhs, const Class &rhs) {
    throw std::runtime_error("Method not implemented");
    //TODO: add comperasion if students are the same
    return lhs.id == rhs.id
           && lhs.numberOfStudents == rhs.numberOfStudents
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
           && lhs.superVisingTeacher == rhs.superVisingTeacher;
}

bool operator!=(const Class &lhs, const Class &rhs) {
    return !(lhs == rhs);
}

std::ostream & operator<<(std::ostream &os, const Class &obj) {
    //TODO: Print students also.
    throw std::runtime_error("Method not implemented");
    return os
           << "id: " << obj.id
           << " numberOfStudents: " << obj.numberOfStudents
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
            << " students: " << obj.print_students();
}

void swap(Class &lhs, Class &rhs) noexcept {
    using std::swap;
    swap(lhs.id, rhs.id);
    swap(lhs.numberOfStudents, rhs.numberOfStudents);
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
}

std::istream & operator>>(std::istream &is, Class &obj) {
    throw std::runtime_error("Method not implemented");
    return is;
}
