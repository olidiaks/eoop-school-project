//
// Created by olidiaks on 4/16/26.
//

#ifndef PROJECT_ASSIGMENT_H
#define PROJECT_ASSIGMENT_H
#include <ostream>
#include <string>


/**
 * @class Assignment
 * @brief Represents a task or work assigned to a person or group, typically for evaluation or completion purposes.
 *
 * The Assignment class is designed to encapsulate the details related to an assignment,
 * such as its attributes, behavior, and potential operations that can be performed
 * on it. This class serves as a model or blueprint for assignments in various contexts,
 * such as educational institutions, work environments, or projects.
 *
 * Responsibilities of this class may include managing the assignment's state,
 * facilitating interactions with its data, and providing utility methods relevant
 * to assignments.
 */
class Assigment {
private:
    int id;
    std::string name;
    std::string description;
    std::string subject;
    static int counter;

    /**
     * @brief Constructs a new Assigment object with the provided name, description, and subject.
     *
     * The constructor initializes a new instance of the Assigment class using the given parameters.
     * Each new instance is assigned a unique ID, which is generated using a static counter.
     *
     * @param name The name of the assignment.
     * @param description A detailed description of the assignment.
     * @param subject The subject associated with the assignment.
     * @return A new instance of the Assigment class.
     */
public:
    Assigment(const std::string &name, const std::string &description, const std::string &subject);

    /**
     * @brief Copy constructor for the Assigment class.
     *
     * Creates a new instance of the Assigment class by copying the attributes
     * from another existing Assigment object. This constructor ensures that all
     * attributes of the source object, such as its ID, name, description, and subject,
     * are copied into the new instance.
     *
     * @param other The Assigment object to copy from.
     * @return A new Assigment instance with the same attribute values as the provided object.
     */
    Assigment(const Assigment &other);

    /**
     * @class Assignment
     * @brief Encapsulates the details and operations related to a specific task or duty assigned to individuals or groups.
     *
     * The Assignment class serves as a representation of tasks or responsibilities that need
     * to be completed, typically within a defined context such as academic, professional,
     * or collaborative environments. It provides a structure to manage and manipulate
     * assignment-specific data and behavior.
     *
     * This class is designed to support features that allow for tracking, evaluating, and managing
     * the lifecycle of an assignment, from creation to completion.
     */
    Assigment(Assigment &&other) noexcept;

    /**
     * @brief Copy assignment operator for the Assigment class.
     *
     * Assigns the contents of another Assigment object to this object,
     * replacing the existing values with those from the provided object.
     * All attributes, such as ID, name, description, and subject, are copied
     * to ensure the two objects have identical data content.
     *
     * This operator handles self-assignment checks and ensures the integrity
     * of the object's state during the assignment operation.
     *
     * @param other The Assigment object to copy from.
     * @return A reference to this Assigment object, with updated attribute values.
     */
    Assigment & operator=(const Assigment &other);

    /**
     * @brief Move assignment operator for the Assigment class.
     *
     * Transfers the contents of another Assigment object to this object
     * using move semantics. This operator ensures efficient ownership
     * transfer of resources, such as dynamically allocated memory, by
     * "stealing" the data from the provided object and leaving it in a
     * valid but unspecified state.
     *
     * This operator checks for self-assignment and ensures that all attributes
     * of the source object, such as its ID, name, description, and subject,
     * are moved to the current object. After the assignment, the source
     * object is valid but no longer contains meaningful data.
     *
     * @param other The Assigment object to move from.
     * @return A reference to this Assigment object, with updated attribute values.
     */
    Assigment & operator=(Assigment &&other) noexcept;

    /**
     * @brief Retrieves the unique identifier of the assignment.
     *
     * This method returns the ID associated with the current instance
     * of the Assigment class. The ID is typically assigned during the
     * object's construction and remains immutable, serving as a unique
     * identifier for the assignment.
     *
     * @return The unique ID of the assignment.
     */
    [[nodiscard]] int get_id() const;

    /**
     * @brief Retrieves the subject associated with the assignment.
     *
     * This method provides access to the subject that the assignment
     * pertains to. The subject is typically defined when the assignment
     * is created and reflects its categorical or thematic context.
     *
     * @return The subject of the assignment as a string.
     */
    [[nodiscard]] std::string get_subject() const;

    /**
     * @brief Retrieves the name of the assignment.
     *
     * This method returns the name associated with the assignment instance.
     * The returned value is typically used to identify or reference the assignment.
     *
     * @return The name of the assignment as a string.
     */
    [[nodiscard]] std::string get_name() const;

    /**
     * @brief Sets the name of the assignment.
     *
     * This method updates the name attribute of the assignment instance
     * to the specified value.
     *
     * @param name The new name to be set for the assignment.
     */
    void set_name(const std::string &name);

    /**
     * @brief Retrieves the description of the assignment.
     *
     * This method provides access to the textual representation of the
     * assignment's description, offering details or context about the
     * specific assignment instance.
     *
     * @return A string containing the description of the assignment.
     */
    [[nodiscard]] std::string get_description() const;

    /**
     * @brief Sets the description of the assignment.
     *
     * This method allows updating the description associated with the assignment,
     * providing the ability to modify or set details about what the assignment entails.
     *
     * @param description The new description to associate with the assignment.
     */
    void set_description(const std::string &description);

    /**
     * @brief Compares two Assignment objects for equality.
     *
     * Determines whether two Assignment instances are considered equal by
     * comparing their properties such as ID, name, description, and subject.
     *
     * @param lhs The first Assignment object to compare.
     * @param rhs The second Assignment object to compare.
     * @return True if both Assignment objects are equal; otherwise, false.
     */
    friend bool operator==(const Assigment &lhs, const Assigment &rhs);

    /**
     * @brief Compares two Assignment objects for inequality.
     *
     * This operator checks if the two provided Assignment objects are not equal
     * by internally using the equality operator.
     *
     * @param lhs The left-hand side Assignment object to compare.
     * @param rhs The right-hand side Assignment object to compare.
     * @return True if the two Assignment objects are not equal, otherwise false.
     */
    friend bool operator!=(const Assigment &lhs, const Assigment &rhs);

    /**
     * @class Operator
     * @brief Represents a generic operator used to perform operations within a system, framework, or calculation.
     *
     * The Operator class models an entity or mechanism that applies a specific operation,
     * transformation, or functionality. This class can be utilized in various contexts such as
     * mathematical computations, handling user-defined behaviors, or managing logical operations.
     *
     * It is designed to define, process, and execute the intended operation while providing the
     * necessary encapsulation and abstraction. The class may also support extended or overloaded
     * functionality for different types of operations.
     */
    friend std::ostream & operator<<(std::ostream &os, const Assigment &obj);

    /**
     * @brief Exchanges the contents of two Assignment objects.
     *
     * This function performs a member-wise swap of all attributes of the provided
     * Assignment instances. The operation is performed in a no-throw manner
     * by leveraging `std::swap` for each member variable of the Assignment class.
     *
     * The function ensures that the `lhs` and `rhs` objects exchange their internal
     * states efficiently.
     *
     * @param lhs Reference to the first Assignment object to be swapped.
     * @param rhs Reference to the second Assignment object to be swapped.
     */
    friend void swap(Assigment &lhs, Assigment &rhs) noexcept;

};


#endif //PROJECT_ASSIGMENT_H
