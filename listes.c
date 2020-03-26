//
// Created by tangu on 21/01/2020.
//
#include <stdio.h>
#include <stdlib.h>
#include "listes.h"



void ajoute_queue(Sequence *S, Point Pcurr) {
    Cellule *curr;
    Cellule *c;
    c = (Cellule *) malloc(sizeof(Cellule));
    c->P = Pcurr;
    c->suivant=NULL;
    if (S->tete==NULL) {
        S->tete=c;
        S->taille=1;
    }
    else {
        curr = S->tete;
        while (curr->suivant!=NULL) {
            curr = curr->suivant;

        }
        curr->suivant =c;
        S->taille=S->taille +1;
    }
    return;
}


void afficher (Sequence* seq)
{
    Cellule *curr;
    curr = seq->tete;
    while(curr != NULL){
        affich_point(curr->P);
        curr = curr->suivant;
    }

}

Cellule* nouvelleCellule (void){
    Cellule *cel =(Cellule*)malloc(sizeof(Cellule));
    cel->suivant = NULL;
    return cel;
}


void detruireCellule (Cellule* cel){
    free(cel);
}
