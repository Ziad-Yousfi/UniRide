#ifndef MODELS_H
#define MODELS_H

#include <string>
#include <iostream>

using namespace std;

struct User {
    int id;
    string name;
    string email;
    string password; // En clair pour ce prototype (à hacher en prod)
    string phone;
    
    // Constructeur par défaut
    User() : id(0) {}

    User(int uid, string n, string e, string p, string ph) 
        : id(uid), name(n), email(e), password(p), phone(ph) {}
};

struct Ride {
    int id;
    int driverId;
    string driverName;
    string origin;
    string destination;
    string date; // Format JJ/MM/AAAA
    string time; // Format HH:MM
    int seatsAvailable;
    double price;

    Ride() : id(0), driverId(0), seatsAvailable(0), price(0.0) {}

    Ride(int rid, int did, string dname, string org, string dest, string d, string t, int seats, double pr)
        : id(rid), driverId(did), driverName(dname), origin(org), destination(dest), date(d), time(t), seatsAvailable(seats), price(pr) {}
};

#endif
