#include "head.h"

int menu()
{
    color(couleur_blanche, 0);
    int rep_menu;
    printf("                     Bonjour, chers voyageurs, laissez-moi vous presenter notre merveilleux projet : \n\n");
    printf("                            [L]  [e]    [L]  [a]  [b]  [y]  [r]  [i]  [n]  [t]  [h]  [e]\n");
    printf("\n\n\n");

    //Menu avec les différentes options
    printf("Voici les differentes options se presentant a vous dans l'absolu :\n\n");
    printf("                                     -------------------------------------\n");
    printf("                                    |          1.Nouvelle partie          |\n");
    printf("                                     -------------------------------------\n\n");
    printf("                                     -------------------------------------\n");
    printf("                                    |             2.Sauvegarde            |\n");
    printf("                                     -------------------------------------\n\n");
    printf("                                     -------------------------------------\n");
    printf("                                    |        3. Charger une partie        |\n");
    printf("                                     -------------------------------------\n\n");
    printf("                                     -------------------------------------\n");
    printf("                                    |   4. Afficher les regles / credits  |\n");
    printf("                                     -------------------------------------\n\n");
    printf("                                     -------------------------------------\n");
    printf("                                    |           5. Quitter le jeu         |\n");
    printf("                                     -------------------------------------\n\n");
    printf("Quel sera votre choix : ");
    scanf("%i", &rep_menu);

    //Blindage des valeurs de l'utilisateur
    if(rep_menu != 1 && rep_menu != 2 && rep_menu != 3 && rep_menu != 4 && rep_menu != 5)
    {
        do {
            fflush(stdin);
            printf("Veuillez reesayer S.V.P (Repondez par 1, 2, 3, 4 ou 5) :\n");
            scanf(" %i", &rep_menu);
        } while (rep_menu != 1 && rep_menu != 2 && rep_menu != 3 && rep_menu != 4 && rep_menu != 5);
    }

    //Les choix
    if (rep_menu == 5) //Quitter le jeu
    {
        printf("Vous avez quitt%c le jeu du labyrinthe.", 130);
        return 0;
    }
    else
        return rep_menu;
}

void conditions(int choix, int* nmbre_joueurs, int matrix[49][3][3])
{
    int sauvegarde = 0;
    char Oui_ou_Non[4];
    char r_ou_c;
    int partie_debut = 0;


    color(couleur_blanche, 0);

    if(choix == 1)
    {
        if(sauvegarde == 1) //-> Blindage pour savoir si, oui ou non, l'utilisateur avait déjà une partie en cours
        {
            printf("Etes-vous sur de vouloir eraser l'ancienne sauvegarde (y ou n) ?\n");
            scanf("%3s", Oui_ou_Non);

            if(Oui_ou_Non[0] == 'y')
            {
                printf("D%cmarrage d'une nouvelle partie...\n", 130);
                partie_debut = 1; //Ca va servir pour blinder la sauvegarde (ligne 70)
                system("cls"); //effacement de la console
                // nouvelle_partie(nmbre_joueurs); //Sous-programme Nouvelle partie (Alternative #1)

            }
            else
            {
                choix = menu();
                conditions(choix,nmbre_joueurs,matrix);
            }
        }
        printf("Demarrage d'une nouvelle partie...\n");
        partie_debut = 1; //Ca va servir pour blinder la sauvegarde (ligne 70)
        nouvelle_partie(nmbre_joueurs,matrix); //Sous-programme Nouvelle partie (Alternative #2)
    }

    if(choix == 2)
    {
        if(partie_debut == 0)
        {
            printf("Vous n'avez encore aucune partie en cours.\n"
                   "Retour au menu");
            Sleep(500); //attente de 1000 ms
            printf(".");
            Sleep(500);
            printf(".");
            Sleep(500);
            printf(".\n");
            Sleep(500);
            system("cls"); //clear screen
            Sleep(500);
            choix = menu();
            conditions(choix,nmbre_joueurs,matrix);
        }

        else
        {
            printf("Sauvegarde de la partie en cours...");
            Sleep(100);
            system("cls"); //clear écran
            Sleep(100);
            //Sous programme Sauvegarde
        }
    }

    if(choix == 3)
    {
        if(sauvegarde == 0)
        {
            printf("Vous n'avez pas d'anciennes parties a votre actif\n");
            printf("Retour au menu");
            Sleep(500); //attente de 500 ms
            printf(".");
            Sleep(500);
            printf(".");
            Sleep(500);
            printf(".\n");
            Sleep(500);
            system("cls"); //clear ecran
            Sleep(500);
            choix = menu();
            conditions(choix,nmbre_joueurs,matrix);
        }
        else
        {
            printf("Chargement de l'ancienne partie...");
            Sleep(500);
            system("cls"); //clear écran
            Sleep(500);
            //Sous-programme chargement
        }

    }

    if(choix == 4)
    {
        regles_et_credits();
    }
}

void color(int couleur_texte,int fond)
{
    HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(H,fond*16+couleur_texte);
}

void nouvelle_partie(int *nmbre_joueurs,int matrix[49][3][3]) {

    int i, action, deplacement;
    int num_pion[4];
    char nom_personnage[nombre_joueurs_max][le_prenom_devient_long];

    Sleep(500);
    system("cls"); //Clear screen
    Sleep(500);
    printf("\n                            [L]  [e]    [L]  [a]  [b]  [y]  [r]  [i]  [n]  [t]  [h]  [e]\n\n\n");
    printf("                          Ce jeu ne peut se jouer que de 2 a 4 joueurs... Combien etes vous : \n\n");
    printf("                                                       Nous sommes ");
    scanf("%i", nmbre_joueurs);
    Sleep(150);
    system("cls");
    Sleep(150);

    if (*nmbre_joueurs < nombre_joueurs_min || *nmbre_joueurs > nombre_joueurs_max) //Blindage nombre de joueurs, boucle infinie si input != nombre
    {
        do {
            fflush(stdin);
            printf("\n                            [L]  [e]    [L]  [a]  [b]  [y]  [r]  [i]  [n]  [t]  [h]  [e]\n\n\n");
            printf("                         Veuillez reesayer S.V.P (minimum [2 joueurs] et maximum [4 joueurs]) :\n\n");
            printf("                                                    Nous sommes ");
            scanf("%i", nmbre_joueurs);
            Sleep(150);
            system("cls");
            Sleep(150);
        } while (*nmbre_joueurs < nombre_joueurs_min || *nmbre_joueurs > nombre_joueurs_max);
    }
    printf("\n                            [L]  [e]    [L]  [a]  [b]  [y]  [r]  [i]  [n]  [t]  [h]  [e]\n\n\n");
    printf("                                     Les pions disponibles sont les suivants :\n\n");

    color(9, 0); //pion bleu
    printf("                                                   1. Le chevalier\n\n");

    color(5, 0); //pion pourpre
    printf("                                                     2. Le mage\n\n");

    color(2, 0); //pion vert
    printf("                                                     3. L'elfe\n\n");

    color(14, 0); //pion jaune-fluo
    printf("                                                     4. Le nain\n\n\n");

    for (i = 0; i < *nmbre_joueurs; i++)
    {
        color(couleur_blanche, 0);
        printf("*   Joueur %i : Quel pion choisissez-vous (Repondez par le numero) : ", i+1);
        scanf("%i", &num_pion[i]); //Stockage dans un tableau, peut poser des problemes apres

        if (num_pion[i] != 1 && num_pion[i] != 2 && num_pion[i] != 3 && num_pion[i] != 4) //Blindage choisissage de pion
        {
            do {
                Sleep(150);
                system("cls");
                Sleep(150);
                fflush(stdin);
                printf("\n                            [L]  [e]    [L]  [a]  [b]  [y]  [r]  [i]  [n]  [t]  [h]  [e]\n\n\n");
                printf("                                  Ce personnage n'existe pas (pions : [1, 2, 3, 4]) :\n\n");
                printf("                                                Je choisis le pion  ");
                scanf("%i", &num_pion[i]);
            } while (num_pion[i] != 1 && num_pion[i] != 2 && num_pion[i] != 3 && num_pion[i] != 4);
        }

        if (num_pion[i] == num_pion[i-1] || num_pion[i] == num_pion[i-2] || num_pion[i] == num_pion[i-3])
        {
            do
            {
                fflush(stdin);
                printf("Ce pion est deja pris malheureusement, veuillez en prendre un autre...\n");
                printf("Joueur %i : Quel pion choisissez-vous (Repondez par un numero pas encore pris par votre camarade) ?\n", i+1);
                scanf("%i", &num_pion[i]);
            } while (num_pion[i] == num_pion[i-1] || num_pion[i] == num_pion[i-2] ||num_pion[i] == num_pion[i-3]);
        }
        printf("*  Comment se nommera votre personnage ?\n"); //Definition du nom du personnage
        scanf("%s", &nom_personnage[i][le_prenom_devient_long]);
    }
    resume_pions(*nmbre_joueurs, num_pion, nom_personnage); //Sous-programme faisant apparaitre un resume des personnages
    color(couleur_blanche, 0);
    printf("Nous pouvons donc commencer a explorer ce labyrinthe remplie de mysteres, de creatures mais surtout de tresors...");

    int player = 3;
    zebi(matrix,*nmbre_joueurs);
    while(nmbre_joueurs !=0)
    {
        depla(matrix,player);
        for (i = 0; i < *nmbre_joueurs; i++)
        {
            printf("                                       * joueur %i, c'est à ton tour : \n", i+1);
            printf("Commence par deplacer une ligne du labyrinthe...\n");
            system("pause"); //Deplacer + Clear + Afficher le nouveau labyritnhe
            printf("Ensuite, voici les differentes options que tu peux effectuer :\n\n");
            printf("                                     -------------------------------------\n");
            printf("                                    |            1.Te Deplacer            |\n");
            printf("                                     -------------------------------------\n\n");
            printf("                                     -------------------------------------\n");
            printf("                                    |   2.Retourner au menu (Fin partie)  |\n");
            printf("                                     -------------------------------------\n\n");
            printf("                                     -------------------------------------\n");
            printf("                                    |             3. Fin du Tour          |\n");
            printf("                                     -------------------------------------\n\n");
            printf("Quel sera votre choix : ");
            scanf("%i", &action);
            if (action == 1)
            {
                do
                {
                    printf("* Appuyez sur Z pour aller tout droit\n"
                           "* Appuyez sur Q pour aller a gauche\n"
                           "* Appuyez sur D pour aller a droite\n"
                           "* Appuyez sur S pour reculer\n");
                    depla(matrix,*nmbre_joueurs);
                    printf("Voulez-vous continuer a vous deplacer ? (1 = oui, 0 = non) : ");
                    scanf("%i", &deplacement);
                }while(deplacement == 1);
            }
        }
    }

}

void regles_et_credits()
{
    int choix;
    int *nmbre_joueurs, nbr_joueurs, matrix[49][3][3];
    system("cls");
    Sleep(150);
    printf("\n                            [L]  [e]    [L]  [a]  [b]  [y]  [r]  [i]  [n]  [t]  [h]  [e]\n\n\n");
    color(12, 0);
    printf("*    But du jeu.\n\n");
    color(15, 0);
    printf("    Vous penetrez dans un labyrinthe enchante a la recherche de fabuleux tresors et de mysterieuses creatures.\n");
    printf("Chacun d'entre vous essaye de creer des chemins pour atteindre le tresor qu'il convoite en faisant coulisser \nastucieusement les couloirs.");
    printf("Le joueur qui aura trouve tous ses tresors et rejoint sa case depart le premier \nsera declare vainqueur.\n");
    printf(" \n");
    printf(" \n");
    color(12, 0);
    printf("*    Deroulement de la partie.\n\n");
    color(15, 0);
    printf("    Chaque joueur commence par regarder secretement la carte superieure de sa pile ; elle indique le premier tresor\nqu'il doit trouver. ");
    printf("Le dernier joueur a avoir participe a une chasse aux tresors entame la partie. \n");
    printf(" \n\n");
    color(3, 0);
    printf("*    Le tour d'un joueur se decompose en deux etapes :\n\n");
    color(15, 0);
    printf("    1) Modifier les couloirs.\n");
    printf("    2) Deplacer son pion.\n");
    printf(" \n");
    printf("    Quand vient son tour, le joueur doit essayer d'atteindre la case sur laquelle figure le meme tresor que sur la cartesuperieure de sa pile.");
    printf(" Pour cela, il modifie toujours d'abord le labyrinthe en inserant la plaque Couloir, \npuis deplace son pion. \n");
    printf("\n\n");
    color(3, 0);
    printf("*    1. modification des couloirs \n");
    color(15, 0);
    printf("\n    Quand vient son tour, le joueur choisit une rangee et un sens pour la piece qu'il veut inserer puis indique \ndans la console la rangee et le sens qu'il souhaite pour sa piece");
    printf("\n\n\n");
    color(3, 0);
    printf("*    2. Deplacement du pion\n\n");
    color(15, 0);
    printf("    Apres avoir modifie le labyrinthe, le joueur peut deplacer son pion jusqu'a n'importe quelle case en suivant \nun couloir ininterrompu.");
    printf(" Il peut se deplacer aussi loin qu'il veut. Il est aussi permis de rester sur place. ");
    printf("\nSi un joueur atteint le tresor recherche, il l'a trouve ! Le compteur lui comptera alors 1 point. ");
    printf(" Le prochain tresor \nqu'il a a trouver lui est alors montre.\n");
    printf(" \n");
    color(4, 0);
    printf("Conseil : Si un joueur ne peut pas atteindre directement son but, il peut se deplacer aussi loin qu'il veut de maniere a etre en meilleure position pour le tour suivant.\n");
    printf(" \n");
    printf("\n");
    color(couleur_blanche, 0);
    printf("Le gagnant est le premier joueur a trouver tout les tresors qui lui ont ete demander de trouver et a retourne à son point de depart\n\n");

    color(12, 0);
    printf("Fin de la partie...\n");
    color(couleur_blanche, 0);
    printf(" \n");

    system("pause");
    Sleep(150);
    system("cls");
    Sleep(150);
    choix = menu();
    conditions(choix, &nbr_joueurs,matrix);

}

void resume_pions(int joueurs, int numero[4], char nom[nombre_joueurs_max][le_prenom_devient_long])
{
   int i;
    Sleep(150);
    system("cls");
    Sleep(150);
    printf("                            [L]  [e]    [L]  [a]  [b]  [y]  [r]  [i]  [n]  [t]  [h]  [e]\n\n\n");
    printf("                                Tres bien, vous avez choisi vos pions avec succes\n");                                                      //resume des pions
    printf("                                        Donc, pour resumer, nous avons :\n\n");

    for (i = 0; i < joueurs; i++)
    {

        if (numero[i] == 1)
        {
            color(9, 0);
            printf("\n                                            Joueur %i : %s le chevalier\n", i+1, nom[i+1]);
        }
        else if (numero[i] == 2)
        {
            color(5, 0);
            printf("\n                                            Joueur %i : %s le mage\n", i+1, nom[i+1]);
        }
        else if (numero[i] == 3)
        {
            color(2, 0);
            printf("\n                                            Joueur %i : %s l'elfe\n", i+1, nom[i+1]);
        }
        else
        {
            color(14, 0);
            printf("\n                                            Joueur %i : %s le nain\n\n\n", i+1, nom[i+1]);
        }
    }
}

void tresors_joueurs(int nbr_joueurs,int *tresors_joueurs1[24/nbr_joueurs]){
    //int tresors_joueurs1[24/nbr_joueurs];
    int tresors_joueurs2[24/nbr_joueurs];
    int tresors_joueurs3[24/nbr_joueurs];
    int tresors_joueurs4[24/nbr_joueurs];
    int s;
    int compte_joueurs1=0;
    int compte_joueurs2=0;
    int compte_joueurs3=0;
    int compte_joueurs4=0;
    for(int i=0;i<24;i++){
        srand(time(NULL));
        s=rand()%nbr_joueurs;
        if(s==0 && compte_joueurs1<24/nbr_joueurs){
            *tresors_joueurs1[compte_joueurs1]=i*10;
            compte_joueurs1=compte_joueurs1+1;
        }
        else {
            s=1+rand()%nbr_joueurs-1;
        }

        if(s==1 && compte_joueurs2<24/nbr_joueurs){
            tresors_joueurs2[compte_joueurs2]=i*10;
            compte_joueurs2=compte_joueurs2+1;
        }
        else {
            if(compte_joueurs1>0){
                *tresors_joueurs1[compte_joueurs1]=i*10;
            }
        }
        if(s==2 && compte_joueurs3<24/nbr_joueurs) {
            tresors_joueurs3[compte_joueurs3] = i * 10;
            compte_joueurs3 = compte_joueurs3 + 1;
        }
        else{
            if(compte_joueurs1>0){
                *tresors_joueurs1[compte_joueurs1]=i*10;
            }
            else if(compte_joueurs2>0){
                *tresors_joueurs1[compte_joueurs2]=i*10;
            }
        }
        if(s==3 && compte_joueurs4<24/nbr_joueurs) {
            tresors_joueurs4[compte_joueurs4] = i * 10;
            compte_joueurs4 = compte_joueurs4 + 1;
        }
        else{
            if(compte_joueurs1>0){
                *tresors_joueurs1[compte_joueurs1]=i*10;
            }
            else if(compte_joueurs2>0){
                tresors_joueurs2[compte_joueurs2]=i*10;
            }
            else if(compte_joueurs3>0){
                tresors_joueurs3[compte_joueurs3]=i*10;
            }
        }
    }
}
