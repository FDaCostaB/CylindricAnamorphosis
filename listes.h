//
// Created by tangu on 21/01/2020.
//

#ifndef INC_2ÈME_ANNÉE_LISTES_H
#define INC_2ÈME_ANNÉE_LISTES_H

#include <stdio.h>
#include "geometrie3D.h"
#include "image.h"

struct Cellule{
    Point P;
    struct Cellule *suivant;
};
typedef struct Cellule Cellule;

struct Sequence{
    Cellule *tete;
    unsigned int taille;
};
typedef struct Sequence Sequence;

typedef struct cellule_dict {
    struct cellule_dict *suivant;
    PointImage cle;
    Pixel valeur;
} Cellule_dict;

typedef struct dictionnaire{
    cellule_dict *tete;
    unsigned int taille;
}Dictionnaire;

typedef struct tableauCoupleFlottant{
    UINT L,H;
    Point2D *tab;
}TableauCoupleFlottant;

void afficher (Sequence* seq);

void ajoute_queue(Sequence *l, Point n);

Cellule* nouvelleCellule (void);

void detruireCellule (Cellule*);

Cellule_dict* nouvelle_cellule_dict (void);

Dictionnaire *nouveauDict (void) ;

void afficherDict (dictionnaire dict);

Pixel recupValeur (dictionnaire dict, PointImage cle);

void ajoutModifEntree(dictionnaire dict, PointImage cle,Pixel val);

void detruireEntree (dictionnaire dict, PointImage cle);

Pixel popEntree (dictionnaire dict, PointImage cle);

Pixel recupXminYmin(dictionnaire dict);

Pixel recupXmaxYmax(dictionnaire dict);

Image dictToImage(dictionnaire dict);

TableauCoupleFlottant creerTableauCoordonnees(void);


#endif //INC_2ÈME_ANNÉE_LISTES_H
