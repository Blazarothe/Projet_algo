#include "head.h"



void afficher_la_derniere_piece(int *compte_T,int *compte_I,int *compte_L,int *compteL_tresors) {

    int matrixe[3][3];
    printf("Votre piece restante est :\n");


    if (*compte_T > 0) {
        for (int l = 0; l < 3; l++) {
            for (int c = 0; c < 3; c++) {

                if ((l == 0 && (c == 0 || c == 2)) || l == 2) {  // pieces en T dans tt les sens
                    matrixe[l][c] = 0;
                } else {
                    matrixe[l][c] = 1;
                }
            }
        }
    }
    if (*compte_I > 0) {
        for (int l = 0; l < 3; l++) {
            for (int c = 0; c < 3; c++) {
                if (l == 0 || l == 2) {
                    matrixe[l][c] = 0;
                } else {
                    matrixe[l][c] = 1;
                }

            }
        }
    }
    if (*compte_L > 0) {
        for (int l = 0; l < 3; l++) {
            for (int c = 0; c < 3; c++) {
                if (c == 0 || (c == 2 && l == 2) || l == 0) {  // piece ne L
                    matrixe[l][c] = 0;
                } else {
                    matrixe[l][c] = 1;
                }
            }

        }
    }
    if (*compteL_tresors > 0) {
        for (int l = 0; l < 3; l++) {
            for (int c = 0; c < 3; c++) {
                if (c == 0 || (c == 2 && l == 2) || l == 0) {  // piece ne L avec tresors
                    matrixe[l][c] = 0;
                }
                else if(c==1 && l==1){
                    matrixe[l][c] =  10;
                }
                else {
                    matrixe[l][c] = 1;
                }
            }

        }
    }
    for (int l = 0; l < 3; l++) {
        for (int c = 0; c < 3; c++) {
            if(matrixe[l][c] == 0)
            {
                Color(6, 6);
                printf(" ");
                color(couleur_blanche, 0);
            }
            else if(matrixe[l][c]==10){
                printf("X");
            }
            else
                printf("%c",' ');
        }
        printf("\n");

    }
}


int depla(int matrix[49][3][3],int player, int compte_T,int compte_L,int compte_I,int compteL_tresors,int deplacement,int *nmbre_joueurs) {

    int victoire1;
    int victoire2;
    int store;
    int r;
    char depl;
    for (int i = 0; i < 49; ++i) {
        for (int l = 0; l < 3; ++l) {
            for (int c = 0; c < 3; ++c) {
                if ((matrix[i][l][c] == player) || (player == 3 && (matrix[i][l][c]/2)%2 == 1)|| (matrix[i][l][c]-2)%10 == 0) {
                    store = i;
                }
            }
        }
    }


    scanf("%c", &depl);
    system("cls");

    if ((depl == 'q' && matrix[store][1][0] == 0) || (depl == 'q' && matrix[store - 1][1][2] == 0) || (depl == 'q' &&(store == 0 ||store == 7 ||store == 14 ||store == 21 ||store == 28 ||store == 35 ||store == 42))) {
        do {
            scanf("%c", &depl);
        } while ((depl == 'q' && matrix[store][1][0] == 0) || (depl == 'q' && matrix[store - 1][1][2] == 0) ||(depl == 'q' &&(store == 0 || store == 7 || store == 14 || store == 21 || store == 28 || store == 35 ||store == 42)));
    }

    if ((depl == 'z' && matrix[store][0][1] == 0) || (depl == 'z' && matrix[store - 7][2][1] == 0) ||
        (depl == 'z' && (store >= 0 && store <= 6))) {
        do {
            scanf("%c", &depl);
        } while ((depl == 'z' && matrix[store][0][1] == 0) || (depl == 'z' && matrix[store - 7][2][1] == 0) ||(depl == 'z' && (store >= 0 && store <= 6)));
    }

    if ((depl == 's' && matrix[store][2][1] == 0) || (depl == 's' && matrix[store + 7][0][1] == 0) ||(depl == 's' && (store >= 42 && store <= 48))) {
        do {
            scanf("%c", &depl);
        } while ((depl == 's' && matrix[store][2][1] == 0) || (depl == 's' && matrix[store + 7][0][1] == 0) ||(depl == 's' && (store >= 42 && store <= 48)));
    }

    if ((depl == 'd' && matrix[store][1][2] == 0) || (depl == 'd' && matrix[store + 1][1][0] == 0) || (depl == 'd' && (store == 6 ||store == 13 ||store == 20 ||store == 27 ||store == 34 ||store == 41 ||store == 48))) {
        do {
            scanf("%c", &depl);
        } while ((depl == 'd' && matrix[store][1][2] == 0) || (depl == 'd' && matrix[store + 1][1][0] == 0) ||(depl == 'd' &&(store == 6 || store == 13 || store == 20 || store == 27 || store == 34 || store == 41 ||store == 48)));
    }

    if (*nmbre_joueurs == 2) //distribution des cartes tresors si 2 joueurs
    {
        int joueur1_tresors[12] = {800, 1100, 300, 900, 49500, 4500, 700, 200, 22500, 31000, 600, 100};
        int joueur2_tresors[12] = {31500, 400, 40500, 13500, 22000, 40000, 1200, 500, 1000, 4000, 49000, 13000};

        if (player == 3)
        {
            if (depl == 'd') {
                r = 0;
                for (int i = 0; i < 12; ++i) {
                    if(matrix[store + 1][1][1] == joueur1_tresors[i])
                    {
                        matrix[store][1][1] = 1;
                        matrix[store + 1][1][1] = 3;
                        r = 1;
                        victoire1++;
                    }
                }
                if(r == 0)
                {
                    matrix[store][1][1] = matrix[store][1][1]-(player-1) ;
                    matrix[store + 1][1][1] = matrix[store + 1][1][1]+(player-1);
                }
            }

            if (depl == 'q') {
                r = 0;
                for (int i = 0; i < 12; ++i) {
                    if(matrix[store -1][1][1] == joueur1_tresors[i])
                    {
                        matrix[store][1][1] = 1;
                        matrix[store -1][1][1] = 3;
                        r = 1;
                        victoire1++;
                    }
                }
                if(r == 0)
                {
                    matrix[store][1][1] = matrix[store][1][1]-(player-1) ;
                    matrix[store -1][1][1] = matrix[store -1][1][1]+(player-1);
                }
            }

            if (depl == 'z') {
                r = 0;
                for (int i = 0; i < 12; ++i) {
                    if(matrix[store -7][1][1] == joueur1_tresors[i])
                    {
                        matrix[store][1][1] = 1;
                        matrix[store -7][1][1] = 3;
                        r = 1;
                        victoire1++;
                    }
                }
                if(r == 0)
                {
                    matrix[store][1][1] = matrix[store][1][1]-(player-1) ;
                    matrix[store -7][1][1] = matrix[store -7][1][1]+(player-1);
                }
            }

            if (depl == 's') {
                r = 0;
                for (int i = 0; i < 12; ++i) {
                    if(matrix[store +7][1][1] == joueur1_tresors[i])
                    {
                        matrix[store][1][1] = 1;
                        matrix[store +7][1][1] = 3;
                        r = 1;
                        victoire1++;
                    }
                }
                if(r == 0)
                {
                    matrix[store][1][1] = matrix[store][1][1]-(player-1) ;
                    matrix[store +7][1][1] = matrix[store +7][1][1]+(player-1);
                }
            }
        }

        if (player == 2)
        {
            if (depl == 'd') {
                r = 0;
                for (int i = 0; i < 12; ++i) {
                    if(matrix[store + 1][1][1] == joueur2_tresors[i])
                    {
                        matrix[store][1][1] = 1;
                        matrix[store + 1][1][1] = 2;
                        r = 1;
                        victoire2++;
                    }
                }
                if(r == 0)
                {
                    matrix[store][1][1] = matrix[store][1][1]-(player-1) ;
                    matrix[store + 1][1][1] = matrix[store + 1][1][1]+(player-1);
                }
            }

            if (depl == 'q') {
                r = 0;
                for (int i = 0; i < 12; ++i) {
                    if(matrix[store -1][1][1] == joueur2_tresors[i])
                    {
                        matrix[store][1][1] = 1;
                        matrix[store -1][1][1] = 2;
                        r = 1;
                        victoire2++;
                    }
                }
                if(r == 0)
                {
                    matrix[store][1][1] = matrix[store][1][1]-(player-1) ;
                    matrix[store -1][1][1] = matrix[store -1][1][1]+(player-1);
                }
            }

            if (depl == 'z') {
                r = 0;
                for (int i = 0; i < 12; ++i) {
                    if(matrix[store -7][1][1] == joueur2_tresors[i])
                    {
                        matrix[store][1][1] = 1;
                        matrix[store -7][1][1] = 2;
                        r = 1;
                        victoire2++;
                    }
                }
                if(r == 0)
                {
                    matrix[store][1][1] = matrix[store][1][1]-(player-1) ;
                    matrix[store -7][1][1] = matrix[store -7][1][1]+(player-1);
                }
            }

            if (depl == 's') {
                r = 0;
                for (int i = 0; i < 12; ++i) {
                    if(matrix[store +7][1][1] == joueur2_tresors[i])
                    {
                        matrix[store][1][1] = 1;
                        matrix[store +7][1][1] = 2;
                        r = 1;
                        victoire2++;
                    }
                }
                if(r == 0)
                {
                    matrix[store][1][1] = matrix[store][1][1]-(player-1) ;
                    matrix[store +7][1][1] = matrix[store +7][1][1]+(player-1);
                }
            }
        }

    }

    if(victoire1 == 12)
        nmbre_joueurs = 0;

    if(victoire2 == 12)
        nmbre_joueurs = 0;

    if(depl == 'e')
    {
        return 0;
    }

    int d = 0;

    //AFFICHER LE PLATEAU DE DEPART

    if(player == 3)
    {
        printf("[H], [K], [C], [I], [S], [X], [G], [B], [V], [O], [F], [A]");
    }
    if (player == 2)
    {
        printf("[U], [D], [T], [W], [P], [N], [L], [E], [J], [R], [M], [Q]");
    }

    printf("\n      %c     %c     %c\n  ", 0x19, 0x19, 0x19);
    for (int a = 0; a < 7; a++) {
        for (int l = 0; l < 3; l++) {
            for (int i = d; i < d + 7; i++) {
                for (int c = 0; c < 3; c++) {


                    if (matrix[i][l][c] == 2 || matrix[i][l][c] == 101 || matrix[i][l][c] == 201|| matrix[i][l][c] == 301|| matrix[i][l][c] == 401|| matrix[i][l][c] == 501|| matrix[i][l][c] == 601|| matrix[i][l][c] == 701|| matrix[i][l][c] == 801|| matrix[i][l][c] == 901|| matrix[i][l][c] == 1001|| matrix[i][l][c] == 1101|| matrix[i][l][c] == 1201|| matrix[i][l][c] == 49001|| matrix[i][l][c] == 40001|| matrix[i][l][c] == 31001|| matrix[i][l][c] == 22001|| matrix[i][l][c] == 13001|| matrix[i][l][c] == 4001|| matrix[i][l][c] == 49501|| matrix[i][l][c] == 40501|| matrix[i][l][c] == 31501|| matrix[i][l][c] == 22501|| matrix[i][l][c] == 13501|| matrix[i][l][c] == 4501) {

                        Color(9, 0);
                        printf("%c", 0xDB);
                        color(couleur_blanche, 0);

                    }


                    if (matrix[i][l][c] == 3 || matrix[i][l][c] == 102 || matrix[i][l][c] == 202 || matrix[i][l][c] == 302 || matrix[i][l][c] == 402 || matrix[i][l][c] == 502 || matrix[i][l][c] == 602|| matrix[i][l][c] == 702|| matrix[i][l][c] == 802|| matrix[i][l][c] == 902|| matrix[i][l][c] == 1002|| matrix[i][l][c] == 1102|| matrix[i][l][c] == 1202|| matrix[i][l][c] == 49002|| matrix[i][l][c] == 40002|| matrix[i][l][c] == 31002|| matrix[i][l][c] == 22002|| matrix[i][l][c] == 13002|| matrix[i][l][c] == 4002|| matrix[i][l][c] == 49502|| matrix[i][l][c] == 40502|| matrix[i][l][c] == 31502|| matrix[i][l][c] == 22502|| matrix[i][l][c] == 13502|| matrix[i][l][c] == 4502) {

                        Color(2, 0);
                        printf("%c", 0xDB);
                        color(couleur_blanche, 0);
                    }

                    if (matrix[i][l][c] == 4) {

                        Color(14, 0);
                        printf("%c", 0xDB);
                        color(couleur_blanche, 0);

                    }
                    if (matrix[i][l][c] == 5) {

                        Color(5, 0);
                        printf("%c", 0xDB);
                        color(couleur_blanche, 0);

                    }

                    // AFFICHAGE TRESORS STATIQUE
                    if (matrix[i][l][c] == 100) {
                        printf("A");
                    }
                    if (matrix[i][l][c] == 200) {
                        printf("B");
                    }
                    if (matrix[i][l][c] == 300) {
                        printf("C");
                    }
                    if (matrix[i][l][c] == 400) {
                        printf("D");
                    }
                    if (matrix[i][l][c] == 500) {
                        printf("E");
                    }
                    if (matrix[i][l][c] == 600) {
                        printf("F");
                    }
                    if (matrix[i][l][c] == 700) {
                        printf("G");
                    }
                    if (matrix[i][l][c] == 800) {
                        printf("H");
                    }
                    if (matrix[i][l][c] == 900) {
                        printf("I");
                    }
                    if (matrix[i][l][c] == 1000) {
                        printf("J");
                    }
                    if (matrix[i][l][c] == 1100) {
                        printf("K");
                    }
                    if (matrix[i][l][c] == 1200) {
                        printf("L");
                    }

                    //AFFICHAGE TRESORS MOBILE
                    if (matrix[i][l][c] == 49000) {
                        printf("M");
                    }
                    if (matrix[i][l][c] == 40000) {
                        printf("N");
                    }
                    if (matrix[i][l][c] == 31000) {
                        printf("0");
                    }
                    if (matrix[i][l][c] == 22000) {
                        printf("P");
                    }
                    if (matrix[i][l][c] == 13000) {
                        printf("Q");
                    }
                    if (matrix[i][l][c] == 4000) {
                        printf("R");
                    }
                    if (matrix[i][l][c] == 49500) {
                        printf("S");
                    }
                    if (matrix[i][l][c] == 40500) {
                        printf("T");
                    }
                    if (matrix[i][l][c] == 31500) {
                        printf("U");
                    }
                    if (matrix[i][l][c] == 22500) {
                        printf("V");
                    }
                    if (matrix[i][l][c] == 13500) {
                        printf("W");
                    }
                    if (matrix[i][l][c] == 4500) {
                        printf("X");
                    }

                    if(matrix[i][l][c]<10)
                    {
                        if (matrix[i][l][c] == 0) {
                            Color(6, 6);
                            printf(" ");
                            color(couleur_blanche, 0);
                        } else if (matrix[i][l][c] == 1) {
                            Color(0, 0);
                            printf("%c", 0x20);
                            color(couleur_blanche, 0);
                        }
                    }

                    if (i == 6 + d && c == 2) {
                        if (l == 0 && (a == 1 || a == 3 || a == 5))
                            printf("\n%c ", 0x1A);
                            //if(l == 1 &&(a == 1 || a == 3 || a == 5))
                            //printf("%c\n ",0x1B);
                        else
                            printf("\n  ");
                        if (l == 2) {
                            //printf("\n  ");
                        }
                    }
                }
                if (i != 6 + d) {
                    //printf("   ");
                }
            }
        }
        d = d + 7;

    }
    afficher_la_derniere_piece(&compte_T,&compte_I,&compte_L,&compteL_tresors);
    return 1;


}
