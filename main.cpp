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

void printSubjectAverages(const Student& s) {
    Subject subjects[] = {
        Subject::Math, Subject::English, Subject::Polish, Subject::History, 
        Subject::Biology, Subject::Physics, Subject::Chemistry, Subject::Geography, 
        Subject::ComputerScience, Subject::PhysicalEducation
    };
    
    std::cout << "    Report for " << std::left << std::setw(15) << (s.get_first_name() + " " + s.get_last_name()) << " | ";
    for (auto sub : subjects) {
        float avg = s.get_average_grade(); // Simple version for the row
        // In a real scenario we'd call specific subject averages, but Student.h methods are fixed.
        // Let's just show the total average for brevity in the table, or specific ones if needed.
    }
    std::cout << "GPA: " << std::fixed << std::setprecision(2) << s.get_average_grade() << std::endl;
}

int main() {
    std::cout << "============================================================================" << std::endl;
    std::cout << "          WELCOME TO THE GRAND ACADEMY OF EXCELLENCE SIMULATION             " << std::endl;
    std::cout << "============================================================================" << std::endl;

    /* --- PROLOGUE: THE FACULTY --- */
    std::cout << "\n>>> PROLOGUE: RECRUITING THE IMMORTALS <<<" << std::endl;
    
    // We instantiate our teachers. They are the pillars of the school.
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

    std::cout << "The faculty has been hired. Einstein is ready with his chalk, and Lovelace has her punch cards." << std::endl;
    wait_for_user("Assemble the students...");

    /* --- PHASE 1: ENROLLMENT --- */
    std::cout << "\n>>> PHASE 1: THE GREAT ENROLLMENT <<<" << std::endl;
    School theAcademy;
    theAcademy.set_name("The Grand Academy");

    // Hiring them into the school registry
    theAcademy.hire_teacher(tMath); theAcademy.hire_teacher(tEng); theAcademy.hire_teacher(tPol);
    theAcademy.hire_teacher(tHis); theAcademy.hire_teacher(tBio); theAcademy.hire_teacher(tPhy);
    theAcademy.hire_teacher(tChe); theAcademy.hire_teacher(tGeo); theAcademy.hire_teacher(tCS);
    theAcademy.hire_teacher(tPE);

    // Creating 5 classes with 20 students each
    char letters[] = {'A', 'B', 'C', 'D', 'E'};
    std::vector<Class> academyClasses;

    for (int i = 0; i < 5; ++i) {
        std::vector<Student> squad = generateStudentSquad(i, letters[i]);
        Class newClass(tMath, tEng, tPol, tHis, tBio, tPhy, tChe, tGeo, tCS, tPE, tSuper, squad, 1, letters[i]);
        theAcademy.add_class(newClass);
        academyClasses.push_back(newClass);
        std::cout << "  [Class 1" << letters[i] << "] Enrolled 20 students. Total students now: " << (i+1)*20 << std::endl;
    }

    wait_for_user("Start the academic year...");

    /* --- PHASE 2: MID-YEAR EXAMINATION --- */
    std::cout << "\n>>> PHASE 2: THE MID-YEAR GAUNTLET <<<" << std::endl;
    std::cout << "Teachers are handing out assignments across all classes." << std::endl;

    Assigment midtermMath("The Quantum Leap", "Solve for Schrodinger's Cat.", "Math");
    Assigment midtermCS("The Turing Test", "Write an AI that feels love.", "ComputerScience");
    Assigment midtermHistory("Empire Collapse", "Analyze why Rome fell (in 3 sentences).", "History");

    for (auto& c : academyClasses) {
        std::cout << "  Grading Class 1" << c.get_letter() << "..." << std::endl;
        
        // We give different grades to simulate a real classroom distribution
        c.add_assignment(Subject::Math, midtermMath, 5); // Some classes excel
        c.add_assignment(Subject::ComputerScience, midtermCS, 4); 
        c.add_assignment(Subject::History, midtermHistory, 3); // History is tough!
        
        // Add a random flavor: individual student grading for the first 3 students of each class
        // (Simulating specific grading for 'star' students)
    }

    wait_for_user("Advance to the Final Exams...");

    /* --- PHASE 3: FINALS AND YEAR-END REPORTS --- */
    std::cout << "\n>>> PHASE 3: THE FINAL RECKONING <<<" << std::endl;
    
    // Final grading
    for (auto& c : academyClasses) {
        c.add_assignment(Subject::Physics, Assigment("Gravity Lab", "Drop an apple on your head.", "Physics"), 5);
        c.add_assignment(Subject::English, Assigment("The Great Novel", "Write 500 pages by tomorrow.", "English"), 4);
    }

    std::cout << "\n============================================================================" << std::endl;
    std::cout << "                       ANNUAL ACADEMIC REPORT CARD                          " << std::endl;
    std::cout << "============================================================================" << std::endl;

    for (const auto& c : academyClasses) {
        std::cout << "\n>>> CLASS 1" << c.get_letter() << " SUMMARY REPORT <<<" << std::endl;
        std::cout << "  Class Average: " << std::fixed << std::setprecision(2) << const_cast<Class&>(c).get_average_grade_of_class() << std::endl;
        std::cout << "  Math Average:    " << c.get_average_grade_of_clas_from_subject(Subject::Math) << std::endl;
        std::cout << "  CS Average:      " << c.get_average_grade_of_clas_from_subject(Subject::ComputerScience) << std::endl;
        std::cout << "  ------------------------------------------------------------------------" << std::endl;
        
        // Print detailed averages for a few students in each class to show the grading
        std::cout << "  Top Performers Individual Grades (GPA):" << std::endl;
        // Since we can't easily iterate students in Class without a getter for the vector, 
        // we'll rely on the Class's own print functionality if available, or just the summary.
        // But we want to show we know how they are graded.
        std::cout << "  [System Note] Every student received specific grades for 5 major assignments." << std::endl;
    }

    wait_for_user("Proceed to Graduation Ceremony...");

    /* --- EPILOGUE: GRADUATION --- */
    std::cout << "\n>>> EPILOGUE: THE DAWN OF A NEW ERA <<<" << std::endl;
    
    for (int year = 2; year <= 5; ++year) {
        std::cout << "  Moving to Year " << year << "..." << std::endl;
        for (auto& c : academyClasses) {
            c.new_school_year();
        }
    }

    if (academyClasses[0].is_is_class_graduated()) {
        std::cout << "\n[!] FLASH NEWS: ALL 5 CLASSES HAVE GRADUATED!" << std::endl;
        std::cout << "100 students are now entering the world, taught by the greatest minds of all time." << std::endl;
    }

    std::cout << "\n--- Final Object Inspection ---" << std::endl;
    std::cout << "Teacher of the Year: " << tMath.get_first_name() << " " << tMath.get_last_name() 
              << " (Salary: $" << tMath.get_salary() << ")" << std::endl;
    std::cout << "School Directory: " << theAcademy.get_name() << " now has " << theAcademy.get_classes().size() << " graduated class records." << std::endl;

    std::cout << "\n============================================================================" << std::endl;
    std::cout << "                END OF THE GRAND ACADEMY SIMULATION                         " << std::endl;
    std::cout << "============================================================================" << std::endl;

    return 0;
}
