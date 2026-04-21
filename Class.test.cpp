#include <gtest/gtest.h>
#include "Class.h"
#include <sstream>

class ClassTest : public ::testing::Test {
protected:
    Teacher mathTeacher{"John", "Doe", "john@math.com", 1, 1, 1980, 5000, "Math"};
    Teacher englishTeacher{"Jane", "Smith", "jane@english.com", 2, 2, 1981, 5100, "English"};
    Teacher polishTeacher{"Adam", "Mickiewicz", "adam@polish.com", 3, 3, 1982, 5200, "Polish"};
    Teacher historyTeacher{"Herodotus", "History", "hero@history.com", 4, 4, 1983, 5300, "History"};
    Teacher biologyTeacher{"Charles", "Darwin", "charles@biology.com", 5, 5, 1984, 5400, "Biology"};
    Teacher physicsTeacher{"Albert", "Einstein", "albert@physics.com", 6, 6, 1985, 5500, "Physics"};
    Teacher chemistryTeacher{"Marie", "Curie", "marie@chemistry.com", 7, 7, 1986, 5600, "Chemistry"};
    Teacher geographyTeacher{"Marco", "Polo", "marco@geography.com", 8, 8, 1987, 5700, "Geography"};
    Teacher computerScienceTeacher{"Alan", "Turing", "alan@cs.com", 9, 9, 1988, 5800, "ComputerScience"};
    Teacher physicalEducationTeacher{"Usain", "Bolt", "usain@pe.com", 10, 10, 1989, 5900, "PE"};
    Teacher superVisingTeacher{"Master", "Shifu", "shifu@super.com", 11, 11, 1990, 6000, "Supervising"};

    Class createClass(int year = 1, char letter = 'A') {
        return Class(mathTeacher, englishTeacher, polishTeacher, historyTeacher, biologyTeacher,
                     physicsTeacher, chemistryTeacher, geographyTeacher, computerScienceTeacher,
                     physicalEducationTeacher, superVisingTeacher, year, letter);
    }
};

TEST_F(ClassTest, ConstructorAndGetters) {
    Class c = createClass(2, 'B');
    EXPECT_GT(c.get_id(), 0);
    EXPECT_EQ(c.get_math_teacher(), mathTeacher);
    EXPECT_EQ(c.get_english_teacher(), englishTeacher);
    EXPECT_EQ(c.get_polish_teacher(), polishTeacher);
    EXPECT_EQ(c.get_history_teacher(), historyTeacher);
    EXPECT_EQ(c.get_biology_teacher(), biologyTeacher);
    EXPECT_EQ(c.get_physics_teacher(), physicsTeacher);
    EXPECT_EQ(c.get_chemistry_teacher(), chemistryTeacher);
    EXPECT_EQ(c.get_geography_teacher(), geographyTeacher);
    EXPECT_EQ(c.get_computer_science_teacher(), computerScienceTeacher);
    EXPECT_EQ(c.get_physical_education_teacher(), physicalEducationTeacher);
    EXPECT_EQ(c.get_super_vising_teacher(), superVisingTeacher);
    EXPECT_EQ(c.get_count_of_students(), 0);
    EXPECT_EQ(c.get_year(), 2);
    EXPECT_EQ(c.get_letter(), 'B');
    EXPECT_FALSE(c.is_is_class_graduated());
}

TEST_F(ClassTest, ConstructorWithStudents) {
    std::vector<Student> students;
    students.emplace_back("Alice", "Wonder", "alice@wonder.com", 1, 1, 2010);
    students.emplace_back("Bob", "Builder", "bob@build.com", 1, 1, 2010);
    
    // Test constructor: (Teachers..., const std::vector<Student>&, int year, char letter)
    Class c1(mathTeacher, englishTeacher, polishTeacher, historyTeacher, biologyTeacher,
             physicsTeacher, chemistryTeacher, geographyTeacher, computerScienceTeacher,
             physicalEducationTeacher, superVisingTeacher, students, 3, 'X');
    
    EXPECT_EQ(c1.get_count_of_students(), 2);
    EXPECT_EQ(c1.get_year(), 3);
    EXPECT_EQ(c1.get_letter(), 'X');
    EXPECT_TRUE(c1.is_student_in_class(students[0].get_id()));
    EXPECT_TRUE(c1.is_student_in_class(students[1].get_id()));

    // Test constructor: (Teachers..., const std::vector<Student>&, char letter)
    Class c2(mathTeacher, englishTeacher, polishTeacher, historyTeacher, biologyTeacher,
             physicsTeacher, chemistryTeacher, geographyTeacher, computerScienceTeacher,
             physicalEducationTeacher, superVisingTeacher, students, 'Y');
    
    EXPECT_EQ(c2.get_count_of_students(), 2);
    EXPECT_EQ(c2.get_year(), 1); // Default year for this constructor
    EXPECT_EQ(c2.get_letter(), 'Y');
}

TEST_F(ClassTest, ConstructorWithStudentsNonConst) {
    std::vector<Student> students;
    students.emplace_back("Alice", "Wonder", "alice@wonder.com", 1, 1, 2010);
    
    // Test constructor: (Teachers..., std::vector<Student>& students, char letter)
    Class c(mathTeacher, englishTeacher, polishTeacher, historyTeacher, biologyTeacher,
            physicsTeacher, chemistryTeacher, geographyTeacher, computerScienceTeacher,
            physicalEducationTeacher, superVisingTeacher, students, 'Z');
    
    EXPECT_EQ(c.get_count_of_students(), 1);
    EXPECT_EQ(c.get_letter(), 'Z');
}

TEST_F(ClassTest, AlternativeConstructors) {
    Class cGraduated(mathTeacher, englishTeacher, polishTeacher, historyTeacher, biologyTeacher,
                     physicsTeacher, chemistryTeacher, geographyTeacher, computerScienceTeacher,
                     physicalEducationTeacher, superVisingTeacher, true);
    EXPECT_TRUE(cGraduated.is_is_class_graduated());
    EXPECT_EQ(cGraduated.get_year(), -1);

    Class cWithLetter(mathTeacher, englishTeacher, polishTeacher, historyTeacher, biologyTeacher,
                      physicsTeacher, chemistryTeacher, geographyTeacher, computerScienceTeacher,
                      physicalEducationTeacher, superVisingTeacher, 'C');
    EXPECT_EQ(cWithLetter.get_letter(), 'C');
    EXPECT_EQ(cWithLetter.get_year(), 1);
    EXPECT_FALSE(cWithLetter.is_is_class_graduated());
}

TEST_F(ClassTest, NewSchoolYear) {
    Class c = createClass(1, 'A');
    EXPECT_EQ(c.get_year(), 1);
    
    c.new_school_year();
    EXPECT_EQ(c.get_year(), 2);
    
    c.new_school_year(); // 3
    c.new_school_year(); // 4
    EXPECT_EQ(c.get_year(), 4);
    EXPECT_FALSE(c.is_is_class_graduated());
    
    c.new_school_year(); // 5 -> graduated
    EXPECT_EQ(c.get_year(), -1);
    EXPECT_TRUE(c.is_is_class_graduated());
}

TEST_F(ClassTest, Setters) {
    Class c = createClass();
    Teacher newTeacher{"New", "Teacher", "new@teacher.com", 1, 1, 1990, 6000, "NewSubject"};
    
    c.set_math_teacher(newTeacher);
    EXPECT_EQ(c.get_math_teacher(), newTeacher);
    
    c.set_english_teacher(newTeacher);
    EXPECT_EQ(c.get_english_teacher(), newTeacher);
    
    c.set_polish_teacher(newTeacher);
    EXPECT_EQ(c.get_polish_teacher(), newTeacher);
    
    c.set_history_teacher(newTeacher);
    EXPECT_EQ(c.get_history_teacher(), newTeacher);
    
    c.set_biology_teacher(newTeacher);
    EXPECT_EQ(c.get_biology_teacher(), newTeacher);
    
    c.set_physics_teacher(newTeacher);
    EXPECT_EQ(c.get_physics_teacher(), newTeacher);
    
    c.set_chemistry_teacher(newTeacher);
    EXPECT_EQ(c.get_chemistry_teacher(), newTeacher);
    
    c.set_geography_teacher(newTeacher);
    EXPECT_EQ(c.get_geography_teacher(), newTeacher);
    
    c.set_computer_science_teacher(newTeacher);
    EXPECT_EQ(c.get_computer_science_teacher(), newTeacher);
    
    c.set_physical_education_teacher(newTeacher);
    EXPECT_EQ(c.get_physical_education_teacher(), newTeacher);
    
    c.set_super_vising_teacher(newTeacher);
    EXPECT_EQ(c.get_super_vising_teacher(), newTeacher);
}

TEST_F(ClassTest, AddAndRemoveStudent) {
    Class c = createClass();
    Student s1("Alice", "Wonderland", "alice@wonder.com", 10, 10, 2010);
    Student s2("Bob", "Builder", "bob@build.com", 11, 11, 2011);
    
    c.add_student(s1);
    EXPECT_EQ(c.get_count_of_students(), 1);
    EXPECT_TRUE(c.is_student_in_class(s1.get_id()));
    
    c.add_student(s2);
    EXPECT_EQ(c.get_count_of_students(), 2);
    EXPECT_TRUE(c.is_student_in_class(s2.get_id()));
    
    EXPECT_EQ(c.get_student(s2.get_id()).get_first_name(), "Bob");
    
    EXPECT_TRUE(c.remove_student(s1.get_id()));
    EXPECT_EQ(c.get_count_of_students(), 1);
    EXPECT_FALSE(c.is_student_in_class(s1.get_id()));
    
    EXPECT_FALSE(c.remove_student(-1)); // Non-existent ID
}

TEST_F(ClassTest, GetStudentThrows) {
    Class c = createClass();
    EXPECT_THROW(c.get_student(9999), std::runtime_error);
}

TEST_F(ClassTest, GradesAndAverages) {
    Class c = createClass();
    Student s1("Alice", "Wonder", "alice@wonder.com", 1, 1, 2010);
    Student s2("Bob", "Builder", "bob@build.com", 1, 1, 2010);
    c.add_student(s1);
    c.add_student(s2);
    
    Assigment mathAss("Algebra Test", "Solve for x", "Math");
    c.add_assignment(Subject::Math, mathAss, 5); // Both students get 5
    
    EXPECT_EQ(c.get_sum_of_grades_from_subject(Subject::Math), 10);
    EXPECT_EQ(c.get_count_of_grades_from_subject(Subject::Math), 2);
    EXPECT_EQ(c.get_average_grade_of_clas_from_subject(Subject::Math), 5);
    
    EXPECT_NEAR(c.get_average_grade_of_class(), 5.0, 0.001);
}

TEST_F(ClassTest, AverageGradeEmptyClass) {
    Class c = createClass();
    EXPECT_EQ(c.get_average_grade_of_clas_from_subject(Subject::Math), 0);
    EXPECT_EQ(c.get_average_grade_of_class(), 0);
}

TEST_F(ClassTest, AddStudentParameters) {
    Class c = createClass();
    c.add_student("Alice", "Wonder", "alice@wonder.com", 1, 1, 2010);
    EXPECT_EQ(c.get_count_of_students(), 1);
}

TEST_F(ClassTest, AddAssignmentOverloads) {
    Class c = createClass();
    Student s1("Alice", "Wonder", "alice@wonder.com", 1, 1, 2010);
    c.add_student(s1);
    
    Assigment ass1("A1", "D1", "Math");
    c.add_assignment(Subject::Math, ass1); // Overload 1
    EXPECT_EQ(c.get_count_of_grades_from_subject(Subject::Math), 1);
    
    c.add_assignment(Subject::Math, "A2", "D2"); // Overload 2
    EXPECT_EQ(c.get_count_of_grades_from_subject(Subject::Math), 2);
    
    c.add_assignment(Subject::Math, ass1, 5); // Overload 3
    EXPECT_EQ(c.get_count_of_grades_from_subject(Subject::Math), 3);
    
    Assigment_graded ass3(ass1, 4);
    c.add_assignment(Subject::Math, ass3); // Overload 4
    EXPECT_EQ(c.get_count_of_grades_from_subject(Subject::Math), 4);

    Assigment_graded ass4(Assigment("A4", "D4", "Math"));
    c.add_assignment(Subject::Math, ass4, 3); // Overload 5
    EXPECT_EQ(c.get_count_of_grades_from_subject(Subject::Math), 5);
}

TEST_F(ClassTest, ComparisonOperators) {
    Class c1 = createClass(1, 'A');
    Class c2 = createClass(1, 'A');
    
    // They have different IDs because of static counter
    EXPECT_FALSE(c1 == c2);
    EXPECT_TRUE(c1 != c2);
    
    Class c3(c1);
    EXPECT_TRUE(c1 == c3);
    
    Class c4 = createClass(2, 'A');
    EXPECT_FALSE(c1 == c4);
    
    Class c5 = createClass(1, 'B');
    EXPECT_FALSE(c1 == c5);
}

TEST_F(ClassTest, CopyAndMove) {
    Class c1 = createClass(3, 'C');
    Student s1("Alice", "Wonder", "alice@wonder.com", 1, 1, 2010);
    c1.add_student(s1);
    
    Class c2(c1);
    EXPECT_EQ(c1, c2);
    EXPECT_EQ(c2.get_count_of_students(), 1);
    EXPECT_EQ(c2.get_year(), 3);
    EXPECT_EQ(c2.get_letter(), 'C');
    
    Class c3 = createClass();
    c3 = c1;
    EXPECT_EQ(c1, c3);
    EXPECT_EQ(c3.get_count_of_students(), 1);
    EXPECT_EQ(c3.get_year(), 3);
    EXPECT_EQ(c3.get_letter(), 'C');
    
    int originalId = c1.get_id();
    Class c4(std::move(c1));
    EXPECT_EQ(c4.get_id(), originalId);
    EXPECT_EQ(c4.get_count_of_students(), 1);
    EXPECT_EQ(c4.get_year(), 3);
    EXPECT_EQ(c4.get_letter(), 'C');
    
    Class c5 = createClass();
    c5 = std::move(c4);
    EXPECT_EQ(c5.get_id(), originalId);
    EXPECT_EQ(c5.get_count_of_students(), 1);
    EXPECT_EQ(c5.get_year(), 3);
    EXPECT_EQ(c5.get_letter(), 'C');
}

TEST_F(ClassTest, Swap) {
    Class c1 = createClass(1, 'A');
    Student s1("Alice", "Wonder", "alice@wonder.com", 1, 1, 2010);
    c1.add_student(s1);
    
    Class c2 = createClass(2, 'B');
    Student s2("Bob", "Builder", "bob@build.com", 1, 1, 2010);
    c2.add_student(s2);
    
    int id1 = c1.get_id();
    int id2 = c2.get_id();
    
    swap(c1, c2);
    
    EXPECT_EQ(c1.get_id(), id2);
    EXPECT_EQ(c2.get_id(), id1);
    EXPECT_EQ(c1.get_year(), 2);
    EXPECT_EQ(c1.get_letter(), 'B');
    EXPECT_EQ(c2.get_year(), 1);
    EXPECT_EQ(c2.get_letter(), 'A');
    EXPECT_EQ(c1.get_count_of_students(), 1);
    EXPECT_EQ(c2.get_count_of_students(), 1);
}

TEST_F(ClassTest, OstreamOperator) {
    Class c = createClass(1, 'A');
    std::stringstream ss;
    ss << c;
    std::string s = ss.str();
    EXPECT_FALSE(s.empty());
    EXPECT_TRUE(s.find("year: 1") != std::string::npos);
    EXPECT_TRUE(s.find("letter: A") != std::string::npos);
}

TEST_F(ClassTest, PrintMethods) {
    Class c = createClass();
    c.print_students();
    c.print_teachers();
}
