#ifndef PATIENT_MANAGER_H // include guard start
#define PATIENT_MANAGER_H // define guard to prevent multiple inclusion

#include <vector> // include vector container support
#include "Patient.h" // include Patient class definition

class PatientManager // declare manager class for patient operations
{
private:
    vector<Patient> patients; // store a list of patients in memory

public:
    void addPatient(); // add a new patient record

    void viewPatients(); // display all stored patient records

    void searchPatient(); // search for a patient by ID

    void updatePatient(); // update an existing patient record

    void deletePatient(); // delete a patient record by ID

    void saveToFile(); // save patients to the data file

    void loadFromFile(); // load patients from the data file
};

#endif // include guard end