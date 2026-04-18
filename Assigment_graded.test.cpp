//
// Created by olidiaks on 4/18/26.
//

#include <gtest/gtest.h>
#include <sstream>
#include "Assigment_graded.h"

class AssigmentGradedTest : public ::testing::Test {
protected:
    Assigment common_assigment{"Test Name", "Test Description", "Test Subject"};
};

// Test constructors
TEST_F(AssigmentGradedTest, ConstructorWithoutGrade) {
    Assigment_graded ag(common_assigment);
    EXPECT_EQ(ag.get_grade(), 0);
    EXPECT_GT(ag.get_id(), 0);
    EXPECT_EQ(ag.get_assigment(), common_assigment);
}

TEST_F(AssigmentGradedTest, ConstructorWithGrade) {
    Assigment_graded ag(common_assigment, 5);
    EXPECT_EQ(ag.get_grade(), 5);
    EXPECT_GT(ag.get_id(), 0);
    EXPECT_EQ(ag.get_assigment(), common_assigment);
}

// Test copy constructor
TEST_F(AssigmentGradedTest, CopyConstructor) {
    Assigment_graded ag1(common_assigment, 4);
    Assigment_graded ag2(ag1);

    EXPECT_EQ(ag1.get_id(), ag2.get_id());
    EXPECT_EQ(ag1.get_grade(), ag2.get_grade());
    EXPECT_EQ(ag1.get_assigment(), ag2.get_assigment());
    EXPECT_EQ(ag1, ag2);
}

// Test move constructor
TEST_F(AssigmentGradedTest, MoveConstructor) {
    Assigment_graded ag1(common_assigment, 3);
    int original_id = ag1.get_id();
    Assigment_graded ag2(std::move(ag1));

    EXPECT_EQ(ag2.get_id(), original_id);
    EXPECT_EQ(ag2.get_grade(), 3);
    EXPECT_EQ(ag2.get_assigment(), common_assigment);
}

// Test assignment operator
TEST_F(AssigmentGradedTest, AssignmentOperator) {
    Assigment_graded ag1(common_assigment, 5);
    Assigment other_assigment{"Other", "Desc", "Subj"};
    Assigment_graded ag2(other_assigment, 2);

    ag2 = ag1;

    EXPECT_EQ(ag2.get_id(), ag1.get_id());
    EXPECT_EQ(ag2.get_grade(), ag1.get_grade());
    EXPECT_EQ(ag2.get_assigment(), ag1.get_assigment());
    EXPECT_EQ(ag2, ag1);
}

// Test setters and getters
TEST_F(AssigmentGradedTest, SettersAndGetters) {
    Assigment_graded ag(common_assigment);
    ag.set_grade(4);
    EXPECT_EQ(ag.get_grade(), 4);
}

// Test equality and inequality operators
TEST_F(AssigmentGradedTest, EqualityOperators) {
    Assigment_graded ag1(common_assigment, 5);
    Assigment_graded ag2(common_assigment, 5);
    // Different IDs, so they should not be equal

    EXPECT_NE(ag1, ag2);
    EXPECT_TRUE(ag1 != ag2);

    Assigment_graded ag3(ag1);
    EXPECT_EQ(ag1, ag3);
    EXPECT_FALSE(ag1 != ag3);
}

// Test stream insertion operator
TEST_F(AssigmentGradedTest, StreamOperator) {
    Assigment_graded ag(common_assigment, 5);
    std::stringstream ss;
    ss << ag;
    std::string output = ss.str();

    EXPECT_NE(output.find("id:"), std::string::npos);
    EXPECT_NE(output.find("grade: 5"), std::string::npos);
    EXPECT_NE(output.find("is_graded: 1"), std::string::npos);
    EXPECT_NE(output.find("assigment:"), std::string::npos);
}

// Test ID incrementation
TEST_F(AssigmentGradedTest, IdIncrementation) {
    Assigment_graded ag1(common_assigment);
    Assigment_graded ag2(common_assigment);
    EXPECT_EQ(ag2.get_id(), ag1.get_id() + 1);
}
