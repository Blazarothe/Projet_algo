#include "head.h"


void depla(int matrix[49][3][3]) {
    int store;
    char depl;

    for (int i = 0; i < 49; ++i) {
        for (int l = 0; l < 3; ++l) {
            for (int c = 0; c < 3; ++c) {
                if (matrix[i][l][c] == 2) {
                    store = i;
                }
            }
        }
    }
    scanf("%c", &depl);

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

    if (depl == 'd') {
        matrix[store][1][1] = 1;
        matrix[store + 1][1][1] = 2;
    }

    if (depl == 'z') {
        matrix[store][1][1] = 1;
        matrix[store - 7][1][1] = 2;
    }

    if (depl == 's') {
        matrix[store][1][1] = 1;
        matrix[store + 7][1][1] = 2;
    }

    if (depl == 'q') {
        matrix[store][1][1] = 1;
        matrix[store - 1][1][1] = 2;
    }

    int d = 0;
    // AFFICHER LE PLATEAU DE DEPART
    printf("\n         %c           %c           %c\n  ", 0x19, 0x19, 0x19);
    for (int a = 0; a < 7; a++) {
        for (int l = 0; l < 3; l++) {
            for (int i = d; i < d + 7; i++) {
                for (int c = 0; c < 3; c++) {


                    if (matrix[i][l][c] == 2) {

                        Color(9, 0);
                        printf("%c", 0xDB);
                        color(couleur_blanche, 0);

                    }


                    if (matrix[i][l][c] == 3) {

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

                    if (matrix[i][l][c] == 0) {
                        printf("%c", 0xDB);
                    } else if (matrix[i][l][c] == 1) {
                        printf("%c", ' ');
                    }
                    if (i == 6 + d && c == 2) {
                        if (l == 0 && (a == 1 || a == 3 || a == 5))
                            printf("\n%c ", 0x1A);
                            //if(l == 1 &&(a == 1 || a == 3 || a == 5))
                            //printf("%c\n ",0x1B);
                        else
                            printf("\n  ");
                        if (l == 2) {
                            printf("\n  ");
                        }
                    }
                }
                if (i != 6 + d) {
                    printf("   ");
                }
            }
        }
        d = d + 7;
    }
}