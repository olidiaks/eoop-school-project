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

void printClassStudents(const std::string& className, const std::vector<Student>& students) {
    std::cout << "\n--- Enrollment List: " << className << " ---" << std::endl;
    for (size_t i = 0; i < students.size(); ++i) {
        std::cout << std::right << std::setw(2) << i + 1 << ". " 
                  << std::left << std::setw(20) << (students[i].get_first_name() + " " + students[i].get_last_name())
                  << " (" << students[i].get_email() << ")" << std::endl;
    }
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

    std::cout << "The faculty has been hired. The starting budget for salaries is significant." << std::endl;
    std::cout << "Einstein starts at $" << tMath.get_salary() << ", Lovelace at $" << tCS.get_salary() << "." << std::endl;

    /* --- YEAR 1: THE SPARK --- */
    std::cout << "\n>>> YEAR 1: THE SPARK (Foundations of Logic) <<<" << std::endl;
    std::cout << "In the first year, 100 students arrive, full of hope and terror." << std::endl;
    
    School theAcademy;
    theAcademy.set_name("The Grand Academy");

    char letters[] = {'A', 'B', 'C', 'D', 'E'};
    std::vector<std::vector<Student>> allStudentSquads;
    std::vector<Class> academyClasses;

    for (int i = 0; i < 5; ++i) {
        std::vector<Student> squad = generateStudentSquad(i, letters[i]);
        allStudentSquads.push_back(squad);
        Class newClass(tMath, tEng, tPol, tHis, tBio, tPhy, tChe, tGeo, tCS, tPE, tSuper, squad, 1, letters[i]);
        academyClasses.push_back(newClass);
        
        std::string className = "Class 1";
        className += letters[i];
        printClassStudents(className, squad);
    }

    std::cout << "\nEinstein and Lovelace take the lead. The students struggle with early calculus." << std::endl;
    for (auto& c : academyClasses) {
        c.add_assignment(Subject::Math, Assigment("Calculus I", "The math of change.", "Math"), 5);
        c.add_assignment(Subject::ComputerScience, Assigment("Logic Gates", "0s and 1s.", "ComputerScience"), 4);
    }

    std::cout << "\n[PROMOTION] End of Year 1: The Board is impressed by the logic results." << std::endl;
    tMath.set_salary(tMath.get_salary() + 1000);
    tCS.set_salary(tCS.get_salary() + 1500);
    std::cout << "  Einstein's salary is now $" << tMath.get_salary() << std::endl;
    std::cout << "  Lovelace's salary is now $" << tCS.get_salary() << " (Highest Raise!)" << std::endl;

    wait_for_user("Moving to Year 2...");

    /* --- YEAR 2: THE NATURAL WORLD --- */
    std::cout << "\n>>> YEAR 2: THE NATURAL WORLD (Life and Matter) <<<" << std::endl;
    for (auto& c : academyClasses) c.new_school_year();

    std::cout << "Darwin takes the students to the Galapagos on a virtual voyage." << std::endl;
    std::cout << "Marie Curie demonstrates the beauty of the atom, while keeping the classroom safe." << std::endl;
    
    for (auto& c : academyClasses) {
        std::cout << "  Class 2" << c.get_letter() << " is discovering the secrets of DNA and the Periodic Table." << std::endl;
        c.add_assignment(Subject::Biology, Assigment("Natural Selection", "Survival of the fittest.", "Biology"), 5);
        c.add_assignment(Subject::Chemistry, Assigment("Radioactivity", "Polonium and Radium.", "Chemistry"), 5);
    }

    std::cout << "\n[PROMOTION] End of Year 2: Natural sciences are flourishing." << std::endl;
    tBio.set_salary(tBio.get_salary() + 1200);
    tChe.set_salary(tChe.get_salary() + 1200);
    std::cout << "  Darwin's salary is now $" << tBio.get_salary() << std::endl;
    std::cout << "  Curie's salary is now $" << tChe.get_salary() << std::endl;

    wait_for_user("Moving to Year 3...");

    /* --- YEAR 3: THE HUMAN SOUL --- */
    std::cout << "\n>>> YEAR 3: THE HUMAN SOUL (Literature and Time) <<<" << std::endl;
    for (auto& c : academyClasses) c.new_school_year();

    std::cout << "Shakespeare demands a tragedy from every student. Mickiewicz recites epics." << std::endl;
    std::cout << "Herodotus tells tales of ancient wars that feel modern." << std::endl;
    
    for (auto& c : academyClasses) {
        std::cout << "  Class 3" << c.get_letter() << " is diving into the complexities of human nature." << std::endl;
        c.add_assignment(Subject::English, Assigment("Hamlet Deep-Dive", "To be or not to be.", "English"), 4);
        c.add_assignment(Subject::History, Assigment("The Peloponnesian War", "Power and Pride.", "History"), 4);
        c.add_assignment(Subject::Polish, Assigment("Pan Tadeusz", "National Identity.", "Polish"), 5);
    }

    std::cout << "\n[PROMOTION] End of Year 3: The students have found their voices." << std::endl;
    tEng.set_salary(tEng.get_salary() + 1000);
    tPol.set_salary(tPol.get_salary() + 1000);
    tHis.set_salary(tHis.get_salary() + 1000);
    std::cout << "  Shakespeare's salary: $" << tEng.get_salary() << " | Mickiewicz: $" << tPol.get_salary() << " | Herodotus: $" << tHis.get_salary() << std::endl;

    wait_for_user("Moving to Year 4...");

    /* --- YEAR 4: THE UNIVERSAL LAWS --- */
    std::cout << "\n>>> YEAR 4: THE UNIVERSAL LAWS (Final Frontiers) <<<" << std::endl;
    for (auto& c : academyClasses) c.new_school_year();

    std::cout << "Newton finally explains the apple. Humboldt maps the entire Academy grounds." << std::endl;
    std::cout << "Usain Bolt prepares the students for the physical rigors of the outside world." << std::endl;

    for (auto& c : academyClasses) {
        std::cout << "  Class 4" << c.get_letter() << " is finalizing their portfolios." << std::endl;
        c.add_assignment(Subject::Physics, Assigment("Principia Mathematica", "Laws of Motion.", "Physics"), 5);
        c.add_assignment(Subject::Geography, Assigment("The Cosmos", "Mapping the world.", "Geography"), 4);
        c.add_assignment(Subject::PhysicalEducation, Assigment("The 100m Dash", "Speed of lightning.", "PhysicalEducation"), 5);
    }

    std::cout << "\n[PROMOTION] End of Year 4: The final faculty rewards." << std::endl;
    tPhy.set_salary(tPhy.get_salary() + 2000);
    tGeo.set_salary(tGeo.get_salary() + 1000);
    tPE.set_salary(tPE.get_salary() + 500);
    std::cout << "  Newton's final salary: $" << tPhy.get_salary() << " (Gravity pay-off!)" << std::endl;

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
        std::cout << "  Math Excellence: " << c.get_average_grade_of_clas_from_subject(Subject::Math) << " / 5.0" << std::endl;
        std::cout << "  Logic & CS:      " << c.get_average_grade_of_clas_from_subject(Subject::ComputerScience) << " / 5.0" << std::endl;
        std::cout << "  Humanities:      " << (c.get_average_grade_of_clas_from_subject(Subject::English) + c.get_average_grade_of_clas_from_subject(Subject::History)) / 2.0 << " / 5.0" << std::endl;
        std::cout << "  Status:          " << (c.is_is_class_graduated() ? "OFFICIALLY GRADUATED" : "PENDING") << std::endl;
        std::cout << "  ------------------------------------------------------------------------" << std::endl;
    }

    std::cout << "\n[!] BREAKING: 100 Legends leave the Academy." << std::endl;
    std::cout << "The Board of Trustees is pleased to announce that the school will continue." << std::endl;

    std::cout << "\n--- Final Faculty Financial Audit ---" << std::endl;
    std::cout << "Total Salary for Einstein: $" << tMath.get_salary() << " (Started at $15000)" << std::endl;
    std::cout << "Total Salary for Lovelace: $" << tCS.get_salary() << " (Started at $16000)" << std::endl;
    std::cout << "Total Salary for Newton:   $" << tPhy.get_salary() << " (Started at $14000)" << std::endl;

    std::cout << "\n============================================================================" << std::endl;
    std::cout << "                END OF THE GRAND ACADEMY SIMULATION                         " << std::endl;
    std::cout << "============================================================================" << std::endl;

    return 0;
}
