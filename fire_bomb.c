#include "fonction.h"
#include <stdio.h>
#include <windows.h>

void fire_bomb(char tab_boat[10][11], char tab[10][11], char mode_de_jeu) {
    HANDLE  hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    int ligne, c, d;
    int colonne;


    // On demande où il veux tirer la bombe
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

    /* Ici on s'occupe de la bombe, tout dabord la "croix" de la bombe:
     *          |
     *          |
     *      _ _ _ _ _
     *          |
     *          |
     * */
    for (int e = -2; e <= 2; e++) {
        if ((colonne + e) > 0 && (colonne + e) <= 10) {  // On vérifie que la coordonne colonne ne dépasse pas

            if (tab_boat[ligne][colonne + e] == '+' || tab[ligne][colonne + e] == 'x') {
                // si la coordonnée correspond à un bateau ( un '+')
                tab[ligne][colonne +
                           e] = 'x'; // alors on modifie la grille pour indiquer au joueur qu'il a toucher un bateau
                tab_boat[ligne][colonne + e] = 'x'; // et on modifie la grille virtuel "tab_boat"
                if(mode_de_jeu == '2'){
                    printf("Touch%c en: %c%d\n",130, 65 + ligne, colonne + e);
                }
            } else {
                tab[ligne][colonne + e] = 'O'; // De même si la coordonnée ne correspond pas à un bateau
                tab_boat[ligne][colonne + e] = 'O';
            }
        }
        if ((ligne + e) >= 0 && (ligne + e) <= 9) { // On vérifie que la coordonne ligne ne dépasse pas
            if (tab_boat[ligne + e][colonne] == '+' ||
                tab[ligne + e][colonne] == 'x') { // Et on recommance horizontalement
                tab[ligne + e][colonne] = 'x';
                tab_boat[ligne + e][colonne] = 'x';
                if(mode_de_jeu == '2' && e!= 0){
                    printf("Touch%c en: %c%d\n",130, 65 + ligne + e, colonne);
                }
            } else {
                tab[ligne + e][colonne] = 'O';
                tab_boat[ligne + e][colonne] = 'O';
            }
        }
    }
    /* Maintenant on s'occupe du "carré" de la bombe:
     *
     *        -     -
     *
     *        -     -
     *
     *   On prosède de la même manière que pour la "croix" de la bombe.
     * */
    for (int l = -1; l <= 1; l++) {
        if ((ligne + l) >= 0 && (colonne - l) > 0 && (ligne + l) <= 9 && (colonne - l) <= 10) {

            if (tab_boat[ligne + l][colonne - l] == '+' || tab[ligne + l][colonne - l] == 'x') {
                tab[ligne + l][colonne - l] = 'x';
                tab_boat[ligne + l][colonne - l] = 'x';
                if(mode_de_jeu == '2' && l != 0){
                    printf("Touch%c en: %c%d\n",130, 65 + ligne + l, colonne - l);
                }
            } else {
                tab[ligne + l][colonne - l] = 'O';
                tab_boat[ligne + l][colonne - l] = 'O';
            }
        }
        if ((ligne + l) >= 0 && (colonne + l) > 0 && (ligne + l) <= 9 && (colonne + l) <= 10) {

            if (tab_boat[ligne + l][colonne + l] == '+' || tab[ligne + l][colonne + l] == 'x') {
                tab[ligne + l][colonne + l] = 'x';
                tab_boat[ligne + l][colonne + l] = 'x';
                if(mode_de_jeu == '2' && l !=0){
                    printf("Touch%c en: %c%d\n",130, 65 + ligne + l, colonne  + l);
                }
            } else {
                tab[ligne + l][colonne + l] = 'O';
                tab_boat[ligne + l][colonne + l] = 'O';
            }
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
        // Aficher la grille
        show_grid(tab);
    }

    SetConsoleTextAttribute(hConsole, 15);
}




