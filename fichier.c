/*
KACIMI Abdelhamid
MONTANGE Aimeric

fichier.c : code des fonctions utlisées pour le bon fonctionnement du programme
*/

#include "fichier.h"


regle Creer_regle(liste pre, char conclu)           //crée une regle a partir d'une premisse et d'une conclusion
{
    regle R;
    R.premisse=pre;
    R.conclusion=conclu;
    return R;
}





regle Creer_regle_vide()                            // crée une regle dont la premisse et la conclusion sont vide
{
    regle R;
    R.premisse=NULL;
    R.conclusion=NULL;
    return R;
}





liste Ajouterq_premisse (char c, liste pre)            //permet de d'ajouter un caractere en queue d'une premisse
{
    liste temp, i;
	temp = (element*)malloc(sizeof(element));
    temp->lettre=c;                                     // la proposition est ajoutée dans une liste temp contenant seulement cette proposition
    temp->suivant=NULL;
    temp->present=0;

    if (Is_present(c,pre)==1)                           // si la proposition est deja presente, on retourne la premisse intacte
    {
        printf("\nErreur : cette proposition est deja presente dans la premisse\n");
        return pre;
    }

    if (pre==NULL)                                      // si la premisse est vide on retourne la liste temp
    {
        return temp ;
    }
    else
	{
		i=pre;                                          // sinon on parcourt la liste jusqu'au dernier element
		while (i->suivant != NULL)                      // pour ajouter la proposition de la liste temp en queue
        {
            i=i->suivant;
        }
		i->suivant = temp;
		return pre;
	}

}





char Creer_conclusion (regle R, char conclu)                // permet de créer une conclusion a partir d'une regle et d'un caractere
{
    liste temp;
    temp=(element*)malloc(sizeof(element));
    temp=R.premisse;
    if (Is_present(conclu,temp)==1)                         // si le carctere est deja la conclusion on retourne cette conclusion
    {
        printf("\nErreur : c'est une des premisses\n");
        return R.conclusion;
    }

    if(R.conclusion==NULL)                                  //si la conclusion est vide on retourne le caractere
    {
        return conclu;
    }
    else
    {
        printf("\nErreur : la regle a deja une conclusion.\n");         // sinon la conclusion a deja une valeur
        return R.conclusion;
    }

}





void Afficher_premisse (liste pre)                  // permet d'afficher la premisse de la forme A+B+C=
{
    liste temp;
    temp=(element*)malloc(sizeof(element));
    temp=pre;

    if (pre==NULL)
    {
        printf("\nLa premisse est vide\n");
    }
    else
    {
        while(temp->suivant!=NULL)
        {
            printf("%c+",temp->lettre);
            temp=temp->suivant;
        }
        printf("%c=",temp->lettre);
    }
}





void Afficher_Regle(regle R)                        // permet d'afficher une regle entiere (premisse et conclusion)
{                                                   // de la forme A+B+C=D
    Afficher_premisse(R.premisse);
    printf("%c",R.conclusion);
}





boolean Is_present(char c,liste a_tester)           // permet de savoir si une propostion est dans une liste, donc si
{                                                   // le caractere est deja dans la premisse, renvoyant un boolean
    if (a_tester==NULL)
    {
        return 0;
    }
    if (a_tester->lettre==c)
        {
            return 1;
        }
        else
        {
            return Is_present(c,a_tester->suivant);
        }
}





void Affichage_present (liste pre,char c)           // permet d'afficher la presence ou non d'une proposition dans une liste
{
    if (Is_present(c,pre))
    {
        printf("\ntrouve\n");
    }
    else
    {
        printf("\npas trouve\n");
    }
}





regle Remove(char c, regle R)                       // permet de supprimer une proposition d'une premisse
{
    if (Is_present(c,R.premisse)==0)                // si la proposition n'est pas dans la premisse : message d'erreur
    {
        printf("\nCette proposition n'est pas dans cette regle\n");
    }
    else
    {
        liste temp, l;
        temp=(element*)malloc(sizeof(element));
        temp= R.premisse;
        while(c!=temp->suivant->lettre)
        {
            temp=temp->suivant;
        }
        l = temp->suivant;                          // on se place sur l'element contenant la proposition est on passe au suivant
        temp->suivant=temp->suivant->suivant;       // tout en liberant sa place memoire
        free(l);
    }
    return R;
}





boolean Is_empty (regle R)                      // permet de tester si une regle est vide ou remplie, renvoyant un boolean
{
    if (R.premisse==NULL)
    {
        printf("\nvide\n");
        return VRAI;
    }
    else
    {
        printf("\nremplie\n");
        return FAUX;
    }
}





char Head_Premisse (regle R)            // permet de renvoyer la proposition en tete d'une premisse, soit le premier element
{
    return R.premisse->lettre;
}





char Conclusion (regle R)               // permet de renvoyer la conclusion d'une regle
{
    return R.conclusion;
}





basec ajouter_reglebc (basec BC, regle R)           // permet d'ajouter une regle a la base de connaissance
{
    basec temp, i;
    temp = (ELEMENT*)malloc(sizeof(ELEMENT));
    temp->reglebc=R;                                // on stock la regle dans une base de connaissance temporaire
    temp->suivant=NULL;

    if (BC==NULL)                                   // si la base de connaissance est vide on renvoie simplement la base de connaissance temporaire
    {
        return temp;
    }
    else
    {
        i=BC;                                       // sinon on se place a la fin de la base de connaissance afin d'y ajouter notre regle en queue
        while (i->suivant != NULL)                  // et ainsi retourner la base de connaissance
        {
            i=i->suivant;
        }
		i->suivant=temp;
		return BC;
    }
}





basec Create_basec()                                // permet de creer une base de connaissance vide avec son emplacement memoire attitrer
{
    basec B;
    B = (ELEMENT*)malloc(sizeof(ELEMENT));
    regle R;
    R=Creer_regle_vide();
    B->reglebc=R;
    B->suivant=NULL;
    return B;
}





regle Head_basec (basec B)                          // permet de rnvoyer la premiere regle de la base de connaissance, celle en tete
{
    return B->reglebc;
}





void Afficher_basec(basec BC)                       // permet d'afficher toute les regles de la base de connaissance
{
    basec temp;
    temp=(ELEMENT*)malloc(sizeof(ELEMENT));
    temp=BC;
    while(temp!=NULL)
    {
        Afficher_Regle(temp->reglebc);
        printf("\n");
        temp=temp->suivant;
    }
}





void Afficher_basef (basef BF)                      // permet d'afficher les propositions de la base de faits
{
    basef temp;
    temp=(El*)malloc(sizeof(El));
    temp=BF;

    if (temp==NULL)                                 // si la base de contient aucun element, message d'erreur
    {
        printf("\nLa premisse est vide\n");
    }
    else
    {
        printf("\nVoici votre base de fait :\n{");      // Sinon on affiche dans la forme {A-B-C}
        while(temp->suivant!=NULL)
        {
            printf("%c-",temp->fait);
            temp=temp->suivant;
        }
        printf("%c}",temp->fait);
    }
}





basef ajouter_basef(basef BF, char c)               // permet d'ajouter une proposition a la base de fait
{
    basef temp, i;
	temp = (El*)malloc(sizeof(El));
    temp->fait=c;
    temp->suivant=NULL;

    if (Is_presentf(c,BF)==1)                       // si la base contient deja la proposition: message d'erreur
    {
        printf("\nErreur : ce fait est deja dans la BF\n");
        return BF;
    }

    if (BF->fait==NULL)                             // si la liste est nulle on retourne l'element a ajouter
    {
        return temp ;
    }
    else
	{
		i=BF;                                      // sinon on parcourt la base pour pouvoir l'ajouter en queue
		while (i->suivant != NULL)
        {
            i=i->suivant;
        }
		i->suivant = temp;
		return BF;
	}
}





basef Create_basef()                                // permet de creer une base de fait vide avec son emplacement memoire attitré
{
    basef temp;
    temp=(El*)malloc(sizeof(El));
    temp->fait=NULL;
    temp->suivant=NULL;
    return temp;
}





boolean Is_presentf(char c,basef F)                 // renvoie un boolean en fonction de la presence ou non d'une proposition dans la base de fait
{
    if (F==NULL)
    {
        return 0;
    }

    if (F->fait==c)
    {
        return 1;
    }
    else
    {
        return Is_presentf(c,F->suivant);
    }
}





int erreur_1_0(void)                         // permet d'afficher un message d'erreur si l'entrée est differente de 1 ou 0 et de corriger en fonction
{                                               // de l'entrée
        int rep;

        scanf("%i",&rep);
        viderBuffer();

        while(rep!=1 && rep!=0)
        {
            printf("\nVeuillez inserez 1 ou 0\n\n");
            scanf("%i",&rep);
            viderBuffer();
        }
        return rep;
}





void accueil (basef BF, basec BC)                                                   //Menu en switch avec plusieurs operations possibles
{
    int x, rep;
    char car;

    printf("\n\nQue voulez faire ?\n\n1. Creer une nouvelle regle\n2. Afficher les regles\n3. Ajouter un fait\n4. Afficher les faits\n0. Quitter le programme\n\n");
    scanf("%i",&x);
    viderBuffer();
    while (x<0 || x>4)
    {
        printf("\n\nQue voulez faire ?\n\n1. Creer une nouvelle regle\n2. Afficher les regles\n3. Ajouter un fait\n4. Afficher les faits\n0. Quitter le programme\n\n");
        scanf("%i",&x);
        viderBuffer();
    }


    switch (x)
    {
    case 1:                                                                         // Ajout d'une regle à la base de connaissance
        BC=ajouter_reglebc(BC,Creer_regle_vide());
        basec temp;
        temp=(ELEMENT*)malloc(sizeof(ELEMENT));
        temp=BC;
        while (temp->suivant!=NULL)
        {
            temp=temp->suivant;
        }
        printf("\nVeuillez inserer la lettre pour cette premisse\n");
        scanf("%c",&car);
        viderBuffer();
        car=Erreur_majuscule(car);
        temp->reglebc.premisse=Ajouterq_premisse(car,temp->reglebc.premisse);       // Insertion du char de la premiere proposition de la premisse
        printf("\nVoulez-vous ajouter une autre lettre a cette premisse ?\n0. non\n1. oui\n\n");
        rep=erreur_1_0();
        while(rep==1)                                                               // Tant que l'utilisateur souhaite inserer une autre premissse
        {                                                                           //L'opération d'ajout de premisse se repette
            printf("\n\nVeuillez inserer la lettre pour cette premisse\n");
            scanf("%c",&car);
            viderBuffer();
            car=Erreur_majuscule(car);
            temp->reglebc.premisse=Ajouterq_premisse(car,temp->reglebc.premisse);
            printf("\nVoulez-vous ajouter une lettre a cette premisse ?\n0. non\n1. oui\n\n");
            rep=erreur_1_0();
        }
        while(temp->reglebc.conclusion==NULL)                                       //Quand l'utilisateur saisis 0, le char de la conclusion est demandé
        {
            printf("\n\nVeuillez inserer la conclusion de cette regle\n");
            scanf("%c",&car);
            car=Erreur_majuscule(car);
            viderBuffer();
            temp->reglebc.conclusion=Creer_conclusion(temp->reglebc,car);           // Insertion de la conclusion
        }
        printf("\n\nVoici la regle que vous avez saisis\n");
        Afficher_Regle(temp->reglebc);
        printf("\n\n");
        Moteur_inference(BC,BF);
        Afficher_basef(BF);
        accueil(BF,BC);                                                             //Le menu s'affiche à nouveaux lorsque l'operation est rerminée
        break;
    case 2:                                                                         //Affichage de la base de connaissance donc des regles
        printf("\n");
        Afficher_basec(BC);
        printf("\n");
        accueil(BF,BC);                                                             //Le menu s'affiche à nouveaux lorsque l'operation est rerminée
        break;
    case 3:                                                                         //Ajout d'un fait à la base de fait
        printf("\nVeuillez inserer la lettre de ce fait\n");
        scanf("%c",&car);
        viderBuffer();
        car=Erreur_majuscule(car);
        BF=ajouter_basef(BF,car);
        printf("\nVoulez-vous ajouter un autre fait ?\n0. non\n1. oui\n\n");
        rep=erreur_1_0();
        while(rep==1)                                                               // Tant que l'utilisateur souhaite inserer un autre fait
        {                                                                           //L'opération d'ajout de fait se repette
            printf("\n\nVeuillez inserer la lettre de ce fait\n");
            scanf("%c",&car);
            viderBuffer();
            car=Erreur_majuscule(car);
            BF=ajouter_basef(BF,car);
            printf("\nVoulez-vous ajouter une autre fait ?\n0. non\n1. oui\n\n");
            rep=erreur_1_0();
        }
        printf("\n");
        Afficher_basef(BF);
        printf("\n");
        Moteur_inference(BC,BF);
        Afficher_basef(BF);
        accueil(BF,BC);                                                             //Le menu s'affiche à nouveaux lorsque l'operation est rerminée
        break;
    case 4:                                                                         // Cet option affiche la base de fait donc tous les faits
        printf("\n");
        Afficher_basef(BF);
        printf("\n");
        accueil(BF,BC);                                                             //Le menu s'affiche à nouveaux lorsque l'operation est rerminée
        break;
    case 0:
        return 0;
        break;

    }
}





void Moteur_inference(basec BC,basef BF)
{
    basec bcbis;
    bcbis=(ELEMENT*)malloc(sizeof(ELEMENT));
    bcbis=BC;

    liste i;
    i=(element*)malloc(sizeof(element));

    basef bfbis;
    bfbis=(El*)malloc(sizeof(El));
    bfbis=BF;

    while(bfbis!=NULL)  //On change la valeur "présent" de chaque proposition si celle-si est un fait
    {
        changementpresence(bfbis->fait,BC);
        bfbis=bfbis->suivant;
    }

    bfbis=BF;

    while (bcbis!=NULL) // on etudie toutes les regles donc toute la base de connaissance
    {
        i=bcbis->reglebc.premisse;
        if(Is_presentf(bcbis->reglebc.conclusion,BF)==0) // on passe à la regle suivant car il est inutile de rajouter une conclusion deja
        {                                                // presente dans la base de fait
            while(i!=NULL && i->present==1) //on passe à la regle suivante si une des premisses n'est pas un fait car il faut que toutes les
            {                               //premisses soit des faits pour que la conclusion en soit un
                if(i->suivant!=NULL) // on continue de parcourir la premisse jusqu'a la fin de celle-ci
                {
                    i=i->suivant;
                }
                else
                {
                    if(BF->fait==NULL) // on ajoute la conclusion à la base de fait et on relance le moteur lorsqu'il y a un nouveau fait car ce dernier peut impliquer d'autres propositions
                    {
                        BF->fait=bcbis->reglebc.conclusion;
                        i=i->suivant;
                        Moteur_inference(BC,BF); //
                    }
                    else
                    {
                        BF=ajouter_basef(BF,bcbis->reglebc.conclusion);
                        i=i->suivant;
                        Moteur_inference(BC,BF);
                    }
                }
            }

        }
        bcbis=bcbis->suivant;
    }

}





void changementpresence(char a, basec C) //On change la valeur "présent" de chaque proposition si celle-si est un fait
{
    basec bcbis;
    bcbis=(ELEMENT*)malloc(sizeof(ELEMENT));
    bcbis=C;

    liste l;
    l=(element*)malloc(sizeof(element));

    while (bcbis!=NULL)             //On parcours toutes les regles donc toute la base de connaissance
    {
        l=bcbis->reglebc.premisse;
        if( Is_present(a,l) == 1)   //On etudie cette regle seulement si le fait est une des premisses
        {
            while( a != l->lettre)  //On parcours la liste de premisse jusqu'a ce que l'on arrive au fait
            {
                l=l->suivant;
            }
            l->present=1;   //Changement de la valeur
        }
    bcbis=bcbis->suivant;
    }
}





char Erreur_majuscule(char x)                   // permet de verifier si l'element entrée est un bien un lettre
{
    while(x<'A' || (x>'Z' && x<'a')||x>'z')
        {
            printf("\nVeuillez rentrer une lettre\n");
            scanf("%c",&x);
            viderBuffer();
        }
    x=toupper(x);                               // transforme la lettre en lettre majuscule afin de manipuler le meme type de lettre
    return x;
}





void viderBuffer()                              // permet de vider le buffer afin qu'aucune donnée ne soit utilisé pour autre chose
{                                               // que son usage
    int c = 0;
    while (c != '\n' && c != EOF)
    {
        c = getchar();
    }
}

