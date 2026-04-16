//
// Created by olidiaks on 4/16/26.
//

#include <gtest/gtest.h>
#include <sstream>
#include "Assigment.h"

TEST(AssigmentTestSuite, ParameterizedConstructorAndGetters) {
    Assigment a(1, "Math Homework", "Solve 10 problems", 95);
    EXPECT_EQ(a.get_id(), 1);
    EXPECT_EQ(a.get_name(), "Math Homework");
    EXPECT_EQ(a.get_description(), "Solve 10 problems");
    EXPECT_EQ(a.get_grade(), 95);
}

TEST(AssigmentTestSuite, CopyConstructor) {
    Assigment a1(1, "Math Homework", "Solve 10 problems", 95);
    Assigment a2(a1);
    EXPECT_EQ(a2.get_id(), 1);
    EXPECT_EQ(a2.get_name(), "Math Homework");
    EXPECT_EQ(a2.get_description(), "Solve 10 problems");
    EXPECT_EQ(a2.get_grade(), 95);
    EXPECT_EQ(a1, a2);
}

TEST(AssigmentTestSuite, MoveConstructor) {
    Assigment a1(1, "Math Homework", "Solve 10 problems", 95);
    Assigment a2(std::move(a1));
    EXPECT_EQ(a2.get_id(), 1);
    EXPECT_EQ(a2.get_name(), "Math Homework");
    EXPECT_EQ(a2.get_description(), "Solve 10 problems");
    EXPECT_EQ(a2.get_grade(), 95);

    // a1 is in a moved-from state, its strings are likely empty
    EXPECT_EQ(a1.get_id(), 1);
    EXPECT_EQ(a1.get_name(), "");
    EXPECT_EQ(a1.get_description(), "");
}

TEST(AssigmentTestSuite, CopyAssignment) {
    Assigment a1(1, "Math Homework", "Solve 10 problems", 95);
    Assigment a2(2, "History Essay", "Write 5 pages", 80);
    a2 = a1;
    EXPECT_EQ(a2.get_id(), 1);
    EXPECT_EQ(a2.get_name(), "Math Homework");
    EXPECT_EQ(a2.get_description(), "Solve 10 problems");
    EXPECT_EQ(a2.get_grade(), 95);
    EXPECT_EQ(a1, a2);
}

TEST(AssigmentTestSuite, MoveAssignment) {
    Assigment a1(1, "Math Homework", "Solve 10 problems", 95);
    Assigment a2(2, "History Essay", "Write 5 pages", 80);
    a2 = std::move(a1);
    EXPECT_EQ(a2.get_id(), 1);
    EXPECT_EQ(a2.get_name(), "Math Homework");
    EXPECT_EQ(a2.get_description(), "Solve 10 problems");
    EXPECT_EQ(a2.get_grade(), 95);
}

TEST(AssigmentTestSuite, EqualityOperators) {
    Assigment a1(1, "Math Homework", "Solve 10 problems", 95);
    Assigment a2(1, "Math Homework", "Solve 10 problems", 95);
    Assigment a3(2, "Math Homework", "Solve 10 problems", 95);
    Assigment a4(1, "Science Lab", "Solve 10 problems", 95);
    Assigment a5(1, "Math Homework", "Write a report", 95);
    Assigment a6(1, "Math Homework", "Solve 10 problems", 100);

    EXPECT_TRUE(a1 == a2);
    EXPECT_FALSE(a1 == a3);
    EXPECT_FALSE(a1 == a4);
    EXPECT_FALSE(a1 == a5);
    EXPECT_FALSE(a1 == a6);

    EXPECT_FALSE(a1 != a2);
    EXPECT_TRUE(a1 != a3);
}

TEST(AssigmentTestSuite, Setters) {
    Assigment a(1, "Initial Name", "Initial Description", 0);

    a.set_name("New Name");
    EXPECT_EQ(a.get_name(), "New Name");

    a.set_description("New Description");
    EXPECT_EQ(a.get_description(), "New Description");

    a.set_grade(100);
    EXPECT_EQ(a.get_grade(), 100);
}

TEST(AssigmentTestSuite, OutputOperator) {
    Assigment a(1, "Math", "Homework", 90);
    std::stringstream ss;
    ss << a;
    std::string expected = "id: 1 name: Math description: Homework grade: 90";
    EXPECT_EQ(ss.str(), expected);
}

TEST(AssigmentTestSuite, SwapFunction) {
    Assigment a1(1, "Math", "Homework", 90);
    Assigment a2(2, "History", "Essay", 80);

    swap(a1, a2);

    EXPECT_EQ(a1.get_id(), 2);
    EXPECT_EQ(a1.get_name(), "History");
    EXPECT_EQ(a2.get_id(), 1);
    EXPECT_EQ(a2.get_name(), "Math");
}
