//
// Created by olidiaks on 4/16/26.
//

#include <gtest/gtest.h>
#include "Student.h"
#include <sstream>

TEST(StudentTestSuite, ParameterizedConstructorAllGrades) {
    // Using the constructor that initializes all grades directly (does not call initGrades())
    Student s(1, "John", "Doe", "john.doe@example.com", 15, 4, 2000,
              5.0f, 4.5f, 4.0f, 3.5f, 3.0f, 2.5f, 2.0f, 1.5f, 1.0f, 0.5f);

    EXPECT_EQ(s.get_id(), 1);
    EXPECT_EQ(s.get_first_name(), "John");
    EXPECT_EQ(s.get_last_name(), "Doe");
    EXPECT_EQ(s.get_email(), "john.doe@example.com");

    EXPECT_FLOAT_EQ(s.get_math_grade(), 5.0f);
    EXPECT_FLOAT_EQ(s.get_english_grade(), 4.5f);
    EXPECT_FLOAT_EQ(s.get_polish_grade(), 4.0f);
    EXPECT_FLOAT_EQ(s.get_history_grade(), 3.5f);
    EXPECT_FLOAT_EQ(s.get_biology_grade(), 3.0f);
    EXPECT_FLOAT_EQ(s.get_physics_grade(), 2.5f);
    EXPECT_FLOAT_EQ(s.get_chemistry_grade(), 2.0f);
    EXPECT_FLOAT_EQ(s.get_geography_grade(), 1.5f);
    EXPECT_FLOAT_EQ(s.get_computer_science_grade(), 1.0f);
    EXPECT_FLOAT_EQ(s.get_physical_education_grade(), 0.5f);
}

TEST(StudentTestSuite, ConstructorThrowsNotImplemented) {
    // These constructors call initGrades(), which currently throws
    EXPECT_THROW(Student s, std::runtime_error);
    EXPECT_THROW(Student s(1, "John", "Doe", "john@email.com", 1, 1, 2000), std::runtime_error);
}

TEST(StudentTestSuite, SettersAndGetters) {
    Student s(1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);

    s.set_math_grade(5.5f);
    EXPECT_FLOAT_EQ(s.get_math_grade(), 5.5f);

    s.set_english_grade(4.4f);
    EXPECT_FLOAT_EQ(s.get_english_grade(), 4.4f);

    s.set_polish_grade(3.3f);
    EXPECT_FLOAT_EQ(s.get_polish_grade(), 3.3f);

    s.set_history_grade(2.2f);
    EXPECT_FLOAT_EQ(s.get_history_grade(), 2.2f);

    s.set_biology_grade(1.1f);
    EXPECT_FLOAT_EQ(s.get_biology_grade(), 1.1f);

    s.set_physics_grade(0.9f);
    EXPECT_FLOAT_EQ(s.get_physics_grade(), 0.9f);

    s.set_chemistry_grade(4.8f);
    EXPECT_FLOAT_EQ(s.get_chemistry_grade(), 4.8f);

    s.set_geography_grade(3.7f);
    EXPECT_FLOAT_EQ(s.get_geography_grade(), 3.7f);

    s.set_computer_science_grade(2.6f);
    EXPECT_FLOAT_EQ(s.get_computer_science_grade(), 2.6f);

    s.set_physical_education_grade(5.9f);
    EXPECT_FLOAT_EQ(s.get_physical_education_grade(), 5.9f);
}

TEST(StudentTestSuite, CopyConstructor) {
    Student s1(1, "John", "Doe", "john@email.com", 1000, 5.0f, 4.0f, 3.0f, 2.0f, 1.0f, 5.0f, 4.0f, 3.0f, 2.0f, 1.0f);
    Student s2(s1);

    EXPECT_EQ(s1, s2);
    EXPECT_EQ(s2.get_id(), 1);
    EXPECT_FLOAT_EQ(s2.get_math_grade(), 5.0f);
}

TEST(StudentTestSuite, MoveConstructor) {
    Student s1(1, "John", "Doe", "john@email.com", 1000, 5.0f, 4.0f, 3.0f, 2.0f, 1.0f, 5.0f, 4.0f, 3.0f, 2.0f, 1.0f);
    Student s2(std::move(s1));

    EXPECT_EQ(s2.get_id(), 1);
    EXPECT_FLOAT_EQ(s2.get_math_grade(), 5.0f);
    // s1's strings are moved, but grades (floats) are copied
}

TEST(StudentTestSuite, EqualityOperators) {
    Student s1(1, "John", "Doe", "john@email.com", 1000, 5.0f, 5.0f, 5.0f, 5.0f, 5.0f, 5.0f, 5.0f, 5.0f, 5.0f, 5.0f);
    Student s2(1, "John", "Doe", "john@email.com", 1000, 5.0f, 5.0f, 5.0f, 5.0f, 5.0f, 5.0f, 5.0f, 5.0f, 5.0f, 5.0f);
    Student s3(2, "John", "Doe", "john@email.com", 1000, 5.0f, 5.0f, 5.0f, 5.0f, 5.0f, 5.0f, 5.0f, 5.0f, 5.0f, 5.0f);
    Student s4(1, "John", "Doe", "john@email.com", 1000, 4.0f, 5.0f, 5.0f, 5.0f, 5.0f, 5.0f, 5.0f, 5.0f, 5.0f, 5.0f);

    EXPECT_TRUE(s1 == s2);
    EXPECT_FALSE(s1 == s3);
    EXPECT_FALSE(s1 == s4);
    EXPECT_TRUE(s1 != s3);
}

TEST(StudentTestSuite, AverageGradeThrows) {
    Student s(5.0f, 5.0f, 5.0f, 5.0f, 5.0f, 5.0f, 5.0f, 5.0f, 5.0f, 5.0f);
    EXPECT_THROW(s.get_average_grade(), std::runtime_error);
}

TEST(StudentTestSuite, OutputOperator) {
    Student s(1, "John", "Doe", "john@email.com", 15, 4, 2026,
              5.0f, 4.0f, 3.0f, 2.0f, 1.0f, 5.0f, 4.0f, 3.0f, 2.0f, 1.0f);
    std::stringstream ss;
    ss << s;

    // Should contain Person info and grades
    std::string output = ss.str();
    EXPECT_TRUE(output.find("John") != std::string::npos);
    EXPECT_TRUE(output.find("Doe") != std::string::npos);
    EXPECT_TRUE(output.find("mathGrade: 5") != std::string::npos);
    EXPECT_TRUE(output.find("physicalEducationGrade: 1") != std::string::npos);
}
