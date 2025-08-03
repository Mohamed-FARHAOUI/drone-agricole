// ===== main.cpp =====
#include "DroneAgricole.h"
#include <iostream>

int main() {
    std::cout << "=== Test du Drone Agricole ===" << std::endl;
    
    // a. Demander à l'utilisateur de saisir un entier ligne compris entre 0 et 3
    int ligne;
    do {
        std::cout << "Entrez la ligne principale que le drone devra surveiller (0-3): ";
        std::cin >> ligne;
    } while (ligne < 0 || ligne > 3);
    
    // b. Créer dynamiquement un objet DroneAgricole nommé drone
    DroneAgricole* drone = new DroneAgricole("Alpha", ligne);
    
    // Afficher l'état initial du champ
    drone->afficherChamp();
    
    // c. Appeler la méthode parcourirLigneCroisee()
    drone->parcourirLigneCroisee();
    
    // d. Appeler la méthode parcourirParcelleCompleteBoustrophedon()
    drone->parcourirParcelleCompleteBoustrophedon();
    
    // e. Appeler la méthode compterPlantesMalades()
    int plantesMalades = drone->compterPlantesMalades();
    std::cout << "\n=== Résultat final ===" << std::endl;
    std::cout << "Nombre total de plantes malades dans la parcelle: " << plantesMalades << std::endl;
    
    // f. Libérer l'objet drone
    delete drone;
    
    return 0;
}
