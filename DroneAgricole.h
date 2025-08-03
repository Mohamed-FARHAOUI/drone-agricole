// ===== DroneAgricole.h =====
#ifndef DRONEAGRICOLE_H
#define DRONEAGRICOLE_H

#include <string>

class DroneAgricole {
private:
    std::string nom;                    // Nom du drone
    int x, y;                          // Position actuelle du drone (x, y)
    int ligneChoisie;                  // Ligne principale que le drone doit parcourir
    static const int taille = 5;       // Taille fixe de la parcelle (grille 5x5)
    static int humidite[5][5];         // Matrice statique d'humidité du sol (0-100)
    static bool etatPlante[5][5];      // Matrice statique d'état des plantes (true=saine, false=malade)
    static bool champInitialise;       // Booléen statique pour vérifier si les données sont générées

public:
    // Constructeur avec paramètres
    DroneAgricole(std::string nom, int ligne);

    // Méthode statique pour initialiser le champ avec des valeurs aléatoires
    static void initialiserChamp();

    // Méthode pour déplacer le drone vers une nouvelle position
    void deplacer(int i, int j);

    // Méthode pour analyser la case actuelle
    void analyserCase();

    // Méthode pour compter le nombre total de plantes malades
    int compterPlantesMalades();

    // Méthode pour parcourir complètement la parcelle en boustrophédon (zigzag)
    void parcourirParcelleCompleteBoustrophedon();

    // Méthode pour parcourir une ligne en croisant (alternativement)
    void parcourirLigneCroisee();

    // Méthode pour afficher l'état du champ
    void afficherChamp();

    // Getters
    std::string getNom() const;
    int getX() const;
    int getY() const;
    int getLigneChoisie() const;
};

#endif // DRONEAGRICOLE_H
