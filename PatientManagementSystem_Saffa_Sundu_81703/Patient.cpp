#include "Patient.h" // include patient header with class declaration
#include <limits> // include numeric limits for input handling
#include <sstream> // include string stream support

// Implementation of Patient class methods
Patient::Patient() // default constructor initializes a patient
{
    age = 0; // default age set to 0
}

// parameterized constructor to initialize all fields
Patient::Patient(string id,
                 string name,
                 int age,
                 string gender,
                 string diagnosis,
                 string doctor,
                 string phone) // parameterized constructor sets all patient fields
{
    this->id = id; // assign provided id
    this->name = name; // assign provided name
    this->age = age; // assign provided age
    this->gender = gender; // assign provided gender
    this->diagnosis = diagnosis; // assign provided diagnosis
    this->doctor = doctor; // assign provided doctor
    this->phone = phone; // assign provided phone
}

string Patient::getId() const // return the patient ID string
{
    return id; // return identifier
}

void Patient::input() // read patient details from console input
{
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // clear previous input from the buffer

    cout << "\nPatient ID: "; // prompt for patient ID
    getline(cin, id); // read full line into id

    cout << "Name: "; // prompt for name
    getline(cin, name); // read full line into name

    cout << "Age: "; // prompt for age
    cin >> age; // read integer age

    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // clear newline from input buffer

    cout << "Gender: "; // prompt for gender
    getline(cin, gender); // read full line into gender

    cout << "Diagnosis: "; // prompt for diagnosis
    getline(cin, diagnosis); // read full line into diagnosis

    cout << "Doctor: "; // prompt for doctor name
    getline(cin, doctor); // read full line into doctor

    cout << "Phone: "; // prompt for phone number
    getline(cin, phone); // read full line into phone
}

void Patient::display() const // print patient details to the console
{
    cout << "\n---------------------------------\n"; // separator line
    cout << "ID: " << id << endl; // display id
    cout << "Name: " << name << endl; // display name
    cout << "Age: " << age << endl; // display age
    cout << "Gender: " << gender << endl; // display gender
    cout << "Diagnosis: " << diagnosis << endl; // display diagnosis
    cout << "Doctor: " << doctor << endl; // display doctor
    cout << "Phone: " << phone << endl; // display phone number
}

void Patient::update() // update patient information from console input
{
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // clear input buffer before taking new strings

    cout << "New Name: "; // prompt for updated name
    getline(cin, name); // read updated name

    cout << "New Age: "; // prompt for updated age
    cin >> age; // read updated age

    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // clear newline from buffer

    cout << "New Gender: "; // prompt for updated gender
    getline(cin, gender); // read updated gender

    cout << "New Diagnosis: "; // prompt for updated diagnosis
    getline(cin, diagnosis); // read updated diagnosis

    cout << "New Doctor: "; // prompt for updated doctor
    getline(cin, doctor); // read updated doctor

    cout << "New Phone: "; // prompt for updated phone
    getline(cin, phone); // read updated phone
}

string Patient::serialize() const // serialize patient data to a file-friendly format
{
    return id + "|" +
           name + "|" +
           to_string(age) + "|" +
           gender + "|" +
           diagnosis + "|" +
           doctor + "|" +
           phone; // combine fields with pipe separators
}