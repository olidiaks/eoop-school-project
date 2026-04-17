//
// Created by Gemini CLI on 17.04.2026.
//

#include <gtest/gtest.h>
#include <sstream>
#include "Teacher.h"

TEST(teacher_test_suite, teacher_test_default_constructor) {
    Teacher t;
    EXPECT_EQ(t.get_id(), -1);
    EXPECT_EQ(t.get_first_name(), "");
    EXPECT_EQ(t.get_last_name(), "");
    EXPECT_EQ(t.get_email(), "");
    EXPECT_EQ(t.get_salary(), 0);
    EXPECT_EQ(t.get_subject(), "");
}

TEST(teacher_test_suite, teacher_test_parameterized_constructor_with_time_t) {
    time_t now = time(nullptr);
    Teacher t("John", "Smith", "john.smith@school.com", now, 5000, "Math");
    EXPECT_EQ(t.get_first_name(), "John");
    EXPECT_EQ(t.get_last_name(), "Smith");
    EXPECT_EQ(t.get_email(), "john.smith@school.com");
    EXPECT_EQ(t.get_birth_date(), now);
    EXPECT_EQ(t.get_salary(), 5000);
    EXPECT_EQ(t.get_subject(), "Math");
}

TEST(teacher_test_suite, teacher_test_parameterized_constructor_with_date) {
    Teacher t("Jane", "Doe", "jane.doe@school.com", 1, 1, 1980, 6000, "Physics");
    EXPECT_EQ(t.get_first_name(), "Jane");
    EXPECT_EQ(t.get_last_name(), "Doe");
    EXPECT_EQ(t.get_email(), "jane.doe@school.com");
    EXPECT_EQ(t.get_year_of_birth(), 1980);
    EXPECT_EQ(t.get_month_of_birth(), 1);
    EXPECT_EQ(t.get_day_of_birth(), 1);
    EXPECT_EQ(t.get_salary(), 6000);
    EXPECT_EQ(t.get_subject(), "Physics");
}

TEST(teacher_test_suite, teacher_test_set_salary) {
    Teacher t;
    t.set_salary(7000);
    EXPECT_EQ(t.get_salary(), 7000);
}

TEST(teacher_test_suite, teacher_test_copy_constructor) {
    Teacher t1("Alice", "Brown", "alice@school.com", 123456789, 5500, "Biology");
    Teacher t2(t1);
    EXPECT_EQ(t2.get_first_name(), "Alice");
    EXPECT_EQ(t2.get_salary(), 5500);
    EXPECT_EQ(t2.get_subject(), "Biology");
    EXPECT_EQ(t2, t1);
}

TEST(teacher_test_suite, teacher_test_move_constructor) {
    Teacher t1("Bob", "White", "bob@school.com", 987654321, 4500, "History");
    Teacher t2(std::move(t1));
    EXPECT_EQ(t2.get_first_name(), "Bob");
    EXPECT_EQ(t2.get_salary(), 4500);
    EXPECT_EQ(t2.get_subject(), "History");
}

TEST(teacher_test_suite, teacher_test_copy_assignment) {
    Teacher t1("Charlie", "Black", "charlie@school.com", 1000, 4000, "Art");
    Teacher t2;
    t2 = t1;
    EXPECT_EQ(t2.get_first_name(), "Charlie");
    EXPECT_EQ(t2.get_salary(), 4000);
    EXPECT_EQ(t2.get_subject(), "Art");
    EXPECT_EQ(t2, t1);
}

TEST(teacher_test_suite, teacher_test_move_assignment) {
    Teacher t1("David", "Green", "david@school.com", 2000, 4200, "Music");
    Teacher t2;
    t2 = std::move(t1);
    EXPECT_EQ(t2.get_first_name(), "David");
    EXPECT_EQ(t2.get_salary(), 4200);
    EXPECT_EQ(t2.get_subject(), "Music");
}

TEST(teacher_test_suite, teacher_test_equality_operator) {
    Teacher t1("John", "Smith", "john@school.com", 1000, 5000, "Math");
    Teacher t2("John", "Smith", "john@school.com", 1000, 5000, "Math");
    Teacher t3("Jane", "Smith", "jane@school.com", 1000, 5000, "Math");

    EXPECT_TRUE(t1 == t2);
    EXPECT_FALSE(t1 == t3);
}

TEST(teacher_test_suite, teacher_test_inequality_operator) {
    Teacher t1("John", "Smith", "john@school.com", 1000, 5000, "Math");
    Teacher t2("Jane", "Smith", "jane@school.com", 1000, 5000, "Math");

    EXPECT_TRUE(t1 != t2);
    EXPECT_FALSE(t1 != t1);
}

TEST(teacher_test_suite, teacher_test_output_operator) {
    Teacher t("John", "Doe", "john@school.com", 15, 4, 1990, 5000, "Math");
    std::stringstream ss;
    ss << t;

    std::stringstream expected;
    expected << static_cast<const Person &>(t)
             << " salary: " << t.get_salary()
             << " subject: " << t.get_subject();

    EXPECT_EQ(ss.str(), expected.str());
}
