//
// Created by olidiaks on 4/16/26.
//

#include <gtest/gtest.h>
#include <sstream>
#include "Assigment.h"

// Test constructors
TEST(AssigmentTest, ConstructorWithoutGrade) {
    Assigment a("Test Name", "Test Description", "Test Subject");
    EXPECT_EQ(a.get_name(), "Test Name");
    EXPECT_EQ(a.get_description(), "Test Description");
    EXPECT_EQ(a.get_subject(), "Test Subject");
    EXPECT_EQ(a.get_grade(), 0);
    EXPECT_GT(a.get_id(), 0);
}

TEST(AssigmentTest, ConstructorWithGrade) {
    Assigment a("Math HW", "Calculus problems", "Math", 5);
    EXPECT_EQ(a.get_name(), "Math HW");
    EXPECT_EQ(a.get_description(), "Calculus problems");
    EXPECT_EQ(a.get_subject(), "Math");
    EXPECT_EQ(a.get_grade(), 5);
}

// Test setters and getters
TEST(AssigmentTest, SettersAndGetters) {
    Assigment a("Name", "Desc", "Subj");
    a.set_name("New Name");
    a.set_description("New Desc");
    a.set_grade(4);
    
    EXPECT_EQ(a.get_name(), "New Name");
    EXPECT_EQ(a.get_description(), "New Desc");
    EXPECT_EQ(a.get_grade(), 4);
}

// Test copy constructor
TEST(AssigmentTest, CopyConstructor) {
    Assigment a1("Name", "Desc", "Subj", 3);
    Assigment a2(a1);
    
    EXPECT_EQ(a1.get_id(), a2.get_id());
    EXPECT_EQ(a1.get_name(), a2.get_name());
    EXPECT_EQ(a1.get_description(), a2.get_description());
    EXPECT_EQ(a1.get_subject(), a2.get_subject());
    EXPECT_EQ(a1.get_grade(), a2.get_grade());
    EXPECT_EQ(a1, a2);
}

// Test move constructor
TEST(AssigmentTest, MoveConstructor) {
    Assigment a1("Name", "Desc", "Subj", 3);
    int original_id = a1.get_id();
    Assigment a2(std::move(a1));
    
    EXPECT_EQ(a2.get_id(), original_id);
    EXPECT_EQ(a2.get_name(), "Name");
    EXPECT_EQ(a2.get_grade(), 3);
}

// Test copy assignment operator
TEST(AssigmentTest, CopyAssignment) {
    Assigment a1("Name1", "Desc1", "Subj1", 1);
    Assigment a2("Name2", "Desc2", "Subj2", 2);
    a2 = a1;
    
    EXPECT_EQ(a1.get_id(), a2.get_id());
    EXPECT_EQ(a1.get_name(), a2.get_name());
    EXPECT_EQ(a1.get_grade(), a2.get_grade());
    EXPECT_EQ(a1, a2);
}

// Test move assignment operator
TEST(AssigmentTest, MoveAssignment) {
    Assigment a1("Name1", "Desc1", "Subj1", 1);
    int original_id = a1.get_id();
    Assigment a2("Name2", "Desc2", "Subj2", 2);
    a2 = std::move(a1);
    
    EXPECT_EQ(a2.get_id(), original_id);
    EXPECT_EQ(a2.get_name(), "Name1");
}

// Test equality and inequality operators
TEST(AssigmentTest, EqualityOperators) {
    Assigment a1("Name", "Desc", "Subj", 5);
    Assigment a2("Name", "Desc", "Subj", 5);
    // These should have different IDs, thus they are not equal
    
    EXPECT_NE(a1, a2);
    EXPECT_TRUE(a1 != a2);
    
    Assigment a3(a1);
    EXPECT_EQ(a1, a3);
    EXPECT_FALSE(a1 != a3);
}

// Test output stream operator
TEST(AssigmentTest, StreamOperator) {
    Assigment a("Name", "Desc", "Subj", 4);
    std::stringstream ss;
    ss << a;
    std::string output = ss.str();
    
    // Check if the output contains key information
    EXPECT_NE(output.find("id:"), std::string::npos);
    EXPECT_NE(output.find("name: Name"), std::string::npos);
    EXPECT_NE(output.find("description: Desc"), std::string::npos);
    EXPECT_NE(output.find("subject: Subj"), std::string::npos);
    EXPECT_NE(output.find("grade: 4"), std::string::npos);
}

// Test swap function
TEST(AssigmentTest, SwapFunction) {
    Assigment a1("Name1", "Desc1", "Subj1", 1);
    Assigment a2("Name2", "Desc2", "Subj2", 2);
    
    Assigment a1_copy(a1);
    Assigment a2_copy(a2);
    
    swap(a1, a2);
    
    EXPECT_EQ(a1, a2_copy);
    EXPECT_EQ(a2, a1_copy);
}

// Test ID incrementation
TEST(AssigmentTest, IdIncrementation) {
    Assigment a1("a", "b", "c");
    Assigment a2("d", "e", "f");
    EXPECT_EQ(a2.get_id(), a1.get_id() + 1);
}
