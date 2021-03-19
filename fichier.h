/*
KACIMI Abdelhamid
MONTANGE Aimeric

fichier header : contient les prototypes des fonctions utlisées
et les differentes structures de données utilisées.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define VRAI 1
#define FAUX 0

typedef struct elem {   char lettre;
                        int present;
                        struct elem* suivant;
                    }   element;

typedef element* liste;                          //Structure permettant de definir une liste chainée de regle, qui constitura la base de connaissance



typedef struct {liste premisse;
                char conclusion;
                }regle;

typedef int boolean;                            //Structure permettant de créer une regle

typedef struct ELEM {   regle reglebc;
                        struct ELEM* suivant;
                    }   ELEMENT;

typedef ELEMENT* basec;                         //Structure permettant de definir une liste chainée de regle, qui constitura la base de connaissance

typedef struct E {char fait;
                  struct E* suivant;
                  }El;

typedef El* basef;                              //Structure permettant de definir une liste chainée de proposition, qui constitura la base de fait

liste Ajouterq_premisse (char c, liste R);      //fonctions relatives aux premisses et conclusions d'une regle
void Afficher_premisse (liste pre);
regle Creer_regle(liste pre, char conclu);
regle Creer_regle_vide();
char Creer_conclusion(regle R, char conclu);
boolean Is_present(char c,liste a_tester);
regle Remove(char c, regle R);
void Afficher_Regle(regle R);
void Affichage_present (liste pre,char c);
boolean Is_empty (regle R);
char Head_Premisse (regle R);
char Conclusion (regle R);

basec ajouter_reglebc (basec BC, regle R);          //fonctions relatives a la base de connaissance
basec Create_basec();
regle Head_basec (basec B);
void Afficher_basec(basec BC);

void Afficher_basef (basef BF);                     //fonctions relatives a la base de fait
basef ajouter_basef(basef BF, char c);
basef Create_basef();
boolean Is_presentf(char c,basef F);

int erreur_1_0(void);                               //fonctions relatives a l'affichage du main
char Erreur_majuscule(char x);
void accueil(basef BF, basec BC);

void viderBuffer();

void changementpresence (char c, basec C);          //fonctions relatives au moteur d'inference permettant de faire fonctionner notre systeme expert
void Moteur_inference (basec C,basef F);



