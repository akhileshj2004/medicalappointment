#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <ctime>

using namespace std;

// Forward declarations
class Appointment;
class MedicalRecord;
class HealthService;

// Patient class
class Patient {
public:
    Patient(string name, int age, string id) : name(name), age(age), patientID(id) {}

    void addAppointment(Appointment* appointment);
    void addMedicalRecord(MedicalRecord* record);
    void addHealthService(HealthService* service);

    void viewAppointments();
    void viewMedicalRecords();
    void viewHealthServices();

    string getName() { return name; }
    string getID() { return patientID; }

private:
    string name;
    int age;
    string patientID;
    vector<Appointment*> appointments;
    vector<MedicalRecord*> medicalRecords;
    vector<HealthService*> healthServices;
};

// HealthcareProvider class
class HealthcareProvider {
public:
    HealthcareProvider(string name, string specialization) : name(name), specialization(specialization) {}

    void addAppointment(Appointment* appointment);
    void addHealthService(HealthService* service);

    void viewAppointments();
    void viewHealthServices();

    string getName() { return name; }
    string getSpecialization() { return specialization; }

private:
    string name;
    string specialization;
    vector<Appointment*> appointments;
    vector<HealthService*> healthServices;
};

// Appointment class
class Appointment {
public:
    Appointment(Patient* patient, HealthcareProvider* provider, string date, string time)
        : patient(patient), provider(provider), date(date), time(time) {}

    void printDetails();

    string getDate() { return date; }
    string getTime() { return time; }

private:
    Patient* patient;
    HealthcareProvider* provider;
    string date;
    string time;
};

// MedicalRecord class
class MedicalRecord {
public:
    MedicalRecord(string patientID, string description, string date)
        : patientID(patientID), description(description), date(date) {}

    void printDetails();

    string getPatientID() { return patientID; }

private:
    string patientID;
    string description;
    string date;
};

// HealthService class
class HealthService {
public:
    HealthService(string serviceID, string name, double cost)
        : serviceID(serviceID), name(name), cost(cost) {}

    void printDetails();

    string getServiceID() { return serviceID; }
    string getName() { return name; }
    double getCost() { return cost; }

private:
    string serviceID;
    string name;
    double cost;
};

// Function implementations for Patient class
void Patient::addAppointment(Appointment* appointment) {
    appointments.push_back(appointment);
}

void Patient::addMedicalRecord(MedicalRecord* record) {
    medicalRecords.push_back(record);
}

void Patient::addHealthService(HealthService* service) {
    healthServices.push_back(service);
}

void Patient::viewAppointments() {
    cout << "Appointments for " << name << ":\n";
    for (auto& appointment : appointments) {
        appointment->printDetails();
    }
}

void Patient::viewMedicalRecords() {
    cout << "Medical records for " << name << ":\n";
    for (auto& record : medicalRecords) {
        record->printDetails();
    }
}

void Patient::viewHealthServices() {
    cout << "Health services for " << name << ":\n";
    for (auto& service : healthServices) {
        service->printDetails();
    }
}

// Function implementations for HealthcareProvider class
void HealthcareProvider::addAppointment(Appointment* appointment) {
    appointments.push_back(appointment);
}

void HealthcareProvider::addHealthService(HealthService* service) {
    healthServices.push_back(service);
}

void HealthcareProvider::viewAppointments() {
    cout << "Appointments for Dr. " << name << ":\n";
    for (auto& appointment : appointments) {
        appointment->printDetails();
    }
}

void HealthcareProvider::viewHealthServices() {
    cout << "Health services provided by Dr. " << name << ":\n";
    for (auto& service : healthServices) {
        service->printDetails();
    }
}

// Function implementations for Appointment class
void Appointment::printDetails() {
    cout << "Appointment with " << provider->getName() << " on " << date << " at " << time << "\n";
}

// Function implementations for MedicalRecord class
void MedicalRecord::printDetails() {
    cout << "Record dated " << date << ": " << description << "\n";
}

// Function implementations for HealthService class
void HealthService::printDetails() {
    cout << "Service ID: " << serviceID << ", Name: " << name << ", Cost: $" << cost << "\n";
}

// Helper functions
Patient* createPatient() {
    string name, id;
    int age;
    cout << "Enter patient name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Enter patient age: ";
    cin >> age;
    cout << "Enter patient ID: ";
    cin >> id;
    return new Patient(name, age, id);
}

HealthcareProvider* createHealthcareProvider() {
    string name, specialization;
    cout << "Enter provider name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Enter specialization: ";
    getline(cin, specialization);
    return new HealthcareProvider(name, specialization);
}

Appointment* createAppointment(Patient* patient, HealthcareProvider* provider) {
    string date, time;
    cout << "Enter appointment date (YYYY-MM-DD): ";
    cin >> date;
    cout << "Enter appointment time (HH:MM AM/PM): ";
    cin >> time;
    return new Appointment(patient, provider, date, time);
}

MedicalRecord* createMedicalRecord(Patient* patient) {
    string description, date;
    cout << "Enter record description: ";
    cin.ignore();
    getline(cin, description);
    cout << "Enter record date (YYYY-MM-DD): ";
    cin >> date;
    return new MedicalRecord(patient->getID(), description, date);
}

HealthService* createHealthService() {
    string serviceID, name;
    double cost;
    cout << "Enter service ID: ";
    cin >> serviceID;
    cout << "Enter service name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Enter service cost: ";
    cin >> cost;
    return new HealthService(serviceID, name, cost);
}

int main() {
    vector<Patient*> patients;
    vector<HealthcareProvider*> providers;

    while (true) {
        cout << "\nMedical Appointment Booking System\n";
        cout << "1. Add Patient\n";
        cout << "2. Add Healthcare Provider\n";
        cout << "3. Schedule Appointment\n";
        cout << "4. Add Medical Record\n";
        cout << "5. Add Health Service\n";
        cout << "6. View Patient Appointments\n";
        cout << "7. View Patient Medical Records\n";
        cout << "8. View Patient Health Services\n";
        cout << "9. View Provider Appointments\n";
        cout << "10. View Provider Health Services\n";
        cout << "11. Exit\n";
        cout << "Choose an option: ";
        int choice;
        cin >> choice;

        if (choice == 1) {
            patients.push_back(createPatient());
        } else if (choice == 2) {
            providers.push_back(createHealthcareProvider());
        } else if (choice == 3) {
            if (patients.empty() || providers.empty()) {
                cout << "Please add patients and providers first.\n";
                continue;
            }
            int patientIdx, providerIdx;
            cout << "Select patient index (0 to " << patients.size() - 1 << "): ";
            cin >> patientIdx;
            cout << "Select provider index (0 to " << providers.size() - 1 << "): ";
            cin >> providerIdx;
            Appointment* appointment = createAppointment(patients[patientIdx], providers[providerIdx]);
            patients[patientIdx]->addAppointment(appointment);
            providers[providerIdx]->addAppointment(appointment);
        } else if (choice == 4) {
            if (patients.empty()) {
                cout << "Please add patients first.\n";
                continue;
            }
            int patientIdx;
            cout << "Select patient index (0 to " << patients.size() - 1 << "): ";
            cin >> patientIdx;
            MedicalRecord* record = createMedicalRecord(patients[patientIdx]);
            patients[patientIdx]->addMedicalRecord(record);
        } else if (choice == 5) {
            if (patients.empty() || providers.empty()) {
                cout << "Please add patients and providers first.\n";
                continue;
            }
            int patientIdx, providerIdx;
            cout << "Select patient index (0 to " << patients.size() - 1 << "): ";
            cin >> patientIdx;
            cout << "Select provider index (0 to " << providers.size() - 1 << "): ";
            cin >> providerIdx;
            HealthService* service = createHealthService();
            patients[patientIdx]->addHealthService(service);
            providers[providerIdx]->addHealthService(service);
        } else if (choice == 6) {
            if (patients.empty()) {
                cout << "Please add patients first.\n";
                continue;
            }
            int patientIdx;
            cout << "Select patient index (0 to " << patients.size() - 1 << "): ";
            cin >> patientIdx;
            patients[patientIdx]->viewAppointments();
        } else if (choice == 7) {
            if (patients.empty()) {
                cout << "Please add patients first.\n";
                continue;
            }
            int patientIdx;
            cout << "Select patient index (0 to " << patients.size() - 1 << "): ";
            cin >> patientIdx;
            patients[patientIdx]->viewMedicalRecords();
        } else if (choice == 8) {
            if (patients.empty()) {
                cout << "Please add patients first.\n";
                continue;
            }
            int patientIdx;
            cout << "Select patient index (0 to " << patients.size() - 1 << "): ";
            cin >> patientIdx;
            patients[patientIdx]->viewHealthServices();
        } else if (choice == 9) {
            if (providers.empty()) {
                cout << "Please add providers first.\n";
                continue;
            }
            int providerIdx;
            cout << "Select provider index (0 to " << providers.size() - 1 << "): ";
            cin >> providerIdx;
            providers[providerIdx]->viewAppointments();
        } else if (choice == 10) {
            if (providers.empty()) {
                cout << "Please add providers first.\n";
                continue;
            }
            int providerIdx;
            cout << "Select provider index (0 to " << providers.size() - 1 << "): ";
            cin >> providerIdx;
            providers[providerIdx]->viewHealthServices();
        } else if (choice == 11) {
            break;
        } else {
            cout << "Invalid option. Please try again.\n";   }
    }
    // Clean up dynamically allocated memory
    for (Patient* patient : patients) {
        delete patient;   }
    for (HealthcareProvider* provider : providers) {
        delete provider;
    }
    return 0;
}
