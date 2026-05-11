//
// Created by olidiaks on 10.04.2026.
//

#include "Student.h"


Student::Student(const std::string &first_name, const std::string &last_name, const std::string &email,
                 const int &day, const int &month, const int &year
) : Person(first_name, last_name, email, day, month, year) {
}


std::ostream &operator<<(std::ostream &os, const std::vector<Assignment> &assignment_list) {
    for (auto &assignment: assignment_list) {
        os << assignment << "\n";
    }
    return os;
}

float Student::get_average_grades_from_subject(const std::list<Assignment> &assignments) {
    int sum = 0;
    int count = 0;

    for (auto &assignment: assignments) {
        sum += assignment.get_grade();
        count++;
    }

    return sum / count;
}

Student::Student(const std::string &first_name, const std::string &last_name, const std::string &email,
                 const time_t birth_date
) : Person(first_name, last_name, email, birth_date) {
}

float Student::get_average_grade() const {
    int count = 0;
    int sum = 0;

    for (auto &subject_and_assignment: assignments) {
        for (auto &assignment : subject_and_assignment.second) {
            sum += assignment.get_grade();
            count++;
        }
    }
    if (count == 0) return 0.0f;
    return static_cast<float>(sum) / count;
}

int Student::get_sum_of_grades_from_subjects(const Subject &subject) const {
    int sum = 0;
    for (auto &assignment: get_assignments_from_subject(subject)) {
        sum += assignment.get_grade();
    }
    return sum;
}

unsigned long Student::get_count_of_grades_from_students_subjects(const Subject &subject) const {
    return get_assignments_from_subject(subject).size();
}

float Student::get_average_grade_from_subject(const Subject &subject) const {
    auto count = get_count_of_grades_from_students_subjects(subject);
    if (count == 0) return 0.0f;
    return static_cast<float>(get_sum_of_grades_from_subjects(subject)) / count;
}


void Student::add_assignment(const Subject &subject, const std::string &name, const std::string &description) {
    add_assignment(subject, Assignment(name, description, to_string(subject)));
}

void Student::add_assignment(const Subject &subject, const std::string &name, const std::string &description,
                             int grade) {
    add_assignment(subject, Assignment(name, description, to_string(subject), grade));
}

void Student::add_assignment(const Subject &subject, const Assignment &assigment) {
    assignments[subject].emplace_back(assigment);
}

void Student::add_assignment(const Subject &subject, const Assignment &assignment, int grade) {
    Assignment graded_assignment(assignment);
    graded_assignment.set_grade(grade);
    add_assignment(subject, graded_assignment);
}

bool Student::operator==(const Student &rhs) const {
    return static_cast<const Person &>(*this) == static_cast<const Person &>(rhs)
           && assignments == rhs.assignments;
}

bool Student::operator!=(const Student &rhs) const {
    return !(*this == rhs);
}

const std::vector<Assignment> & Student::get_assignments_from_subject(const Subject &subject) const {
    auto it = assignments.find(subject);
    if (it == assignments.end()) {
        static constexpr std::vector<Assignment> empty_list;
        return empty_list;
    };
    return it->second;
}

unsigned long Student::get_count_of_grades_from_all_subjects() const {
    unsigned long count = 0;
    for (auto &[subject, assignment]: assignments) {
        count += assignment.size();
    }
    return count;
}

unsigned long Student::get_sum_of_grades_from_all_subjects() const {
    unsigned long sum = 0;
    for (auto &[subject, assignment]: assignments) {
        for (auto &assignment_from_subject: assignment) {
            sum += assignment_from_subject.get_grade();
        }
    }
    return sum;
}

std::ostream &operator<<(std::ostream &os, const Student &obj) {
    os
           << static_cast<const Person &>(obj);
           for (const auto &[subject, assignments] : obj.assignments) {
               os << " " << to_string(subject) << " assignments: " << assignments << std::endl;
           }
    return os;
}
