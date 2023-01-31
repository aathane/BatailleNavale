#include <stdio.h>
#include "fonction.h"
#include <windows.h>

void fire_tactical(char tab_boat[10][11], char tab[10][11],boat_structure Boat1, boat_structure Boat2, boat_structure Boat3,boat_structure Boat4, boat_structure Boat5, char mode_de_jeu) {
    HANDLE  hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    int ligne, c, d;
    int colonne;

    // On demande où il veux tirer le missile

    printf("donnez les coordonn%ces\n ",130);
    printf("Ligne(A,B,C,...,J) : ");
    ligne = getchar();

    // verification avec message d'erreur

    while (ligne != 'A' && ligne != 'B' && ligne != 'C' && ligne != 'D' && ligne != 'E' && ligne != 'F' &&
           ligne != 'G' && ligne != 'H' && ligne != 'I' && ligne != 'J') {  // Acquisition avec message d'erreur
        fflush(stdin);//on vide le buffer
        SetConsoleTextAttribute(hConsole, 12); // On met la couleur rouge
        printf("Vous n\'avez pas choisie (A,B,C,...,J), Recommencez !\nLigne :");
        SetConsoleTextAttribute(hConsole, 15); // On remet la couleur normal

        ligne = getchar();
    }
    while ((c = getchar()) != '\n' && c != EOF); //on vide le buffer
    printf("Colonne(1,2,3,...,10)  :");

    scanf("%d", &colonne);
    while (colonne != 1 && colonne != 2 && colonne != 3 && colonne != 4 && colonne != 5 && colonne != 6 &&
           colonne != 7 && colonne != 8 && colonne != 9 && colonne != 10) {  // Acquisition avec message d'erreur
        fflush(stdin);//on vide le buffer
        SetConsoleTextAttribute(hConsole, 12); // On met la couleur rouge
        printf("Vous n\'avez pas choisie (1,2,3,...,10), Recommencez !\nColonne :");
        SetConsoleTextAttribute(hConsole, 15); // On remet la couleur normal
        scanf("%d", &colonne);
    }
    while ((d = getchar()) != '\n' && d != EOF); //on vide le buffer


    // On affiche l'entête ici uniquement pour blind ( celles des deux autres modes sont plus en bas)
    // Car tout au long de ce programe nous allons printf où le joueur a touché un bateau pour le mode blinf
    if (mode_de_jeu == '2') {
        for(int j = 0; j<=10; j++){
            printf("\n \n \n \n \n");
        }
        SetConsoleTextAttribute(hConsole, 13);
        printf("---------------------------------------------MODE BLIND-----------------------------------------------------------------\n\n");
    }
    SetConsoleTextAttribute(hConsole, 10);


    // On associe une lettre (ligne) avec un chiffre
    switch (ligne) {
        case 'A' :
            ligne = 0;
            break;
        case 'B' :
            ligne = 1;
            break;
        case 'C' :
            ligne = 2;
            break;
        case 'D' :
            ligne = 3;
            break;
        case 'E' :
            ligne = 4;
            break;
        case 'F' :
            ligne = 5;
            break;
        case 'G' :
            ligne = 6;
            break;
        case 'H' :
            ligne = 7;
            break;
        case 'I' :
            ligne = 8;
            break;
        case 'J' :
            ligne = 9;
            break;
    }


    if(tab_boat[ligne][colonne] == '+'){
        // Bateau 1
        if (Boat1.orientation == 'V') {
            for (int k = 0; k < Boat1.taille; k++) {
                if(Boat1.position_Ligne + k == ligne && Boat1.position_Colonne == colonne){
                    for (int i = 0; i < Boat1.taille; i++) {
                        tab_boat[Boat1.position_Ligne + i][Boat1.position_Colonne] = 'x';
                        tab[Boat1.position_Ligne + i][Boat1.position_Colonne] = 'x';
                        if(mode_de_jeu == '2'){
                            printf("Touch%c, coule, en: %c%d\n",130, 65 + Boat1.position_Ligne + i, Boat1.position_Colonne);
                        }
                    }
                }
            }
        }

        if (Boat1.orientation == 'H') {
            for (int l = 0; l < Boat1.taille; l++) {
                if(Boat1.position_Ligne == ligne && Boat1.position_Colonne + l == colonne){
                    for (int k = 0; k < Boat1.taille; k++) {
                        tab_boat[Boat1.position_Ligne ][Boat1.position_Colonne + k] = 'x';
                        tab[Boat1.position_Ligne ][Boat1.position_Colonne + k] = 'x';
                        if(mode_de_jeu == '2'){
                            printf("Touch%c, coule, en: %c%d\n",130, 65 + Boat1.position_Ligne, Boat1.position_Colonne + k);
                        }
                    }
                }
            }
        }
        // Bateau 2
        if (Boat2.orientation == 'V') {
            for (int k = 0; k < Boat2.taille; k++) {
                if(Boat2.position_Ligne + k == ligne && Boat2.position_Colonne == colonne){
                    for (int i = 0; i < Boat2.taille; i++) {
                        tab_boat[Boat2.position_Ligne + i][Boat2.position_Colonne] = 'x';
                        tab[Boat2.position_Ligne + i][Boat2.position_Colonne] = 'x';
                        if(mode_de_jeu == '2'){
                            printf("Touch%c, coule, en: %c%d\n",130, 65 + Boat2.position_Ligne + i, Boat2.position_Colonne);
                        }
                    }
                }
            }
        }

        if (Boat2.orientation == 'H') {
            for (int l = 0; l < Boat2.taille; l++) {
                if(Boat2.position_Ligne == ligne && Boat2.position_Colonne + l == colonne){
                    for (int k = 0; k < Boat2.taille; k++) {
                        tab_boat[Boat2.position_Ligne ][Boat2.position_Colonne + k] = 'x';
                        tab[Boat2.position_Ligne ][Boat2.position_Colonne + k] = 'x';
                        if(mode_de_jeu == '2'){
                            printf("Touch%c, coule, en: %c%d\n",130, 65 + Boat2.position_Ligne, Boat2.position_Colonne + k);
                        }
                    }
                }
            }
        }
        if (Boat3.orientation == 'V') {
            for (int k = 0; k < Boat3.taille; k++) {
                if(Boat3.position_Ligne + k == ligne && Boat3.position_Colonne == colonne){
                    for (int i = 0; i < Boat3.taille; i++) {
                        tab_boat[Boat3.position_Ligne + i][Boat3.position_Colonne] = 'x';
                        tab[Boat3.position_Ligne + i][Boat3.position_Colonne] = 'x';
                        if(mode_de_jeu == '2'){
                            printf("Touch%c, coule, en: %c%d\n",130, 65 + Boat3.position_Ligne + i, Boat3.position_Colonne);
                        }
                    }
                }
            }
        }

        if (Boat3.orientation == 'H') {
            for (int l = 0; l < Boat3.taille; l++) {
                if(Boat3.position_Ligne == ligne && Boat3.position_Colonne + l == colonne){
                    for (int k = 0; k < Boat3.taille; k++) {
                        tab_boat[Boat3.position_Ligne ][Boat3.position_Colonne + k] = 'x';
                        tab[Boat3.position_Ligne ][Boat3.position_Colonne + k] = 'x';
                        if(mode_de_jeu == '2'){
                            printf("Touch%c, coule, en: %c%d\n",130, 65 + Boat3.position_Ligne, Boat3.position_Colonne + k);
                        }
                    }
                }
            }
        }

        if (Boat4.orientation == 'V') {
            for (int k = 0; k < Boat4.taille; k++) {
                if(Boat4.position_Ligne + k == ligne && Boat4.position_Colonne == colonne){
                    for (int i = 0; i < Boat4.taille; i++) {
                        tab_boat[Boat4.position_Ligne + i][Boat4.position_Colonne] = 'x';
                        tab[Boat4.position_Ligne + i][Boat4.position_Colonne] = 'x';
                        if(mode_de_jeu == '2'){
                            printf("Touch%c, coule, en: %c%d\n",130, 65 + Boat4.position_Ligne + i, Boat4.position_Colonne);
                        }
                    }
                }
            }
        }

        if (Boat4.orientation == 'H') {
            for (int l = 0; l < Boat4.taille; l++) {
                if(Boat4.position_Ligne == ligne && Boat4.position_Colonne + l == colonne){
                    for (int k = 0; k < Boat4.taille; k++) {
                        tab_boat[Boat4.position_Ligne ][Boat4.position_Colonne + k] = 'x';
                        tab[Boat4.position_Ligne ][Boat4.position_Colonne + k] = 'x';
                        if(mode_de_jeu == '2'){
                            printf("Touch%c, coule, en: %c%d\n",130, 65 + Boat4.position_Ligne, Boat4.position_Colonne + k);
                        }
                    }
                }
            }
        }

        if (Boat5.orientation == 'V') {
            for (int k = 0; k < Boat5.taille; k++) {
                if(Boat5.position_Ligne + k == ligne && Boat5.position_Colonne == colonne){
                    for (int i = 0; i < Boat5.taille; i++) {
                        tab_boat[Boat5.position_Ligne + i][Boat5.position_Colonne] = 'x';
                        tab[Boat5.position_Ligne + i][Boat5.position_Colonne] = 'x';
                        if(mode_de_jeu == '2'){
                            printf("Touch%c, coule, en: %c%d\n",130, 65 + Boat5.position_Ligne + i, Boat5.position_Colonne);
                        }
                    }
                }
            }
        }

        if (Boat5.orientation == 'H') {
            for (int l = 0; l < Boat5.taille; l++) {
                if(Boat5.position_Ligne == ligne && Boat5.position_Colonne + l == colonne){
                    for (int k = 0; k < Boat5.taille; k++) {
                        tab_boat[Boat5.position_Ligne ][Boat5.position_Colonne + k] = 'x';
                        tab[Boat5.position_Ligne ][Boat5.position_Colonne + k] = 'x';
                        if(mode_de_jeu == '2'){
                            printf("Touch%c, coule, en: %c%d\n",130, 65 + Boat5.position_Ligne, Boat5.position_Colonne + k);
                        }
                    }
                }
            }
        }
    }else {
        if(tab_boat[ligne][colonne] == 'x'){
            tab[ligne][colonne] = 'x';
            tab_boat[ligne][colonne] = 'x';
        }else{
            tab[ligne][colonne] = 'O';
            tab_boat[ligne][colonne] = 'O';
        }
}


        // On affiche l'entête pour que se soit plus jolie
        if (mode_de_jeu == '1') {
            // On "efface" ce qu'il y a dans la console
            for(int j = 0; j<=10; j++){
                printf("\n \n \n \n \n");
            }
            SetConsoleTextAttribute(hConsole, 14);
            printf("---------------------------------------------MODE CLASSIQUE------------------------------------------------------------\n\n");
        }
        if (mode_de_jeu == '3') {
            // On "efface" ce qu'il y a dans la console
            for(int j = 0; j<=10; j++){
                printf("\n \n \n \n \n");
            }
            SetConsoleTextAttribute(hConsole, 10);
            printf("---------------------------------------------MODE ACTIVE----------------------------------------------------------------\n\n");
        }


    // en mode de jeu Blind la grille n'est pas affiché
    if (mode_de_jeu != '2') {
        show_grid(tab);
    }

    SetConsoleTextAttribute(hConsole, 15);
}