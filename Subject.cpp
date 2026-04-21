//
// Created by olidiaks on 4/21/26.
//

#include "Subject.h"

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

std::ostream &operator<<(std::ostream &os, Subject subject) {
    return os << to_string(subject);
}