#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm>
#include <random>
#include "School.h"
#include "Teacher.h"
#include "Student.h"
#include "Class.h"
#include "Subject.h"
#include "Assigment.h"

// Helper to manage the flow of the presentation
void wait_for_user(const std::string& message = "Press Enter to continue...") {
    std::cout << "\n[" << message << "]" << std::endl;
    std::cin.get();
}

// Arrays for generating 100 unique students
const std::string firstNames[] = {
    "Alice", "Bob", "Charlie", "Diana", "Edward", "Fiona", "George", "Hannah", "Ian", "Julia",
    "Kevin", "Lydia", "Marcus", "Nora", "Oscar", "Penelope", "Quentin", "Rose", "Sebastian", "Tessa",
    "Ulysses", "Victoria", "Walter", "Xena", "Yosef", "Zoe", "Arthur", "Beatrice", "Caspian", "Dorothy"
};
const std::string lastNames[] = {
    "Smith", "Johnson", "Williams", "Brown", "Jones", "Garcia", "Miller", "Davis", "Rodriguez", "Martinez",
    "Hernandez", "Lopez", "Gonzalez", "Wilson", "Anderson", "Thomas", "Taylor", "Moore", "Jackson", "Martin"
};

// Helper to generate a squad of 20 students
std::vector<Student> generateStudentSquad(int classNum, char classLetter) {
    std::vector<Student> squad;
    for (int i = 0; i < 20; ++i) {
        std::string fn = firstNames[(classNum * 20 + i) % 30];
        std::string ln = lastNames[(classNum * 20 + i) % 20];
        std::string email = fn + "." + ln + std::to_string(classNum) + classLetter + "@academy.edu";
        squad.emplace_back(fn, ln, email, 1 + (i % 28), 1 + (i % 12), 2012);
    }
    return squad;
}

int main() {
    std::cout << "============================================================================" << std::endl;
    std::cout << "          WELCOME TO THE GRAND ACADEMY OF EXCELLENCE SIMULATION             " << std::endl;
    std::cout << "============================================================================" << std::endl;

    /* --- PROLOGUE: THE FACULTY --- */
    std::cout << "\n>>> PROLOGUE: RECRUITING THE IMMORTALS <<<" << std::endl;
    
    Teacher tMath("Albert", "Einstein", "physics.god@academy.edu", 14, 3, 1879, 15000, Subject::Math);
    Teacher tEng("William", "Shakespeare", "the.bard@academy.edu", 23, 4, 1564, 12000, Subject::English);
    Teacher tPol("Adam", "Mickiewicz", "national.poet@academy.edu", 24, 12, 1798, 11000, Subject::Polish);
    Teacher tHis("Herodotus", "Halicarnassus", "father.history@academy.edu", 1, 1, 1900, 10500, Subject::History);
    Teacher tBio("Charles", "Darwin", "evolution@academy.edu", 12, 2, 1809, 13000, Subject::Biology);
    Teacher tPhy("Isaac", "Newton", "apple.man@academy.edu", 4, 1, 1643, 14000, Subject::Physics);
    Teacher tChe("Marie", "Curie", "polonium@academy.edu", 7, 11, 1867, 14500, Subject::Chemistry);
    Teacher tGeo("Alexander", "Humboldt", "explorer@academy.edu", 14, 9, 1769, 11500, Subject::Geography);
    Teacher tCS("Ada", "Lovelace", "first.logic@academy.edu", 10, 12, 1815, 16000, Subject::ComputerScience);
    Teacher tPE("Usain", "Bolt", "fastest.man@academy.edu", 21, 8, 1986, 9500, Subject::PhysicalEducation);
    Teacher tSuper("Socrates", "Athens", "the.gadfly@academy.edu", 1, 1, 1900, 8000, Subject::None);

    std::cout << "The faculty has been hired. The greatest minds in history are ready to teach." << std::endl;

    /* --- YEAR 1: THE SPARK --- */
    std::cout << "\n>>> YEAR 1: THE SPARK (Foundations of Logic) <<<" << std::endl;
    School theAcademy;
    theAcademy.set_name("The Grand Academy");

    char letters[] = {'A', 'B', 'C', 'D', 'E'};
    std::vector<Class> academyClasses;

    for (int i = 0; i < 5; ++i) {
        std::vector<Student> squad = generateStudentSquad(i, letters[i]);
        Class newClass(tMath, tEng, tPol, tHis, tBio, tPhy, tChe, tGeo, tCS, tPE, tSuper, squad, 1, letters[i]);
        academyClasses.push_back(newClass);
        std::cout << "  - Class 1" << letters[i] << " has been formed with 20 brilliant minds." << std::endl;
    }

    std::cout << "\nEinstein and Lovelace take the lead this year." << std::endl;
    for (auto& c : academyClasses) {
        c.add_assignment(Subject::Math, Assigment("Calculus I", "The math of change.", "Math"), 5);
        c.add_assignment(Subject::ComputerScience, Assigment("Logic Gates", "0s and 1s.", "ComputerScience"), 4);
    }
    std::cout << "Year 1 completed. Averages: " << academyClasses[0].get_average_grade_of_class() << std::endl;
    wait_for_user("Moving to Year 2...");

    /* --- YEAR 2: THE NATURAL WORLD --- */
    std::cout << "\n>>> YEAR 2: THE NATURAL WORLD (Life and Matter) <<<" << std::endl;
    for (auto& c : academyClasses) c.new_school_year();

    std::cout << "Darwin takes the students to the Galapagos, while Curie starts the Lab experiments." << std::endl;
    for (auto& c : academyClasses) {
        std::cout << "  Class 2" << c.get_letter() << " is studying Evolution and Radioactivity." << std::endl;
        c.add_assignment(Subject::Biology, Assigment("Natural Selection", "Survival of the fittest.", "Biology"), 5);
        c.add_assignment(Subject::Chemistry, Assigment("Periodic Table", "Understanding elements.", "Chemistry"), 4);
    }
    std::cout << "Year 2 completed. The students are becoming true scientists." << std::endl;
    wait_for_user("Moving to Year 3...");

    /* --- YEAR 3: THE HUMAN SOUL --- */
    std::cout << "\n>>> YEAR 3: THE HUMAN SOUL (Literature and Time) <<<" << std::endl;
    for (auto& c : academyClasses) c.new_school_year();

    std::cout << "Shakespeare demands a tragedy, and Herodotus narrates the fall of kings." << std::endl;
    for (auto& c : academyClasses) {
        std::cout << "  Class 3" << c.get_letter() << " is writing plays and analyzing history." << std::endl;
        c.add_assignment(Subject::English, Assigment("Macbeth Analysis", "Ambition and Fate.", "English"), 4);
        c.add_assignment(Subject::History, Assigment("Ancient Civilizations", "The cradle of humanity.", "History"), 3);
    }
    std::cout << "Year 3 completed. Their hearts are as sharp as their minds." << std::endl;
    wait_for_user("Moving to Year 4...");

    /* --- YEAR 4: THE UNIVERSAL LAWS --- */
    std::cout << "\n>>> YEAR 4: THE UNIVERSAL LAWS (Final Frontiers) <<<" << std::endl;
    for (auto& c : academyClasses) c.new_school_year();

    std::cout << "Newton explains gravity, and Humboldt maps the unknown world." << std::endl;
    for (auto& c : academyClasses) {
        std::cout << "  Class 4" << c.get_letter() << " is preparing for the real world." << std::endl;
        c.add_assignment(Subject::Physics, Assigment("Orbital Mechanics", "The dance of planets.", "Physics"), 5);
        c.add_assignment(Subject::Geography, Assigment("Global Mapping", "Connecting the continents.", "Geography"), 4);
    }
    std::cout << "Year 4 completed. The final exams are over." << std::endl;
    wait_for_user("Proceed to Graduation Day...");

    /* --- EPILOGUE: THE GRAND GRADUATION --- */
    std::cout << "\n>>> THE GRAND GRADUATION CEREMONY <<<" << std::endl;
    for (auto& c : academyClasses) c.new_school_year(); // Trigger Year 5 (Graduation)

    std::cout << "============================================================================" << std::endl;
    std::cout << "                       FINAL ACADEMIC RECORD BOOK                           " << std::endl;
    std::cout << "============================================================================" << std::endl;

    for (const auto& c : academyClasses) {
        std::cout << "\n>>> CLASS " << c.get_letter() << " GRADUATION REPORT <<<" << std::endl;
        std::cout << "  Final Class GPA: " << std::fixed << std::setprecision(2) << const_cast<Class&>(c).get_average_grade_of_class() << std::endl;
        std::cout << "  Math Average:    " << c.get_average_grade_of_clas_from_subject(Subject::Math) << " / 5.0" << std::endl;
        std::cout << "  Science Average: " << (c.get_average_grade_of_clas_from_subject(Subject::Physics) + c.get_average_grade_of_clas_from_subject(Subject::Biology)) / 2.0 << " / 5.0" << std::endl;
        std::cout << "  Status:          " << (c.is_is_class_graduated() ? "OFFICIALLY GRADUATED" : "PENDING") << std::endl;
        std::cout << "  ------------------------------------------------------------------------" << std::endl;
    }

    std::cout << "\n[!] BREAKING: All 100 students from the Academy have officially entered society." << std::endl;
    std::cout << "They carry the wisdom of Einstein, the logic of Lovelace, and the vision of Darwin." << std::endl;

    std::cout << "\n============================================================================" << std::endl;
    std::cout << "                END OF THE GRAND ACADEMY SIMULATION                         " << std::endl;
    std::cout << "============================================================================" << std::endl;

    return 0;
}
