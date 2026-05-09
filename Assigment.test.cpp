//
// Created by olidiaks on 4/16/26.
//

#include <gtest/gtest.h>
#include <sstream>
#include "Assignment.h"

// Test constructors
TEST(AssigmentTest, ConstructorWithoutGrade) {
    Assignment a("Test Name", "Test Description", "Test Subject");
    EXPECT_EQ(a.get_name(), "Test Name");
    EXPECT_EQ(a.get_description(), "Test Description");
    EXPECT_EQ(a.get_subject(), "Test Subject");
    EXPECT_GT(a.get_id(), 0);
}

TEST(AssigmentTest, ConstructorWithGrade) {
    Assignment a("Math HW", "Calculus problems", "Math", 5);
    EXPECT_EQ(a.get_name(), "Math HW");
    EXPECT_EQ(a.get_description(), "Calculus problems");
    EXPECT_EQ(a.get_subject(), "Math");
    EXPECT_EQ(a.get_grade(), 5);
    EXPECT_TRUE(a.is_assigment_graded());
}

// Test setters and getters
TEST(AssigmentTest, SettersAndGetters) {
    Assignment a("Name", "Desc", "Subj");
    a.set_name("New Name");
    a.set_description("New Desc");
    a.set_grade(4);

    EXPECT_EQ(a.get_name(), "New Name");
    EXPECT_EQ(a.get_description(), "New Desc");
    EXPECT_EQ(a.get_grade(), 4);
    EXPECT_TRUE(a.is_assigment_graded());

    a.remove_grade();
    EXPECT_EQ(a.get_grade(), 0);
    EXPECT_FALSE(a.is_assigment_graded());
}

// Test copy constructor
TEST(AssigmentTest, CopyConstructor) {
    Assignment a1("Name", "Desc", "Subj");
    Assignment a2(a1);
    
    EXPECT_EQ(a1.get_id(), a2.get_id());
    EXPECT_EQ(a1.get_name(), a2.get_name());
    EXPECT_EQ(a1.get_description(), a2.get_description());
    EXPECT_EQ(a1.get_subject(), a2.get_subject());
    EXPECT_EQ(a1, a2);
}

// Test move constructor
TEST(AssigmentTest, MoveConstructor) {
    Assignment a1("Name", "Desc", "Subj");
    int original_id = a1.get_id();
    Assignment a2(std::move(a1));
    
    EXPECT_EQ(a2.get_id(), original_id);
    EXPECT_EQ(a2.get_name(), "Name");
}

// Test copy assignment operator
TEST(AssigmentTest, CopyAssignment) {
    Assignment a1("Name1", "Desc1", "Subj1");
    Assignment a2("Name2", "Desc2", "Subj2");
    a2 = a1;
    
    EXPECT_EQ(a1.get_id(), a2.get_id());
    EXPECT_EQ(a1.get_name(), a2.get_name());
    EXPECT_EQ(a1, a2);
}

// Test move assignment operator
TEST(AssigmentTest, MoveAssignment) {
    Assignment a1("Name1", "Desc1", "Subj1");
    int original_id = a1.get_id();
    Assignment a2("Name2", "Desc2", "Subj2");
    a2 = std::move(a1);
    
    EXPECT_EQ(a2.get_id(), original_id);
    EXPECT_EQ(a2.get_name(), "Name1");
}

// Test equality and inequality operators
TEST(AssigmentTest, EqualityOperators) {
    Assignment a1("Name", "Desc", "Subj");
    Assignment a2("Name", "Desc", "Subj");
    // These should have different IDs, thus they are not equal
    
    EXPECT_NE(a1, a2);
    EXPECT_TRUE(a1 != a2);
    
    Assignment a3(a1);
    EXPECT_EQ(a1, a3);
    EXPECT_FALSE(a1 != a3);
}

// Test output stream operator
TEST(AssigmentTest, StreamOperator) {
    Assignment a("Name", "Desc", "Subj");
    std::stringstream ss;
    ss << a;
    std::string output = ss.str();
    
    // Check if the output contains key information
    EXPECT_NE(output.find("id:"), std::string::npos);
    EXPECT_NE(output.find("name: Name"), std::string::npos);
    EXPECT_NE(output.find("description: Desc"), std::string::npos);
    EXPECT_NE(output.find("subject: Subj"), std::string::npos);
}

// Test swap function
TEST(AssigmentTest, SwapFunction) {
    Assignment a1("Name1", "Desc1", "Subj1");
    Assignment a2("Name2", "Desc2", "Subj2");
    
    Assignment a1_copy(a1);
    Assignment a2_copy(a2);
    
    swap(a1, a2);
    
    EXPECT_EQ(a1, a2_copy);
    EXPECT_EQ(a2, a1_copy);
}

// Test ID incrementation
TEST(AssigmentTest, IdIncrementation) {
    Assignment a1("a", "b", "c");
    Assignment a2("d", "e", "f");
    EXPECT_EQ(a2.get_id(), a1.get_id() + 1);
}
