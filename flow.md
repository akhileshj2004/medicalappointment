## List of Objects Identified
	`Patient`
	`HealthcareProvider`
	`Appointment`
	`MedicalRecord`
	`HealthService`

## Standard Design Patterns
-	Singleton Pattern: For managing a single instance of the booking system (not explicitly shown in the code but can be considered for enhancement).
-	Observer Pattern: To notify patients and providers about new appointments or updates (can be considered for future enhancements).
-	Factory Pattern: For creating instances of patients, providers, appointments, medical records, and health services.


## Description of Each Class
### Patient Class 
#### Attributes:
-	`name`: string
-	`age`: int
-	`patientID`: string
-	`appointments`: vector of `Appointment*`
-	`medicalRecords`: vector of `MedicalRecord*`
-	`healthServices`: vector of `HealthService*`
#### Methods:
-	`addAppointment(Appointment* appointment)`
-	`addMedicalRecord(MedicalRecord* record)`
-	`addHealthService(HealthService* service)`
-	`viewAppointments()`
-	`viewMedicalRecords()`
-	`viewHealthServices()`
-	Getters: `getName()`, `getID()`

### HealthcareProvider Class
#### Attributes:
-	`name`: string
-	`specialization`: string
-	`appointments`: vector of `Appointment*`
-	`healthServices`: vector of `HealthService*`
#### Methods:
-	`addAppointment(Appointment* appointment)`
-	`addHealthService(HealthService* service)`
-	`viewAppointments()`
-	`viewHealthServices()`
-	Getters: `getName()`, `getSpecialization()`

### Appointment Class
#### Attributes:
-	`patient`: `Patient*`
-	`provider`: `HealthcareProvider*`
-	`date`: string
-	`time`: string
#### Methods:
-	`printDetails()`
-	Getters: `getDate()`, `getTime()`

### MedicalRecord Class
#### Attributes:
-	`patientID`: string
-	`description`: string
-	`date`: string
### Methods:
-	`printDetails()`
-	Getter: `getPatientID()`

### HealthService Class
#### Attributes:
-	`serviceID`: string
-	`name`: string
-	`cost`: double
#### Methods:
-	`printDetails()`
-	Getters: `getServiceID()`, `getName()`, `getCost()`

## Relationships
-	-Patient "has-a" Appointment
-	Patient "has-a" MedicalRecord
-	Patient "has-a" HealthService
-	HealthcareProvider "has-a" Appointment
-	HealthcareProvider "has-a" HealthService
-	Appointment "has-a" Patient
-	Appointment "has-a" HealthcareProvider

## OOP Concepts
-	Encapsulation: Each class encapsulates its attributes and provides public methods for accessing and modifying them.
-	Inheritance: Not explicitly used in the given code, but can be applied if there are subclasses for different types of providers or services.
-	Polymorphism: Implemented through the use of base pointers (`Appointment*`, `MedicalRecord*`, `HealthService*`) which can point to derived class objects.

## Standard Design Pattern Application
-	Factory Pattern:
-	Helper functions like `createPatient()`,   `createHealthcareProvider()`, `createAppointment()`, `createMedicalRecord()`, `createHealthService()` act as simple factories for creating objects.

 ## Exception Handling
-	Exception handling is not explicitly implemented in the given code but can be added to handle errors like invalid inputs, null pointers, etc.
Use of Additional Library Code
-	Standard C++ libraries like `<iostream>`, `<vector>`, `<string>` are used.



