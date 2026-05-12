#include <gtest/gtest.h>
#include "Class.h"
#include <vector>
#include <sstream>

class ClassTest : public ::testing::Test {
protected:
    std::vector<Student> students;
    Teacher mathTeacher;
    Teacher englishTeacher;
    Class testClass;

    ClassTest() : 
        mathTeacher("Albert", "Einstein", "einstein@example.com", 14, 3, 1879, 1000, Subject::Math),
        englishTeacher("William", "Shakespeare", "shakespeare@example.com", 23, 4, 1564, 900, Subject::English),
        testClass(1, 'A', mathTeacher)
    {}

    void SetUp() override {
        // Create some students
        students = {
            Student("Alice", "Smith", "alice@example.com", 1, 1, 2010),
            Student("Bob", "Jones", "bob@example.com", 2, 2, 2010)
        };
        
        // Create some teachers
        mathTeacher = Teacher("Albert", "Einstein", "einstein@example.com", 14, 3, 1879, 1000, Subject::Math);
        englishTeacher = Teacher("William", "Shakespeare", "shakespeare@example.com", 23, 4, 1564, 900, Subject::English);
        
        // Create a class
        testClass = Class(1, 'A', mathTeacher);
        testClass.add_student(students[0]);
        testClass.add_student(students[1]);
        testClass.add_teacher(mathTeacher);
    }
};

TEST_F(ClassTest, BasicProperties) {
    EXPECT_EQ(testClass.get_year(), 1);
    EXPECT_EQ(testClass.get_letter(), 'A');
    EXPECT_FALSE(testClass.is_class_graduated());
    EXPECT_EQ(testClass.get_count_of_students(), 2);
}

TEST_F(ClassTest, AddRemoveStudent) {
    Student newStudent("Charlie", "Brown", "charlie@example.com", 3, 3, 2010);
    EXPECT_TRUE(testClass.add_student(newStudent));
    EXPECT_EQ(testClass.get_count_of_students(), 3);
    EXPECT_TRUE(testClass.is_student_in_class(newStudent.get_id()));
    
    EXPECT_FALSE(testClass.add_student(newStudent));
    
    EXPECT_TRUE(testClass.remove_student(newStudent.get_id()));
    EXPECT_EQ(testClass.get_count_of_students(), 2);
    EXPECT_FALSE(testClass.is_student_in_class(newStudent.get_id()));
}

TEST_F(ClassTest, AddRemoveTeacherByID) {
    EXPECT_TRUE(testClass.add_teacher(englishTeacher));
    EXPECT_FALSE(testClass.add_teacher(englishTeacher));
    
    EXPECT_TRUE(testClass.remove_teacher(englishTeacher.get_id()));
    EXPECT_FALSE(testClass.remove_teacher(englishTeacher.get_id()));
}

TEST_F(ClassTest, AddRemoveTeacher) {
    EXPECT_TRUE(testClass.add_teacher(englishTeacher));
    EXPECT_FALSE(testClass.add_teacher(englishTeacher));

    EXPECT_TRUE(testClass.remove_teacher(englishTeacher));
    EXPECT_FALSE(testClass.remove_teacher(englishTeacher));
}

TEST_F(ClassTest, AddRemoveTeacherByMix) {
    EXPECT_TRUE(testClass.add_teacher(englishTeacher));
    EXPECT_FALSE(testClass.add_teacher(englishTeacher));

    EXPECT_TRUE(testClass.remove_teacher(englishTeacher.get_id()));
    EXPECT_FALSE(testClass.remove_teacher(englishTeacher));

}

TEST_F(ClassTest, AddRemoveTeacherByMix2) {
    EXPECT_TRUE(testClass.add_teacher(englishTeacher));
    EXPECT_FALSE(testClass.add_teacher(englishTeacher));

    EXPECT_TRUE(testClass.remove_teacher(englishTeacher));
    EXPECT_FALSE(testClass.remove_teacher(englishTeacher.get_id()));
}

TEST_F(ClassTest, SchoolYearProgression) {
    EXPECT_EQ(testClass.get_year(), 1);
    testClass.new_school_year();
    EXPECT_EQ(testClass.get_year(), 2);
    testClass.new_school_year();
    testClass.new_school_year();
    testClass.new_school_year(); // Year 5
    EXPECT_EQ(testClass.get_year(), -1);
    EXPECT_TRUE(testClass.is_class_graduated());
}

TEST_F(ClassTest, AssignmentsAndGrades) {
    Assignment mathHW("Algebra", "Solve for x", "Math");
    testClass.add_assignment(Subject::Math, mathHW, 5); // Alice gets 5, Bob gets 5
    
    EXPECT_EQ(testClass.get_sum_of_grades_from_subject(Subject::Math), 10);
    EXPECT_EQ(testClass.get_count_of_grades_from_subject(Subject::Math), 2);
    EXPECT_EQ(testClass.get_average_grade_of_clas_from_subject(Subject::Math), 5);
    EXPECT_FLOAT_EQ(testClass.get_average_grade_of_class(), 5.0f);
    
    // Add another assignment with different grades
    // Since we can't easily set individual grades through Class, we'll use get_students()
    // Wait, get_students() returns a const reference.
    // But we have get_student(id) which also returns const reference.
    // So we can only add assignments to the whole class through Class methods.
    
    testClass.add_assignment(Subject::Math, "Geometry", "Pythagorean theorem", 3);
    EXPECT_EQ(testClass.get_sum_of_grades_from_subject(Subject::Math), 16); // 10 + 6
    EXPECT_EQ(testClass.get_count_of_grades_from_subject(Subject::Math), 4);
    EXPECT_EQ(testClass.get_average_grade_of_clas_from_subject(Subject::Math), 4); // 16/4
}

TEST_F(ClassTest, EqualityAndCopy) {
    Class classCopy = testClass;
    EXPECT_EQ(classCopy, testClass);
    
    classCopy.new_school_year();
    EXPECT_NE(classCopy, testClass);
    
    Class classMove = std::move(classCopy);
    EXPECT_EQ(classMove.get_year(), 2);
    EXPECT_EQ(classMove.get_letter(), 'A');
}

TEST_F(ClassTest, GetStudentException) {
    EXPECT_THROW(testClass.get_student(-999), std::runtime_error);
}

TEST_F(ClassTest, StreamOperators) {
    std::stringstream ss;
    ss << testClass;
    std::string output = ss.str();
    EXPECT_NE(output.find("year: 1"), std::string::npos);
    EXPECT_NE(output.find("letter: A"), std::string::npos);
    EXPECT_NE(output.find("Alice"), std::string::npos);
}

TEST_F(ClassTest, AdditionalMethods) {
    // Test add_student by components
    EXPECT_TRUE(testClass.add_student("Charlie", "Day", "charlie@itshappening.com", 5, 5, 1980));
    EXPECT_EQ(testClass.get_count_of_students(), 3);
    
    // Test get_id
    EXPECT_GT(testClass.get_id(), 0);
    
    // Test get_subjects
    auto subjects = testClass.get_subjects();
    EXPECT_FALSE(subjects.empty());
    bool foundMath = false;
    for(auto s : subjects) if(s == Subject::Math) foundMath = true;
    EXPECT_TRUE(foundMath);
    
    // Test is_teacher_teaching
    EXPECT_TRUE(testClass.is_teacher_teaching(mathTeacher));
    EXPECT_TRUE(testClass.is_teacher_teaching(mathTeacher.get_id()));
    EXPECT_FALSE(testClass.is_teacher_teaching(englishTeacher));
    
    // Test get_students
    const auto& studentList = testClass.get_students();
    EXPECT_EQ(studentList.size(), 3);
}

TEST_F(ClassTest, SwapFunction) {
    Teacher otherTeacher("Other", "Teacher", "other@school.com", 1, 1, 1980, 5000, Subject::Physics);
    Class otherClass(2, 'B', otherTeacher);
    otherClass.add_student("Charlie", "Brown", "charlie@school.com", 1, 1, 2010);
    
    int id1 = testClass.get_id();
    int id2 = otherClass.get_id();
    
    swap(testClass, otherClass);
    
    EXPECT_EQ(testClass.get_id(), id2);
    EXPECT_EQ(testClass.get_letter(), 'B');
    EXPECT_EQ(otherClass.get_id(), id1);
    EXPECT_EQ(otherClass.get_letter(), 'A');
}

TEST_F(ClassTest, OtherConstructors) {
    std::map<Subject, const Teacher&> teachers;
    teachers.emplace(Subject::Math, mathTeacher);
    
    Class c1('C', mathTeacher, teachers, students);
    EXPECT_EQ(c1.get_letter(), 'C');
    EXPECT_EQ(c1.get_count_of_students(), 2);
    
    Class c2('D', mathTeacher, teachers);
    EXPECT_EQ(c2.get_letter(), 'D');
    EXPECT_EQ(c2.get_count_of_students(), 0);
    
    Class c3('E', mathTeacher, students);
    EXPECT_EQ(c3.get_letter(), 'E');
    EXPECT_EQ(c3.get_count_of_students(), 2);
}

TEST_F(ClassTest, PrintMethods) {
    // Just ensure they don't crash
    testing::internal::CaptureStdout();
    testClass.print_students();
    testClass.print_teachers();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_FALSE(output.empty());
}

TEST_F(ClassTest, MoreAssignments) {
    testClass.add_assignment(Subject::Math, "HW1", "Desc1", 4);
    //Alice and Bob already in class, Charlie added in previous test (but tests are independent)
    //SetUp adds Alice and Bob.
    EXPECT_EQ(testClass.get_sum_of_grades_from_subject(Subject::Math), 8); // 4 (Alice) + 4 (Bob)
    
    testClass.add_assignment(Subject::Math, "HW2", "Desc2"); // Ungraded (grade=0)
    EXPECT_EQ(testClass.get_count_of_grades_from_subject(Subject::Math), 4); // 2 students * 2 assignments
}

