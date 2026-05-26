# Patient Management System

This is a simple C++ console application for managing patient records.

## Features

- Add patient records
- View all stored patients
- Search patients by ID
- Update a patient record by ID
- Delete a patient record by ID
- Save patient records to file
- Load patient records from file on startup

## Project Structure

- `main.cpp` - application entry point and menu loop
- `Patient.h` - patient data class definition
- `Patient.cpp` - patient class implementation
- `PatientManager.h` - patient manager class definition
- `PatientManager.cpp` - patient manager implementation
- `patients.txt` - patient data file used for persistence

## Build Instructions

1. Open a terminal in the project root.
2. Compile the code with a C++ compiler such as g++:

```bash
g++ main.cpp Patient.cpp PatientManager.cpp -o patientSystem.exe
```

3. Run the application:

```bash
./patientSystem.exe
```

## Usage

- Choose a menu option by entering its number.
- When adding or updating a patient, provide the requested details.
- Select option `6` to save records manually.
- The application saves records automatically when exiting with option `7`.

## Notes

- Patient records are stored in `patients.txt`.
- Each record is saved as a pipe-delimited line.
- The application loads data from the file when it starts.
