#include <iostream>
#include <limits>
#include "CarpoolSystem.h"

using namespace std;

// Fonction utilitaire pour nettoyer le buffer d'entrée
void clearInput() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void showHeader() {
    cout << "\n==========================================" << endl;
    cout << "   PLATEFORME DE COVOITURAGE UNIVERSITAIRE" << endl;
    cout << "==========================================" << endl;
}

int main() {
    CarpoolSystem system;
    int choice;

    while (true) {
        showHeader();
        if (system.getCurrentUser() == nullptr) {
            cout << "1. Se connecter" << endl;
            cout << "2. S'inscrire" << endl;
            cout << "3. Quitter" << endl;
            cout << "Choix: ";
            cin >> choice;

            if (cin.fail()) {
                clearInput();
                continue;
            }

            if (choice == 1) {
                string email, pass;
                cout << "Email: "; cin >> email;
                cout << "Mot de passe: "; cin >> pass;
                if (system.login(email, pass)) {
                    cout << ">> Connexion reussie ! Bonjour " << system.getCurrentUser()->name << "." << endl;
                } else {
                    cout << "!! Erreur : Email ou mot de passe incorrect." << endl;
                }
            } else if (choice == 2) {
                string name, email, pass, phone;
                cout << "Nom complet (sans espaces pour ce prototype): "; cin >> name;
                cout << "Email: "; cin >> email;
                cout << "Mot de passe: "; cin >> pass;
                cout << "Telephone: "; cin >> phone;
                if (system.registerUser(name, email, pass, phone)) {
                    cout << ">> Inscription reussie ! Vous pouvez vous connecter." << endl;
                } else {
                    cout << "!! Erreur : Cet email est deja utilise." << endl;
                }
            } else if (choice == 3) {
                break;
            }
        } else {
            // Menu Connecté
            cout << "Utilisateur: " << system.getCurrentUser()->name << endl;
            cout << "------------------------------------------" << endl;
            cout << "1. Chercher un trajet" << endl;
            cout << "2. Proposer un trajet (Conducteur)" << endl;
            cout << "3. Voir tous les trajets disponibles" << endl;
            cout << "4. Se deconnecter" << endl;
            cout << "Choix: ";
            cin >> choice;

            if (cin.fail()) {
                clearInput();
                continue;
            }

            if (choice == 1) {
                string from, to;
                cout << "Ville de depart: "; cin >> from;
                cout << "Ville d'arrivee: "; cin >> to;
                vector<Ride> results = system.searchRides(from, to);
                
                if (results.empty()) {
                    cout << "Aucun trajet trouve pour ce parcours." << endl;
                } else {
                    cout << "\n--- Trajets Trouves ---" << endl;
                    for (const auto& r : results) {
                        cout << "ID: " << r.id << " | " << r.date << " a " << r.time 
                             << " | Conducteur: " << r.driverName 
                             << " | Prix: " << r.price << " euros | Places: " << r.seatsAvailable << endl;
                    }
                    
                    cout << "\nEntrez l'ID du trajet pour reserver (ou 0 pour annuler): ";
                    int rideId;
                    cin >> rideId;
                    if (rideId != 0) {
                        if (system.bookRide(rideId)) {
                            cout << ">> Reservation confirmee !" << endl;
                        } else {
                            cout << "!! Echec de la reservation (Trajet complet ou ID invalide)." << endl;
                        }
                    }
                }

            } else if (choice == 2) {
                string from, to, date, time;
                int seats;
                double price;
                
                cout << "Depart: "; cin >> from;
                cout << "Arrivee: "; cin >> to;
                cout << "Date (JJ/MM/AAAA): "; cin >> date;
                cout << "Heure (HH:MM): "; cin >> time;
                cout << "Nombre de places: "; cin >> seats;
                cout << "Prix par personne: "; cin >> price;

                system.publishRide(from, to, date, time, seats, price);
                cout << ">> Trajet publie avec succes !" << endl;

            } else if (choice == 3) {
                 vector<Ride> allRides = system.getAllRides();
                 cout << "\n--- Tous les trajets ---" << endl;
                 for (const auto& r : allRides) {
                        cout << "ID: " << r.id << " | De " << r.origin << " a " << r.destination 
                             << " | " << r.date << " (" << r.time << ")"
                             << " | Places: " << r.seatsAvailable << endl;
                 }
            } else if (choice == 4) {
                system.logout();
                cout << ">> Deconnexion." << endl;
            }
        }
    }

    return 0;
}
