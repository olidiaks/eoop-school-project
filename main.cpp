#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm>
#include <random>
#include <map>
#include "School.h"
#include "Teacher.h"
#include "Student.h"
#include "Class.h"
#include "Subject.h"
#include "Assignment.h"

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
    Assignment task(name, desc, to_string(sub));
    std::cout << "\n    >>> Grading Session: '" << name << "' (" << to_string(sub) << ") <<<" << std::endl;
    std::cout << "    " << std::left << std::setw(25) << "STUDENT NAME" << " | " << "GRADE" << std::endl;
    std::cout << "    ------------------------------------------" << std::endl;
    
    std::uniform_int_distribution<int> dist(2, 5); // Grades from 2 to 5
    
    for (auto& student : c.get_students()) {
        int grade = dist(g_rng);
        student.add_assignment(sub, task, grade);
        std::string student_name = student.get_first_name() + " " + student.get_last_name();
        std::cout << "    " << std::left << std::setw(25) << student_name << " | " << grade << std::endl;
    }
}

void printValedictorian(const Class& c) {
    const Student* best = nullptr;
    float maxGpa = -1.0f;
    
    for (const auto& s : c.get_students()) {
        float gpa = s.get_average_grade();
        if (gpa > maxGpa) {
            maxGpa = gpa;
            best = &s;
        }
    }
    
    if (best) {
        std::cout << "  [VALEDICTORIAN] " << best->get_first_name() << " " << best->get_last_name() 
                  << " with GPA: " << std::fixed << std::setprecision(2) << maxGpa << std::endl;
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

    School theAcademy;
    theAcademy.set_name("The Grand Academy");
    
    // Hire faculty
    theAcademy.hire_teacher(tMath); theAcademy.hire_teacher(tEng); theAcademy.hire_teacher(tPol);
    theAcademy.hire_teacher(tHis); theAcademy.hire_teacher(tBio); theAcademy.hire_teacher(tPhy);
    theAcademy.hire_teacher(tChe); theAcademy.hire_teacher(tGeo); theAcademy.hire_teacher(tCS);
    theAcademy.hire_teacher(tPE); theAcademy.hire_teacher(tSuper);

    std::cout << "The faculty has been hired into '" << theAcademy.get_name() << "'." << std::endl;

    /* --- YEAR 1: THE SPARK --- */
    std::cout << "\n>>> YEAR 1: THE SPARK (Foundations of Logic) <<<" << std::endl;

    char letters[] = {'A', 'B', 'C', 'D', 'E'};
    std::map<Subject, const Teacher&> teacherMap = {
        {Subject::Math, tMath}, {Subject::English, tEng}, {Subject::Polish, tPol},
        {Subject::History, tHis}, {Subject::Biology, tBio}, {Subject::Physics, tPhy},
        {Subject::Chemistry, tChe}, {Subject::Geography, tGeo}, {Subject::ComputerScience, tCS},
        {Subject::PhysicalEducation, tPE}
    };

    for (int i = 0; i < 5; ++i) {
        std::vector<Student> squad = generateStudentSquad(i, letters[i]);
        theAcademy.add_class(tSuper, teacherMap, letters[i], squad);
    }

    std::cout << "Enrollment complete. 100 students distributed across 5 classes." << std::endl;

    for (auto& c : theAcademy.get_classes()) {
        performIndividualGrading(c, Subject::Math, "Calculus Basics", "Derivatives.");
        performIndividualGrading(c, Subject::ComputerScience, "Logic Circuits", "Boolean Algebra.");
    }

    std::cout << "Year 1 Averages: School GPA is " << std::fixed << std::setprecision(2) << theAcademy.get_average_grade_of_school() << std::endl;

    std::cout << "\n[PROMOTION] Year 1: Einstein and Lovelace receive raises." << std::endl;
    tMath.set_salary(tMath.get_salary() + 1000);
    tCS.set_salary(tCS.get_salary() + 1500);
    wait_for_user("Moving to Year 2...");

    /* --- YEAR 2: THE NATURAL WORLD --- */
    std::cout << "\n>>> YEAR 2: THE NATURAL WORLD (Life and Matter) <<<" << std::endl;
    theAcademy.new_school_year();

    for (auto& c : theAcademy.get_classes()) {
        performIndividualGrading(c, Subject::Biology, "Natural Selection", "Survival.");
        performIndividualGrading(c, Subject::Chemistry, "Radioactive Decay", "Half-life.");
    }

    /* --- THE GADFLY CRISIS --- */
    std::cout << "\n[CRISIS] Socrates has been accused of corrupting the youth!" << std::endl;
    std::cout << "Firing supervising teacher Socrates (ID: " << tSuper.get_id() << ")..." << std::endl;
    theAcademy.fire_teacher(tSuper.get_id());
    
    std::cout << "Hiring Plato as the new Philosophy & Supervision Lead..." << std::endl;
    theAcademy.hire_teacher("Plato", "Athens", "the.cave@academy.edu", 1, 1, 1920, 9000, Subject::None);
    
    std::cout << "\n[PROMOTION] Year 2: Darwin and Curie receive raises." << std::endl;
    tBio.set_salary(tBio.get_salary() + 1200);
    tChe.set_salary(tChe.get_salary() + 1200);
    wait_for_user("Moving to Year 3...");

    /* --- YEAR 3: THE HUMAN SOUL --- */
    std::cout << "\n>>> YEAR 3: THE HUMAN SOUL (Literature and Time) <<<" << std::endl;
    theAcademy.new_school_year();

    for (auto& c : theAcademy.get_classes()) {
        performIndividualGrading(c, Subject::English, "Hamlet Analysis", "To be.");
        performIndividualGrading(c, Subject::History, "Peloponnesian War", "Conflict.");
        performIndividualGrading(c, Subject::Polish, "Epic Poetry", "Pan Tadeusz.");
    }

    std::cout << "\n[PROMOTION] Year 3: The humanities faculty receive raises." << std::endl;
    tEng.set_salary(tEng.get_salary() + 1000);
    tPol.set_salary(tPol.get_salary() + 1000);
    tHis.set_salary(tHis.get_salary() + 1000);
    wait_for_user("Moving to Year 4...");

    /* --- YEAR 4: THE UNIVERSAL LAWS --- */
    std::cout << "\n>>> YEAR 4: THE UNIVERSAL LAWS (Final Frontiers) <<<" << std::endl;
    theAcademy.new_school_year();

    for (auto& c : theAcademy.get_classes()) {
        performIndividualGrading(c, Subject::Physics, "Laws of Motion", "F = ma.");
        performIndividualGrading(c, Subject::Geography, "Global Mapping", "Systems.");
        performIndividualGrading(c, Subject::PhysicalEducation, "Endurance", "Marathon.");
    }

    std::cout << "\n[PROMOTION] Year 4: The physics and PE faculty receive final raises." << std::endl;
    tPhy.set_salary(tPhy.get_salary() + 2000);
    tGeo.set_salary(tGeo.get_salary() + 1000);
    tPE.set_salary(tPE.get_salary() + 500);
    wait_for_user("Proceed to Graduation Day...");

    /* --- EPILOGUE: THE GRAND GRADUATION --- */
    std::cout << "\n>>> THE GRAND GRADUATION CEREMONY <<<" << std::endl;
    theAcademy.new_school_year(); // Mark as graduated

    std::cout << "============================================================================" << std::endl;
    std::cout << "                       FINAL ACADEMIC RECORD BOOK                           " << std::endl;
    std::cout << "============================================================================" << std::endl;

    for (const auto& c : theAcademy.get_classes()) {
        std::cout << "\n>>> CLASS " << c.get_letter() << " GRADUATION REPORT <<<" << std::endl;
        std::cout << "  Final Class GPA: " << std::fixed << std::setprecision(2) << c.get_average_grade_of_class() << std::endl;
        printValedictorian(c);
    }

    std::cout << "\n--- School-Wide Performance Audit ---" << std::endl;
    std::cout << "  Grand Academy Final Average: " << std::fixed << std::setprecision(2) << theAcademy.get_average_grade_of_school() << std::endl;
    
    std::cout << "\n--- Faculty Grading Rigor Audit ---" << std::endl;
    std::cout << "  Einstein (Math) Avg:    " << std::fixed << std::setprecision(2) << theAcademy.get_average_students_grades_of_teacher(tMath.get_id()) << std::endl;
    std::cout << "  Lovelace (CS) Avg:      " << std::fixed << std::setprecision(2) << theAcademy.get_average_students_grades_of_teacher(tCS.get_id()) << std::endl;
    std::cout << "  Newton (Physics) Avg:   " << std::fixed << std::setprecision(2) << theAcademy.get_average_students_grades_of_teacher(tPhy.get_id()) << std::endl;

    std::cout << "\n============================================================================" << std::endl;
    std::cout << "                END OF THE GRAND ACADEMY SIMULATION                         " << std::endl;
    std::cout << "============================================================================" << std::endl;

    return 0;
}
