// Augustin ATHANE Alexendre CHENIVESSE Mathis DUPEYRE
#include <stdio.h>
#include <stdlib.h>
#include "fonction.h"
#include <windows.h>

int main() {

        HANDLE  hConsole;
        hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

        char tab[10][11], menu, niveau, mode, tab_boat[10][11], fin;
        int artillerie, bombes, tactique, simple, c, g, e, h, v, type_missile, verif_missile, nb_missile, tous_les_bateaux_sont_detruit;
        int couleur;

        boat_structure Boat1;
        boat_structure Boat2;
        boat_structure Boat3;
        boat_structure Boat4;
        boat_structure Boat5;

        SetConsoleTextAttribute(hConsole, 12);

        printf("----------------------------------------------------MENU---------------------------------------------------------------\n\n");
        SetConsoleTextAttribute(hConsole, 15);
        printf("- D%cmarrer une nouvelle partie (tapez 1)\n- Charger une partie existante (tapez 2)\n- Quitter (tapez 3)\n",
               130);
        printf("choix :");
        menu = getchar();
        printf("\n");

        while (menu != '1' && menu != '2' && menu != '3') {  // Acquisition avec message d'erreur
            fflush(stdin);//on vide le buffer
            SetConsoleTextAttribute(hConsole, 12); // On met la couleur rouge
            printf("Vous n\'avez pas choisie (1, 2 ou 3), Recommencez !\n");
            printf("choix :");
            SetConsoleTextAttribute(hConsole, 15); // On remet la couleur normal
            menu = getchar();
            printf("\n");
        }
        while ((c = getchar()) != '\n' && c != EOF); //on vide le buffer

    if (menu == '2') {

        // charger une partie déja existante
        load(&artillerie, &bombes, &tactique, &simple, &mode, tab_boat, &Boat1, &Boat2, &Boat3, &Boat4, &Boat5);

        // On vérifie que la pertie sauvegardé n'est pas terminé
        if(is_alive(tab_boat, Boat1, 1, 0) == 0 && is_alive(tab_boat, Boat2, 2, 0) == 0 &&
           is_alive(tab_boat, Boat3, 3, 0) == 0 && is_alive(tab_boat, Boat4, 4, 0) == 0 &&
           is_alive(tab_boat, Boat5, 5, 0) == 0){
            menu = '1';
            printf("La partie charg%ce est d%cj%c termin%ce\nNouvelle partie d%cmarr%c\n\n",130, 130, 133, 130, 130, 130);
        }
        else{
            if(artillerie == 0 && simple == 0 && tactique == 0 && bombes == 0){
                menu = '1';
                printf("La partie charg%ce est d%cj%c termin%ce\nNouvelle partie d%cmarr%c\n\n",130, 130, 133, 130, 130, 130);
            }else{
                printf("Donn%ces charg%ces avec succ%cs !\n", 130, 130, 138);
                // Initialiser le Tab ( ce qui est afficher à l'utilisateur) en fonction du tableau virtuel
                grid(tab);
                for (int i = 0; i <= 9; i++) {
                    for (int j = 0; j <= 10; j++) {
                        if (tab_boat[i][j] == 'O') {
                            tab[i][j] = 'O';
                        }
                        if (tab_boat[i][j] == 'x') {
                            tab[i][j] = 'x';
                        }
                    }
                }
            }
        }

    }

        if (menu == '1' || menu == '2') {
            do {
                nb_missile = 1;
                tous_les_bateaux_sont_detruit = 1;
                if (menu == '1') {

                    printf("Quel est le niveau de difficult%c desir%c ?\n- Facile (tapez 1)\n- Moyen (tapez 2)\n- Difficile (tapez 3)\n",130, 130);
                    printf("choix :");
                    niveau = getchar();
                    printf("\n");


                    while (niveau != '1' && niveau != '2' && niveau != '3') {  // Acquisition avec message d'erreur
                        fflush(stdin);//on vide le buffer
                        SetConsoleTextAttribute(hConsole, 12); // On met la couleur rouge
                        printf("Vous n\'avez pas choisie (1, 2 ou 3), Recommencez !\n");
                        printf("choix :");
                        SetConsoleTextAttribute(hConsole, 15); // On remet la couleur normal
                        niveau = getchar();
                        printf("\n");

                    }
                    while ((g = getchar()) != '\n' && g != EOF); //on vide le buffer

                    inventory(&artillerie, &bombes, &tactique, &simple, niveau);

                    printf("Initialisation de la grille, veuillez patienter");
                    grid_boat(tab_boat, &Boat1, &Boat2, &Boat3, &Boat4, &Boat5);
                    grid(tab);
                    printf("\n\n");
                    printf("A quel mode de jeu voulez vous jouer ?\n- Classique (tapez 1)\n- Blind (tapez 2)\n- Active (tapez 3)\n");
                    printf("choix :");
                    mode = getchar();
                    printf("\n");


                    while (mode != '1' && mode != '2' && mode != '3') {  // Acquisition avec message d'erreur
                        fflush(stdin);//on vide le buffer
                        SetConsoleTextAttribute(hConsole, 12); // On met la couleur rouge
                        printf("Vous n\'avez pas choisie (1, 2 ou 3), Recommencez !\n");
                        printf("choix :");
                        SetConsoleTextAttribute(hConsole, 15); // On remet la couleur normal
                        mode = getchar();
                        printf("\n");

                    }
                    while ((e = getchar()) != '\n' && e != EOF); //on vide le buffer
                }

                // On "efface" ce qu'il y a dans la console
                for(int j = 0; j<=10; j++){
                    printf("\n \n \n \n \n");
                }

                        if (mode == '1') {
                            SetConsoleTextAttribute(hConsole, 14);
                            printf("---------------------------------------------MODE CLASSIQUE------------------------------------------------------------\n\n");
                            show_grid(tab);
                            // Pour la présentation ( les bateaux coulés serons affichés à la place des '-'
                            SetConsoleTextAttribute(hConsole, 15);
                            printf("-\n");
                            printf("-\n");
                            printf("-\n");
                            printf("-\n");
                            printf("-\n");
                            couleur = 14; // Petit ajout pour faire jolie =), on annoncera que les bateaux on été détruit de la même couleur que l'entête

                        }
                        if (mode == '2') {
                            SetConsoleTextAttribute(hConsole, 13);
                            printf("---------------------------------------------MODE BLIND-----------------------------------------------------------------\n\n");
                            printf("\n");
                            couleur = 13;
                        }
                        if (mode == '3') {
                            SetConsoleTextAttribute(hConsole, 10);
                            printf("---------------------------------------------MODE ACTIVE----------------------------------------------------------------\n\n");
                            show_grid(tab);
                            // Pour la présentation ( les bateaux coulés serons affichés à la place des '-'
                            SetConsoleTextAttribute(hConsole, 15);
                            printf("-\n");
                            printf("-\n");
                            printf("-\n");
                            printf("-\n");
                            printf("-\n");
                            couleur = 10;
                        }
                        do { // Boucle principal du jeux
                            SetConsoleTextAttribute(hConsole, 15);
                            printf("Quel missile voulez-vous tirer ?\n\n");
                            printf("Nombre de missiles simples : %d         (tapez 1)\n", simple);
                            printf("Nombre de missiles tactiques : %d       (tapez 2)\n", tactique);
                            printf("Nombre de bombes : %d                   (tapez 3)\n", bombes);
                            printf("Nombre de missiles d\'artilleries : %d  (tapez 4)\n", artillerie);
                            printf("Si vous voulez quitter et sauvegarder   (tapez 5)\n");
                            printf("Si vous voulez quitter sans sauvegarder (tapez 6)\n");
                            printf("choix :");

                            do {
                                verif_missile = 0;
                                type_missile = getchar();
                                printf("\n");


                                while (type_missile != '1' && type_missile != '2' && type_missile != '3' &&
                                       type_missile != '4' && type_missile != '5' && type_missile != '6') {
                                    // Ici on vérifie que le joueur demande un missile existant
                                    fflush(stdin);//on vide le buffer
                                    SetConsoleTextAttribute(hConsole, 12); // On met la couleur rouge
                                    printf("Vous n\'avez pas choisie (1,2,3,4,5 ou 6), Recommencez !\n");
                                    printf("choix :");
                                    SetConsoleTextAttribute(hConsole, 15); // On remet la couleur normal
                                    type_missile = getchar();
                                }


                                if (type_missile == '1') {
                                    if (simple == 0) {
                                        verif_missile = 1;
                                        printf("Vous n\'avez plus de missile simple. Recommencez !\n");
                                    }
                                }

                                if (type_missile == '2') {
                                    if (tactique == 0) {
                                        verif_missile = 1;
                                        printf("Vous n\'avez plus de missile tactique. Recommencez !\n");
                                    }
                                }

                                if (type_missile == '3') {
                                    if (bombes == 0) {
                                        verif_missile = 1;
                                        printf("Vous n\'avez plus de bombe. Recommencez !\n");
                                    }
                                }

                                if (type_missile == '4') {
                                    if (artillerie == 0) {
                                        verif_missile = 1;
                                        printf("Vous n\'avez plus de missile d\'artillerie. Recommencez !\n");
                                    }
                                }

                                if (type_missile == '5') {
                                    // !! ON VAS ECRIRE LES SAUVEGARDES ICI

                                    save(artillerie, bombes, tactique, simple, mode, tab_boat, Boat1, Boat2, Boat3, Boat4, Boat5);
                                    printf("Donnes sauvegardes avec succes !");
                                    exit(EXIT_SUCCESS);
                                }
                                if (type_missile == '6') {

                                    exit(EXIT_SUCCESS);
                                }

                            } while (verif_missile == 1);


                            while ((h = getchar()) != '\n' && h != EOF); //on vide le buffer

                            switch (type_missile) {
                                case '1' :
                                    fire_simple(tab_boat, tab, mode);
                                    simple = simple - 1;
                                    break;
                                case '2' :
                                    fire_tactical(tab_boat, tab, Boat1, Boat2, Boat3, Boat4, Boat5, mode);
                                    tactique = tactique - 1;
                                    break;
                                case '3' :
                                    fire_bomb(tab_boat, tab, mode);
                                    bombes = bombes - 1;
                                    break;
                                case '4' :
                                    fire_artillery(tab_boat, tab, mode);
                                    artillerie = artillerie - 1;
                                    break;

                            }
                            // Ici on annonce au jouer qu'il a déruit un bateau
                            is_alive(tab_boat, Boat1, 1, couleur);
                            is_alive(tab_boat, Boat2, 2, couleur);
                            is_alive(tab_boat, Boat3, 3, couleur);
                            is_alive(tab_boat, Boat4, 4, couleur);
                            is_alive(tab_boat, Boat5, 5, couleur);


                            if (artillerie == 0 && simple == 0 && tactique == 0 && bombes == 0) {
                                nb_missile = 0;
                                SetConsoleTextAttribute(hConsole, 12);
                                printf("Vous n\'avez plus de missiles \nVous avez perdu\n\n\n");
                                SetConsoleTextAttribute(hConsole, 15); // On remet la couleur normal
                            }

                            if (is_alive(tab_boat, Boat1,1, 0) == 0 && is_alive(tab_boat, Boat2, 2, 0) == 0 &&
                                is_alive(tab_boat, Boat3, 3, 0) == 0 && is_alive(tab_boat, Boat4, 4, 0) == 0 &&
                                is_alive(tab_boat, Boat5, 5, 0) == 0) {
                                tous_les_bateaux_sont_detruit = 0;
                                SetConsoleTextAttribute(hConsole, 10);
                                printf("Tous les bateaux sont detruit ! \nVous avez gagn%c !\n\n\n", 130);
                                SetConsoleTextAttribute(hConsole, 15);
                            }

                            if(mode == '3' && tous_les_bateaux_sont_detruit == 1 && nb_missile == 1) { // Ne se lance pas si la partie est finie
                                mode_active(tab_boat, &Boat1, &Boat2, &Boat3, &Boat4, &Boat5);
                            }

                        } while (nb_missile == 1 && tous_les_bateaux_sont_detruit == 1);
                        // SOIT ON QUITTE ET ON SAUVEGARDE, SOIT ON QUITTE SANS SAUVEGARDER,SOIT TOUS LES BATEAUX SONT DETRUITS, SOIT YA PLUS DE MISSILES


                printf("La partie est termin%c\n\n", 130);
                printf("SI vous voulez rejouer ? (tapez 1)\nSi vous voulez quitter (tapez 2)");
                printf("choix :");
                fin = getchar();

                while (fin != '1' && fin != '2') {
                    fflush(stdin);//on vide le buffer
                    SetConsoleTextAttribute(hConsole, 12); // On met la couleur rouge
                    printf("Vous n\'avez pas choisie (1 ou 2), Recommencez !\n");
                    printf("choix :");
                    SetConsoleTextAttribute(hConsole, 15); // On remet la couleur normal
                    fin = getchar();
                }
                while ((v = getchar()) != '\n' && v != EOF); //on vide le buffer


                if(fin == '1'){
                    SetConsoleTextAttribute(hConsole, 12);
                    menu = '1'; // Si menu = '2' la grille ne se relancera pas
                    // On "efface" ce qu'il y a dans la console
                    for(int j = 0; j<=10; j++){
                        printf("\n \n \n \n \n");
                    }
                    printf("----------------------------------------------------MENU---------------------------------------------------------------\n\n");
                    SetConsoleTextAttribute(hConsole, 15);
                }

                }while (fin == '1');
            }


        if (menu == '3') {
            system("exit");
        }

        return 0;
}