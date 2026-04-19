//
// Created by olidiaks on 10.04.2026.
//

#include "Student.h"

#include "cmake-build-debug/_deps/googletest-src/googlemock/include/gmock/gmock-actions.h"


Student::Student(const std::string &first_name, const std::string &last_name, const std::string &email,
                 const int &day, const int &month, const int &year
) : Person(first_name, last_name, email, day, month, year) {
}


const char *to_string(Subject e) {
    switch (e) {
        case Subject::Math: return "Math";
        case Subject::English: return "English";
        case Subject::Polish: return "Polish";
        case Subject::History: return "History";
        case Subject::Biology: return "Biology";
        case Subject::Physics: return "Physics";
        case Subject::Chemistry: return "Chemistry";
        case Subject::Geography: return "Geography";
        case Subject::ComputerScience: return "ComputerScience";
        case Subject::PhysicalEducation: return "PhysicalEducation";
        default: return "unknown";
    }
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
    float sum = 0;
    for (auto &assignment: mathAssignments) {
        sum += assignment.get_grade();
        count++;
    }

    for (auto &assigment: englishAssignments) {
        sum += assigment.get_grade();
        count++;
    }
    for (auto &assigment: polishAssignments) {
        sum += assigment.get_grade();
        count++;
    }
    for (auto &assigment: historyAssignments) {
        sum += assigment.get_grade();
        count++;
    }
    for (auto &assigment: biologyAssignments) {
        sum += assigment.get_grade();
        count++;
    }
    for (auto &assigment: physicsAssignments) {
        sum += assigment.get_grade();
        count++;
    }
    for (auto &assigment: chemistryAssignments) {
        sum += assigment.get_grade();
        count++;
    }
    for (auto &assigment: geographyAssignments) {
        sum += assigment.get_grade();
        count++;
    }
    for (auto &assigment: computerScienceAssignments) {
        sum += assigment.get_grade();
        count++;
    }
    for (auto &assigment: physicalEducationAssignments) {
        sum += assigment.get_grade();
        count++;
    }
    return sum / count;
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
