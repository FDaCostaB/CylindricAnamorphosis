//
// Created by tangu on 21/01/2020.
//

#ifndef INC_2ÈME_ANNÉE_LISTES_H
#define INC_2ÈME_ANNÉE_LISTES_H

#include <stdio.h>
#include "geometrie3D.h"

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


void afficher (Sequence* seq);

void ajoute_queue(Sequence *l, Point n);

Cellule* nouvelleCellule (void);

void detruireCellule (Cellule*);


#endif //INC_2ÈME_ANNÉE_LISTES_H
