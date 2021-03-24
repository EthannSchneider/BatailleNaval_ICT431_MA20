/*
Name : Bataille navale
Author : Ethann Schneider
Version : beta 1.0
*/

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <math.h>
#include <string.h>

int x = 0;
int y = 0;
int win = 0;
int nbtry = 0;
int nberreur = 0;
int nbjuste = 0;
char ychar[1];
int mode = 0;
char o[2];
int hours, minutes, seconds, day, month, year;
char scorechar[3][3];
char username[100];
FILE* BatLog = NULL;
FILE* scorefile = NULL;
FILE* boattabfile = NULL;

//<editor-fold desc="Boat">
//1 : porte-avion (5 cases)
//2 : cruiser (4 cases)
//3 : contre-torpedoboat (3 cases)
//4 : sous-marin (3 cases)
//5 : torpedoboat (2 cases)
int boat[10][10] = {
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
//</editor-fold>

//<editor-fold desc="Tab">
//0 : pas encore visé
//1 : vide
//2 : touché
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
//</editor-fold>

/**
 * description: write in score and player file
 * @param PlayerScore
 */
void writescore(int PlayerScore){
    scorefile = fopen("score.txt", "a+"); //a+ is to write in a new line

    if (scorefile != NULL) { //continue while it's not end of file
        fprintf(scorefile,"%s : %d\n",username,PlayerScore);
    }
    fclose(scorefile);
}

/**
 * description: Bataille navale Title
*/
void textbataillenavale(){
    printf(" ____        _        _ _ _        _   _                  _\n"
           "| __ )  __ _| |_ __ _(_) | | ___  | \\ | | __ ___   ____ _| | ___\n"
           "|  _ \\ / _` | __/ _` | | | |/ _ \\ |  \\| |/ _` \\ \\ / / _` | |/ _ \\\n"
           "| |_) | (_| | || (_| | | | |  __/ | |\\  | (_| |\\ V / (_| | |  __/\n"
           "|____/ \\__,_|\\__\\__,_|_|_|_|\\___| |_| \\_|\\__,_| \\_/ \\__,_|_|\\___|\n");
}

/**
 * description:  show all score
*/
void allscore(){
    system("cls");//clear
    textbataillenavale();

    printf("\n");

    scorefile = fopen("score.txt", "r");
    char charaterInFile;

    charaterInFile = fgetc(scorefile);
    while (charaterInFile != EOF) { //continue while it's not end of file
        printf("%c", charaterInFile);
        charaterInFile = fgetc(scorefile);
    }
    fclose(scorefile);
    printf("\n");

    system("pause");//wait
}

/**
 * description:  write in log file
 *@param1: Text to write in log
 * */
void BatNavlog(const char *BatNavlog,const char *VarSupl){
    char *batnav;

    BatLog = fopen("log.txt", "a+");//a+ is to write in a new line

    time_t now;
    time(&now);
    struct tm *local = localtime(&now);
    hours = local->tm_hour;          // get hours since midnight (0-23)
    minutes = local->tm_min;         // get minutes passed after the hour (0-59)
    seconds = local->tm_sec;         // get seconds passed after minute (0-59)

    day = local->tm_mday;            // get day of month (1 to 31)
    month = local->tm_mon + 1;       // get month of year (0 to 11)
    year = local->tm_year + 1900;    // get year since 1900

    if (BatLog != NULL) {
        fprintf(BatLog,"[%02d/%02d/%d %02d:%02d:%02d]: %s %s\n", day, month, year, hours, minutes, seconds, BatNavlog,VarSupl);
    }

    fclose(BatLog);
}

/**
 * description: to generate tab with file
 */
void tabfile(){
    int fileToChoose = 0;
    char fileChoose[50];

    fileToChoose = rand() % 4 + 1;

    sprintf(fileChoose,"tab/tab%d",fileToChoose);

    boattabfile = fopen(fileChoose,"r");

    char charaterInFile;

    charaterInFile = fgetc(boattabfile);
    int itab = 0;
    int ytab = 0;
    while (charaterInFile != EOF) { //continue while it's not end of file
        int charct = charaterInFile;
        boat[ytab][itab] = charct-48;
        charaterInFile = fgetc(boattabfile);
        if(itab == 9){
            itab = 0;
            ytab++;
        }else{
            itab++;
        }
    }

    fclose(boattabfile);
}

/**
 * description: to generate the random boat table
 * (unuse because it's not in the Specifications)
 *
void tableaualea(){
    int direction = 0;
    int coordx = 0;
    int coordy = 0;
    int batalea[5][2];
    int sizebat[5]={5,4,3,3,2};
    int badcoords[100][2];
    int badcoordcalc = 0;
    int test = 0;

    for (int y = 5; y >= 1; y--) {
        do {
            test = 1;
            direction = rand() % 2;
            coordx = rand() % 6; // - case - 10
            coordy = rand() % 6; // - case - 10
            for (int i = 0; i < 100; ++i) {
                for (int j = 0; j < sizebat[y-1]; ++j) { // - case
                    if (badcoords[i][0] == coordx && badcoords[i][1] == coordy+j || badcoords[i][0] == coordx+j && badcoords[i][1] == coordy){
                        test = 0;
                    }
                }
            }
        }while (test != 1);

        for (int i = 0; i < sizebat[y-1]; ++i) { // - case
            switch (direction) {
                case 0:
                    batalea[i][0] = coordx;
                    batalea[i][1] = coordy+i;
                    badcoords[badcoordcalc][0] = coordx;
                    badcoords[badcoordcalc][1] = coordy+i;
                    break;
                case 1:
                    batalea[i][0] = coordx+i;
                    batalea[i][1] = coordy;
                    badcoords[badcoordcalc][0] = coordx+i;
                    badcoords[badcoordcalc][1] = coordy;
                    break;
                default:
                    break;
            }
            boat[batalea[i][0]][batalea[i][1]] = y; // - boat
            badcoordcalc+=1;
        }
    }

} */

/**
 * description: transform number to char on the graphic table
*/
char numtochar(int i){
    switch (i) {
        case 0: return ' '; break; //nothing
        case 2: return 'O'; break; //not touch
        default: return 'X'; break; //touch
    }
}

/**
 * description:  to show the table
*/
void tableau(){
    printf("     1   2   3   4   5   6   7   8   9  10\n");
    printf("   ╔═══╦═══╦═══╦═══╦═══╦═══╦═══╦═══╦═══╦═══╗\n %c ║",97); //first line
    for (int i = 0; i < 10; i++) { //seconde line
        printf(" %c ║",numtochar(tab[0][i]));
        //printf(" %d ║", boat[y][i]);
    }
    printf("\n");
    for (int y = 1; y < 10; y++) { // center line
        printf("   ╠═══╬═══╬═══╬═══╬═══╬═══╬═══╬═══╬═══╬═══╣\n %c ║",y+97);
        for (int i = 0; i < 10; i++) {
            printf(" %c ║",numtochar(tab[y][i]));
            //printf(" %d ║", boat[y][i]);
        }
        printf("\n");
    }
    printf("   ╚═══╩═══╩═══╩═══╩═══╩═══╩═══╩═══╩═══╩═══╝\n"); //last line
}

/**
 * description: check if boat is sink
*/
void checksinkwin(){
    int aircraftcarrier = 0, cruiser = 0, destroyer = 0, submarine = 0, torpedoboat = 0,aircraftcarriert = 0, cruisert = 0, destroyert = 0, submarinet = 0, torpedoboatt = 0;

    for (int i = 0; i < 10; i++) {//colone
        for (int j = 0; j < 10; j++) { //line
            switch (boat[i][j]) { //calculate case of the boat on the 2 table
                case 1:
                    aircraftcarrier++;
                    if(tab[i][j] == 2) aircraftcarriert++;
                    break;
                case 2:
                    cruiser++;
                    if(tab[i][j] == 2) cruisert++;
                    break;
                case 3:
                    destroyer++;
                    if(tab[i][j] == 2) destroyert++;
                    break;
                case 4:
                    submarine++;
                    if(tab[i][j] == 2) submarinet++;
                    break;
                case 5:
                    torpedoboat++;
                    if(tab[i][j] == 2) torpedoboatt++;
                    break;
            }
        }
    }
    if (aircraftcarrier == aircraftcarriert){ //check if is equals to touch boat then boat is sink
        printf("\nyou sunk successfully an ennemy aircraft carrier\n");
    }
    if (cruiser == cruisert){//check if is equals to touch boat then boat is sink
        printf("\nyou sunk successfully an ennemy cruiser\n");
    }
    if (destroyer == destroyert){//check if is equals to touch boat then boat is sink
        printf("\nyou sunk successfully an ennemy destroyer\n");
    }
    if (submarine == submarinet){//check if is equals to touch boat  then boat is sink
        printf("\nyou sunk successfully an ennemy submarine\n");
    }
    if (torpedoboat == torpedoboatt){//check if is equals to touch boat then boat is sink
        printf("\nyou sunk successfully an ennemy torpedo boat\n");
    }
    //check if all boat is equals to touch boat then win
    if (aircraftcarrier == aircraftcarriert && cruiser == cruisert && destroyer == destroyert && submarine == submarinet && torpedoboat == torpedoboatt){
        win = 1;
    }
}

/**
 * description:  show the win screen when player win
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
           "\nNumber of strike : %d"
           "\nNumber of error : %d"
           "\nNumber of hit : %d"
           "\n"
           "\n"
           "\n"
           "\n"
           "\n"
           "\n"
           "\n", nbtry, nberreur,nbjuste);
    sprintf(scorechar[0],"%d", nbtry);
    BatNavlog("Number of try : ",scorechar[0]);
    sprintf(scorechar[1],"%d", nberreur);
    BatNavlog("Number of error : ",scorechar[1]);
    sprintf(scorechar[2],"%d", nbjuste);
    BatNavlog("Number of hit : ",scorechar[2]);
    writescore(nbtry);
    system("pause");//wait
    system("cls");//clear
}

/**
 * description:  Show game help
*/
void gamehelp(){
    system("cls"); //clear
    textbataillenavale();
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

/**
 * description: function to reset tab
*/
void resettab(){
    for (int i = 0; i < 10; i++) {
        for (int y = 0; y < 10; y++) {
            tab[i][y] = 0;
        }
    }
}

/**
 * description:  It's the games
*/
void game(){
    BatNavlog("New Party","");

    tabfile();

    while (win == 0){ //wait player win
        system("cls");//clear
        textbataillenavale();

        tableau();

        checksinkwin();
        if (win != 0) continue;

        nbtry+=1;
        do {
            do {
                printf("\nColumn : ");
                scanf("%s", &o);
                x = strtol( o, NULL, 10 );
                if (x > 10 || x == 0) printf("the number need to be between 1 - 10 !"); //check if number is between 1 - 10 then error message
            }while (x > 10 || x == 0); //check if number is between 1 - 10
            BatNavlog("X : ",o);

            do {
                printf("\nLine : ");
                scanf("%s", &ychar);
                if (ychar[0] >= 65 && ychar[0] <= 74 ) ychar[0]+=32;
                y = (int) (ychar[0]) - 96;
                if (ychar[0] <= 96 || ychar[0] >= 107) printf("The character need to be between A and J !"); //check if char is between A - J then error message
            } while (ychar[0] <= 96 || ychar[0] >= 107); //check if char is between A - J
            BatNavlog("Y : ",ychar);

            if (tab[y-1][x-1] >= 1) printf("Allready touch !");
        }while (tab[y-1][x-1] >= 1);

        switch (boat[y-1][x-1]) { //switch to write touch or not touch
            case 0:
                tab[y-1][x-1] = 1;
                nberreur+=1;
                BatNavlog("Not touch","");
                printf("\nNot touch\n");
                break;
            default:
                tab[y-1][x-1] = 2;
                nbjuste+=1;
                BatNavlog("touch","");
                printf("\nTouch\n");
                break;
        }
        system("pause");

    }
    system("pause");
    winscreen();
    win = 0;
    nbtry = 0;//
    nbjuste = 0;//  <- reset counter
    nberreur = 0;//
    resettab();
}

/**
 * description:  function to set a name
*/
void name(){
    system("cls");//clear
    textbataillenavale();
    printf("\n\nWhat's your name ? ");
    scanf("%s",&username);
    BatNavlog("New User : ",username);
}

/**
 * description: Main function
*/
int main() {
    SetConsoleOutputCP(65001);

    srand( (unsigned)time(NULL));

    name();

    while (mode != 5) { //if player do not select quit
        do {
            system("cls");//clear
            textbataillenavale();
            printf("\n\nWhat do you want to do ? \n  1. Play\n  2. game help\n  3. Print all score\n  4. Change name\n  5. quit\n ");
            scanf("%s",&o);
            mode = strtol( o, NULL, 10 );
            if(mode > 5 || mode == 0){printf("\nThe number isn't between 1 - 5 !\n"); system("pause");}
        }while (mode > 10 || mode == 0); //check if number is between 1 - 3

        switch (mode) {
            case 1: game(); break;
            case 2: gamehelp(); break;
            case 3: allscore(); break;
            case 4: name(); break;
        }
    }
    return 0;
}
