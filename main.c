/*
Name : Bataille naval
Author : Ethann Schneider
Version : beta 0.1
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int x = 0;
int y = 0;

//1 : 1 porte-avion (5 cases)
//2 : 1 croiseur (4 cases)
//3 : 1 contre-torpilleur (3 cases)
//4 : 1 sous-marin (3 cases)
//5 : 1 torpilleur (2 cases)
int bateau[10][10] = {
        {1,2,3,4,2,0,0,0,0,0},
        {1,2,3,4,2,0,0,0,0,0},
        {1,2,3,4,0,0,0,0,0,0},
        {1,2,0,0,0,0,0,0,0,0},
        {1,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0}
};

//0 : pas encore visé
//1 : vide
//2 : touché
//3 : couler
int tab[10][10] = {
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0}
};

int tableau(){
    printf("     1   2   3   4   5   6   7   8   9  10\n");
    printf("   ╔═══╦═══╦═══╦═══╦═══╦═══╦═══╦═══╦═══╦═══╗\n %c ║",97);
    for (int i = 0; i < 10; i++) {
        printf("%2d ║",tab[0][i]);
    }
    printf("\n");
    for (int y = 1; y < 10; y++) {
        printf("   ╠═══╬═══╬═══╬═══╬═══╬═══╬═══╬═══╬═══╬═══╣\n %c ║",y+97);
        for (int i = 0; i < 10; i++) {
            printf("%2d ║",tab[y][i]);
        }
        printf("\n");
    }
    printf("   ╚═══╩═══╩═══╩═══╩═══╩═══╩═══╩═══╩═══╩═══╝\n");
}

int main() {
    char ychar;
    while (1){
        printf("\e[1;1H\e[2J");
        tableau();

        do {
            printf("\nCoords 1 : ");
            scanf("%d", &x);
            if (x > 10 || x == 0){printf("le nombre doit être inférieur à 10 et supérieur a 0 !");}
        }while (x > 10 || x == 0);

        do {
            printf("\nCoords 2 : ");
            scanf("%s", &ychar);
            y = (int) (ychar) - 96;
            if (ychar <= 96 || ychar >= 107){printf("La lettre doit être entre a et k !");}
        } while (ychar <= 96 || ychar >= 107);

        switch (bateau[x-1][y-1]) {
            case 0:
                tab[x-1][y-1] = 1;
                break;
            case 1:
                tab[x-1][y-1] = 2;
                break;
            case 2:
                tab[x-1][y-1] = 2;
                break;
            case 3:
                tab[x-1][y-1] = 2;
                break;
            case 4:
                tab[x-1][y-1] = 2;
                break;


        }

    }

    return 0;
}
