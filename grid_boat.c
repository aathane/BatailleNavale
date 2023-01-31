#include "fonction.h"
#include <windows.h>
#include <stdio.h>
void grid_boat(char tab_boat[10][11], boat_structure *Boat1, boat_structure *Boat2, boat_structure *Boat3,boat_structure *Boat4, boat_structure *Boat5) {


    boat_structure boat1;
    boat_structure boat2;
    boat_structure boat3;
    boat_structure boat4;
    boat_structure boat5;

    int superpose = 0;
    HANDLE  hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);


    // prend le bateau 1
    boat(&boat1,1);

    Boat1->taille = boat1.taille;
    Boat1->orientation = boat1.orientation;
    Boat1->position_Ligne = boat1.position_Ligne;
    Boat1->position_Colonne = boat1.position_Colonne;


    //créer la grille
    for (int i = 0; i <= 10; i++) {
        for (int j = 0; j <= 10; j++) {
            tab_boat[i][j] = '_';
        }
    }
    for (int i = 0; i <= 9; i++) {
        tab_boat[i][0] = 65 + i; // 65 en decimal correspond au caractère A dans le tableau ASCII
    }
    SetConsoleTextAttribute(hConsole, 7);
    printf(".");


    // affiche bateau 1
    if (boat1.orientation == 'V') {
        Boat1->orientation = 'V';

        for (int k = 0; k < boat1.taille; k++) {
            tab_boat[boat1.position_Ligne + k][boat1.position_Colonne] = '+';

        }
    }

    if (boat1.orientation == 'H') {
        for (int l = 0; l < boat1.taille; l++) {
            tab_boat[boat1.position_Ligne][boat1.position_Colonne + l] = '+';
        }
    }
    Sleep(1000); // On ralenti la boucle car il faut attendre que l'horloge interne de l'ordinateur change de valeur
                             // Sinon le chiffre donné par Rand() est le même

    // prendre le bateau 2
    do {
        superpose = 0;
        // 0 => ça ne se supperpose pas
        boat(&boat2, 2);

        Boat2->taille = boat2.taille;
        Boat2->orientation = boat2.orientation;
        Boat2->position_Ligne = boat2.position_Ligne;
        Boat2->position_Colonne = boat2.position_Colonne;

        for (int k = -1; k < boat2.taille + 1; k++) {
            for (int l = -1; l <= 1; l++) {

                if (boat2.orientation == 'V') {
                    if (tab_boat[boat2.position_Ligne + k][boat2.position_Colonne + l] == '+') {
                        superpose = 1;
                    }
                }

                if (boat2.orientation == 'H') {

                    if (tab_boat[boat2.position_Ligne + l][boat2.position_Colonne + k] == '+') {
                        superpose = 1;
                    }
                }
            }
        }



        Sleep(1000);
    } while (superpose == 1);

    SetConsoleTextAttribute(hConsole, 8);
    printf(".");

    // Affiche bateau 2

    if (boat2.orientation == 'V') {
        for (int k = 0; k < boat2.taille; k++) {
            tab_boat[boat2.position_Ligne + k][boat2.position_Colonne] = '+';
        }
    }

    if (boat2.orientation == 'H') {
        for (int l = 0; l < boat2.taille; l++) {
            tab_boat[boat2.position_Ligne][boat2.position_Colonne + l] = '+';
        }
    }

    //Prendre le bateau 3

    do { ;
        superpose = 0;
        // 0 => ça ne se supperpose pas

        boat(&boat3, 3);

        Boat3->taille = boat3.taille;
        Boat3->orientation = boat3.orientation;
        Boat3->position_Ligne = boat3.position_Ligne;
        Boat3->position_Colonne = boat3.position_Colonne;

        for (int k = -1; k < boat3.taille + 1; k++) {
            for (int l = -1; l <= 1; l++) {

                if (boat3.orientation == 'V') {
                    if (tab_boat[boat3.position_Ligne + k][boat3.position_Colonne + l] == '+') {
                        superpose = 1;
                    }
                }

                if (boat3.orientation == 'H') {

                    if (tab_boat[boat3.position_Ligne + l][boat3.position_Colonne + k] == '+') {
                        superpose = 1;
                    }
                }
            }
        }
        Sleep(1000);
    } while (superpose == 1);

    SetConsoleTextAttribute(hConsole, 9);
    printf(".");

    // Affiche bateau  3

    if (boat3.orientation == 'V') {
        for (int k = 0; k < boat3.taille; k++) {
            tab_boat[boat3.position_Ligne + k][boat3.position_Colonne] = '+';
        }
    }

    if (boat3.orientation == 'H') {
        for (int l = 0; l < boat3.taille; l++) {
            tab_boat[boat3.position_Ligne][boat3.position_Colonne + l] = '+';
        }
    }

    //Prendre le bateau 4

    do {
        superpose = 0;
        // 0 => ça ne se supperpose pas

        boat(&boat4, 4);

        Boat4->taille = boat4.taille;
        Boat4->orientation = boat4.orientation;
        Boat4->position_Ligne = boat4.position_Ligne;
        Boat4->position_Colonne = boat4.position_Colonne;

        for (int k = -1; k < boat4.taille + 1; k++) {
            for (int l = -1; l <= 1; l++) {

                if (boat4.orientation == 'V') {
                    if (tab_boat[boat4.position_Ligne + k][boat4.position_Colonne + l] == '+') {
                        superpose = 1;
                    }
                }

                if (boat4.orientation == 'H') {

                    if (tab_boat[boat4.position_Ligne + l][boat4.position_Colonne + k] == '+') {
                        superpose = 1;
                    }
                }
            }
        }
        Sleep(1000);
    } while (superpose == 1);

    SetConsoleTextAttribute(hConsole, 6);
    printf(".");

    // Affiche bateau  4

    if (boat4.orientation == 'V') {
        for (int k = 0; k < boat4.taille; k++) {
            tab_boat[boat4.position_Ligne + k][boat4.position_Colonne] = '+';
        }
    }

    if (boat4.orientation == 'H') {
        for (int l = 0; l < boat4.taille; l++) {
            tab_boat[boat4.position_Ligne][boat4.position_Colonne + l] = '+';
        }
    }

    //Prendre le bateau 5

    do {
        superpose = 0;
        // 0 => ça ne se supperpose pas

        boat(&boat5, 5);

        Boat5->taille = boat5.taille;
        Boat5->orientation = boat5.orientation;
        Boat5->position_Ligne = boat5.position_Ligne;
        Boat5->position_Colonne = boat5.position_Colonne;

        for (int k = -1; k < boat5.taille + 1; k++) {
            for (int l = -1; l <= 1; l++) {

                if (boat5.orientation == 'V') {
                    if (tab_boat[boat5.position_Ligne + k][boat5.position_Colonne + l] == '+') {
                        superpose = 1;
                    }
                }

                if (boat5.orientation == 'H') {

                    if (tab_boat[boat5.position_Ligne + l][boat5.position_Colonne + k] == '+') {
                        superpose = 1;
                    }
                }
            }
        }
        Sleep(1000);
    } while (superpose == 1);

    SetConsoleTextAttribute(hConsole, 5);
    printf(".");
    SetConsoleTextAttribute(hConsole, 15);
    // Affiche bateau  5

    if (boat5.orientation == 'V') {
        for (int k = 0; k < boat5.taille; k++) {
            tab_boat[boat5.position_Ligne + k][boat5.position_Colonne] = '+';
        }
    }

    if (boat5.orientation == 'H') {
        for (int l = 0; l < boat5.taille; l++) {
            tab_boat[boat5.position_Ligne][boat5.position_Colonne + l] = '+';
        }
    }
}