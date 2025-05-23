# Student Course Registration System

## Project Overview
This project implements a **three-layered Student Course Registration System** in C++ using the **Qt Framework**.  
The application is designed to demonstrate object-oriented principles, design patterns, and GUI development with clear architectural separation among the layers:

- **Repository Layer**: Manages persistent data storage in CSV and JSON formats.
- **Controller Layer**: Handles business logic, including add/update/remove operations, filtering, and undo/redo functionality using design patterns.
- **User Interface Layer**: Provides a responsive Qt Widgets-based GUI for users to interact with the system.

---

## Architecture

### Repository Layer
- Abstract base repository class.
- Two concrete implementations:
  - CSV Repository: Stores data in CSV files.
  - JSON Repository: Uses Qt JSON classes (`QJsonDocument`, `QJsonObject`, etc.) to serialize/deserialize data.
- Responsibilities: Object storage and retrieval.

### Controller Layer
- Acts as a bridge between the UI and Repository.
- Core functionalities:
  - **Add** new items.
  - **Remove** existing items.
  - **Update** existing items.
  - **Undo/Redo** operations implemented via the **Command Design Pattern**.
  - **Filtering** capabilities using the **Filtering Design Pattern** (Strategy or Specification).
  
### User Interface Layer
- Built with Qt Widgets and layouts.
- Enables users to:
  - View a list of students and courses.
  - Add, update, and remove registration items via forms.
  - Apply complex filters (AND/OR combinations).
  - Perform undo and redo actions.
- Focus on a clean, navigable, and user-friendly design.

---

## Features
- Multi-layered architecture enforcing separation of concerns.
- Persistent data handling in both CSV and JSON formats.
- Robust undo/redo system via Command pattern.
- Flexible, extendable filtering mechanism.
- Automated unit tests for core functionalities using GoogleTest.
- Memory-safe with smart pointers and RAII principles.
- Leak-free resource management verified via Valgrind/Qt tools.

---

## Getting Started

### Prerequisites
- Qt 5 or Qt 6 (Qt Widgets module)
- C++17 compatible compiler (e.g., MSVC, GCC, Clang)
- CMake or Qt Creator for build configuration
- GoogleTest (optional, for running unit tests)

### Build Instructions
1. Clone the repository:
   ```bash
   git clone https://github.com/yourusername/StudentCourseRegistration.git
   cd StudentCourseRegistration
