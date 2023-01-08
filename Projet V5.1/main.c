#include "head.h"



int main() {
    int matrix[49][3][3];
    int choix;
    int nbr_joueurs = 2;
    int *J1[24/nbr_joueurs];

    choix = menu();
    conditions(choix,&nbr_joueurs,matrix);
    // tresors_joueurs(nbr_joueurs,J1);

    // for(int i=0;i<24/nbr_joueurs;i++){
    //printf("\n%d sz",*J1[i]);}



}
