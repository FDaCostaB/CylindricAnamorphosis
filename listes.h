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

typedef struct cellule_dict {
    struct cellule_dict *suivant;
    PointImage cle;
    SequencePix *valeur;
} Cellule_dict;

typedef struct dictionnaire{
    Cellule_dict *tete;
    unsigned int taille;
}Dictionnaire;

typedef struct tableauCoupleFlottant{
    UINT L,H;
    Point2D *tab;
}TableauCoupleFlottant;

void afficher (SequencePix* seq);

void ajoute_queue(SequencePix *l, Pixel P);

CellulePix* nouvelleCellule (void);

void detruireCellule (CellulePix*);

void detruireSequencePix (SequencePix*);

Cellule_dict* nouvelle_cellule_dict (void);

Dictionnaire *nouveauDict (void) ;

SequencePix * nouvelleSequence (void);

void afficherDict (Dictionnaire *dict);

SequencePix *recupValeur (Dictionnaire *dict, PointImage cle);

Cellule_dict *trouveCouple(Dictionnaire *dict, PointImage cle);

void ajoutModifEntree(Dictionnaire *dict, PointImage cle,Pixel val);

void detruireEntree (Dictionnaire *dict, PointImage cle);

void detruireDico (Dictionnaire *dict );

SequencePix *popEntree (Dictionnaire *dict, PointImage cle);

PointImage recupXminYmin(Dictionnaire *dict);

PointImage recupXmaxYmax(Dictionnaire *dict);

Pixel moyenneSeqPix(SequencePix * seq);

TableauCoupleFlottant *creerTableauCoordonnees(UINT L,UINT H);

//NON TESTE
Image dictToImage(Dictionnaire *dict);

#endif //INC_2ÈME_ANNÉE_LISTES_H
