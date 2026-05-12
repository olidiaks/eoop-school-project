//
// Created by olidiaks on 4/21/26.
//

#include <gtest/gtest.h>
#include "School.h"
#include "Teacher.h"
#include "Class.h"
#include "Student.h"
#include "Subject.h"

class SchoolTest : public ::testing::Test {
protected:
    School school;
    
    // Helper to create a dummy teacher
    Teacher createTeacher(const std::string& first, const std::string& last, Subject subject) {
        return Teacher(first, last, first + "." + last + "@school.com", 1, 1, 1980, 5000, subject);
    }

    // Helper to create dummy students
    std::vector<Student> createStudents(int count) {
        std::vector<Student> students;
        for (int i = 0; i < count; ++i) {
            students.emplace_back("Student", std::to_string(i), "student" + std::to_string(i) + "@school.com", 1, 1, 2010);
        }
        return students;
    }
};

TEST_F(SchoolTest, DefaultConstructor) {
    EXPECT_EQ(school.get_name(), "");
    EXPECT_TRUE(school.get_classes().empty());
}

TEST_F(SchoolTest, SetAndGetName) {
    school.set_name("High School");
    EXPECT_EQ(school.get_name(), "High School");
}

TEST_F(SchoolTest, HireTeacher) {
    Teacher t1 = createTeacher("John", "Doe", Subject::Math);
    school.hire_teacher(t1);
    
    School expected;
    expected.hire_teacher(t1);
    EXPECT_EQ(school, expected);
}

TEST_F(SchoolTest, HireTeacherDetailed) {
    Teacher jane("Jane", "Smith", "jane.smith@school.com", 15, 5, 1985, 6000, Subject::English);
    school.hire_teacher(jane);
    
    School expected;
    expected.hire_teacher(jane);
    EXPECT_EQ(school, expected);
}

TEST_F(SchoolTest, AddAndRemoveClass) {
    Teacher tSup = createTeacher("Sup", "T", Subject::Math);
    
    auto students = createStudents(5);
    
    school.add_class(tSup, 'A');
    
    ASSERT_EQ(school.get_classes().size(), 1);
    EXPECT_EQ(school.get_classes().front().get_year(), 1);
    EXPECT_EQ(school.get_classes().front().get_letter(), 'A');
    
    school.remove_class(1, 'A');
    EXPECT_TRUE(school.get_classes().empty());
}

TEST_F(SchoolTest, NewSchoolYear) {
    Teacher tSup = createTeacher("Sup", "T", Subject::Math);
    school.add_class(tSup, 'A');
    
    school.new_school_year();
    
    ASSERT_EQ(school.get_classes().size(), 1);
    EXPECT_EQ(school.get_classes().front().get_year(), 2);
}

TEST_F(SchoolTest, CopyConstructor) {
    school.set_name("Original");
    Teacher t = createTeacher("John", "Doe", Subject::Math);
    school.hire_teacher(t);
    
    School copy(school);
    EXPECT_EQ(copy.get_name(), "Original");
    EXPECT_EQ(copy, school);
}

TEST_F(SchoolTest, CopyAssignment) {
    school.set_name("Original");
    School other;
    other = school;
    EXPECT_EQ(other.get_name(), "Original");
    EXPECT_EQ(other, school);
}

TEST_F(SchoolTest, MoveConstructor) {
    school.set_name("Original");
    School other;
    other.set_name("Original");
    School moved(std::move(school));
    EXPECT_EQ(moved.get_name(), "Original");
    EXPECT_EQ(moved, other);
}

TEST_F(SchoolTest, MoveAssignment) {
    school.set_name("Original");
    School other;
    other = std::move(school);
    EXPECT_EQ(other.get_name(), "Original");
}

TEST_F(SchoolTest, EqualityOperators) {
    School s1, s2;
    s1.set_name("School");
    s2.set_name("School");
    EXPECT_TRUE(s1 == s2);
    
    s2.set_name("Other");
    EXPECT_TRUE(s1 != s2);
}

TEST_F(SchoolTest, HireAllSubjects) {
    Subject subjects[] = {
        Subject::Math, Subject::English, Subject::Polish, Subject::History,
        Subject::Biology, Subject::Physics, Subject::Chemistry, Subject::Geography,
        Subject::ComputerScience, Subject::PhysicalEducation
    };
    
    School expected;
    for (auto s : subjects) {
        Teacher t("First", "Last", "email@test.com", 1, 1, 1990, 5000, s);
        school.hire_teacher(t);
        expected.hire_teacher(t);
    }
    
    EXPECT_EQ(school, expected);
}

TEST_F(SchoolTest, AddClassOverloads) {
    Teacher t = createTeacher("T", "T", Subject::Math);
    std::vector<Student> students = createStudents(1);
    
    // Test overload with letter and students
    school.add_class(t, students, 'B');
    EXPECT_EQ(school.get_classes().size(), 1);
    EXPECT_EQ(school.get_classes().back().get_letter(), 'B');
    
    // Test overload with just supervising teacher and letter
    school.add_class(t, 'C');
    EXPECT_EQ(school.get_classes().size(), 2);
    EXPECT_EQ(school.get_classes().back().get_letter(), 'C');
}

TEST_F(SchoolTest, SwapFunction) {
    School s1, s2;
    s1.set_name("School1");
    s2.set_name("School2");
    
    s1.swap(s2);
    
    EXPECT_EQ(s1.get_name(), "School2");
    EXPECT_EQ(s2.get_name(), "School1");
}

TEST_F(SchoolTest, NotImplementedMethods) {
    EXPECT_THROW(school.get_average_students_grades_of_teacher(1), std::runtime_error);
}

TEST_F(SchoolTest, SchoolMetrics) {
    Teacher tSup = createTeacher("Sup", "T", Subject::Math);
    school.hire_teacher(tSup);
    
    Class& c = school.add_class(tSup, 'A');
    c.add_teacher(tSup); // Ensure teacher is in the subject map
    Student s1("S1", "L1", "s1@school.com", 1, 1, 2010);
    s1.add_assignment(Subject::Math, "HW1", "D1", 5);
    c.add_student(s1);
    
    EXPECT_FLOAT_EQ(school.get_average_grade_of_school(), 5.0f);
    EXPECT_FLOAT_EQ(school.get_average_students_grades_of_teacher(tSup.get_id()), 5.0f);
}

TEST_F(SchoolTest, SetClasses) {
    Teacher tSup = createTeacher("Sup", "T", Subject::Math);
    Class c1(1, 'A', tSup);
    std::list<Class> classes = {c1};
    school.set_classes(classes);
    EXPECT_EQ(school.get_classes().size(), 1);
}

TEST_F(SchoolTest, AddClassAdvancedOverloads) {
    Teacher tSup = createTeacher("Sup", "T", Subject::Math);
    std::vector<Teacher> teachers = {tSup};
    std::vector<Student> students = createStudents(2);
    
    school.add_class(teachers, tSup, 1, 'D', students);
    EXPECT_EQ(school.get_classes().size(), 1);
    EXPECT_EQ(school.get_classes().back().get_letter(), 'D');
    
    std::map<Subject, const Teacher&> tMap;
    tMap.emplace(Subject::Math, tSup);
    school.add_class(tSup, tMap, 'E', students);
    EXPECT_EQ(school.get_classes().size(), 2);
    EXPECT_EQ(school.get_classes().back().get_letter(), 'E');
}

TEST_F(SchoolTest, FireTeacher) {
    Teacher t = createTeacher("John", "Doe", Subject::Math);
    School comper, experiment;
    EXPECT_EQ(comper, experiment);
    experiment.hire_teacher(t);
    EXPECT_NE(comper, experiment);
    
    EXPECT_TRUE(experiment.fire_teacher(t.get_id()));
    EXPECT_EQ(comper, experiment);
}

TEST_F(SchoolTest, FireTeacherByName) {
    school.hire_teacher("Jane", "Smith", "jane@school.com", 1, 1, 1980, 5000, Subject::English);
    school.fire_teacher("Jane", "Smith");
    
    School empty;
    EXPECT_EQ(school, empty);
}
