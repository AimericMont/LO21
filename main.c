/*
KACIMI Abdelhamid
MONTANGE Aimeric

main.c : Interface avec l'utilisateur, affichage et récuperation des données
*/

#include "fichier.h"

int main()
{
    printf("SYSTEME EXPERT");

    char car;
    int x, rep;

    basef BF; // Creation de la base de fait
    BF=Create_basef();
    printf("\n\nBASE F\n\nY a-t-il des faits deja connus ?\n0. non\n1. oui\n\n");
    rep=erreur_1_0();
    while(rep==1)
    {
        printf("\nVeuillez inserer la lettre du fait a ajouter\n");
        scanf("%c",&car);
        viderBuffer();
        car=Erreur_majuscule(car);
        BF=ajouter_basef(BF,car);
        printf("\nVoulez-vous ajouter un autre fait ?\n0. non\n1. oui\n\n");
        rep=erreur_1_0();
    }

    basec BC;
    BC=Create_basec();
    printf("\n\nBASE C (regle)\n\nInsertion 1ere regle\n\nQuelle est la lettre pour cette premisse ?\n");
    scanf("%c",&car);
    viderBuffer();
    car=Erreur_majuscule(car);
    BC->reglebc.premisse=Ajouterq_premisse(car,BC->reglebc.premisse);
    printf("\nVoulez-vous ajouter une autre lettre a cette premisse ?\n0. non\n1. oui\n\n");
    rep=erreur_1_0();
    while(rep==1)
    {
        printf("\nVeuillez inserer la lettre pour cette premisse\n");
        scanf("%c",&car);
        viderBuffer();
        car=Erreur_majuscule(car);
        BC->reglebc.premisse=Ajouterq_premisse(car,BC->reglebc.premisse);
        printf("\nVoulez-vous ajouter une autre lettre  cette premisse ?\n0. non\n1. oui\n\n");
        rep=erreur_1_0();
    }
    while(BC->reglebc.conclusion==NULL)
    {
        printf("\nVeuillez inserer la conclusion de cette regle\n");
        scanf("%c",&car);
        viderBuffer();
        car=Erreur_majuscule(car);
        BC->reglebc.conclusion=Creer_conclusion(BC->reglebc,car);
    }

    printf("\n\nVoici la regle que vous avez saisis\n");
    Afficher_Regle(BC->reglebc);
    printf("\n\n");


    Moteur_inference(BC,BF);

    accueil(BF,BC);

    return 0;
}
