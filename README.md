# 🚗 University Carpooling Platform (C++)

A simple carpooling application developed in C++ to facilitate ride sharing among students and members of the university community.

## 📋 Description

This project implements a command-line carpooling system that allows users to sign up, offer rides as drivers, and book seats as passengers. Data is persisted in text files for simple, local usage.

## ✨ Features

### User Authentication
- **Sign up**: Create an account with name, email, password, and phone number
- **Log in**: Secure authentication via email/password
- **Log out**: User session management

### Ride Management
- **Post rides**: Drivers can publish rides with:
  - Departure and arrival cities
  - Ride date and time
  - Number of available seats
  - Price per person
- **Search rides**: Search by departure and arrival city
- **Booking**: Book available seats on rides
- **Browse**: Display all available rides

### Data Persistence
- Automatic user saving to `users.txt`
- Automatic ride saving to `rides.txt`
- CSV format with `;` separator

## 📁 Project Structure

```
cpp_carpooling/
├── main.cpp              # Application entry point (user interface)
├── CarpoolSystem.h       # Main class handling business logic
├── Models.h              # Data structures (User, Ride)
├── build_and_run.bat     # Build and run script (Windows)
├── users.txt             # Users database
└── rides.txt             # Rides database
```

### File details

- **`main.cpp`**: Handles the command-line user interface with interactive menus
- **`CarpoolSystem.h`**: Contains the `CarpoolSystem` class, which manages:
  - The list of users and rides
  - Authentication
  - Ride search and booking
  - Reading/writing the data files
- **`Models.h`**: Defines the structures:
  - `User`: User information (id, name, email, password, phone)
  - `Ride`: Ride information (id, driver, origin, destination, date, time, seats, price)

## 🛠️ Requirements

- A compatible C++ compiler:
  - **Windows**: MinGW (g++), MSVC, or Clang
  - **Linux**: g++ or clang++
  - **macOS**: Xcode Command Line Tools (g++ or clang++)

## 🚀 Build and Run

### Windows

#### Method 1: Automatic script
```powershell
.\build_and_run.bat
```

#### Method 2: Manual compilation
```powershell
g++ main.cpp -o main.exe
.\main.exe
```

### Linux / macOS

```bash
g++ main.cpp -o main
./main
```

## 📖 Usage

1. **Start the application** by running the compiled executable
2. **Create an account** or **log in** with an existing account
3. Once logged in, use the menu to:
   - **Search for a ride**: Find available rides between two cities
   - **Offer a ride**: Post a new ride as a driver
   - **View all rides**: Browse the full list of available rides
   - **Log out**: End your session

### Usage example

```
==========================================
   UNIVERSITY CARPOOLING PLATFORM
==========================================
1. Log in
2. Sign up
3. Quit
Choice: 2

Full name: Jean_Dupont
Email: jean.dupont@univ.fr
Password: motdepasse123
Phone: 0612345678
>> Registration successful! You can now log in.
```

## 🔒 Security

⚠️ **Important note**: This project is an educational prototype. Passwords are stored in plain text in the text files. For production use, it would be necessary to implement:

- Password hashing (bcrypt, Argon2, etc.)
- User input validation
- More robust error handling
- Encryption of sensitive data

## 📝 Data File Formats

### users.txt
CSV format with `;` separator:
```
id;nom;email;mot_de_passe;telephone
```

### rides.txt
CSV format with `;` separator:
```
id;driverId;nom_conducteur;origine;destination;date;heure;places_disponibles;prix
```

## 🤝 Contributing

Contributions are welcome! Feel free to:
- Report bugs
- Propose new features
- Improve the documentation
- Optimize the code

## 📄 License

This project is provided as-is for educational purposes.

## 👨‍💻 Author

Developed as part of a university project in C++.

---

**Note**: This project is designed for learning and demonstrating object-oriented programming concepts in C++. For a production application, a more robust architecture would be required.
