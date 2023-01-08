#include "head.h"

int decalage(int matrix[49][3][3]) {
    int first_piece = 1;
    char quitter;
    int choix;
    int r = 0;
    int stocks[7][3][3];
    int piece_f[3][3];
    int piece_k[3][3];

    printf("\nchoisissez le cote a decaller\n");
    scanf("%d", &choix);

    if (choix == 1) {
        if (first_piece > 0) {
            first_piece--;
        }
        int z = -6;
        for (int i = 0; i < 7; i++) {
            z += 7;
            for (int j = 0; j < 3; ++j) {
                for (int k = 0; k < 3; ++k) {
                    stocks[i][j][k] = matrix[z][j][k];
                    piece_f[j][k] = matrix[43][j][k];
                }
            }
        }
        z = -6;
        for (int i = 0; i < 7; i++) {
            z += 7;
            for (int j = 0; j < 3; ++j) {
                for (int k = 0; k < 3; ++k) {
                    if (first_piece > 0) {
                        //piece_f[j][k] = matrice[j][k];
                    }
                    matrix[z + 7][j][k] = stocks[i][j][k];
                    matrix[1][j][k] = piece_f[j][k];
                }
            }
        }
    }

    if (choix == 2) {
        if (first_piece > 0) {
            first_piece--;
        }
        int z = -3;
        for (int i = 0; i < 7; i++) {
            z += 7;
            for (int j = 0; j < 3; ++j) {
                for (int k = 0; k < 3; ++k) {
                    stocks[i][j][k] = matrix[z][j][k];
                    piece_f[j][k] = matrix[45][j][k];
                }
            }
        }
        z = -3;
        for (int i = 0; i < 7; i++) {
            z += 7;
            for (int j = 0; j < 3; ++j) {
                for (int k = 0; k < 3; ++k) {
                    if (first_piece > 0) {
                        //piece_f[j][k] = matrice[j][k];
                    }
                    matrix[z + 7][j][k] = stocks[i][j][k];
                    matrix[3][j][k] = piece_f[j][k];

                }
            }
        }
    }

    if (choix == 3) {
        if (first_piece > 0) {
            first_piece--;
        }
        int z = -1;
        for (int i = 0; i < 7; i++) {
            z += 7;
            for (int j = 0; j < 3; ++j) {
                for (int k = 0; k < 3; ++k) {
                    stocks[i][j][k] = matrix[z][j][k];
                    piece_f[j][k] = matrix[47][j][k];
                }
            }
        }
        z = -1;
        for (int i = 0; i < 7; i++) {
            z += 7;
            for (int j = 0; j < 3; ++j) {
                for (int k = 0; k < 3; ++k) {
                    if (first_piece > 0) {
                        //piece_f[j][k] = matrice[j][k];
                    }
                    matrix[z + 7][j][k] = stocks[i][j][k];
                    matrix[5][j][k] = piece_f[j][k];

                }
            }
        }
    }

    if (choix == 4) {
        if (first_piece > 0) {
            first_piece--;
        }
        int z = 14;
        for (int i = 0; i < 7; i++) {
            z += -1;
            for (int j = 0; j < 3; ++j) {
                for (int k = 0; k < 3; ++k) {
                    stocks[i][j][k] = matrix[z][j][k];
                    piece_f[j][k] = matrix[7][j][k];

                }
            }
        }

        z = 14;
        for (int i = 0; i < 7; i++) {
            z += -1;
            for (int j = 0; j < 3; ++j) {
                for (int k = 0; k < 3; ++k) {
                    if (first_piece > 0) {
                        //piece_f[j][k] = matrice[j][k];
                    }
                    matrix[z - 1][j][k] = stocks[i][j][k];
                    matrix[13][j][k] = piece_f[j][k];
                }
            }
        }
    }

    if (choix == 5) {
        if (first_piece > 0) {
            first_piece--;
        }
        int z = 29;
        for (int i = 0; i < 7; i++) {
            z += -1;
            for (int j = 0; j < 3; ++j) {
                for (int k = 0; k < 3; ++k) {
                    stocks[i][j][k] = matrix[z][j][k];
                    piece_f[j][k] = matrix[21][j][k];

                }
            }
        }
        z = 29;
        for (int i = 0; i < 7; i++) {
            z += -1;
            for (int j = 0; j < 3; ++j) {
                for (int k = 0; k < 3; ++k) {
                    if (first_piece > 0) {
                        //piece_f[j][k] = matrice[j][k];
                    }
                    matrix[z - 1][j][k] = stocks[i][j][k];
                    matrix[27][j][k] = piece_f[j][k];

                }
            }
        }
    }
    if (choix == 6) {
        if (first_piece > 0) {
            first_piece--;
        }
        int z = 42;
        for (int i = 0; i < 7; i++) {
            z += -1;
            for (int j = 0; j < 3; ++j) {
                for (int k = 0; k < 3; ++k) {
                    stocks[i][j][k] = matrix[z][j][k];
                    piece_f[j][k] = matrix[1][j][k];
                }
            }
        }
        z = 42;
        for (int i = 0; i < 7; i++) {
            z += -1;
            for (int j = 0; j < 3; ++j) {
                for (int k = 0; k < 3; ++k) {
                    if (first_piece > 0) {
                        //piece_f[j][k] = matrice[j][k];
                    }
                    matrix[z - 1][j][k] = stocks[i][j][k];
                    matrix[41][j][k] = piece_f[j][k];
                }
            }
        }
    }

    if (choix == 7) {
        if (first_piece > 0) {
            first_piece--;
        }
        int z = 54;
        for (int i = 0; i < 7; i++) {
            z += -7;
            for (int j = 0; j < 3; ++j) {
                for (int k = 0; k < 3; ++k) {
                    stocks[i][j][k] = matrix[z][j][k];
                    piece_f[j][k] = matrix[5][j][k];
                }
            }
        }
        z = 54;
        for (int i = 0; i < 7; i++) {
            z += -7;
            for (int j = 0; j < 3; ++j) {
                for (int k = 0; k < 3; ++k) {
                    if (first_piece > 0) {
                        //piece_f[j][k] = matrice[j][k];
                    }
                    matrix[z - 7][j][k] = stocks[i][j][k];
                    matrix[47][j][k] = piece_f[j][k];
                }
            }
        }
    }

    if (choix == 8) {
        if (first_piece > 0) {
            first_piece--;
        }
        int z = 52;
        for (int i = 0; i < 7; i++) {
            z += -7;
            for (int j = 0; j < 3; ++j) {
                for (int k = 0; k < 3; ++k) {
                    stocks[i][j][k] = matrix[z][j][k];
                    piece_f[j][k] = matrix[3][j][k];
                }
            }
        }
        z = 52;
        for (int i = 0; i < 7; i++) {
            z += -7;
            for (int j = 0; j < 3; ++j) {
                for (int k = 0; k < 3; ++k) {
                    if (first_piece > 0) {
                        //piece_f[j][k] = matrice[j][k];
                    }
                    matrix[z - 7][j][k] = stocks[i][j][k];
                    matrix[45][j][k] = piece_f[j][k];

                }
            }
        }
    }

    if (choix == 9) {
        if (first_piece > 0) {
            first_piece--;
        }
        int z = 50;
        for (int i = 0; i < 7; i++) {
            z += -7;
            for (int j = 0; j < 3; ++j) {
                for (int k = 0; k < 3; ++k) {
                    stocks[i][j][k] = matrix[z][j][k];
                    piece_f[j][k] = matrix[1][j][k];
                }
            }
        }
        z = 50;
        for (int i = 0; i < 7; i++) {
            z += -7;
            for (int j = 0; j < 3; ++j) {
                for (int k = 0; k < 3; ++k) {
                    if (first_piece > 0) {
                        //piece_f[j][k] = matrice[j][k];
                    }
                    matrix[z - 7][j][k] = stocks[i][j][k];
                    matrix[43][j][k] = piece_f[j][k];
                }
            }
        }
    }

    if (choix == 10) {
        if (first_piece > 0) {
            first_piece--;
        }
        int z = 34;
        for (int i = 0; i < 7; i++) {
            z += +1;
            for (int j = 0; j < 3; ++j) {
                for (int k = 0; k < 3; ++k) {
                    stocks[i][j][k] = matrix[z][j][k];
                    piece_f[j][k] = matrix[41][j][k];
                }
            }
        }
        z = 34;
        for (int i = 0; i < 7; i++) {
            z += +1;
            for (int j = 0; j < 3; ++j) {
                for (int k = 0; k < 3; ++k) {
                    if (first_piece > 0) {
                        //piece_f[j][k] = matrice[j][k];
                    }
                    matrix[z +1][j][k] = stocks[i][j][k];
                    matrix[35][j][k] = piece_f[j][k];
                }
            }
        }
    }

    if (choix == 11) {
        if (first_piece > 0) {
            first_piece--;
        }
        int z = 20;
        for (int i = 0; i < 7; i++) {
            z += +1;
            for (int j = 0; j < 3; ++j) {
                for (int k = 0; k < 3; ++k) {
                    stocks[i][j][k] = matrix[z][j][k];
                    piece_f[j][k] = matrix[21][j][k];
                }
            }
        }
        z = 20;
        for (int i = 0; i < 7; i++) {
            z += +1;
            for (int j = 0; j < 3; ++j) {
                for (int k = 0; k < 3; ++k) {
                    if (first_piece > 0) {
                        //piece_f[j][k] = matrice[j][k];
                    }
                    matrix[z +1][j][k] = stocks[i][j][k];
                    matrix[27][j][k] = piece_f[j][k];
                }
            }
        }
    }

    if (choix == 12) {
        if (first_piece > 0) {
            first_piece--;
        }
        int z = 6;
        for (int i = 0; i < 7; i++) {
            z += +1;
            for (int j = 0; j < 3; ++j) {
                for (int k = 0; k < 3; ++k) {
                    stocks[i][j][k] = matrix[z][j][k];
                    piece_f[j][k] = matrix[13][j][k];
                }
            }
        }
        z = 6;
        for (int i = 0; i < 7; i++) {
            z += +1;
            for (int j = 0; j < 3; ++j) {
                for (int k = 0; k < 3; ++k) {
                    if (first_piece > 0) {
                        //piece_f[j][k] = matrice[j][k];
                    }
                    matrix[z + 1][j][k] = stocks[i][j][k];
                    matrix[7][j][k] = piece_f[j][k];
                }
            }
        }
    }

    if (choix == 13) {
        return 1;
    }


    int d = 0;
    //AFFICHER LE PLATEAU DE DEPART
    printf("\n         %c           %c           %c\n  ",0x19,0x19,0x19);
    for (int a = 0; a <7 ; a++) {
        for (int l = 0; l < 3; l++) {
            for (int i = d; i < d+7; i++) {
                for (int c = 0; c < 3; c++) {


                    if (matrix[i][l][c] == 2|| matrix[i][l][c] == 102|| matrix[i][l][c] == 202|| matrix[i][l][c] == 302|| matrix[i][l][c] == 402|| matrix[i][l][c] == 502|| matrix[i][l][c] == 602|| matrix[i][l][c] == 702|| matrix[i][l][c] == 802|| matrix[i][l][c] == 902|| matrix[i][l][c] == 1002|| matrix[i][l][c] == 1102|| matrix[i][l][c] == 1202|| matrix[i][l][c] == 49002|| matrix[i][l][c] == 40002|| matrix[i][l][c] == 31002|| matrix[i][l][c] == 22002|| matrix[i][l][c] == 13002|| matrix[i][l][c] == 4002|| matrix[i][l][c] == 49502|| matrix[i][l][c] == 40502|| matrix[i][l][c] == 31502|| matrix[i][l][c] == 22502|| matrix[i][l][c] == 13502|| matrix[i][l][c] == 4502) {

                        Color(9, 0);
                        printf("%c", 0xDB);
                        color(couleur_blanche, 0);

                    }


                    if (matrix[i][l][c] == 3 || matrix[i][l][c] == 103|| matrix[i][l][c] == 203|| matrix[i][l][c] == 303|| matrix[i][l][c] == 403|| matrix[i][l][c] == 503|| matrix[i][l][c] == 603|| matrix[i][l][c] == 703|| matrix[i][l][c] == 803|| matrix[i][l][c] == 903|| matrix[i][l][c] == 1003|| matrix[i][l][c] == 1103|| matrix[i][l][c] == 1203|| matrix[i][l][c] == 49003|| matrix[i][l][c] == 40003|| matrix[i][l][c] == 31003|| matrix[i][l][c] == 22003|| matrix[i][l][c] == 13003|| matrix[i][l][c] == 4003|| matrix[i][l][c] == 49503|| matrix[i][l][c] == 40503|| matrix[i][l][c] == 31503|| matrix[i][l][c] == 22503|| matrix[i][l][c] == 13503|| matrix[i][l][c] == 4503) {

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
                    if (matrix[i][l][c] == 100){
                        printf("A");
                    }
                    if (matrix[i][l][c] == 200){
                        printf("B");
                    }
                    if (matrix[i][l][c] == 300){
                        printf("C");
                    }
                    if (matrix[i][l][c] == 400){
                        printf("D");
                    }
                    if (matrix[i][l][c] == 500){
                        printf("E");
                    }
                    if (matrix[i][l][c] == 600){
                        printf("F");
                    }
                    if (matrix[i][l][c] == 700){
                        printf("G");
                    }
                    if (matrix[i][l][c] == 800){
                        printf("H");
                    }
                    if (matrix[i][l][c] == 900){
                        printf("I");
                    }
                    if (matrix[i][l][c] == 1000){
                        printf("J");
                    }
                    if (matrix[i][l][c] == 1100){
                        printf("K");
                    }
                    if (matrix[i][l][c] == 1200){
                        printf("L");
                    }
                    if (matrix[i][l][c] == 49000){
                        printf("M");
                    }
                    if (matrix[i][l][c] == 40000){
                        printf("N");
                    }
                    if (matrix[i][l][c] == 31000){
                        printf("0");
                    }
                    if (matrix[i][l][c] == 22000){
                        printf("P");
                    }
                    if (matrix[i][l][c] == 13000){
                        printf("Q");
                    }
                    if (matrix[i][l][c] == 4000){
                        printf("R");
                    }
                    if (matrix[i][l][c] == 49500){
                        printf("S");
                    }
                    if (matrix[i][l][c] == 40500){
                        printf("T");
                    }
                    if (matrix[i][l][c] == 31500){
                        printf("U");
                    }
                    if (matrix[i][l][c] == 22500){
                        printf("V");
                    }
                    if (matrix[i][l][c] == 13500){
                        printf("W");
                    }
                    if (matrix[i][l][c] == 4500){
                        printf("X");
                    }

                    if (matrix[i][l][c] == 0) {
                        printf("%c", 0xDB);
                    } else if(matrix[i][l][c] == 1){
                        printf("%c", ' ');}
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
                if (i != 6+d) {
                    printf("   ");
                }
            }
        }
        d=d+7;
    }

}
