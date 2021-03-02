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
        {1,2,3,4,5,0,0,0,0,0},
        {1,2,3,4,5,0,0,0,0,0},
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

int checkcouler(){
    int porteavion = 0, croiseur = 0, contretorpilleur = 0, sousmarin = 0, torpilleur = 0,porteaviont = 0, croiseurt = 0, contretorpilleurt = 0, sousmarint = 0, torpilleurt = 0;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            switch (bateau[i][j]) {
                case 1:
                    porteavion++;
                    if(tab[i][j] == 2){porteaviont++;}
                    break;
                case 2:
                    croiseur++;
                    if(tab[i][j] == 2){croiseurt++;}
                    break;
                case 3:
                    contretorpilleur++;
                    if(tab[i][j] == 2){contretorpilleurt++;}
                    break;
                case 4:
                    sousmarin++;
                    if(tab[i][j] == 2){sousmarint++;}
                    break;
                case 5:
                    torpilleur++;
                    if(tab[i][j] == 26){torpilleurt++;}
                    break;
            }
        }
    }
    if (porteavion == porteaviont){
        printf("\nle porte-avion adverse a couler\n");
    }else if (croiseur == croiseurt){
        printf("\nle croiseur adverse a couler\n");
    }else if (contretorpilleur == contretorpilleurt){
        printf("\nle contre-torpilleur adverse a couler\n");
    }else if (sousmarin == sousmarint){
        printf("\nle sous-marin adverse a couler\n");
    }else if (torpilleur == torpilleurt){
        printf("\nle torpilleur adverse a couler\n");
    }
}

int main() {
    char ychar;
    while (1){
        printf("\e[1;1H\e[2J");
        tableau();
        checkcouler();

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

        switch (bateau[y-1][x-1]) {
            case 0:
                tab[y-1][x-1] = 1;
                break;
            case 1:
                tab[y-1][x-1] = 2;
                break;
            case 2:
                tab[y-1][x-1] = 2;
                break;
            case 3:
                tab[y-1][x-1] = 2;
                break;
            case 4:
                tab[y-1][x-1] = 2;
                break;
            case 5:
                tab[y-1][x-1] = 2;
                break;

        }

    }

    return 0;
}
