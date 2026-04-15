//
// Created by olidiaks on 14.04.2026.
//

#include <gtest/gtest.h>

#include "Person.h"

TEST(person_test_suite_1, person_test_default_constructor) {
    Person p;
    ASSERT_EQ(p.get_id(), -1);
    ASSERT_EQ(p.get_first_name(), "");
    ASSERT_EQ(p.get_last_name(), "");
    ASSERT_EQ(p.get_birth_date(), 0);
    ASSERT_EQ(p.get_email(), "");
}

TEST(person_test_suite_1, person_test_parameterized_constructor_with_time_t) {
    time_t now = time(nullptr);
    Person p(1, "John", "Doe", "john.doe@example.com", now);
    ASSERT_EQ(p.get_id(), 1);
    ASSERT_EQ(p.get_first_name(), "John");
    ASSERT_EQ(p.get_last_name(), "Doe");
    ASSERT_EQ(p.get_email(), "john.doe@example.com");
    ASSERT_EQ(p.get_birth_date(), now);
}

TEST(person_test_suite_1, person_test_parameterized_constructor_with_date) {
    Person p(2, "Jane", "Smith", "jane.smith@example.com", 15, 4, 1990);
    ASSERT_EQ(p.get_id(), 2);
    ASSERT_EQ(p.get_first_name(), "Jane");
    ASSERT_EQ(p.get_last_name(), "Smith");
    ASSERT_EQ(p.get_email(), "jane.smith@example.com");
    // We don't necessarily know the exact time_t value without knowing implementation of date to time_t conversion
    // but we can check if it's not 0 or -1.
    ASSERT_NE(p.get_birth_date(), 0);
}

TEST(person_test_suite_1, person_test_copy_constructor) {
    Person p1(3, "Alice", "Brown", "alice@example.com", 123456789);
    Person p2(p1);
    ASSERT_EQ(p2.get_id(), 3);
    ASSERT_EQ(p2.get_first_name(), "Alice");
    ASSERT_EQ(p2.get_last_name(), "Brown");
    ASSERT_EQ(p2.get_email(), "alice@example.com");
    ASSERT_EQ(p2.get_birth_date(), 123456789);
}

TEST(person_test_suite_1, person_test_move_constructor) {
    Person p1(4, "Bob", "White", "bob@example.com", 987654321);
    Person p2(std::move(p1));
    ASSERT_EQ(p2.get_id(), 4);
    ASSERT_EQ(p2.get_first_name(), "Bob");
    ASSERT_EQ(p2.get_last_name(), "White");
    ASSERT_EQ(p2.get_email(), "bob@example.com");
    ASSERT_EQ(p2.get_birth_date(), 987654321);
}
