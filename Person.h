/**
 * @file Person.h
 * @brief Header file for the Person class, providing a robust representation of an individual's personal data.
 * @author olidiaks
 * @date 4/11/26
 */

#ifndef PROJECT_PERSON_H
#define PROJECT_PERSON_H
#include <ostream>
#include <string>

/**
 * @class Person
 * @brief Represents an individual with properties such as ID, name, email, and birth date.
 *
 * Provides functionalities for setting and retrieving personal information,
 * calculating age, formatting birth dates, and comparing Person objects.
 */
class Person {
private:
    int id; ///< A unique integer identifier assigned to each person upon creation. Defaults to -1 if uninitialized.
    std::string firstName; ///< The given name of the individual.
    std::string lastName; ///< The family name or surname of the individual.
    std::string email; ///< The primary contact email address.
    time_t birthDate; ///< The person's date of birth, stored as seconds since the Unix Epoch (Jan 1, 1970).
    static int counter; ///< A shared static counter used to ensure each Person instance receives a unique, incrementing ID.

public:
    /**
     * @brief Constructs a default instance of the Person class.
     *
     * Initializes the Person object with default values for all properties.
     * The ID is set to -1, names and email are set to empty strings, and the birth date is initialized to 0.
     *
     * @return A fully constructed Person object with default property values.
     */
    Person();

    /**
     * @brief Specialized constructor using a pre-calculated time_t value for the birth date.
     * 
     * @param first_name The individual's first name.
     * @param last_name The individual's last name.
     * @param email The individual's contact email.
     * @param birth_date A time_t value representing the exact moment of birth.
     * 
     * This constructor increments the static `counter` and assigns the new value to the person's `id`.
     */
    Person(const std::string &first_name, const std::string &last_name, const std::string &email,
           const time_t birth_date);

    /**
     * @brief Overloaded constructor for initialization using human-readable date components.
     * 
     * Internally converts the day, month, and year into a `time_t` value using the `tm` structure.
     * 
     * @param first_name The individual's first name.
     * @param last_name The individual's last name.
     * @param email The individual's contact email.
     * @param day Calendar day (1-31).
     * @param month Calendar month (1-12).
     * @param year Calendar year (e.g., 1995).
     * 
     * Like other parameterized constructors, this increments the global ID counter.
     */
    Person(const std::string &first_name, const std::string &last_name, const std::string &email, const int &day, const int &month, const int &year);

    /**
     * @brief Retrieves the stored first name.
     * @return A string containing the person's first name.
     */
    [[nodiscard]] std::string get_first_name() const;

    /**
     * @brief Updates the person's first name.
     * @param first_name The new first name to be assigned.
     */
    void set_first_name(const std::string &first_name);

    /**
     * @brief Retrieves the stored last name.
     * @return A string containing the person's last name.
     */
    [[nodiscard]] std::string get_last_name() const;

    /**
     * @brief Updates the person's last name.
     * @param last_name The new last name to be assigned.
     */
    void set_last_name(const std::string &last_name);

    /**
     * @brief Retrieves the unique system identifier for this person.
     * @return An integer representing the unique ID.
     */
    [[nodiscard]] int get_id() const;

    /**
     * @brief Retrieves the full birth date as a time_t value.
     * @return The birth date in seconds since the Epoch.
     */
    [[nodiscard]] time_t get_birth_date() const;

    /**
     * @brief Calculates the person's current age based on the system time.
     * 
     * The method calculates the difference between the current time and the birth date,
     * then extracts the year component from the resulting duration.
     * 
     * @return The number of full years elapsed since the birth date.
     */
    [[nodiscard]] int get_age() const;

    /**
     * @brief Extracts the day component from the birth date.
     * @return The day of the month (1-31).
     */
    [[nodiscard]] int get_day_of_birth() const;

    /**
     * @brief Extracts the month component from the birth date.
     * @return The month of the year as an integer (1-12).
     */
    [[nodiscard]] int get_month_of_birth() const;

    /**
     * @brief Extracts the year component from the birth date.
     * @return The four-digit birth year (e.g., 2026).
     */
    [[nodiscard]] int get_year_of_birth() const;

    /**
     * @brief Retrieves the person's email address.
     * @return A string representing the email address.
     */
    [[nodiscard]] std::string get_email() const;

    /**
     * @brief Updates the person's email address.
     * @param email The new email string to validate and store.
     */
    void set_email(const std::string &email);

    /**
     * @brief Checks if two Person instances are identical across all fields.
     * 
     * @param lhs The first person to compare.
     * @param rhs The second person to compare.
     * @return True if ID, name, email, and birth date all match.
     */
    friend bool operator==(const Person &lhs, const Person &rhs);

    /**
     * @brief Checks if two Person instances differ in any field.
     * 
     * @param lhs The first person to compare.
     * @param rhs The second person to compare.
     * @return True if any attribute differs between the two objects.
     */
    friend bool operator!=(const Person &lhs, const Person &rhs);

    /**
     * @brief Formats the Person's information for output to a stream.
     * 
     * Generates a string including the ID, full name, email, age, and a 
     * formatted DD.MM.YYYY birth date.
     * 
     * @param os The output stream (e.g., std::cout or a file stream).
     * @param obj The Person instance to be serialized.
     * @return A reference to the modified output stream.
     */
    friend std::ostream & operator<<(std::ostream &os, const Person &obj);

    /**
     * @brief Copy constructor creating a new Person as a clone of an existing one.
     * @param other The source Person instance to copy data from.
     */
    Person(const Person &other);

    /**
     * @brief Move constructor for efficient transfer of resources.
     * @param other The temporary Person instance whose resources will be moved.
     */
    Person(Person &&other) noexcept;

    /**
     * @brief Copy assignment operator replacing current data with a copy of another instance.
     * @param other The source Person to copy from.
     * @return A reference to this updated instance.
     */
    Person & operator=(const Person &other);

    /**
     * @brief Move assignment operator transferring ownership of resources from another instance.
     * @param other The source Person instance to move from.
     * @return A reference to this updated instance.
     */
    Person & operator=(Person &&other) noexcept;
};


#endif //PROJECT_PERSON_H
