#ifndef CARPOOLSYSTEM_H
#define CARPOOLSYSTEM_H

#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>
#include "Models.h"

class CarpoolSystem {
private:
    vector<User> users;
    vector<Ride> rides;
    int nextUserId = 1;
    int nextRideId = 1;
    User* currentUser = nullptr;

    const string USERS_FILE = "users.txt";
    const string RIDES_FILE = "rides.txt";

    // Utilitaires pour séparer les chaines par point-virgule
    vector<string> split(const string& s, char delimiter) {
        vector<string> tokens;
        string token;
        istringstream tokenStream(s);
        while (getline(tokenStream, token, delimiter)) {
            tokens.push_back(token);
        }
        return tokens;
    }

public:
    CarpoolSystem() {
        loadData();
    }

    ~CarpoolSystem() {
        saveData();
    }

    // --- Authentification ---

    bool registerUser(string name, string email, string password, string phone) {
        for (const auto& u : users) {
            if (u.email == email) return false; // Email existe déjà
        }
        users.emplace_back(nextUserId++, name, email, password, phone);
        saveData();
        return true;
    }

    bool login(string email, string password) {
        for (auto& u : users) {
            if (u.email == email && u.password == password) {
                currentUser = &u;
                return true;
            }
        }
        return false;
    }

    void logout() {
        currentUser = nullptr;
    }

    User* getCurrentUser() {
        return currentUser;
    }

    // --- Gestion des Trajets ---

    void publishRide(string origin, string destination, string date, string time, int seats, double price) {
        if (!currentUser) return;
        rides.emplace_back(nextRideId++, currentUser->id, currentUser->name, origin, destination, date, time, seats, price);
        saveData();
    }

    vector<Ride> searchRides(string origin, string destination) {
        vector<Ride> results;
        for (const auto& r : rides) {
            // Recherche simple (insensible à la casse peut être ajoutée plus tard)
            if (r.origin == origin && r.destination == destination && r.seatsAvailable > 0) {
                results.push_back(r);
            }
        }
        return results;
    }

    vector<Ride> getAllRides() {
        return rides;
    }

    bool bookRide(int rideId) {
        for (auto& r : rides) {
            if (r.id == rideId) {
                if (r.seatsAvailable > 0) {
                    r.seatsAvailable--;
                    saveData();
                    return true;
                }
                return false; // Plus de place
            }
        }
        return false; // Trajet non trouvé
    }

    // --- Persistance des Données ---

    void saveData() {
        ofstream userFile(USERS_FILE);
        if (userFile.is_open()) {
            for (const auto& u : users) {
                userFile << u.id << ";" << u.name << ";" << u.email << ";" << u.password << ";" << u.phone << "\n";
            }
            userFile.close();
        }

        ofstream rideFile(RIDES_FILE);
        if (rideFile.is_open()) {
            for (const auto& r : rides) {
                rideFile << r.id << ";" << r.driverId << ";" << r.driverName << ";" << r.origin << ";" 
                         << r.destination << ";" << r.date << ";" << r.time << ";" << r.seatsAvailable << ";" << r.price << "\n";
            }
            rideFile.close();
        }
    }

    void loadData() {
        users.clear();
        rides.clear();
        nextUserId = 1;
        nextRideId = 1;

        ifstream userFile(USERS_FILE);
        string line;
        if (userFile.is_open()) {
            while (getline(userFile, line)) {
                vector<string> data = split(line, ';');
                if (data.size() == 5) {
                    User u(stoi(data[0]), data[1], data[2], data[3], data[4]);
                    users.push_back(u);
                    if (u.id >= nextUserId) nextUserId = u.id + 1;
                }
            }
            userFile.close();
        }

        ifstream rideFile(RIDES_FILE);
        if (rideFile.is_open()) {
            while (getline(rideFile, line)) {
                vector<string> data = split(line, ';');
                if (data.size() == 9) {
                    Ride r(stoi(data[0]), stoi(data[1]), data[2], data[3], data[4], data[5], data[6], stoi(data[7]), stod(data[8]));
                    rides.push_back(r);
                    if (r.id >= nextRideId) nextRideId = r.id + 1;
                }
            }
            rideFile.close();
        }
    }
};

#endif
