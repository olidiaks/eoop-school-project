#include <iostream>
#include <vector>
#include <thread>
#include <chrono>
#include "School.h"
#include "Teacher.h"
#include "Student.h"
#include "Class.h"
#include "Subject.h"
#include "Assigment.h"

// Helper to add a bit of "theatrical" delay to the story
void pause() {
    std::cout << "\n[Press Enter to continue the story...]" << std::endl;
    std::cin.get();
}

int main() {
    std::cout << "==========================================================" << std::endl;
    std::cout << "   THE CHRONICLE OF THE ACADEMY OF EXCELLENCE (2026-2030)  " << std::endl;
    std::cout << "==========================================================" << std::endl;

    /* --- CHAPTER 1: THE FOUNDATION --- */
    // In the year 2026, a visionary project began: The Academy of Excellence was born.
    // Its mission was simple: gather the greatest minds in history to teach the next generation.
    
    School academy;
    academy.set_name("The Academy of Excellence");
    std::cout << "\n>>> CHAPTER 1: THE FOUNDATION <<<" << std::endl;
    std::cout << "The gates of '" << academy.get_name() << "' have officially opened." << std::endl;

    // We start by recruiting a faculty of legends.
    std::cout << "Recruiting the Faculty of Legends..." << std::endl;
    
    Teacher einstein("Albert", "Einstein", "emc2@academy.edu", 14, 3, 1879, 12000, Subject::Math);
    Teacher shakespeare("William", "Shakespeare", "bard@academy.edu", 23, 4, 1564, 11000, Subject::English);
    Teacher curie("Marie", "Curie", "radium@academy.edu", 7, 11, 1867, 11500, Subject::Chemistry);
    Teacher lovelace("Ada", "Lovelace", "first.coder@academy.edu", 10, 12, 1815, 13000, Subject::ComputerScience);
    Teacher darwin("Charles", "Darwin", "origin@academy.edu", 12, 2, 1809, 10500, Subject::Biology);
    Teacher mickiewicz("Adam", "Mickiewicz", "pan.tadeusz@academy.edu", 24, 12, 1798, 10000, Subject::Polish);
    Teacher herodotus("Herodotus", "Halicarnassus", "history@academy.edu", 1, 1, 1900, 9500, Subject::History);
    Teacher newton("Isaac", "Newton", "gravity@academy.edu", 4, 1, 1643, 11000, Subject::Physics);
    Teacher humboldt("Alexander", "Humboldt", "cosmos@academy.edu", 14, 9, 1769, 10000, Subject::Geography);
    Teacher bolt("Usain", "Bolt", "lightning@academy.edu", 21, 8, 1986, 9000, Subject::PhysicalEducation);
    Teacher socrates("Socrates", "Athens", "wisdom@academy.edu", 1, 1, 1900, 8000, Subject::None); // Supervising

    academy.hire_teacher(einstein);
    academy.hire_teacher(shakespeare);
    academy.hire_teacher(curie);
    academy.hire_teacher(lovelace);
    std::cout << "Successfully hired: Einstein (Math), Shakespeare (English), Curie (Chemistry), and Lovelace (CS)." << std::endl;

    /* --- CHAPTER 2: THE ARRIVAL --- */
    // Four brave students were chosen for the inaugural 'Class A'. 
    // They represent the hope of the future.
    
    std::cout << "\n>>> CHAPTER 2: THE ARRIVAL <<<" << std::endl;
    std::vector<Student> classA_students;
    classA_students.emplace_back("Alice", "Liddell", "alice@wonderland.com", 4, 5, 2012);
    classA_students.emplace_back("Arthur", "Pendragon", "king@camelot.org", 10, 10, 2012);
    classA_students.emplace_back("Marie", "Shelley", "frankenstein@author.com", 30, 8, 2012);
    classA_students.emplace_back("Nikola", "Tesla", "lighting@energy.com", 10, 7, 2012);

    std::cout << "The 'Dream Team' of students has arrived for Year 1:" << std::endl;
    for(const auto& s : classA_students) {
        std::cout << " - " << s.get_first_name() << " " << s.get_last_name() << " (Future Genius)" << std::endl;
    }

    // Forming Class 1A
    Class class1A(einstein, shakespeare, mickiewicz, herodotus, darwin, newton, curie, 
                  humboldt, lovelace, bolt, socrates, classA_students, 1, 'A');
    academy.add_class(class1A);

    /* --- CHAPTER 3: YEAR 1 - THE SPARK --- */
    // The first year was all about fundamentals. Einstein didn't take it easy on them.
    
    std::cout << "\n>>> CHAPTER 3: YEAR 1 - THE SPARK <<<" << std::endl;
    std::cout << "Einstein announces the 'General Relativity for Kids' exam." << std::endl;
    class1A.add_assignment(Subject::Math, "General Relativity Basics", "Prove E=mc^2 in 3 steps.");
    
    // Grading Year 1 Math: They did surprisingly well!
    std::cout << "Grading Class 1A's first Math exams..." << std::endl;
    class1A.add_assignment(Subject::Math, Assigment("General Relativity Basics", "...", "Math"), 5);
    
    std::cout << "Shakespeare assigns a sonnet." << std::endl;
    class1A.add_assignment(Subject::English, "Modern Sonnet", "Write about a smartphone in iambic pentameter.", 4);

    std::cout << "Year 1 Results: Average Grade = " << class1A.get_average_grade_of_class() << std::endl;
    pause();

    /* --- CHAPTER 4: YEAR 2 - THE CHALLENGE --- */
    // As they entered Year 2, the workload doubled. Curie introduced them to Radium (safely!).
    
    std::cout << "\n>>> CHAPTER 4: YEAR 2 - THE CHALLENGE <<<" << std::endl;
    class1A.new_school_year(); // Moves to Year 2
    std::cout << "Class 1A is now Class 2A. The students look older and slightly more tired." << std::endl;

    std::cout << "Marie Curie sets up a Lab Experiment." << std::endl;
    class1A.add_assignment(Subject::Chemistry, "Isotope Identification", "Find the stable ones.", 5);

    std::cout << "Ada Lovelace challenges them with the Analytical Engine." << std::endl;
    class1A.add_assignment(Subject::ComputerScience, "Babbage Loops", "Calculate Bernoulli numbers.", 5);

    std::cout << "Class 2A is excelling under the pressure!" << std::endl;
    pause();

    /* --- CHAPTER 5: YEAR 3 - THE DEPTHS --- */
    // Year 3 brought deep philosophical questions from Socrates and History from Herodotus.
    
    std::cout << "\n>>> CHAPTER 5: YEAR 3 - THE DEPTHS <<<" << std::endl;
    class1A.new_school_year(); // Moves to Year 3
    
    std::cout << "Herodotus asks for a 50-page report on the Greco-Persian Wars." << std::endl;
    class1A.add_assignment(Subject::History, "The Persian Wars", "Fact or Fiction?", 3); // Tough grading this year!

    std::cout << "Biology with Darwin: The Galapagos Trip." << std::endl;
    class1A.add_assignment(Subject::Biology, "Beak Variation Study", "Observation of finches.", 4);

    std::cout << "Current Academic Standing: " << class1A.get_average_grade_of_class() << std::endl;
    pause();

    /* --- CHAPTER 6: YEAR 4 - THE FINAL STRETCH --- */
    // The final year. The students are preparing for the real world.
    
    std::cout << "\n>>> CHAPTER 6: YEAR 4 - THE FINAL STRETCH <<<" << std::endl;
    class1A.new_school_year(); // Moves to Year 4
    
    std::cout << "Newton teaches 'Final Laws of Motion'." << std::endl;
    class1A.add_assignment(Subject::Physics, "Universal Gravitation", "Calculate the moon's orbit.", 5);

    std::cout << "The students are studying day and night..." << std::endl;
    std::cout << "Tesla is particularly good at Physics, as expected." << std::endl;
    
    pause();

    /* --- CHAPTER 7: GRADUATION --- */
    // The moment has arrived. After 4 years of hard work, the students are ready to leave.
    
    std::cout << "\n>>> CHAPTER 7: GRADUATION <<<" << std::endl;
    class1A.new_school_year(); // Year 5 trigger -> Graduation
    
    if (class1A.is_is_class_graduated()) {
        std::cout << "**********************************************************" << std::endl;
        std::cout << "  CONGRATULATIONS! CLASS 1A HAS OFFICIALLY GRADUATED!    " << std::endl;
        std::cout << "**********************************************************" << std::endl;
        std::cout << "They leave the Academy as the most educated cohort in history." << std::endl;
    }

    /* --- FINAL REPORT --- */
    std::cout << "\n>>> THE ACADEMY FINAL RECORDS <<<" << std::endl;
    
    // Printing the final state of the graduates
    std::cout << "\n--- Graduate Diploma Details ---" << std::endl;
    std::cout << class1A << std::endl;

    std::cout << "\n--- Faculty Spotlight: Professor Einstein ---" << std::endl;
    std::cout << einstein << std::endl;

    std::cout << "\n--- Faculty Spotlight: Professor Lovelace ---" << std::endl;
    std::cout << lovelace << std::endl;

    std::cout << "\nFinal School Status: " << academy.get_name() << " is preparing for the next generation." << std::endl;
    std::cout << "==========================================================" << std::endl;
    std::cout << "             END OF THE CHRONICLE (2026-2030)            " << std::endl;
    std::cout << "==========================================================" << std::endl;

    return 0;
}
