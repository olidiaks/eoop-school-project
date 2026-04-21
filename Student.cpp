//
// Created by olidiaks on 10.04.2026.
//

#include "Student.h"


Student::Student(const std::string &first_name, const std::string &last_name, const std::string &email,
                 const int &day, const int &month, const int &year
) : Person(first_name, last_name, email, day, month, year) {
}




std::ostream &operator<<(std::ostream &os, const std::list<Assigment_graded> &assignment_list) {
    for (auto &assignment: assignment_list) {
        os << assignment << "\n";
    }
    return os;
}

float Student::get_average_grades_from_subject(const std::list<Assigment_graded> &assignments) {
    float sum = 0;
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

    for (auto &assignments: {
             mathAssignments, englishAssignments, polishAssignments, historyAssignments, biologyAssignments,
             physicsAssignments, chemistryAssignments, geographyAssignments, computerScienceAssignments,
             physicalEducationAssignments
         }) {
        for (auto &assignment: assignments) {
            sum += assignment.get_grade();
            count++;
        }
    }
    return (float) sum / count;
}

const std::list<Assigment_graded> &Student::get_assignments_from_subject(const Subject &subject) const {
    switch (subject) {
        case Subject::Math:
            return mathAssignments;
            break;
        case Subject::English:
            return englishAssignments;
            break;
        case Subject::Polish:
            return polishAssignments;
            break;
        case Subject::History:
            return historyAssignments;
            break;
        case Subject::Biology:
            return biologyAssignments;
            break;
        case Subject::Physics:
            return physicsAssignments;
            break;
        case Subject::Chemistry:
            return chemistryAssignments;
            break;
        case Subject::Geography:
            return geographyAssignments;
            break;
        case Subject::ComputerScience:
            return computerScienceAssignments;
            break;
        case Subject::PhysicalEducation:
            return physicalEducationAssignments;
            break;
    }
}

int Student::get_sum_of_grades_from_students_subjects(const Subject &subject) const {
    int sum = 0;
    for (auto &assignment: get_assignments_from_subject(subject)) {
        sum += assignment.get_grade();
    }
    return sum;
}

int Student::get_count_of_grades_from_students_subjects(const Subject &subject) const {
    return get_assignments_from_subject(subject).size();
}

float Student::get_average_grade_from_math() const {
    return get_average_grades_from_subject(mathAssignments);
}

float Student::get_average_grade_from_english() const {
    return get_average_grades_from_subject(englishAssignments);
}

float Student::get_average_grade_from_polish() const {
    return get_average_grades_from_subject(polishAssignments);
}

float Student::get_average_grade_from_history() const {
    return get_average_grades_from_subject(historyAssignments);
}

float Student::get_average_grade_from_biology() const {
    return get_average_grades_from_subject(biologyAssignments);
}

float Student::get_average_grade_from_physics() const {
    return get_average_grades_from_subject(physicsAssignments);
}

float Student::get_average_grade_from_chemistry() const {
    return get_average_grades_from_subject(chemistryAssignments);
}

float Student::get_average_grade_from_geography() const {
    return get_average_grades_from_subject(geographyAssignments);
}

float Student::get_average_grade_from_computer_science() const {
    return get_average_grades_from_subject(computerScienceAssignments);
}

float Student::get_average_grade_from_physical_education() const {
    return get_average_grades_from_subject(physicalEducationAssignments);
}

void Student::add_assignment(const Subject &subject, const Assigment &assigment) {
    add_assignment(subject, Assigment_graded(assigment));
}

void Student::add_assignment(const Subject &subject, const std::string &name, const std::string &description) {
    add_assignment(subject, Assigment(name, description, to_string(subject)));
}

void Student::add_assignment(const Subject &subject, const Assigment &assigment, const int grade) {
    add_assignment(subject, Assigment_graded(assigment, grade));
}

void Student::add_assignment(const Subject &subject, const Assigment_graded &assigment) {
    switch (subject) {
        case Subject::Math:
            mathAssignments.push_back(assigment);
            break;
        case Subject::English:
            englishAssignments.push_back(assigment);
            break;
        case Subject::Polish:
            polishAssignments.push_back(assigment);
            break;
        case Subject::History:
            historyAssignments.push_back(assigment);
            break;
        case Subject::Biology:
            biologyAssignments.push_back(assigment);
            break;
        case Subject::Physics:
            physicsAssignments.push_back(assigment);
            break;
        case Subject::Chemistry:
            chemistryAssignments.push_back(assigment);
            break;
        case Subject::Geography:
            geographyAssignments.push_back(assigment);
            break;
        case Subject::ComputerScience:
            computerScienceAssignments.push_back(assigment);
            break;
        case Subject::PhysicalEducation:
            physicalEducationAssignments.push_back(assigment);
            break;
    }
}

void Student::add_assignment(const Subject &subject, Assigment_graded &assigment_graded, const int grade) {
    assigment_graded.set_grade(grade);
    add_assignment(subject, assigment_graded);
}

const std::list<Assigment_graded> &Student::get_math_assignments() const {
    return mathAssignments;
}

const std::list<Assigment_graded> &Student::get_english_assignments() const {
    return englishAssignments;
}

const std::list<Assigment_graded> &Student::get_polish_assignments() const {
    return polishAssignments;
}

const std::list<Assigment_graded> &Student::get_history_assignments() const {
    return historyAssignments;
}

const std::list<Assigment_graded> &Student::get_biology_assignments() const {
    return biologyAssignments;
}

const std::list<Assigment_graded> &Student::get_physics_assignments() const {
    return physicsAssignments;
}

const std::list<Assigment_graded> &Student::get_chemistry_assignments() const {
    return chemistryAssignments;
}

const std::list<Assigment_graded> &Student::get_geography_assignments() const {
    return geographyAssignments;
}

const std::list<Assigment_graded> &Student::get_computer_science_assignments() const {
    return computerScienceAssignments;
}

const std::list<Assigment_graded> &Student::get_physical_education_assignments() const {
    return physicalEducationAssignments;
}

bool operator==(const Student &lhs, const Student &rhs) {
    return static_cast<const Person &>(lhs) == static_cast<const Person &>(rhs)
           && lhs.mathAssignments == rhs.mathAssignments
           && lhs.englishAssignments == rhs.englishAssignments
           && lhs.polishAssignments == rhs.polishAssignments
           && lhs.historyAssignments == rhs.historyAssignments
           && lhs.biologyAssignments == rhs.biologyAssignments
           && lhs.physicsAssignments == rhs.physicsAssignments
           && lhs.chemistryAssignments == rhs.chemistryAssignments
           && lhs.geographyAssignments == rhs.geographyAssignments
           && lhs.computerScienceAssignments == rhs.computerScienceAssignments
           && lhs.physicalEducationAssignments == rhs.physicalEducationAssignments;
}

bool operator!=(const Student &lhs, const Student &rhs) {
    return !(lhs == rhs);
}

std::ostream &operator<<(std::ostream &os, const Student &obj) {
    return os
           << static_cast<const Person &>(obj)
           << " mathAssignments: " << obj.mathAssignments
           << " englishAssignments: " << obj.englishAssignments
           << " polishAssignments: " << obj.polishAssignments
           << " historyAssignments: " << obj.historyAssignments
           << " biologyAssignments: " << obj.biologyAssignments
           << " physicsAssignments: " << obj.physicsAssignments
           << " chemistryAssignments: " << obj.chemistryAssignments
           << " geographyAssignments: " << obj.geographyAssignments
           << " computerScienceAssignments: " << obj.computerScienceAssignments
           << " physicalEducationAssignments: " << obj.physicalEducationAssignments;
}

std::ostream &stream_assignments(std::ostream &os, const Subject &subject, const Student &obj) {
    os << "Subject: " << to_string(subject) << "\n";
    const std::list<Assigment_graded> *assignments = nullptr;
    switch (subject) {
        case Subject::Math:
            assignments = &(obj.mathAssignments);
            break;
        case Subject::English:
            assignments = &(obj.englishAssignments);
            break;
        case Subject::Polish:
            assignments = &(obj.polishAssignments);
            break;
        case Subject::History:
            assignments = &(obj.historyAssignments);
            break;
        case Subject::Biology:
            assignments = &(obj.biologyAssignments);
            break;
        case Subject::Physics:
            assignments = &(obj.physicsAssignments);
            break;
        case Subject::Chemistry:
            assignments = &(obj.chemistryAssignments);
            break;
        case Subject::Geography:
            assignments = &(obj.geographyAssignments);
            break;
        case Subject::ComputerScience:
            assignments = &(obj.computerScienceAssignments);
            break;
        case Subject::PhysicalEducation:
            assignments = &(obj.physicalEducationAssignments);
            break;
    }

    if (assignments == nullptr) {
        throw std::runtime_error("Imposible error");
    }
    for (auto &assignment: *assignments) {
        os << assignment << "\n";
    }
    return os;
}
