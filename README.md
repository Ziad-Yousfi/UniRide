# 🚗 University Carpooling Platform (C++)

<p align="right">
  <a href="#-plateforme-de-covoiturage-universitaire-c">🇫🇷 Français</a> | <a href="#-university-carpooling-platform-c">🇬🇧 English</a>
</p>

---

## 🇬🇧 University Carpooling Platform (C++)

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

---

## 🇫🇷 Plateforme de covoiturage universitaire (C++)

Une application de covoiturage simple développée en C++ pour faciliter le partage de trajets entre les étudiants et les membres de la communauté universitaire.

## 📋 Description

Ce projet implémente un système de covoiturage en ligne de commande qui permet aux utilisateurs de s’inscrire, de proposer des trajets en tant que conducteurs, et de réserver des places en tant que passagers. Les données sont persistées dans des fichiers texte pour un usage local et simple.

## ✨ Fonctionnalités

### Authentification des utilisateurs
- **Inscription** : Créer un compte avec nom, email, mot de passe et numéro de téléphone
- **Connexion** : Authentification via email/mot de passe
- **Déconnexion** : Gestion de session utilisateur

### Gestion des trajets
- **Publier des trajets** : Les conducteurs peuvent publier des trajets avec :
  - Ville de départ et ville d’arrivée
  - Date et heure du trajet
  - Nombre de places disponibles
  - Prix par personne
- **Rechercher des trajets** : Recherche par ville de départ et d’arrivée
- **Réservation** : Réserver des places disponibles sur un trajet
- **Parcourir** : Afficher tous les trajets disponibles

### Persistance des données
- Sauvegarde automatique des utilisateurs dans `users.txt`
- Sauvegarde automatique des trajets dans `rides.txt`
- Format CSV avec séparateur `;`

## 📁 Structure du projet

```
cpp_carpooling/
├── main.cpp              # Point d’entrée (interface utilisateur)
├── CarpoolSystem.h       # Classe principale (logique métier)
├── Models.h              # Structures de données (User, Ride)
├── build_and_run.bat     # Script build & run (Windows)
├── users.txt             # Base de données utilisateurs
└── rides.txt             # Base de données trajets
```

### Détails des fichiers

- **`main.cpp`** : Gère l’interface en ligne de commande avec des menus interactifs
- **`CarpoolSystem.h`** : Contient la classe `CarpoolSystem`, qui gère :
  - La liste des utilisateurs et des trajets
  - L’authentification
  - La recherche et la réservation
  - La lecture/écriture des fichiers de données
- **`Models.h`** : Définit les structures :
  - `User` : Informations utilisateur (id, nom, email, mot de passe, téléphone)
  - `Ride` : Informations trajet (id, conducteur, origine, destination, date, heure, places, prix)

## 🛠️ Prérequis

- Un compilateur C++ compatible :
  - **Windows** : MinGW (g++), MSVC, ou Clang
  - **Linux** : g++ ou clang++
  - **macOS** : Xcode Command Line Tools (g++ ou clang++)

## 🚀 Compilation et exécution

### Windows

#### Méthode 1 : Script automatique
```powershell
.\build_and_run.bat
```

#### Méthode 2 : Compilation manuelle
```powershell
g++ main.cpp -o main.exe
.\main.exe
```

### Linux / macOS

```bash
g++ main.cpp -o main
./main
```

## 📖 Utilisation

1. **Lancer l’application** en exécutant le binaire compilé
2. **Créer un compte** ou **se connecter** avec un compte existant
3. Une fois connecté, utiliser le menu pour :
   - **Rechercher un trajet** : Trouver des trajets disponibles entre deux villes
   - **Proposer un trajet** : Publier un nouveau trajet en tant que conducteur
   - **Voir tous les trajets** : Parcourir tous les trajets disponibles
   - **Se déconnecter** : Terminer la session

### Exemple d’utilisation

```
==========================================
   PLATEFORME DE COVOITURAGE UNIVERSITAIRE
==========================================
1. Connexion
2. Inscription
3. Quitter
Choix : 2

Nom complet : Jean_Dupont
Email : jean.dupont@univ.fr
Mot de passe : motdepasse123
Téléphone : 0612345678
>> Inscription réussie ! Vous pouvez maintenant vous connecter.
```

## 🔒 Sécurité

⚠️ **Note importante** : Ce projet est un prototype éducatif. Les mots de passe sont stockés en clair dans les fichiers texte. Pour une utilisation en production, il faudrait implémenter :

- Hachage des mots de passe (bcrypt, Argon2, etc.)
- Validation des entrées utilisateur
- Gestion d’erreurs plus robuste
- Chiffrement des données sensibles

## 📝 Formats des fichiers de données

### users.txt
Format CSV avec séparateur `;` :
```
id;nom;email;mot_de_passe;telephone
```

### rides.txt
Format CSV avec séparateur `;` :
```
id;driverId;nom_conducteur;origine;destination;date;heure;places_disponibles;prix
```

## 🤝 Contribuer

Les contributions sont les bienvenues ! N’hésitez pas à :
- Signaler des bugs
- Proposer de nouvelles fonctionnalités
- Améliorer la documentation
- Optimiser le code

## 📄 Licence

Ce projet est fourni tel quel à des fins éducatives.

## 👨‍💻 Auteur

Développé dans le cadre d’un projet universitaire en C++.
