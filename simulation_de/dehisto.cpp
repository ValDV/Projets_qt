#include "dehisto.h"
#include <cstdlib>
#include <ctime>

Dehisto::Dehisto() : De(), index(0) {
    std::srand(std::time(nullptr)); // Initialisation pour les valeurs aléatoires
    for (int i = 0; i < 7; ++i) {
        tab[i] = 0;
    }
}

void Dehisto::jet() {
    int result = std::rand() % 6 + 1; // Génère un résultat entre 1 et 6
    tab[index % 7] = result;         // Stocke dans le tableau en mode circulaire
    index++;
}

void Dehisto::jet(int n) {
    for (int i = 0; i < n; ++i) {
        jet();
    }
}

int Dehisto::getValueAt(int i) {
    if (i >= 0 && i < 7) {
        return tab[i];
    }
    return 0; // Valeur par défaut si l'indice est invalide
}
