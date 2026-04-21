//
// Created by olidiaks on 4/18/26.
//

#ifndef EOOP_SCHOOL_PROJECT_ASSIGEMNT_GRADED_H
#define EOOP_SCHOOL_PROJECT_ASSIGEMNT_GRADED_H
#include <ostream>

#include "Assigment.h"


/**
 * @class Assignment_graded
 * @brief Represents a graded assignment with associated properties and functionality.
 *
 * This class manages information related to an assignment that has been graded,
 * including details about the assignment, the grade achieved, and any associated metadata.
 * It can be extended or used in educational or grading systems where tracking graded
 * assignments is required.
 *
 * The class provides methods to interact with and modify the graded assignment's information,
 * supporting features related to grading, feedback, and statistical analysis if implemented.
 *
 * @note Ensure proper validation is done when modifying assignment grades.
 */
class Assigment_graded {
private:
    static int counter;
    int id;
    Assigment assigment;
    int grade;
    bool is_graded;

    /**
     * @brief Constructs an Assignment_graded object from the provided assignment.
     *
     * This constructor initializes a graded assignment object by associating it with an
     * existing assignment. It ensures that the graded assignment is tied to the relevant
     * assignment details for further use and analysis in grading systems.
     *
     * @param assignment The assignment object to be used for initializing the graded assignment.
     */
public:
    Assigment_graded(const Assigment &assigment);

    /**
     * @brief Constructs an Assignment_graded object with the provided assignment and grade.
     *
     * This constructor initializes a graded assignment by associating it with a specific
     * assignment and the grade achieved. It is used to represent and store information
     * about the grading of a particular assignment.
     *
     * @param assignment The assignment associated with the grade.
     * @param grade The grade achieved for the assignment.
     */
    Assigment_graded(const Assigment &assigment, const int grade);

    /**
     * @brief Copy constructor for the Assignment_graded class.
     *
     * This constructor creates a new instance of the Assignment_graded class by copying
     * the data from an existing Assignment_graded object. It duplicates the state of the
     * provided object, ensuring all assignment properties, grading details, and metadata
     * are replicated.
     *
     * @param other The Assignment_graded object to copy from.
     *
     * @note Use caution when copying objects, ensuring there are no unintended
     * side effects or duplicate resource allocations.
     */
    Assigment_graded(const Assigment_graded &other);

    /**
     * @brief Move constructor for the Assignment_graded class.
     *
     * This constructor initializes a new Assignment_graded object by transferring ownership
     * of resources from another Assignment_graded object. It ensures efficient resource
     * management by avoiding unnecessary copying of data and transferring the state of the
     * source object instead.
     *
     * @param other The Assignment_graded object to move from. After the operation, the state
     * of the source object is valid but unspecified.
     *
     * @note No exceptions are thrown by this constructor.
     */
    Assigment_graded(Assigment_graded &&other) noexcept;

    /**
     * @brief Assignment operator for the Assignment_graded class.
     *
     * This operator assigns the contents of one Assignment_graded object to another,
     * performing a deep copy of all assignment details, grade information, and related
     * metadata. It ensures that the target object fully replicates the state of the
     * source object without sharing resources.
     *
     * @param other The Assignment_graded object to copy data from.
     * @return A reference to the current Assignment_graded object after assignment.
     *
     * @note Ensure no self-assignment occurs, and manage any allocated resources
     * appropriately to avoid memory leaks or undefined behavior.
     */
    Assigment_graded & operator=(const Assigment_graded &other);

    /**
     * @brief Move assignment operator for the Assignment_graded class.
     *
     * This operator transfers ownership of resources and state from one Assignment_graded
     * object to another, ensuring efficient reassignment without unnecessary copying.
     * After the operation, the source object is in a valid but unspecified state.
     *
     * @param other The Assignment_graded object to move from. Ownership of its data will be
     * transferred to the current object.
     * @return A reference to the current Assignment_graded object after the move operation.
     *
     * @note No exceptions are thrown by this operator. Ensure proper handling of the object's
     * state after the move to avoid any potential side effects.
     */
    Assigment_graded & operator=(Assigment_graded &&other) noexcept;

    /**
     * @brief Retrieves the grade associated with the assignment.
     *
     * This method provides access to the numerical grade of the graded assignment.
     * It ensures the grade value is returned in a consistent manner without modifying
     * the state of the object. The method is marked as `[[nodiscard]]` to indicate that
     * the returned grade should not be discarded.
     *
     * @return The integer grade associated with the assignment.
     */
    [[nodiscard]] int get_grade() const;

    /**
     * @brief Sets the grade for the assignment.
     *
     * This method updates the grade associated with the assignment. It ensures
     * the assignment is assigned a specific grade value, which can later be used
     * for evaluation or further processing.
     *
     * @param grade The grade to be assigned to the assignment. It should be a valid
     *              integer that aligns with the grading criteria.
     */
    void set_grade(const int grade);

    /**
     * @brief Retrieves the associated assignment.
     *
     * This method returns the assignment object linked to the current instance.
     * It provides access to the assignment details, which may include relevant
     * information about the task.
     *
     * @return An instance of the Assigment class representing the associated assignment.
     *         The returned object is marked as [[nodiscard]] to indicate that the caller
     *         should not discard the result.
     */
    [[nodiscard]] Assigment get_assigment() const;

    /**
     * @brief Retrieves the unique identifier of the instance.
     *
     * This method returns the unique ID associated with the object,
     * enabling identification or lookup in scenarios where objects
     * are uniquely tracked.
     *
     * @return The unique identifier of the object.
     */
    [[nodiscard]] int get_id() const;

    /**
     * @brief Compares two Assignment_graded objects for equality.
     *
     * This operator checks if two Assignment_graded instances are equal by comparing
     * their respective properties. The exact criteria for equality depend on the
     * implementation of the class's members and their comparison logic.
     *
     * @param lhs The left-hand side Assignment_graded object in the comparison.
     * @param rhs The right-hand side Assignment_graded object in the comparison.
     * @return true if both Assignment_graded objects are considered equal; otherwise, false.
     */
    friend bool operator==(const Assigment_graded &lhs, const Assigment_graded &rhs);

    /**
     * @brief Compares two Assignment_graded objects for inequality.
     *
     * This operator checks whether two Assignment_graded instances are not equal
     * based on their respective properties and values. It is used to determine if
     * there are differences between the two provided objects.
     *
     * @param lhs The first Assignment_graded object to compare.
     * @param rhs The second Assignment_graded object to compare.
     * @return True if the objects are not equal, false otherwise.
     */
    friend bool operator!=(const Assigment_graded &lhs, const Assigment_graded &rhs);

    /**
     * @class Operator
     * @brief Represents a mathematical or logical operator with specific functionality.
     *
     * This class defines and manages the behavior associated with an operator,
     * enabling its utilization in various computational or logical operations.
     * It facilitates the execution of operations and provides the necessary
     * functionality for operator-based calculations or evaluations.
     *
     * Use this class in scenarios where abstraction and management of operators
     * are required, such as parsing expressions or performing dynamic operations.
     *
     * @note Ensure that the operator's functionality aligns with the intended context of use.
     */
    friend std::ostream & operator<<(std::ostream &os, const Assigment_graded &obj);
};



#endif //EOOP_SCHOOL_PROJECT_ASSIGEMNT_GRADED_H
