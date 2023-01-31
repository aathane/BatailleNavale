#include <time.h>
#include <stdlib.h>
#include "fonction.h"


void boat(boat_structure *boat, int numero_bateau) {
    int position_Ligne, position_Colonne, taille_boat1 = 5, taille_boat2 = 4, taille_boat3 = 3, taille_boat4 = 3, taille_boat5 = 2, taille;
    char orientation;

    srand(time(NULL));

    switch (numero_bateau) { // On associe la taille du bateau en fonction du bateau en question
        case 1 :
            taille = taille_boat1;
            break;
        case 2 :
            taille = taille_boat2;
            break;
        case 3 :
            taille = taille_boat3;
            break;
        case 4 :
            taille = taille_boat4;
            break;
        case 5 :
            taille = taille_boat5;
            break;
    }

    // On defini aléatoirement si l'orientation est verticale ou horizontale

    if ((rand() % 2) == 0) {
        orientation = 'V';
    } else {
        orientation = 'H';
    }
    // On fait en sorte que le bateau ne dépasse pas de la grille tout en étant positionné aléatoirement

    if (orientation == 'V') {
        position_Ligne = rand() % ((9 - taille + 1) + 1);
        position_Colonne = rand() % 10 + 1;
    }
    if (orientation == 'H') {
        position_Ligne = rand() % 10;
        position_Colonne = rand() % (10 - taille + 1) + 1;
    }

        //Enfin on retoure les valeurs du bateau à l'aide de pointeurs
        boat->orientation = orientation;
        boat->taille = taille;
        boat->position_Colonne = position_Colonne;
        boat->position_Ligne = position_Ligne;

}