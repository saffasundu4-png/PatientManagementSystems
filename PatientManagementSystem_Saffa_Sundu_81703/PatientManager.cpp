#include "PatientManager.h" // include header for manager class
#include <fstream> // include file stream support for reading and writing
#include <sstream> // include string stream support for parsing

void PatientManager::addPatient() // add a new patient record interactively
{
    Patient p; // create a temporary Patient object
    p.input(); // read patient data from user input

    patients.push_back(p); // add the patient to the list

    cout << "\nPatient Added Successfully.\n"; // confirm addition
}

void PatientManager::viewPatients() // show all stored patient records
{
    if (patients.empty()) // if there are no records
    {
        cout << "\nNo Records Found.\n"; // notify user that list is empty
        return; // exit early
    }

    for (const auto &patient : patients) // iterate through each patient
    {
        patient.display(); // display the patient details
    }
}

void PatientManager::searchPatient() // search for a patient by ID
{
    string id; // store the search ID

    cout << "Enter Patient ID: "; // prompt for patient ID
    cin >> id; // read the ID from input

    for (const auto &patient : patients) // iterate over patients
    {
        if (patient.getId() == id) // if this patient matches
        {
            patient.display(); // show the patient's information
            return; // stop searching after first match
        }
    }

    cout << "\nPatient Not Found.\n"; // no match found
}

void PatientManager::updatePatient() // update an existing patient record
{
    string id; // store the ID to update

    cout << "Enter Patient ID: "; // prompt user for patient ID
    cin >> id; // read the entered ID

    for (auto &patient : patients) // iterate over patients by reference
    {
        if (patient.getId() == id) // if a matching ID is found
        {
            patient.update(); // update the patient's stored values

            cout << "\nRecord Updated.\n"; // confirm update
            return; // stop after updating the record
        }
    }

    cout << "\nPatient Not Found.\n"; // notify if not found
}

void PatientManager::deletePatient() // delete a patient record by ID
{
    string id; // store the ID to delete

    cout << "Enter Patient ID: "; // prompt for patient ID
    cin >> id; // read the ID

    for (auto it = patients.begin();
         it != patients.end();
         ++it) // iterate with iterator to allow erase
    {
        if (it->getId() == id) // if the iterator points to the correct patient
        {
            patients.erase(it); // remove the patient from the list

            cout << "\nPatient Deleted.\n"; // confirm deletion
            return; // stop after deleting
        }
    }

    cout << "\nPatient Not Found.\n"; // no matching patient found
}

void PatientManager::saveToFile() // write all patient records to disk
{
    ofstream file("data/patients.txt"); // open the patient data file for writing

    for (const auto &patient : patients) // iterate through each patient
    {
        file << patient.serialize() << endl; // write serialized data line-by-line
    }

    file.close(); // close the file stream

    cout << "\nRecords Saved Successfully.\n"; // notify user of successful save
}

void PatientManager::loadFromFile() // read patient records from disk
{
    ifstream file("data/patients.txt"); // open the patient data file for reading

    if (!file) // if file does not open successfully
        return; // nothing to load, exit quietly

    string line; // hold each line read from the file

    while (getline(file, line)) // read file line-by-line
    {
        stringstream ss(line); // create a stream to parse the line

        string id, name, age,
               gender, diagnosis,
               doctor, phone; // define variables for each field

        getline(ss, id, '|'); // parse patient ID
        getline(ss, name, '|'); // parse name
        getline(ss, age, '|'); // parse age as text
        getline(ss, gender, '|'); // parse gender
        getline(ss, diagnosis, '|'); // parse diagnosis
        getline(ss, doctor, '|'); // parse doctor
        getline(ss, phone, '|'); // parse phone

        patients.push_back(
            Patient(
                id,
                name,
                stoi(age),
                gender,
                diagnosis,
                doctor,
                phone)); // create Patient object and add it to the list
    }

    file.close(); // close the file after loading
}