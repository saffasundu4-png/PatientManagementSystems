#include <iostream> // provide standard I/O stream objects
#include "PatientManager.h" // include the patient manager class definition

using namespace std; // allow usage of standard library names without std::

int main() // program entry point
{
    PatientManager manager; // create a patient manager object to handle records

    manager.loadFromFile(); // load existing patient data from file if available

    int choice; // store the user's menu choice

    do // run the main menu loop until the user chooses to exit
    {
        cout << R"(

====================================================
         PATIENT RECORD MANAGEMENT SYSTEM
====================================================

1. Add Patient
2. View All Patients
3. Search Patient
4. Update Patient
5. Delete Patient
6. Save Records
7. Exit

Enter Choice:
)"; // print the menu to the console

        cin >> choice; // read the user's selected menu option

        switch (choice) // branch based on menu selection
        {
        case 1:
            manager.addPatient(); // add a new patient record
            break;

        case 2:
            manager.viewPatients(); // display all patient records
            break;

        case 3:
            manager.searchPatient(); // search for a patient by ID
            break;

        case 4:
            manager.updatePatient(); // update a patient record by ID
            break;

        case 5:
            manager.deletePatient(); // delete a patient record by ID
            break;

        case 6:
            manager.saveToFile(); // save the current records back to file
            break;

        case 7:
            manager.saveToFile(); // save records one last time before exit
            cout << "\nThank you for using the system.\n"; // farewell message
            break;

        default:
            cout << "\nInvalid Choice.\n"; // handle invalid menu options
        }

    } while (choice != 7); // continue looping until exit option selected

    return 0; // return success status
}