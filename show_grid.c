#include <stdio.h>
#include <windows.h>
#include "fonction.h"

void show_grid(char tab[10][11]) {
    HANDLE  hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    // Aficher la grille
    SetConsoleTextAttribute(hConsole, 16); // On met de la couleur !
    char chiffre[10];

    printf(" ");
    for (int i = 1; i < 11; ++i) {
        chiffre[i] = i;
        printf("   %d", i);
    }
    printf("  \n");

    for (int i = 0; i <= 9; i++) {
        for (int j = 0; j <= 10; j++) {
            if(tab[i][j] == 'x'){
                hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
                SetConsoleTextAttribute(hConsole, 28);
            }else {
                if (tab[i][j] == '_') {
                    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
                    SetConsoleTextAttribute(hConsole, 31);
                }
                else{
                    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
                    SetConsoleTextAttribute(hConsole, 16);
                }
            }
            printf("%c   ", tab[i][j]);
            if (j == 10) {
                printf("\n");
            }
        }
    }
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
SetConsoleTextAttribute(hConsole, 15);
}
