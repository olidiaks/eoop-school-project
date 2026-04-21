//
// Created by olidiaks on 4/21/26.
//

#ifndef EOOP_SCHOOL_PROJECT_SUBJECT_H
#define EOOP_SCHOOL_PROJECT_SUBJECT_H
#include <ostream>


/**
 * @enum Subject
 * @brief Represents the list of school subjects available within the system.
 *
 * This enumeration is used to identify and categorize various academic
 * subjects. It simplifies subject-related operations by providing
 * predefined constants. The subjects included are:
 *
 * - None: Default value or no subject.
 * - Math: Mathematics.
 * - English: English language and literature.
 * - Polish: Polish language and literature.
 * - History: History studies.
 * - Biology: Biological sciences.
 * - Physics: Physical sciences.
 * - Chemistry: Chemical sciences.
 * - Geography: Geographical studies.
 * - ComputerScience: Computer science and programming.
 * - PhysicalEducation: Physical education and sports activities.
 */
enum class Subject {
    None,
    Math,
    English,
    Polish,
    History,
    Biology,
    Physics,
    Chemistry,
    Geography,
    ComputerScience,
    PhysicalEducation,
};

/**
 * @brief Converts a Subject enumeration value to its string representation.
 *
 * This function maps each Subject enum value to a predefined string
 * description. It is primarily used for logging, display, and other
 * output-related purposes where the human-readable equivalent of the
 * Subject enumeration is required.
 *
 * @param e The Subject enum value to be converted.
 * @return A const char pointer to the string representation of the
 *         provided Subject enum value. If the input does not match
 *         any known Subject, "unknown" is returned.
 */
const char *to_string(Subject e);

/**
 * @enum Operator
 * @brief Defines the set of mathematical or logical operators supported by the system.
 *
 * This enumeration provides a collection of constants representing
 * various operators that can be used in mathematical or logical expressions.
 * It is intended to standardize operator usage across the application and
 * ensure consistency in computations and evaluations.
 */
std::ostream & operator<<(std::ostream &os, Subject subject);


#endif //EOOP_SCHOOL_PROJECT_SUBJECT_H
