#ifndef PATIENT_H // include guard start
#define PATIENT_H // define guard to prevent multiple inclusion

#include <iostream>  // include standard I/O utilities for cin/cout
using namespace std; // allow use of std symbols directly

class Patient // declare Patient class to store patient information
{

// private member variables that hold patient details
private:
    string id;        // unique patient identifier
    string name;      // patient name
    int age;          // patient age
    string gender;    // patient gender
    string diagnosis; // patient diagnosis description
    string doctor;    // doctor assigned to the patient
    string phone;     // patient phone number

// public methods that define the behavior of the Patient class
public:
    // Constructors
    Patient(); // default constructor

    // parameterized constructor to initialize all fields
    Patient(string id,
            string name,
            int age,
            string gender,
            string diagnosis,
            string doctor,
            string phone);

    // Getters and other member functions
    string getId() const; // return the patient's ID

    string serialize() const; // convert patient fields to a pipe-delimited string

    void input(); // read patient data from standard input

    void display() const; // print patient data to console

    void update(); // update patient fields from standard input
};

#endif // include guard end