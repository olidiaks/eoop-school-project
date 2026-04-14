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
