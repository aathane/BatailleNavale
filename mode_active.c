#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "fonction.h"
#include <windows.h>

void mode_active(char tab_boat[10][11], boat_structure *Boat1, boat_structure *Boat2, boat_structure *Boat3, boat_structure *Boat4, boat_structure *Boat5) {
    int deplacement_ou_pas, quel_bateau, direction, nb_case_deplacement_ligne, nb_case_deplacement_colonne, superpose, en_dehors;
    int refaire;
    char touche[5] = {'_', '_', '_', '_', '_'};

    // On commence par choisir aleatoirement si un bateau va se deplacer ou non.
    srand(time(NULL));
    deplacement_ou_pas = rand() % 2;
    //Si le bateau ne se supperpose avec aucun bateau, on peut déplacer le bateau !

    // Si l'ordinateur a choisit de déplacer un bateau
    if (deplacement_ou_pas == 1) {
        // On choisit aléatoirement lequel des 5 bateaux vas se déplacer. En vérifiant que ce bateau n'est pas coulé.
        do {
            quel_bateau = rand() % (5) + 1;

            switch (quel_bateau) {
                case 1 :
                    refaire = is_alive(tab_boat, *Boat1, 1, 0);
                    break;
                case 2 :
                    refaire = is_alive(tab_boat, *Boat2, 2, 0);
                    break;
                case 3 :
                    refaire = is_alive(tab_boat, *Boat3, 3, 0);
                    break;
                case 4 :
                    refaire = is_alive(tab_boat, *Boat4, 4, 0);
                    break;
                case 5 :
                    refaire = is_alive(tab_boat, *Boat5, 5, 0);
                    break;

            }
        } while (refaire == 0);


        // Alors on entre dans une boucle qui se répète tant que le bateau ne se déplace pas correctement. (Ne sort pas de la grille et ne se superpose pas)
        do {
            srand(time(NULL));
            direction = rand() % 2;  // On défini aleatoirement la direction, c'est à dire si le bateau vas se déplacer verticalement ou horizontalement. 0 = ligne et 1 = colonne
            superpose = 0; // On initialise superpose à 0, la valeur passera à 1 si le bateau se superpose avec un autre.
            en_dehors = 0; // On initialise en_dehors à 0, la valeur passera à 1 si le bateau sort de la grille.

            // Ici on définit de combien de casses le bateau vas se déplacer.
            if (direction == 0) { // deplacement sur ligne
                do {
                    nb_case_deplacement_ligne = rand() % (7) - 3;
                } while (nb_case_deplacement_ligne == 0); // Le bateau ne peut pas se déplacer de 0 cases car il doit se déplacer
                nb_case_deplacement_colonne = 0; // Comme le bateau se déplace verticalement (sur les lignes), son déplacement sur les colonnes est nul
            } else { //deplacement sur colonne
                do {
                    nb_case_deplacement_colonne = rand() % (7) - 3;
                } while (nb_case_deplacement_colonne == 0); // Le bateau ne peut pas se déplacer de 0 cases car il doit se déplacer
                nb_case_deplacement_ligne = 0; // Comme le bateau se déplace horizontalement (sur les colonnes), son déplacement sur les lignes est nul
            }
            printf("%d %d", nb_case_deplacement_colonne, nb_case_deplacement_ligne);
            // Si le bateau déplacer est le bateau 1
            if (quel_bateau == 1) {

                // Si le bateau est vertical
                if (Boat1->orientation == 'V') {
                    // Alors on commence par vérifier si le bateau sort de la grille ou non
                    if (Boat1->position_Ligne + nb_case_deplacement_ligne + Boat1->taille >= 10 ||
                        Boat1->position_Ligne + nb_case_deplacement_ligne < 0 ||
                        Boat1->position_Colonne + nb_case_deplacement_colonne <= 0 ||
                        Boat1->position_Colonne + nb_case_deplacement_colonne >= 10) {
                        en_dehors = 1;
                    } else {

                        // Si il ne sort pas, on enleve les '+' et les 'x' du bateau1 de grid_boat pour eviter que le bateau se confonde avec lui même.
                        for (int k = 0; k < Boat1->taille; k++) {
                            if (tab_boat[Boat1->position_Ligne + k][Boat1->position_Colonne] ==
                                '+') {
                                tab_boat[Boat1->position_Ligne + k][Boat1->position_Colonne] = '_';
                            }
                            if (tab_boat[Boat1->position_Ligne + k][Boat1->position_Colonne] ==
                                'x') { // on garde en mémoire où le bateau a déjà été toucher
                                tab_boat[Boat1->position_Ligne + k][Boat1->position_Colonne] = '_';
                                touche[k] = 'C';
                            }
                        }

                        // Maintenant on vérifie que le bateau ne se supperpose pas avec un autre. Si c'est le cas la boucle "do" se
                        // relancera et le sens et le nombre de casse de déplacement sera re tiré au hasard
                        for (int l = 0; l < Boat1->taille; l++) {
                            if (tab_boat[Boat1->position_Ligne + l + nb_case_deplacement_ligne][Boat1->position_Colonne + nb_case_deplacement_colonne] == '+'|| tab_boat[Boat1->position_Ligne + l + nb_case_deplacement_ligne][Boat1->position_Colonne + nb_case_deplacement_colonne] == 'x') {
                                superpose = 1;
                            }
                        }

                        //Si le bateau ne se supperpose avec aucun bateau, on peut déplacer le bateau !
                        if (superpose == 0) {
                            for (int m = 0; m < Boat1->taille; m++) {
                                if (touche[m]== '_') { // On regarde où le bateau a été touché
                                    tab_boat[Boat1->position_Ligne + m + nb_case_deplacement_ligne][
                                            Boat1->position_Colonne + nb_case_deplacement_colonne] = '+';
                                }
                                else{
                                    tab_boat[Boat1->position_Ligne + m + nb_case_deplacement_ligne][
                                            Boat1->position_Colonne + nb_case_deplacement_colonne] = 'x';
                                }
                            }
                            // Et pour finir on met à jour les nouvelles coordonnées du bateau.
                            Boat1->position_Ligne += nb_case_deplacement_ligne;
                            Boat1->position_Colonne += nb_case_deplacement_colonne;
                        }
                    }
                }

                // Si le bateau est horizontal, on procède de la même manière en prenant en compte l'orientation vertical et non horizontal du bateau.
                if (Boat1->orientation == 'H') {
                    if (Boat1->position_Ligne + nb_case_deplacement_ligne >= 10 ||
                        Boat1->position_Ligne + nb_case_deplacement_ligne < 0 ||
                        Boat1->position_Colonne + nb_case_deplacement_colonne <= 0 ||
                        Boat1->position_Colonne + nb_case_deplacement_colonne + Boat1->taille >= 10) {
                        en_dehors = 1;
                    } else {
                        for (int k = 0; k < Boat1->taille; k++) {
                            if (tab_boat[Boat1->position_Ligne][Boat1->position_Colonne + k] =='+') {
                                tab_boat[Boat1->position_Ligne][Boat1->position_Colonne + k] = '_';
                            }
                            if (tab_boat[Boat1->position_Ligne][Boat1->position_Colonne + k] =='x') {
                                tab_boat[Boat1->position_Ligne][Boat1->position_Colonne + k] = '_';
                                touche[k] = 'C';
                            }
                        }

                        for (int l = 0; l < Boat1->taille; l++) {
                            if (tab_boat[Boat1->position_Ligne + nb_case_deplacement_ligne][Boat1->position_Colonne + l + nb_case_deplacement_colonne] == '+' || tab_boat[Boat1->position_Ligne + nb_case_deplacement_ligne][Boat1->position_Colonne + l + nb_case_deplacement_colonne] == 'x') {
                                superpose = 1;
                            }
                        }

                        if (superpose == 0) {
                            for (int m = 0; m < Boat1->taille; m++) {
                                if (touche[m]== '_') {
                                    tab_boat[Boat1->position_Ligne + nb_case_deplacement_ligne][
                                            Boat1->position_Colonne + m + nb_case_deplacement_colonne] = '+';
                                }
                                else{
                                    tab_boat[Boat1->position_Ligne + nb_case_deplacement_ligne][
                                            Boat1->position_Colonne + m + nb_case_deplacement_colonne] = 'x';
                                }
                            }
                            Boat1->position_Ligne += nb_case_deplacement_ligne;
                            Boat1->position_Colonne += nb_case_deplacement_colonne;
                        }
                    }
                }
            }

            // On prosède de la même manière pour le bateau 2
            if (quel_bateau == 2) {
                if (Boat2->orientation == 'V') {
                    if (Boat2->position_Ligne + nb_case_deplacement_ligne + Boat2->taille >= 10 ||
                        Boat2->position_Ligne + nb_case_deplacement_ligne < 0 ||
                        Boat2->position_Colonne + nb_case_deplacement_colonne <= 0 ||
                        Boat2->position_Colonne + nb_case_deplacement_colonne >= 10) {
                        en_dehors = 1;
                    } else {
                        for (int k = 0; k < Boat2->taille; k++) {
                            if (tab_boat[Boat2->position_Ligne + k][Boat2->position_Colonne] =='+') {
                                tab_boat[Boat2->position_Ligne + k][Boat2->position_Colonne] = '_';
                            }
                            if (tab_boat[Boat2->position_Ligne + k][Boat2->position_Colonne] =='x') {
                                tab_boat[Boat2->position_Ligne + k][Boat2->position_Colonne] = '_';
                                touche[k] = 'C';
                            }
                        }


                        for (int l = 0; l < Boat2->taille; l++) {
                            if (tab_boat[Boat2->position_Ligne + l + nb_case_deplacement_ligne][Boat2->position_Colonne + nb_case_deplacement_colonne] == '+'|| tab_boat[Boat2->position_Ligne + l + nb_case_deplacement_ligne][Boat2->position_Colonne + nb_case_deplacement_colonne] == 'x') {
                                superpose = 1;
                            }
                        }


                        if (superpose == 0) {
                            for (int m = 0; m < Boat2->taille; m++) {

                                if (touche[m]== '_') {
                                    tab_boat[Boat2->position_Ligne + m + nb_case_deplacement_ligne][
                                            Boat2->position_Colonne + nb_case_deplacement_colonne] = '+';
                                }
                                else{
                                    tab_boat[Boat2->position_Ligne + m + nb_case_deplacement_ligne][
                                            Boat2->position_Colonne + nb_case_deplacement_colonne] = 'x';
                                }
                            }
                            Boat2->position_Ligne += nb_case_deplacement_ligne;
                            Boat2->position_Colonne += nb_case_deplacement_colonne;
                        }
                    }
                }


                if (Boat2->orientation == 'H') {
                    if (Boat2->position_Ligne + nb_case_deplacement_ligne >= 10 ||
                        Boat2->position_Ligne + nb_case_deplacement_ligne < 0 ||
                        Boat2->position_Colonne + nb_case_deplacement_colonne <= 0 ||
                        Boat2->position_Colonne + nb_case_deplacement_colonne + Boat2->taille >= 10) {
                        en_dehors = 1;
                    } else {
                        for (int k = 0; k < Boat2->taille; k++) {
                            if (tab_boat[Boat2->position_Ligne][Boat2->position_Colonne + k] =='+') {
                                tab_boat[Boat2->position_Ligne][Boat2->position_Colonne + k] = '_';
                            }
                            if (tab_boat[Boat2->position_Ligne][Boat2->position_Colonne + k] =='x') {
                                tab_boat[Boat2->position_Ligne][Boat2->position_Colonne + k] = '_';
                                touche[k] = 'C';
                            }
                        }


                        for (int l = 0; l < Boat2->taille; l++) {
                            if (tab_boat[Boat2->position_Ligne + nb_case_deplacement_ligne][Boat2->position_Colonne + l + nb_case_deplacement_colonne] == '+' || tab_boat[Boat2->position_Ligne + nb_case_deplacement_ligne][Boat2->position_Colonne + l + nb_case_deplacement_colonne] == 'x') {
                                superpose = 1;
                            }
                        }


                        if (superpose == 0) {
                            for (int m = 0; m < Boat2->taille; m++) {
                                if (touche[m]== '_') {
                                    tab_boat[Boat2->position_Ligne + nb_case_deplacement_ligne][
                                            Boat2->position_Colonne + m + nb_case_deplacement_colonne] = '+';
                                }
                                else{
                                    tab_boat[Boat2->position_Ligne + nb_case_deplacement_ligne][
                                            Boat2->position_Colonne + m + nb_case_deplacement_colonne] = 'x';
                                }
                            }
                            Boat2->position_Ligne += nb_case_deplacement_ligne;
                            Boat2->position_Colonne += nb_case_deplacement_colonne;
                        }
                    }
                }
            }

            // On prosède de la même manière pour le bateau 3
            if (quel_bateau == 3) {

                if (Boat3->orientation == 'V') {
                    if (Boat3->position_Ligne + nb_case_deplacement_ligne + Boat3->taille >= 10 ||
                        Boat3->position_Ligne + nb_case_deplacement_ligne < 0 ||
                        Boat3->position_Colonne + nb_case_deplacement_colonne <= 0 ||
                        Boat3->position_Colonne + nb_case_deplacement_colonne >= 10) {
                        en_dehors = 1;
                    } else {
                        for (int k = 0; k < Boat3->taille; k++) {
                            if (tab_boat[Boat3->position_Ligne + k][Boat3->position_Colonne] =='+') {
                                tab_boat[Boat3->position_Ligne + k][Boat3->position_Colonne] = '_';
                            }
                            if (tab_boat[Boat3->position_Ligne + k][Boat3->position_Colonne] =='x') {
                                tab_boat[Boat3->position_Ligne + k][Boat3->position_Colonne] = '_';
                                touche[k] = 'C';
                            }
                        }


                        for (int l = 0; l < Boat3->taille; l++) {
                            if (tab_boat[Boat3->position_Ligne + l + nb_case_deplacement_ligne][Boat3->position_Colonne + nb_case_deplacement_colonne] == '+'|| tab_boat[Boat3->position_Ligne + l + nb_case_deplacement_ligne][Boat3->position_Colonne + nb_case_deplacement_colonne] == 'x') {
                                superpose = 1;
                            }
                        }


                        if (superpose == 0) {
                            for (int m = 0; m < Boat3->taille; m++) {
                                if (touche[m]== '_') {
                                    tab_boat[Boat3->position_Ligne + m + nb_case_deplacement_ligne][
                                            Boat3->position_Colonne + nb_case_deplacement_colonne] = '+';
                                }
                                else{
                                    tab_boat[Boat3->position_Ligne + m + nb_case_deplacement_ligne][
                                            Boat3->position_Colonne + nb_case_deplacement_colonne] = 'x';
                                }
                            }
                            Boat3->position_Ligne += nb_case_deplacement_ligne;
                            Boat3->position_Colonne += nb_case_deplacement_colonne;
                        }
                    }
                }


                if (Boat3->orientation == 'H') {
                    if (Boat3->position_Ligne + nb_case_deplacement_ligne >= 10 ||
                        Boat3->position_Ligne + nb_case_deplacement_ligne < 0 ||
                        Boat3->position_Colonne + nb_case_deplacement_colonne <= 0 ||
                        Boat3->position_Colonne + nb_case_deplacement_colonne + Boat3->taille >= 10) {
                        en_dehors = 1;
                    } else {
                        for (int k = 0; k < Boat3->taille; k++) {
                            if (tab_boat[Boat3->position_Ligne][Boat3->position_Colonne + k] =='+') {
                                tab_boat[Boat3->position_Ligne][Boat3->position_Colonne + k] = '_';
                            }
                            if (tab_boat[Boat3->position_Ligne][Boat3->position_Colonne + k] =='x') {
                                tab_boat[Boat3->position_Ligne][Boat3->position_Colonne + k] = '_';
                                touche[k] = 'C';
                            }
                        }


                        for (int l = 0; l < Boat3->taille; l++) {
                            if (tab_boat[Boat3->position_Ligne + nb_case_deplacement_ligne][Boat3->position_Colonne + l + nb_case_deplacement_colonne] =='+' || tab_boat[Boat3->position_Ligne + nb_case_deplacement_ligne][Boat3->position_Colonne + l + nb_case_deplacement_colonne] == 'x') {
                                superpose = 1;
                            }
                        }


                        if (superpose == 0) {
                            for (int m = 0; m < Boat3->taille; m++) {
                                if (touche[m]== '_') {
                                    tab_boat[Boat3->position_Ligne + nb_case_deplacement_ligne][
                                            Boat3->position_Colonne + m + nb_case_deplacement_colonne] = '+';
                                }
                                else{
                                    tab_boat[Boat3->position_Ligne + nb_case_deplacement_ligne][
                                            Boat3->position_Colonne + m + nb_case_deplacement_colonne] = 'x';
                                }
                            }
                            Boat3->position_Ligne += nb_case_deplacement_ligne;
                            Boat3->position_Colonne += nb_case_deplacement_colonne;
                        }
                    }
                }
            }

            // On prosède de la même manière pour le bateau 4
            if (quel_bateau == 4) {
                if (Boat4->orientation == 'V') {
                    if (Boat4->position_Ligne + nb_case_deplacement_ligne + Boat4->taille >= 10 ||
                        Boat4->position_Ligne + nb_case_deplacement_ligne < 0 ||
                        Boat4->position_Colonne + nb_case_deplacement_colonne <= 0 ||
                        Boat4->position_Colonne + nb_case_deplacement_colonne >= 10) {
                        en_dehors = 1;
                    } else {
                        for (int k = 0; k < Boat4->taille; k++) {
                            if (tab_boat[Boat4->position_Ligne + k][Boat4->position_Colonne] =='+') {
                                tab_boat[Boat4->position_Ligne + k][Boat4->position_Colonne] = '_';
                            }
                            if (tab_boat[Boat4->position_Ligne + k][Boat4->position_Colonne] =='x') {
                                tab_boat[Boat4->position_Ligne + k][Boat4->position_Colonne] = '_';
                                touche[k] = 'C';
                            }
                        }


                        for (int l = 0; l < Boat4->taille; l++) {
                            if (tab_boat[Boat4->position_Ligne + l + nb_case_deplacement_ligne][Boat4->position_Colonne + nb_case_deplacement_colonne] == '+'||tab_boat[Boat4->position_Ligne + l + nb_case_deplacement_ligne][Boat4->position_Colonne + nb_case_deplacement_colonne] == 'x') {
                                superpose = 1;
                            }
                        }


                        if (superpose == 0) {
                            for (int m = 0; m < Boat4->taille; m++) {
                                if (touche[m]== '_') {
                                    tab_boat[Boat4->position_Ligne + m + nb_case_deplacement_ligne][
                                            Boat4->position_Colonne + nb_case_deplacement_colonne] = '+';
                                }
                                else{
                                    tab_boat[Boat4->position_Ligne + m + nb_case_deplacement_ligne][
                                            Boat4->position_Colonne + nb_case_deplacement_colonne] = 'x';
                                }
                            }
                            Boat4->position_Ligne += nb_case_deplacement_ligne;
                            Boat4->position_Colonne += nb_case_deplacement_colonne;
                        }
                    }
                }


                if (Boat4->orientation == 'H') {
                    if (Boat4->position_Ligne + nb_case_deplacement_ligne >= 10 ||
                        Boat4->position_Ligne + nb_case_deplacement_ligne < 0 ||
                        Boat4->position_Colonne + nb_case_deplacement_colonne <= 0 ||
                        Boat4->position_Colonne + nb_case_deplacement_colonne + Boat4->taille >= 10) {
                        en_dehors = 1;
                    } else {
                        for (int k = 0; k < Boat4->taille; k++) {
                            if (tab_boat[Boat4->position_Ligne][Boat4->position_Colonne + k] =='+') {
                                tab_boat[Boat4->position_Ligne][Boat4->position_Colonne + k] = '_';
                            }
                            if (tab_boat[Boat4->position_Ligne][Boat4->position_Colonne + k] =='x') {
                                tab_boat[Boat4->position_Ligne][Boat4->position_Colonne + k] = '_';
                                touche[k] = 'C';
                            }
                        }


                        for (int l = 0; l < Boat4->taille; l++) {
                            if (tab_boat[Boat4->position_Ligne + nb_case_deplacement_ligne][Boat4->position_Colonne + l + nb_case_deplacement_colonne] == '+' || tab_boat[Boat4->position_Ligne + nb_case_deplacement_ligne][Boat4->position_Colonne + l + nb_case_deplacement_colonne] == 'x') {
                                superpose = 1;
                            }
                        }


                        if (superpose == 0) {
                            for (int m = 0; m < Boat4->taille; m++) {
                                if (touche[m]== '_') {
                                    tab_boat[Boat4->position_Ligne + nb_case_deplacement_ligne][
                                            Boat4->position_Colonne + m + nb_case_deplacement_colonne] = '+';
                                }
                                else{
                                    tab_boat[Boat4->position_Ligne + nb_case_deplacement_ligne][
                                            Boat4->position_Colonne + m + nb_case_deplacement_colonne] = 'x';
                                }
                            }
                            Boat4->position_Ligne += nb_case_deplacement_ligne;
                            Boat4->position_Colonne += nb_case_deplacement_colonne;
                        }
                    }
                }
            }

            // On prosède de la même manière pour le bateau 5
            if (quel_bateau == 5) {
                if (Boat5->orientation == 'V') {
                    if (Boat5->position_Ligne + nb_case_deplacement_ligne + Boat5->taille >= 10 ||
                        Boat5->position_Ligne + nb_case_deplacement_ligne < 0 ||
                        Boat5->position_Colonne + nb_case_deplacement_colonne <= 0 ||
                        Boat5->position_Colonne + nb_case_deplacement_colonne >= 10) {
                        en_dehors = 1;
                    } else {
                        for (int k = 0; k < Boat5->taille; k++) {
                            if (tab_boat[Boat5->position_Ligne + k][Boat5->position_Colonne] =='+') {
                                tab_boat[Boat5->position_Ligne + k][Boat5->position_Colonne] = '_';
                            }
                            if (tab_boat[Boat5->position_Ligne + k][Boat5->position_Colonne] =='x') {
                                tab_boat[Boat5->position_Ligne + k][Boat5->position_Colonne] = '_';
                                touche[k] = 'C';
                            }
                        }


                        for (int l = 0; l < Boat5->taille; l++) {
                            if (tab_boat[Boat5->position_Ligne + l + nb_case_deplacement_ligne][Boat5->position_Colonne + nb_case_deplacement_colonne] == '+'||tab_boat[Boat5->position_Ligne + l + nb_case_deplacement_ligne][Boat5->position_Colonne + nb_case_deplacement_colonne] == 'x') {
                                superpose = 1;
                            }
                        }


                        if (superpose == 0) {
                            for (int m = 0; m < Boat5->taille; m++) {
                                if (touche[m]== '_') {
                                    tab_boat[Boat5->position_Ligne + m + nb_case_deplacement_ligne][
                                            Boat5->position_Colonne + nb_case_deplacement_colonne] = '+';
                                }
                                else{
                                    tab_boat[Boat5->position_Ligne + m + nb_case_deplacement_ligne][
                                            Boat5->position_Colonne + nb_case_deplacement_colonne] = 'x';
                                }
                            }
                            Boat5->position_Ligne += nb_case_deplacement_ligne;
                            Boat5->position_Colonne += nb_case_deplacement_colonne;
                        }
                    }
                }


                if (Boat5->orientation == 'H') {
                    if (Boat5->position_Ligne + nb_case_deplacement_ligne >= 10 ||
                        Boat5->position_Ligne + nb_case_deplacement_ligne < 0 ||
                        Boat5->position_Colonne + nb_case_deplacement_colonne <= 0 ||
                        Boat5->position_Colonne + nb_case_deplacement_colonne + Boat5->taille >= 10) {
                        en_dehors = 1;
                    } else {
                        for (int k = 0; k < Boat5->taille; k++) {
                            if (tab_boat[Boat5->position_Ligne][Boat5->position_Colonne + k] =='+') {
                                tab_boat[Boat5->position_Ligne][Boat5->position_Colonne + k] = '_';
                            }
                            if (tab_boat[Boat5->position_Ligne][Boat5->position_Colonne + k] =='x') {
                                tab_boat[Boat5->position_Ligne][Boat5->position_Colonne + k] = '_';
                                touche[k] = 'C';
                            }
                        }


                        for (int l = 0; l < Boat5->taille; l++) {
                            if (tab_boat[Boat5->position_Ligne + nb_case_deplacement_ligne][Boat5->position_Colonne + l + nb_case_deplacement_colonne] == '+' || tab_boat[Boat5->position_Ligne + nb_case_deplacement_ligne][Boat5->position_Colonne + l + nb_case_deplacement_colonne] == 'x') {
                                superpose = 1;
                            }
                        }


                        if (superpose == 0) {
                            for (int m = 0; m < Boat5->taille; m++) {
                                if (touche[m]== '_') {
                                    tab_boat[Boat5->position_Ligne + nb_case_deplacement_ligne][
                                            Boat5->position_Colonne + m + nb_case_deplacement_colonne] = '+';
                                }
                                else{
                                    tab_boat[Boat5->position_Ligne + nb_case_deplacement_ligne][
                                            Boat5->position_Colonne + m + nb_case_deplacement_colonne] = 'x';
                                }
                            }
                            Boat5->position_Ligne += nb_case_deplacement_ligne;
                            Boat5->position_Colonne += nb_case_deplacement_colonne;
                        }
                    }
                }
            }


            Sleep(1000);  // On ralenti la boucle car il faut attendre que l'horloge interne de l'ordinateur change de valeur.
            // Sinon les chiffres donnés par Rand() seront les mêmes.

        } while (superpose == 1 || en_dehors == 1);

    }

}