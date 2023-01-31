#include <stdio.h>
#include <stdlib.h>
#include "fonction.h"
#include <windows.h>


// retourne 0 si le bateau est détruit et 1 sinon

int is_alive(char tab_boat[10][11], boat_structure boat, int numero, int couleur) {
    int alive = 0;       // Boolean, 0 = détruit, 1 = en vie
    HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);


    if (boat.orientation == 'V') {
        for (int k = 0; k < boat.taille; k++) {
            if (tab_boat[boat.position_Ligne + k][boat.position_Colonne] == '+') {
                // si il reste une casse du bateau non toucher, le bateau est en vie
                alive = 1;
            }
        }
    }

    if (boat.orientation == 'H') {
        for (int l = 0; l < boat.taille; l++) {
            if (tab_boat[boat.position_Ligne][boat.position_Colonne + l] == '+') {
                // si il reste une casse du bateau non toucher, le bateau est en vie
                alive = 1;
            }
        }
    }


    if (couleur != 0) { // Si couleur == 0 cela signifie qu'il ne faut rien afficher
        if (alive == 0) {
            // On affiche au joueur si les bateaux ont été détruits
            SetConsoleTextAttribute(hConsole, couleur);
            printf("-Le bateau %d a %ct%c detruit\n", numero, 130, 130);
            SetConsoleTextAttribute(hConsole, 15); // On remet la couleur normal
        } else {
            printf("-\n"); // Pour la présentation
        }
    }

    return alive;
}