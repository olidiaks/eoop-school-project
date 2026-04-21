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
        std::string email = fn + "." + ln + std::to_string(classNum + 1) + classLetter + "@academy.edu";
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

// Global random engine for grading
std::mt19937 g_rng(1337);

void performIndividualGrading(Class& c, Subject sub, const std::string& name, const std::string& desc) {
    Assigment task(name, desc, to_string(sub));
    std::cout << "\n    >>> Grading Session: '" << name << "' (" << to_string(sub) << ") <<<" << std::endl;
    std::cout << "    " << std::left << std::setw(25) << "STUDENT NAME" << " | " << "GRADE" << std::endl;
    std::cout << "    ------------------------------------------" << std::endl;
    
    std::uniform_int_distribution<int> dist(2, 5); // Grades from 2 to 5
    
    for (auto& student : c.get_students()) {
        int grade = dist(g_rng);
        student.add_assignment(sub, task, grade);
        std::cout << "    " << std::left << std::setw(25) << (student.get_first_name() + " " + student.get_last_name())
                  << " |   " << grade << std::endl;
    }
}

int main() {
    std::cout << "============================================================================" << std::endl;
    std::cout
    << "          WELCOME TO THE GRAND ACADEMY OF EXCELLENCE SIMULATION             " << std::endl;
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

    std::cout << "The faculty has been hired. Starting salaries:" << std::endl;
    std::cout << "  Einstein: $" << tMath.get_salary() << " | Lovelace: $" << tCS.get_salary() << std::endl;

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
        printClassStudents("Class 1" + std::string(1, letters[i]), squad);
    }

    std::cout << "\nEinstein and Lovelace take the lead. Performing individual grading..." << std::endl;
    for (auto& c : academyClasses) {
        std::cout << "\n[CLASS 1" << c.get_letter() << " LEDGER]" << std::endl;
        performIndividualGrading(c, Subject::Math, "Calculus Basics", "Derivatives and Integrals.");
        performIndividualGrading(c, Subject::ComputerScience, "Logic Circuits", "AND, OR, NOT gates.");
    }

    std::cout << "\n[PROMOTION] Year 1: Einstein and Lovelace receive raises." << std::endl;
    tMath.set_salary(tMath.get_salary() + 1000);
    tCS.set_salary(tCS.get_salary() + 1500);
    wait_for_user("Moving to Year 2...");

    /* --- YEAR 2: THE NATURAL WORLD --- */
    std::cout << "\n>>> YEAR 2: THE NATURAL WORLD (Life and Matter) <<<" << std::endl;
    for (auto& c : academyClasses) c.new_school_year();

    std::cout << "Darwin and Curie begin their specialized curriculum." << std::endl;
    for (auto& c : academyClasses) {
        std::cout << "\n[CLASS 2" << c.get_letter() << " LEDGER]" << std::endl;
        performIndividualGrading(c, Subject::Biology, "Natural Selection", "Survival of the fittest.");
        performIndividualGrading(c, Subject::Chemistry, "Radioactive Decay", "Half-life calculations.");
    }

    std::cout << "\n[PROMOTION] Year 2: Darwin and Curie receive raises." << std::endl;
    tBio.set_salary(tBio.get_salary() + 1200);
    tChe.set_salary(tChe.get_salary() + 1200);
    wait_for_user("Moving to Year 3...");

    /* --- YEAR 3: THE HUMAN SOUL --- */
    std::cout << "\n>>> YEAR 3: THE HUMAN SOUL (Literature and Time) <<<" << std::endl;
    for (auto& c : academyClasses) c.new_school_year();

    std::cout << "Shakespeare, Mickiewicz, and Herodotus explore the depths of humanity." << std::endl;
    for (auto& c : academyClasses) {
        std::cout << "\n[CLASS 3" << c.get_letter() << " LEDGER]" << std::endl;
        performIndividualGrading(c, Subject::English, "Hamlet Analysis", "To be or not to be.");
        performIndividualGrading(c, Subject::History, "Peloponnesian War", "Conflict of empires.");
        performIndividualGrading(c, Subject::Polish, "Epic Poetry", "Pan Tadeusz study.");
    }

    std::cout << "\n[PROMOTION] Year 3: The humanities faculty receive raises." << std::endl;
    tEng.set_salary(tEng.get_salary() + 1000);
    tPol.set_salary(tPol.get_salary() + 1000);
    tHis.set_salary(tHis.get_salary() + 1000);
    wait_for_user("Moving to Year 4...");

    /* --- YEAR 4: THE UNIVERSAL LAWS --- */
    std::cout << "\n>>> YEAR 4: THE UNIVERSAL LAWS (Final Frontiers) <<<" << std::endl;
    for (auto& c : academyClasses) c.new_school_year();

    std::cout << "Newton, Humboldt, and Bolt prepare the students for the real world." << std::endl;
    for (auto& c : academyClasses) {
        std::cout << "\n[CLASS 4" << c.get_letter() << " LEDGER]" << std::endl;
        performIndividualGrading(c, Subject::Physics, "Laws of Motion", "F = ma.");
        performIndividualGrading(c, Subject::Geography, "Global Mapping", "The Earth as a system.");
        performIndividualGrading(c, Subject::PhysicalEducation, "Endurance Test", "The Marathon.");
    }

    std::cout << "\n[PROMOTION] Year 4: The physics and PE faculty receive final raises." << std::endl;
    tPhy.set_salary(tPhy.get_salary() + 2000);
    tGeo.set_salary(tGeo.get_salary() + 1000);
    tPE.set_salary(tPE.get_salary() + 500);
    wait_for_user("Proceed to Graduation Day...");

    /* --- EPILOGUE: THE GRAND GRADUATION --- */
    std::cout << "\n>>> THE GRAND GRADUATION CEREMONY <<<" << std::endl;
    for (auto& c : academyClasses) c.new_school_year();

    std::cout << "============================================================================" << std::endl;
    std::cout << "                       FINAL ACADEMIC RECORD BOOK                           " << std::endl;
    std::cout << "============================================================================" << std::endl;

    for (const auto& c : academyClasses) {
        std::cout << "\n>>> CLASS " << c.get_letter() << " GRADUATION REPORT <<<" << std::endl;
        std::cout << "  Final Class GPA: " << std::fixed << std::setprecision(2) << const_cast<Class&>(c).get_average_grade_of_class() << std::endl;
        std::cout << "  Status:          OFFICIALLY GRADUATED" << std::endl;
        std::cout << "  ------------------------------------------------------------------------" << std::endl;
    }

    std::cout << "\n--- Final Faculty Financial Audit ---" << std::endl;
    std::cout << "Einstein Final Salary: $" << tMath.get_salary() << std::endl;
    std::cout << "Lovelace Final Salary: $" << tCS.get_salary() << std::endl;
    std::cout << "Newton Final Salary:   $" << tPhy.get_salary() << std::endl;

    std::cout << "\n============================================================================" << std::endl;
    std::cout << "                END OF THE GRAND ACADEMY SIMULATION                         " << std::endl;
    std::cout << "============================================================================" << std::endl;

    return 0;
}
