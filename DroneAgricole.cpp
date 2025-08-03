// ===== DroneAgricole.cpp =====
#include "DroneAgricole.h"
#include <iostream>
#include <random>
#include <iomanip>

// Initialisation des membres statiques
int DroneAgricole::humidite[5][5];
bool DroneAgricole::etatPlante[5][5];
bool DroneAgricole::champInitialise = false;

// Constructeur avec paramètres
DroneAgricole::DroneAgricole(std::string nom, int ligne) : nom(nom), ligneChoisie(ligne), x(0), y(ligne) {
    if (!champInitialise) {
        initialiserChamp();
    }
}

// Méthode statique pour initialiser le champ avec des valeurs aléatoires
void DroneAgricole::initialiserChamp() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> humidite_dist(0, 100);
    std::uniform_int_distribution<> plante_dist(0, 1);

    // Génération aléatoire de l'humidité (0-100)
    for (int i = 0; i < taille; i++) {
        for (int j = 0; j < taille; j++) {
            humidite[i][j] = humidite_dist(gen);
            etatPlante[i][j] = plante_dist(gen); // 0=malade, 1=saine
        }
    }
    champInitialise = true;
}

// Méthode pour déplacer le drone vers une nouvelle position
void DroneAgricole::deplacer(int i, int j) {
    if (i >= 0 && i < taille && j >= 0 && j < taille) {
        x = i;
        y = j;
    }
}

// Méthode pour analyser la case actuelle
void DroneAgricole::analyserCase() {
    std::cout << "Position (" << x << "," << y << ") - ";
    std::cout << "Humidité: " << humidite[x][y] << "% - ";
    std::cout << "Plante: " << (etatPlante[x][y] ? "Saine" : "Malade") << std::endl;
}

// Méthode pour compter le nombre total de plantes malades
int DroneAgricole::compterPlantesMalades() {
    int count = 0;
    for (int i = 0; i < taille; i++) {
        for (int j = 0; j < taille; j++) {
            if (!etatPlante[i][j]) { // false = malade
                count++;
            }
        }
    }
    return count;
}

// Méthode pour parcourir complètement la parcelle en boustrophédon (zigzag)
void DroneAgricole::parcourirParcelleCompleteBoustrophedon() {
    std::cout << "\n=== Parcours complet en boustrophédon ===" << std::endl;
    
    for (int ligne = 0; ligne < taille; ligne++) {
        if (ligne % 2 == 0) {
            // Lignes paires: gauche à droite
            for (int col = 0; col < taille; col++) {
                deplacer(ligne, col);
                analyserCase();
            }
        } else {
            // Lignes impaires: droite à gauche
            for (int col = taille - 1; col >= 0; col--) {
                deplacer(ligne, col);
                analyserCase();
            }
        }
    }
}

// Méthode pour parcourir une ligne en croisant (alternativement)
void DroneAgricole::parcourirLigneCroisee() {
    std::cout << "\n=== Parcours ligne croisée (ligne " << ligneChoisie << ") ===" << std::endl;
    
    int ligne = ligneChoisie;
    int colonne = 0;
    
    // Commencer par la ligne choisie et la ligne suivante (si elle existe)
    int ligneVoisine = (ligneChoisie + 1 < taille) ? ligneChoisie + 1 : ligneChoisie - 1;
    
    std::cout << "Séquence de parcours: ";
    for (int step = 0; step < taille; step++) {
        // Alterner entre la ligne principale et la ligne voisine
        if (step % 2 == 0) {
            deplacer(ligne, colonne);
            std::cout << "(" << ligne << "," << colonne << ") -> ";
        } else {
            deplacer(ligneVoisine, colonne);
            std::cout << "(" << ligneVoisine << "," << colonne << ") -> ";
            colonne++; // Avancer à la prochaine colonne après avoir visité les deux lignes
        }
    }
    std::cout << "FIN" << std::endl;
    
    // Afficher l'analyse de chaque position visitée
    colonne = 0;
    for (int step = 0; step < taille; step++) {
        if (step % 2 == 0) {
            deplacer(ligne, colonne);
            analyserCase();
        } else {
            deplacer(ligneVoisine, colonne);
            analyserCase();
            colonne++;
        }
    }
}

// Méthode pour afficher l'état du champ
void DroneAgricole::afficherChamp() {
    std::cout << "\n=== État du champ ===" << std::endl;
    std::cout << "Humidité du sol:" << std::endl;
    for (int i = 0; i < taille; i++) {
        for (int j = 0; j < taille; j++) {
            std::cout << std::setw(3) << humidite[i][j] << " ";
        }
        std::cout << std::endl;
    }
    
    std::cout << "\nÉtat des plantes (S=Saine, M=Malade):" << std::endl;
    for (int i = 0; i < taille; i++) {
        for (int j = 0; j < taille; j++) {
            std::cout << "  " << (etatPlante[i][j] ? 'S' : 'M') << " ";
        }
        std::cout << std::endl;
    }
}

// Getters
std::string DroneAgricole::getNom() const { return nom; }
int DroneAgricole::getX() const { return x; }
int DroneAgricole::getY() const { return y; }
int DroneAgricole::getLigneChoisie() const { return ligneChoisie; }
