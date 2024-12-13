#ifndef DEHISTO_H
#define DEHISTO_H

#include "de.h"

class Dehisto : public De {
    int tab[7]; // Tableau pour stocker les résultats des jets
    int index;  // Indice du prochain emplacement dans le tableau

public:
    Dehisto();               // Constructeur
    void jet();              // Simule un jet
    void jet(int n);         // Simule plusieurs jets
    int getValueAt(int i);   // Récupère une valeur du tableau
};

#endif // DEHISTO_H
