/**
 * @file Person.h
 * @brief Header file for the Person class.
 * @author olidiaks
 * @date 4/11/26
 */

#ifndef PROJECT_PERSON_H
#define PROJECT_PERSON_H
#include <ostream>
#include <string>

/**
 * @class Person
 * @brief Represents a person with personal information like name, email, and birth date.
 */
class Person {
private:
    int id; ///< Unique identifier for the person.
    std::string firstName; ///< First name of the person.
    std::string lastName; ///< Last name of the person.
    std::string email; ///< Email address of the person.
    time_t birthDate; ///< Birth date of the person.
    static int counter; ///< Static counter to generate unique IDs.

public:
    /**
     * @brief Default constructor. Initializes an empty person.
     */
    Person();

    /**
     * @brief Constructor with birth date as time_t.
     * @param first_name First name of the person.
     * @param last_name Last name of the person.
     * @param email Email address of the person.
     * @param birth_date Birth date of the person as time_t.
     */
    Person(const std::string &first_name, const std::string &last_name, const std::string &email,
           const time_t birth_date);

    /**
     * @brief Constructor with birth date components.
     * @param first_name First name of the person.
     * @param last_name Last name of the person.
     * @param email Email address of the person.
     * @param day Day of birth.
     * @param month Month of birth (1-12).
     * @param year Year of birth.
     */
    Person(const std::string &first_name, const std::string &last_name, const std::string &email, const int &day, const int &month, const int &year);

    /**
     * @brief Gets the first name of the person.
     * @return The first name.
     */
    [[nodiscard]] std::string get_first_name() const;

    /**
     * @brief Sets the first name of the person.
     * @param first_name The new first name.
     */
    void set_first_name(const std::string &first_name);

    /**
     * @brief Gets the last name of the person.
     * @return The last name.
     */
    [[nodiscard]] std::string get_last_name() const;

    /**
     * @brief Sets the last name of the person.
     * @param last_name The new last name.
     */
    void set_last_name(const std::string &last_name);

    /**
     * @brief Gets the unique ID of the person.
     * @return The ID.
     */
    [[nodiscard]] int get_id() const;

    /**
     * @brief Gets the birth date of the person.
     * @return The birth date as time_t.
     */
    [[nodiscard]] time_t get_birth_date() const;

    /**
     * @brief Calculates the current age of the person.
     * @return The age in years.
     */
    [[nodiscard]] int get_age() const;

    /**
     * @brief Gets the day of birth.
     * @return The day of the month.
     */
    [[nodiscard]] int get_day_of_birth() const;

    /**
     * @brief Gets the month of birth.
     * @return The month (1-12).
     */
    [[nodiscard]] int get_month_of_birth() const;

    /**
     * @brief Gets the year of birth.
     * @return The year.
     */
    [[nodiscard]] int get_year_of_birth() const;

    /**
     * @brief Gets the email address of the person.
     * @return The email address.
     */
    [[nodiscard]] std::string get_email() const;

    /**
     * @brief Sets the email address of the person.
     * @param email The new email address.
     */
    void set_email(const std::string &email);

    /**
     * @brief Equality operator.
     * @param lhs Left-hand side person.
     * @param rhs Right-hand side person.
     * @return True if persons are identical.
     */
    friend bool operator==(const Person &lhs, const Person &rhs);

    /**
     * @brief Inequality operator.
     * @param lhs Left-hand side person.
     * @param rhs Right-hand side person.
     * @return True if persons are different.
     */
    friend bool operator!=(const Person &lhs, const Person &rhs);

    /**
     * @brief Output stream operator.
     * @param os The output stream.
     * @param obj The person to output.
     * @return Reference to the output stream.
     */
    friend std::ostream & operator<<(std::ostream &os, const Person &obj);

    /**
     * @brief Copy constructor.
     * @param other The person to copy from.
     */
    Person(const Person &other);

    /**
     * @brief Move constructor.
     * @param other The person to move from.
     */
    Person(Person &&other) noexcept;

    /**
     * @brief Copy assignment operator.
     * @param other The person to copy from.
     * @return Reference to this person.
     */
    Person & operator=(const Person &other);

    /**
     * @brief Move assignment operator.
     * @param other The person to move from.
     * @return Reference to this person.
     */
    Person & operator=(Person &&other) noexcept;
};


#endif //PROJECT_PERSON_H
