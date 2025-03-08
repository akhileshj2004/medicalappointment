# 🏥 Medical Appointment Booking System

<p align="center">
  <img src="https://img.shields.io/badge/C%2B%2B-17-blue" alt="C++ 17">
  <img src="https://img.shields.io/badge/Platform-Cross--platform-green" alt="Cross-platform">
  <img src="https://img.shields.io/badge/Status-Stable-success" alt="Status: Stable">
  <img src="https://img.shields.io/badge/Version-1.0.0-informational" alt="Version 1.0.0">
</p>

A comprehensive C++ console application for managing medical appointments, patient records, healthcare providers, and health services. This system streamlines healthcare administration processes and improves patient care coordination.

## ✨ Features

- **Patient Management:**
  - Store patient demographics
  - Track medical history
  - Manage appointments

- **Healthcare Provider Management:**
  - Track provider specializations
  - Manage provider availability
  - Associate providers with services

- **Appointment Scheduling:**
  - Create and manage appointments
  - Link patients with appropriate healthcare providers
  - Avoid scheduling conflicts

- **Medical Records:**
  - Maintain detailed patient history
  - Secure storage of sensitive information
  - Chronological tracking of medical events

- **Health Services:**
  - Catalog available healthcare services
  - Track service costs
  - Associate services with providers and patients

## 🏗️ System Architecture

The system follows Object-Oriented Design principles with the following class structure:

```
┌─────────────┐      ┌────────────────────┐      ┌─────────────────────────┐
│   Patient   │◄─────┤    Appointment     │─────►│   HealthcareProvider    │
└─────┬───────┘      └────────────────────┘      └───────────┬─────────────┘
      │                                                      │
      │               ┌────────────────────┐                 │
      └──────────────►│   HealthService    │◄────────────────┘
      │               └────────────────────┘                 
      │                                                      
      │               ┌────────────────────┐                 
      └──────────────►│   MedicalRecord    │                 
                      └────────────────────┘                 
```

## 🚀 Getting Started

### Prerequisites

- C++ compiler with C++11 support or later
- Standard C++ libraries

### Installation

1. Clone the repository:
   ```bash
   git clone https://github.com/yourusername/medical-appointment-system.git
   cd medical-appointment-system
   ```

2. Compile the program:
   ```bash
   g++ -std=c++11 main.cpp -o medical_system
   ```

3. Run the application:
   ```bash
   ./medical_system
   ```

## 📋 Usage Guide

### Main Menu

The system presents the following options:

1. **Add Patient** - Register a new patient
2. **Add Healthcare Provider** - Add a new doctor or specialist
3. **Schedule Appointment** - Create a new appointment
4. **Add Medical Record** - Add medical history for a patient
5. **Add Health Service** - Create a new service offering
6. **View Patient Appointments** - See all appointments for a specific patient
7. **View Patient Medical Records** - Access patient's medical history
8. **View Patient Health Services** - See services associated with a patient
9. **View Provider Appointments** - See all appointments for a provider
10. **View Provider Health Services** - List all services offered by a provider
11. **Exit** - Close the application

### Example Workflow

```
1. Add a new patient (Option 1)
2. Add a new healthcare provider (Option 2)
3. Schedule an appointment between them (Option 3)
4. Add medical records for the patient (Option 4)
5. Add health services (Option 5)
6. View the created data using options 6-10
```

## 💻 Technical Details

- **Language:** C++
- **Programming Paradigm:** Object-Oriented
- **Data Structures:** Vectors for dynamic collections
- **Memory Management:** Manual allocation/deallocation of objects
- **Input Handling:** Console-based user input validation

## 🔄 Class Relationships

- **Patient** maintains collections of appointments, medical records, and health services
- **HealthcareProvider** tracks appointments and health services
- **Appointment** links patients and providers
- **MedicalRecord** stores patient health information
- **HealthService** represents medical procedures or services

## 🛣️ Roadmap

Future enhancements planned for this system include:

- Database integration for persistent storage
- Graphical user interface
- Appointment conflict detection
- Automated reminder system
- Patient billing integration
- Export functionality for records
- Encrypted storage for sensitive information

## 🤝 Contributing

Contributions are welcome! Please feel free to submit a Pull Request.

1. Fork the repository
2. Create your feature branch (`git checkout -b feature/amazing-feature`)
3. Commit your changes (`git commit -m 'Add some amazing feature'`)
4. Push to the branch (`git push origin feature/amazing-feature`)
5. Open a Pull Request

