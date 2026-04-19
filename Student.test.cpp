//
// Created by olidiaks on 4/19/26.
//

#include <gtest/gtest.h>
#include <sstream>
#include <list>
#include "Student.h"

class StudentTest : public ::testing::Test {
protected:
    // Create a default student for testing
    Student student{"John", "Doe", "john.doe@example.com", 15, 4, 2005};

    // Helper to check if an assignment exists in a list
    bool contains_assignment(const std::list<Assigment_graded>& list, const std::string& name) {
        for (const auto& ag : list) {
            if (ag.get_assigment().get_name() == name) return true;
        }
        return false;
    }
};

TEST_F(StudentTest, ConstructorAndInheritance) {
    EXPECT_EQ(student.get_first_name(), "John");
    EXPECT_EQ(student.get_last_name(), "Doe");
    EXPECT_EQ(student.get_email(), "john.doe@example.com");
    EXPECT_EQ(student.get_day_of_birth(), 15);
    EXPECT_EQ(student.get_month_of_birth(), 4);
    EXPECT_EQ(student.get_year_of_birth(), 2005);
}

TEST_F(StudentTest, AddAssignment_Object) {
    Assigment a("HW1", "Desc1", "Math");
    student.add_assignment(Subject::Math, a);
    
    const auto& math = student.get_math_assignments();
    ASSERT_EQ(math.size(), 1);
    EXPECT_EQ(math.front().get_assigment().get_name(), "HW1");
    EXPECT_EQ(math.front().get_grade(), 0);
}

TEST_F(StudentTest, AddAssignment_NameDescription) {
    student.add_assignment(Subject::English, "Essay", "Summer theme");
    
    const auto& english = student.get_english_assignments();
    ASSERT_EQ(english.size(), 1);
    EXPECT_EQ(english.front().get_assigment().get_name(), "Essay");
    EXPECT_EQ(english.front().get_assigment().get_description(), "Summer theme");
}

TEST_F(StudentTest, AddAssignment_WithGrade) {
    Assigment a("Test1", "History quiz", "History");
    student.add_assignment(Subject::History, a, 5);
    
    const auto& history = student.get_history_assignments();
    ASSERT_EQ(history.size(), 1);
    EXPECT_EQ(history.front().get_grade(), 5);
}

TEST_F(StudentTest, AddAssignment_GradedObject) {
    Assigment a("Lab1", "Biology lab", "Biology");
    Assigment_graded ag(a, 4);
    student.add_assignment(Subject::Biology, ag);
    
    const auto& biology = student.get_biology_assignments();
    ASSERT_EQ(biology.size(), 1);
    EXPECT_EQ(biology.front().get_grade(), 4);
}

TEST_F(StudentTest, AddAssignment_GradedObjectWithNewGrade) {
    Assigment a("Prob1", "Physics problems", "Physics");
    Assigment_graded ag(a, 2);
    student.add_assignment(Subject::Physics, ag, 5);
    
    const auto& physics = student.get_physics_assignments();
    ASSERT_EQ(physics.size(), 1);
    EXPECT_EQ(physics.front().get_grade(), 5);
}

TEST_F(StudentTest, AverageGradePerSubject) {
    student.add_assignment(Subject::Math, "M1", "D1", 5);
    student.add_assignment(Subject::Math, "M2", "D2", 3);
    EXPECT_FLOAT_EQ(student.get_average_grade_from_math(), 4.0f);

    student.add_assignment(Subject::Polish, "P1", "D1", 2);
    student.add_assignment(Subject::Polish, "P2", "D2", 4);
    student.add_assignment(Subject::Polish, "P3", "D3", 6);
    EXPECT_FLOAT_EQ(student.get_average_grade_from_polish(), 4.0f);
}

TEST_F(StudentTest, TotalAverageGrade) {
    student.add_assignment(Subject::Math, "M1", "D1", 5); 
    student.add_assignment(Subject::English, "E1", "D1", 3); 
    // Total (5+3)/2 = 4.0
    EXPECT_FLOAT_EQ(student.get_average_grade(), 4.0f);

    student.add_assignment(Subject::History, "H1", "D1", 2);
    student.add_assignment(Subject::History, "H2", "D2", 2);
    // Total (5+3+2+2)/4 = 12/4 = 3.0
    EXPECT_FLOAT_EQ(student.get_average_grade(), 3.0f);
}

TEST_F(StudentTest, GetAllAssignments) {
    student.add_assignment(Subject::Chemistry, "C1", "D1");
    student.add_assignment(Subject::Geography, "G1", "D1");
    student.add_assignment(Subject::ComputerScience, "CS1", "D1");
    student.add_assignment(Subject::PhysicalEducation, "PE1", "D1");

    EXPECT_EQ(student.get_chemistry_assignments().size(), 1);
    EXPECT_EQ(student.get_geography_assignments().size(), 1);
    EXPECT_EQ(student.get_computer_science_assignments().size(), 1);
    EXPECT_EQ(student.get_physical_education_assignments().size(), 1);
}

TEST_F(StudentTest, EqualityOperators) {
    Student student2{"John", "Doe", "john.doe@example.com", 15, 4, 2005};
    // Since Person has unique IDs (unless default constructor -1), they won't be equal.
    EXPECT_NE(student, student2);

    Student student3(student);
    EXPECT_EQ(student, student3);
    
    student3.add_assignment(Subject::Math, "M1", "D1");
    EXPECT_NE(student, student3);
}

TEST_F(StudentTest, StreamOperator) {
    student.add_assignment(Subject::Math, "M1", "D1", 5);
    std::stringstream ss;
    ss << student;
    std::string output = ss.str();
    
    EXPECT_NE(output.find("John"), std::string::npos);
    EXPECT_NE(output.find("Doe"), std::string::npos);
    EXPECT_NE(output.find("mathAssignments:"), std::string::npos);
}

TEST_F(StudentTest, StreamAssignments) {
    student.add_assignment(Subject::Math, "M1", "D1", 5);
    std::stringstream ss;
    stream_assignments(ss, Subject::Math, student);
    std::string output = ss.str();

    EXPECT_NE(output.find("Subject: Math"), std::string::npos);
    EXPECT_NE(output.find("grade: 5"), std::string::npos);
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
