//
// Created by tangu on 21/01/2020.
//

#ifndef INC_2ÈME_ANNÉE_LISTES_H
#define INC_2ÈME_ANNÉE_LISTES_H

#include <stdio.h>
#include "geometrie3D.h"
#include "image.h"
#include "types_erreur.h"

struct CellulePix{
    Pixel P;
    struct CellulePix *suivant;
};
typedef struct CellulePix CellulePix;

struct SequencePix{
    CellulePix *tete;
    unsigned int taille;
};
typedef struct SequencePix SequencePix;

typedef struct celluleLinkedL {
    struct celluleLinkedL *suivant;
    PointImage cle;
    Pixel valeur;
} CelluleLinkedList;

typedef struct LinkedList{
    CelluleLinkedList *tete;
    unsigned int taille;
}LinkedList;

typedef struct tableauCoupleFlottant{
    UINT L,H;
    Point2D *tab;
}TableauCoupleFlottant;

typedef struct tabSeqPix{
    UINT L,H;
    SequencePix **tab;
}TabSeqPix;

void afficher (SequencePix* seq);

void ajoute_queue(SequencePix *l, Pixel P);

CellulePix* nouvelleCellule (void);

void detruireCellule (CellulePix*);

void detruireSequencePix (SequencePix*);

CelluleLinkedList* nouvelleCelluleLinkedL (void);

LinkedList *nouvelleLinkedL (void) ;

SequencePix nouvelleSequence (void);

void afficherLinkedL (LinkedList *list);

//Meaning less as they are no more unique key
//SequencePix *recupValeur (LinkedList, PointImage cle);
//Cellule_dict *trouveCouple(Dictionnaire *dict, PointImage cle);
//void ajoutModifEntree(Dictionnaire *dict, PointImage cle,Pixel val);
//void detruireEntree (Dictionnaire *dict, PointImage cle);
//SequencePix *popEntree (Dictionnaire *dict, PointImage cle);

void ajoutEntree(LinkedList *list, PointImage cle,Pixel val);

void ajoutEntree(LinkedList *list, PointImage cle,Pixel val);

void detruireLinkedL (LinkedList *list );

PointImage recupXminYmin(LinkedList *list);

PointImage recupXmaxYmax(LinkedList *list);

Pixel moyenneSeqPix(SequencePix * seq);

TableauCoupleFlottant *creerTableauCoordonnees(UINT L,UINT H);

TabSeqPix *creerTableauSeqPixel(UINT L,UINT H);

TabSeqPix *convertLinkedLToTabSeqPix(LinkedList *list);

Image tabSeqPixToImage(TabSeqPix *tab);

#endif //INC_2ÈME_ANNÉE_LISTES_H
