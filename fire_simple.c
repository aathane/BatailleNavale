#include <stdio.h>
#include "fonction.h"
#include <windows.h>

void fire_simple(char tab_boat[10][11], char tab[10][11], char mode_de_jeu) {
    HANDLE  hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    // en haut pour la couleur
    int ligne, c, d;
    int colonne;


    // On demande où il veux tirer le missile
    printf("donnez les coordonn%ces :\n ",130);
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


    if (tab_boat[ligne][colonne] == '+' || tab_boat[ligne][colonne] == 'x') {
        // si la coordonnée correspond à un bateau ( un '+')
        tab[ligne][colonne] = 'x'; // alors on modifie la grille pour indiquer au joueur qu'il a toucher un bateau
        tab_boat[ligne][colonne] = 'x'; // et on modifie la grille virtuel "tab_boat"
        if(mode_de_jeu == '2'){
            printf("Touch%c en: %c%d\n",130, 65 + ligne, colonne);
        }
    } else {
        tab[ligne][colonne] = 'O';
        tab_boat[ligne][colonne] = 'O';
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

