//
// Created by olidiaks on 4/19/26.
//

#include <gtest/gtest.h>
#include <sstream>
#include <vector>
#include "Student.h"

class StudentTest : public ::testing::Test {
protected:
    Student student{"John", "Doe", "john.doe@example.com", 15, 4, 2005};
};

TEST_F(StudentTest, ConstructorAndInheritance) {
    EXPECT_EQ(student.get_first_name(), "John");
    EXPECT_EQ(student.get_last_name(), "Doe");
    EXPECT_EQ(student.get_email(), "john.doe@example.com");
    EXPECT_EQ(student.get_day_of_birth(), 15);
    EXPECT_EQ(student.get_month_of_birth(), 4);
    EXPECT_EQ(student.get_year_of_birth(), 2005);
}

TEST_F(StudentTest, Not_Initalized_Subject) {
    const std::vector<Assignment> & math = student.get_assignments_from_subject(Subject::Math);
    ASSERT_EQ(math.size(), 0);
}

TEST_F(StudentTest, AddAssignment_Object) {
    Assignment a("HW1", "Desc1", "Math");
    student.add_assignment(Subject::Math, a);
    
    const std::vector<Assignment> & math = student.get_assignments_from_subject(Subject::Math);
    ASSERT_EQ(math.size(), 1);
    EXPECT_EQ(math.front().get_name(), "HW1");
    EXPECT_EQ(math.front().get_grade(), 0);
}

TEST_F(StudentTest, AddAssignment_NameDescription) {
    student.add_assignment(Subject::English, "Essay", "Summer theme");

    const std::vector<Assignment>& english = student.get_assignments_from_subject(Subject::English);
    ASSERT_EQ(english.size(), 1);
    EXPECT_EQ(english.front().get_name(), "Essay");
    EXPECT_EQ(english.front().get_description(), "Summer theme");
}

TEST_F(StudentTest, AddAssignment_WithGrade) {
    Assignment a("Test1", "History quiz", "History");
    student.add_assignment(Subject::History, a, 5);
    
    const auto& history = student.get_assignments_from_subject(Subject::History);
    ASSERT_EQ(history.size(), 1);
    EXPECT_EQ(history.front().get_grade(), 5);
}

TEST_F(StudentTest, AddAssignment_GradedObject) {
    Assignment a("Lab1", "Biology lab", "Biology", 4);
    student.add_assignment(Subject::Biology, a);
    
    const auto& biology = student.get_assignments_from_subject(Subject::Biology);
    ASSERT_EQ(biology.size(), 1);
    EXPECT_EQ(biology.front().get_grade(), 4);
}

TEST_F(StudentTest, AddAssignment_GradedObjectWithNewGrade) {
    Assignment a("Prob1", "Physics problems", "Physics", 2);
    student.add_assignment(Subject::Physics, a, 5);
    
    const auto& physics = student.get_assignments_from_subject(Subject::Physics);
    ASSERT_EQ(physics.size(), 1);
    EXPECT_EQ(physics.front().get_grade(), 5);
}

TEST_F(StudentTest, AverageGradePerSubject) {
    student.add_assignment(Subject::Math, Assignment("M1", "D1", "Math"), 5);
    student.add_assignment(Subject::Math, Assignment("M2", "D2", "Math"), 3);
    EXPECT_FLOAT_EQ(student.get_average_grade_from_subject(Subject::Math), 4.0f);

    student.add_assignment(Subject::Polish, Assignment("P1", "D1", "Polish"), 2);
    student.add_assignment(Subject::Polish, Assignment("P2", "D2", "Polish"), 4);
    student.add_assignment(Subject::Polish, Assignment("P3", "D3", "Polish"), 6);
    EXPECT_FLOAT_EQ(student.get_average_grade_from_subject(Subject::Polish), 4.0f);
}

TEST_F(StudentTest, TotalAverageGrade) {
    student.add_assignment(Subject::Math, Assignment("M1", "D1", "Math"), 5); 
    student.add_assignment(Subject::English, Assignment("E1", "D1", "English"), 3); 
    // Total (5+3)/2 = 4.0
    EXPECT_FLOAT_EQ(student.get_average_grade(), 4.0f);

    student.add_assignment(Subject::History, Assignment("H1", "D1", "History"), 2);
    student.add_assignment(Subject::History, Assignment("H2", "D2", "History"), 2);
    // Total (5+3+2+2)/4 = 12/4 = 3.0
    EXPECT_FLOAT_EQ(student.get_average_grade(), 3.0f);

    student.add_assignment(Subject::Math, Assignment("M3", "D3", "Math"), 4);
    // Total (12+4)/5 = 16/5 = 3.2
    EXPECT_FLOAT_EQ(student.get_average_grade(), 3.2f);
}

TEST_F(StudentTest, GetAllAssignments) {
    student.add_assignment(Subject::Chemistry, "C1", "D1");
    student.add_assignment(Subject::Geography, "G1", "D1");
    student.add_assignment(Subject::ComputerScience, "CS1", "D1");
    student.add_assignment(Subject::PhysicalEducation, "PE1", "D1");

    EXPECT_EQ(student.get_assignments_from_subject(Subject::Chemistry).size(), 1);
    EXPECT_EQ(student.get_assignments_from_subject(Subject::Geography).size(), 1);
    EXPECT_EQ(student.get_assignments_from_subject(Subject::ComputerScience).size(), 1);
    EXPECT_EQ(student.get_assignments_from_subject(Subject::PhysicalEducation).size(), 1);
}

TEST_F(StudentTest, EqualityOperators) {
    Student student2{"John", "Doe", "john.doe@example.com", 15, 4, 2005};
    EXPECT_NE(student, student2);

    Student student3(student);
    EXPECT_EQ(student, student3);
    
    student3.add_assignment(Subject::Math, "M1", "D1");
    EXPECT_NE(student, student3);
}

TEST_F(StudentTest, StreamOperator) {
    student.add_assignment(Subject::Math, Assignment("M1", "D1", "Math"), 5);
    std::stringstream ss;
    ss << student;
    std::string output = ss.str();
    
    EXPECT_NE(output.find("John"), std::string::npos);
    EXPECT_NE(output.find("Doe"), std::string::npos);
    EXPECT_NE(output.find("Math assignments:"), std::string::npos);
}

TEST_F(StudentTest, ToStringSubject) {
    EXPECT_STREQ(to_string(Subject::Math), "Math");
    EXPECT_STREQ(to_string(Subject::English), "English");
    EXPECT_STREQ(to_string(Subject::Polish), "Polish");
    EXPECT_STREQ(to_string(Subject::History), "History");
    EXPECT_STREQ(to_string(Subject::Biology), "Biology");
    EXPECT_STREQ(to_string(Subject::Physics), "Physics");
    EXPECT_STREQ(to_string(Subject::Chemistry), "Chemistry");
    EXPECT_STREQ(to_string(Subject::Geography), "Geography");
    EXPECT_STREQ(to_string(Subject::ComputerScience), "ComputerScience");
    EXPECT_STREQ(to_string(Subject::PhysicalEducation), "PhysicalEducation");
}
