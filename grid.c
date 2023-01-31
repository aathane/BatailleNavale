#include <stdio.h>
void grid(char tab[10][11]) {

/* On initialise la grilles en 2 morceaux
   1  2  3  4  5  6  7  8  9  10
              et
A  _  _  _  _  _  _  _  _  _  _
B  _  _  _  _  _  _  _  _  _  _
C  _  _  _  _  _  _  _  _  _  _
D  _  _  _  _  _  _  _  _  _  _
E  _  _  _  _  _  _  _  _  _  _
F  _  _  _  _  _  _  _  _  _  _
G  _  _  _  _  _  _  _  _  _  _
H  _  _  _  _  _  _  _  _  _  _
I  _  _  _  _  _  _  _  _  _  _
J  _  _  _  _  _  _  _  _  _  _

*/
    for (int i = 0; i <= 10; i++) {
        for (int j = 0; j <= 10; j++) {
            tab[i][j] = '_';
        }
    }

    for (int i = 0; i <= 9; i++) {
        tab[i][0] = 65 + i;          // 65 en decimal dans le tableau ASCII correspond au caractère A
    }

}