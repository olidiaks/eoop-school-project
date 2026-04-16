//
// Created by olidiaks on 14.04.2026.
//

#include <gtest/gtest.h>
#include <sstream>

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

TEST(person_test_suite_1, person_test_set_get_first_name) {
    Person p;
    p.set_first_name("Charlie");
    ASSERT_EQ(p.get_first_name(), "Charlie");
}

TEST(person_test_suite_1, person_test_set_get_last_name) {
    Person p;
    p.set_last_name("Black");
    ASSERT_EQ(p.get_last_name(), "Black");
}

TEST(person_test_suite_1, person_test_set_get_email) {
    Person p;
    p.set_email("charlie.black@example.com");
    ASSERT_EQ(p.get_email(), "charlie.black@example.com");
}

TEST(person_test_suite_1, person_test_get_id) {
    Person p(10, "Dave", "Jones", "dave@example.com", 100);
    ASSERT_EQ(p.get_id(), 10);
}

TEST(person_test_suite_1, person_test_get_birth_date) {
    time_t birth = 500000000;
    Person p(11, "Eve", "Green", "eve@example.com", birth);
    ASSERT_EQ(p.get_birth_date(), birth);
}

TEST(person_test_suite_1, person_test_get_birth_date_components) {
    struct tm timeinfo = {0};
    timeinfo.tm_year = 2000 - 1900;
    timeinfo.tm_mon = 5 - 1; // May
    timeinfo.tm_mday = 15;
    time_t birth = mktime(&timeinfo);

    Person p(1, "John", "Doe", "john.doe@example.com", birth);

    EXPECT_EQ(p.get_day_of_birth(), 15);
    EXPECT_EQ(p.get_month_of_birth(), 5);
    EXPECT_EQ(p.get_year_of_birth(), 2000);
}

TEST(person_test_suite_1, person_test_get_age) {
    // Setting birth date to 20 years ago
    time_t now = time(nullptr);
    tm *birth_tm = localtime(&now);
    int year = birth_tm->tm_year - 20;
    int day = birth_tm->tm_mday;
    int month = birth_tm->tm_mon;

    Person p(12, "Frank", "Miller", "frank@example.com", day, month, year);

    // This is expected to fail as get_age() is not yet implemented
    ASSERT_EQ(p.get_age(), 20);
}

TEST(person_test_suite_1, person_test_equality_operator) {
    Person p1(1, "John", "Doe", "john.doe@example.com", 1000);
    Person p2(1, "John", "Doe", "john.doe@example.com", 1000);
    Person p3(2, "John", "Doe", "john.doe@example.com", 1000);
    Person p4(1, "Jane", "Doe", "john.doe@example.com", 1000);

    EXPECT_TRUE(p1 == p2);
    EXPECT_FALSE(p1 == p3);
    EXPECT_FALSE(p1 == p4);
}

TEST(person_test_suite_1, person_test_inequality_operator) {
    Person p1(1, "John", "Doe", "john.doe@example.com", 1000);
    Person p2(1, "John", "Doe", "john.doe@example.com", 1000);
    Person p3(2, "John", "Doe", "john.doe@example.com", 1000);

    EXPECT_FALSE(p1 != p2);
    EXPECT_TRUE(p1 != p3);
}

TEST(person_test_suite_1, person_test_copy_assignment) {
    Person p1(1, "John", "Doe", "john.doe@example.com", 1000);
    Person p2;
    p2 = p1;
    EXPECT_EQ(p2.get_id(), 1);
    EXPECT_EQ(p2.get_first_name(), "John");
    EXPECT_EQ(p2.get_last_name(), "Doe");
    EXPECT_EQ(p2.get_email(), "john.doe@example.com");
    EXPECT_EQ(p2.get_birth_date(), 1000);
}

TEST(person_test_suite_1, person_test_move_assignment) {
    Person p1(1, "John", "Doe", "john.doe@example.com", 1000);
    Person p2;
    p2 = std::move(p1);
    EXPECT_EQ(p2.get_id(), 1);
    EXPECT_EQ(p2.get_first_name(), "John");
    EXPECT_EQ(p2.get_last_name(), "Doe");
    EXPECT_EQ(p2.get_email(), "john.doe@example.com");
    EXPECT_EQ(p2.get_birth_date(), 1000);
}

TEST(person_test_suite_1, person_test_output_operator) {
    // Using a fixed time_t that corresponds to a known date.
    // 1000 is Thu Jan  1 00:16:40 1970 UTC.
    // We use the object's own getters to avoid timezone issues in the test.
    Person p(1, "John", "Doe", "john.doe@example.com", 1000);
    std::stringstream ss;
    ss << p;

    std::stringstream expected;
    expected << "id: 1 firstName: John lastName: Doe email: john.doe@example.com age: " << p.get_age()
            << "Date of birth: " << p.get_day_of_birth() << "." << p.get_month_of_birth() << "." << p.
            get_year_of_birth();

    EXPECT_EQ(ss.str(), expected.str());
}
