
#include <stdio.h>
#include "fonction.h"



void save(int artillerie, int bombes, int tactique, int simple, char mode, char tab_boat[10][11], boat_structure Boat1, boat_structure Boat2, boat_structure Boat3, boat_structure Boat4, boat_structure Boat5)
{
    FILE* fichier = NULL;

    fichier = fopen("save.txt", "w"); // ouverture du fichier

    if (fichier != NULL) // On vérifie si l'ouverture a réussi
    {
        // On lit et on écrit dans le fichier

        fprintf(fichier, "%d\n%d\n%d\n%d\n%c\n", artillerie, bombes, tactique, simple, mode);



        for (int i = 0; i <= 9; i++)
        {
            for (int j = 0; j <= 10; j++)
            {
                fprintf(fichier, "%c   ", tab_boat[i][j]);
                if (j == 10)
                {
                    fprintf(fichier , "\n");
                }
            }
        }


        fprintf(fichier, "%c\n%d\n%d\n%d\n", Boat1.orientation, Boat1.position_Colonne, Boat1.position_Ligne, Boat1.taille);
        fprintf(fichier, "%c\n%d\n%d\n%d\n", Boat2.orientation, Boat2.position_Colonne, Boat2.position_Ligne, Boat2.taille);
        fprintf(fichier, "%c\n%d\n%d\n%d\n", Boat3.orientation, Boat3.position_Colonne, Boat3.position_Ligne, Boat3.taille);
        fprintf(fichier, "%c\n%d\n%d\n%d\n", Boat4.orientation, Boat4.position_Colonne, Boat4.position_Ligne, Boat4.taille);
        fprintf(fichier, "%c\n%d\n%d\n%d\n", Boat5.orientation, Boat5.position_Colonne, Boat5.position_Ligne, Boat5.taille);



        fclose(fichier); // Fermeture du fichier
    }

    else
    {
        // On affiche un message d'erreur
        printf("Impossible d'ouvrir le fichier save.txt");
        fclose(fichier);
    }
}
