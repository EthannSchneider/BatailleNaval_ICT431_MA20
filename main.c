/*
Name : Bataille naval
Author : Ethann Schneider
Version : beta 0.1
*/

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int x = 0;
int y = 0;
int win = 0;

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

/* @function : transform number to char on the graphic table
*/
void numtochar(int i){
    switch (i) {
        case 0: printf("   ║"); break; //nothing
        case 2: printf(" O ║"); break; //not touch
        default: printf(" X ║"); break; //touch
    }
}

/* @function : to show the table
*/
void tableau(){
    printf("     1   2   3   4   5   6   7   8   9  10\n");
    printf("   ╔═══╦═══╦═══╦═══╦═══╦═══╦═══╦═══╦═══╦═══╗\n %c ║",97); //first line
    for (int i = 0; i < 10; i++) { //seconde line
        numtochar(tab[0][i]);
    }
    printf("\n");
    for (int y = 1; y < 10; y++) { // center line
        printf("   ╠═══╬═══╬═══╬═══╬═══╬═══╬═══╬═══╬═══╬═══╣\n %c ║",y+97);
        for (int i = 0; i < 10; i++) {
            numtochar(tab[y][i]);
        }
        printf("\n");
    }
    printf("   ╚═══╩═══╩═══╩═══╩═══╩═══╩═══╩═══╩═══╩═══╝\n"); //last line
}

/* @function : check if boat is sink
*/
void checkcouler(){
    int porteavion = 0, croiseur = 0, contretorpilleur = 0, sousmarin = 0, torpilleur = 0,porteaviont = 0, croiseurt = 0, contretorpilleurt = 0, sousmarint = 0, torpilleurt = 0;

    for (int i = 0; i < 10; i++) {//colone
        for (int j = 0; j < 10; j++) { //line
            switch (bateau[i][j]) { //calculate case of the boat on the 2 table
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
                    if(tab[i][j] == 2){torpilleurt++;}
                    break;
            }
        }
    }
    if (porteavion == porteaviont){ //check if is equals to touch boat then boat is sink
        printf("\nyou sunk successfully an ennemy aircraft carrier\n");
    }
    if (croiseur == croiseurt){//check if is equals to touch boat then boat is sink
        printf("\nyou sunk successfully an ennemy cruiser\n");
    }
    if (contretorpilleur == contretorpilleurt){//check if is equals to touch boat then boat is sink
        printf("\nyou sunk successfully an ennemy destroyer\n");
    }
    if (sousmarin == sousmarint){//check if is equals to touch boat  then boat is sink
        printf("\nyou sunk successfully an ennemy submarine\n");
    }
    if (torpilleur == torpilleurt){//check if is equals to touch boat then boat is sink
        printf("\nyou sunk successfully an ennemy torpedo boat\n");
    }
    //check if all boat is equals to touch boat then win
    if (porteavion == porteaviont && croiseur == croiseurt && contretorpilleur == contretorpilleurt && sousmarin == sousmarint && torpilleur == torpilleurt){
        win = 1;
    }
}

/* @function : show the win screen when player win
*/
void winscreen(){
    system("cls");//clear
    printf(""
           "\n"
           "\n"
           "\n"
           "\n"
           "\n"
           "\n"
           "\n"
           "\n"
           "__   __           __        ___       \n"
           "\\ \\ / /__  _   _  \\ \\      / (_)_ __  \n"
           " \\ V / _ \\| | | |  \\ \\ /\\ / /| | '_ \\ \n"
           "  | | (_) | |_| |   \\ V  V / | | | | |\n"
           "  |_|\\___/ \\__,_|    \\_/\\_/  |_|_| |_|\n"
           "                                      "
           "\n    \\\n"
           "     \\\n"
           "                                   .::!!!!!!!:.\n"
           "  .!!!!!:.                        .:!!!!!!!!!!!!\n"
           "  ~~~~!!!!!!.                 .:!!!!!!!!!UWWW$$$\n"
           "      :$$NWX!!:           .:!!!!!!XUWW$$$$$$$$$P\n"
           "      $$$$$##WX!:      .<!!!!UW$$$$\"  $$$$$$$$#\n"
           "      $$$$$  $$$UX   :!!UW$$$$$$$$$   4$$$$$*\n"
           "      ^$$$B  $$$$\\     $$$$$$$$$$$$   d$$R\"\n"
           "        \"*$bd$$$$      '*$$$$$$$$$$$o+#\"\n"
           "             \"\"\"\"          \"\"\"\"\"\"\""
           "\n"
           "\n"
           "\n"
           "\n"
           "\n"
           "\n"
           "\n"
           "\n"
           "\n");
    system("pause");//wait
    system("cls");//clear
}

/* @function : Bataille navale Title
*/
void textebataillenavale(){
    printf(" ____        _        _ _ _        _   _                  _\n"
           "| __ )  __ _| |_ __ _(_) | | ___  | \\ | | __ ___   ____ _| | ___\n"
           "|  _ \\ / _` | __/ _` | | | |/ _ \\ |  \\| |/ _` \\ \\ / / _` | |/ _ \\\n"
           "| |_) | (_| | || (_| | | | |  __/ | |\\  | (_| |\\ V / (_| | |  __/\n"
           "|____/ \\__,_|\\__\\__,_|_|_|_|\\___| |_| \\_|\\__,_| \\_/ \\__,_|_|\\___|\n");
}

int main() {
    char ychar;
    int mode = 0;
    char o[2];

    SetConsoleOutputCP(65001);

    while (mode != 3) { //if player do not select quit
        do {
            system("cls");//clear
            textebataillenavale();
            printf("\n\nWhat do you want to do ? \n  1. Play\n  2. game help\n  3. quit\n ");
            scanf("%s",&o);
            mode = strtol( o, NULL, 10 );
        }while (mode > 10 || mode == 0); //check if number is between 1 - 3

        if (mode == 1){ //if player want to play a game
            while (win == 0){
                system("cls");//clear
                textebataillenavale();
                tableau();

                checkcouler();
                if (win != 0){continue;}

                do {
                    printf("\nCoords 1 : ");
                    scanf("%s", &o);
                    x = strtol( o, NULL, 10 );
                    if (x > 10 || x == 0){printf("the number need to be between 1 - 10 !");} //check if number is between 1 - 10 then error message
                }while (x > 10 || x == 0); //check if number is between 1 - 10

                do {
                    printf("\nCoords 2 : ");
                    scanf("%s", &ychar);
                    y = (int) (ychar) - 96;
                    if (ychar <= 96 || ychar >= 107){printf("The character need to be between A and J !");} //check if char is between A - J then error message
                } while (ychar <= 96 || ychar >= 107); //check if char is between A - J

                switch (bateau[y-1][x-1]) { //switch to write touch or not touch
                    case 0:
                        tab[y-1][x-1] = 1;
                        break;
                    default:
                        tab[y-1][x-1] = 2;
                        break;
                }

            }
            winscreen();
        }else if(mode == 2){ //if player want to know how to play
            system("cls"); //clear
            textebataillenavale();
            printf("\n\n\n  there is 5 boat : \n"
                   "                    1 aircraft carrier (5 cases)\n"
                   "                    1 cruiser (4 cases)\n"
                   "                    1 destroyer (3 cases)\n"
                   "                    1 submarine (3 cases)\n"
                   "                    1 torpedo boat (2 cases)\n"
                   "  each turn you choose a coordinate between 1 and 10 and a coordinate between A and J\n"
                   "  then on the board will be marked if hit or nothing\n"
                   "  as soon as all the squares of a boat are touched the boat sinks\n"
                   "  in the table X is not touch and O is hit\n"
                   "  Coords 1 is number and Coords 2 is a letter\n");
            system("pause");//wait
            system("cls");//clear
        }
    }
    return 0;
}
