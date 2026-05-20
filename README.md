# eoop-school-project

## Polish / Polski

Ten projekt został stworzony na drugi semestr studiów z przedmiotu Programowanie Obiektowe (EOOP). Jest to system zarządzania szkołą napisany w języku C++, demonstrujący zasady programowania obiektowego, takie jak dziedziczenie, enkapsulacja oraz wykorzystanie kontenerów biblioteki standardowej.

### Funkcjonalności
- Zarządzanie danymi osób (uczniowie, nauczyciele).
- Obsługa klas szkolnych, przedmiotów oraz przypisywanie zadań.
- System oceniania i obliczanie średnich.
- Zarządzanie strukturą szkoły (zatrudnianie nauczycieli, tworzenie klas).
- Rozbudowane testy jednostkowe.

### Struktura Projektu
- `School`: Główna klasa zarządzająca nauczycielami i klasami.
- `Class`: Reprezentuje grupę uczniów z wychowawcą i zestawem przedmiotów.
- `Student` / `Teacher`: Klasy pochodne od `Person`, przechowujące specyficzne dane.
- `Assignment`: Reprezentuje zadania domowe lub testy z przypisanymi ocenami.
- `Subject`: Typ wyliczeniowy dla przedmiotów szkolnych.

### Wymagania i Kompilacja
Projekt korzysta z CMake i wymaga standardu C++26.
Do testów wykorzystywany jest GoogleTest.

```bash
mkdir build && cd build
cmake ..
make
```

Aby uruchomić testy:
```bash
ctest
# lub za pomocą dedykowanego celu
make run-tests
```

---

## English

This project was developed for the second semester of studies in the Object-Oriented Programming (EOOP) course. It is a school management system written in C++, demonstrating OOP principles such as inheritance, encapsulation, and the use of STL containers.

### Features
- Management of person data (students, teachers).
- Handling of school classes, subjects, and assignments.
- Grading system and average calculation.
- School structure management (hiring teachers, creating classes).
- Comprehensive unit tests.

### Project Structure
- `School`: Main class managing teachers and classes.
- `Class`: Represents a group of students with a supervising teacher and a set of subjects.
- `Student` / `Teacher`: Classes derived from `Person`, storing specific data.
- `Assignment`: Represents homework or tests with assigned grades.
- `Subject`: Enumeration for school subjects.

### Requirements and Compilation
The project uses CMake and requires the C++26 standard.
GoogleTest is used for testing.

```bash
mkdir build && cd build
cmake ..
make
```

To run tests:
```bash
ctest
# or using the dedicated target
make run-tests
```