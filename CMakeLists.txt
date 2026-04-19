cmake_minimum_required(VERSION 4.1)
project(Project)

set(CMAKE_CXX_STANDARD 26)

include(FetchContent)
FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG main
)
FetchContent_MakeAvailable(googletest)


add_executable(Project main.cpp
        Student.cpp
        Student.h
        Teacher.cpp
        Teacher.h
        School.cpp
        School.h
        Person.cpp
        Person.h
        Assigment.cpp
        Assigment.h
        Class.cpp
        Class.h
        Assigment_graded.cpp
        Assigment_graded.h
)

add_executable(test-person Person.test.cpp Person.cpp Person.h)
target_link_libraries(test-person PUBLIC gtest_main)
add_executable(Assigment-test Assigment.test.cpp Assigment.cpp Assigment.h)
target_link_libraries(Assigment-test PUBLIC gtest_main)
add_executable(Subject-test Subject.cpp Subject.h
        Subject.test.cpp)
target_link_libraries(Subject-test PUBLIC gtest_main)
add_executable(Teacher-test Teacher.test.cpp Teacher.cpp Teacher.h Person.cpp Person.h)
target_link_libraries(Teacher-test PUBLIC gtest_main)
add_executable(Assigment-graded-test Assigment_graded.test.cpp Assigment_graded.cpp Assigment_graded.h Assigment.cpp Assigment.h)
target_link_libraries(Assigment-graded-test PUBLIC gtest_main)
add_executable(Student-test Student.test.cpp Student.cpp Student.h Person.cpp Person.h Assigment_graded.cpp Assigment_graded.h Assigment.cpp Assigment.h)
target_link_libraries(Student-test PUBLIC gtest_main)
