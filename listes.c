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


void afficher (SequencePix* seq)
{
    Cellule *curr;
    curr = seq->tete;
    while(curr != NULL){
        affich_point(curr->P);
        curr = curr->suivant;
    }

}

Cellule* nouvelleCellule (void){
    CellulePix *cel =(CellulePix*)malloc(sizeof(CellulePix));
    cel->suivant = NULL;
    return cel;
}


void detruireCellule (CellulePix* cel){
    free(cel);
}

Cellule_dict* nouvelle_cellule_dict (){
    Cellule_dict *cel = (Cellule_dict*)malloc(sizeof(Cellule_dict));
    cel->suivant = NULL;
    return cel;
}

Dictionnaire *nouveauDict (void){
    Dictionnaire *dict = (Dictionnaire *)malloc(sizeof(Dictionnaire));
    dict->tete=NULL;
    dict->taille = 0;
    return dict;
}

void afficherDict (Dictionnaire *dict){
    Cellule_dict *curr = dict->tete;
    if(curr==NULL) {
        printf("Dictionnaire vide...\n");
    } else{
        printf("{ ");
        while(curr!=NULL){
            if(curr->suivant==NULL){
                printf(" ( %d, %d ) : %d }\n", curr->cle.x, curr->cle.y, curr->valeur);
            }else{
                printf(" ( %d, %d ) : %d,", curr->cle.x, curr->cle.y, curr->valeur);
            }
            curr = curr->suivant;
        }
    }
}

Pixel recupValeur (Dictionnaire *dict, PointImage cle){
    Cellule_dict *curr = dict->tete;
    while(curr!=NULL){
        if(curr->cle.x==cle.x && curr->cle.y==cle.y){
            return curr->valeur;
        }
        curr = curr->suivant;
    }
    return -1;
}

Cellule_dict *trouveCouple(Dictionnaire *dict, PointImage cle) {
    Cellule_dict *curr = dict->tete;
    while(curr!=NULL){
        if(curr->cle.x==cle.x && curr->cle.y==cle.y){
            return curr;
        }
        curr = curr->suivant;
    }
    return NULL;
}

void ajoutModifEntree(Dictionnaire *dict, PointImage cle,Pixel val){
    Cellule_dict *res =trouveCouple(dict,cle);
    if(res!=NULL){
        res->valeur=val;
    }else{
        Cellule_dict *nouv = nouvelle_cellule_dict();
        nouv->cle.x=cle.x;
        nouv->cle.y=cle.y;
        nouv->valeur=val;
        nouv->suivant = dict->tete;
        dict->tete=nouv;
        dict->taille ++;
    }
}

void detruireEntree (Dictionnaire *dict, PointImage cle){
    Cellule_dict *curr = dict->tete;
    Cellule_dict *aSuppr = NULL;
    if(curr==NULL) {
        return;
    }
    if(curr->cle.x==cle.x && curr->cle.y==cle.y){
        aSuppr=curr;
        dict->tete=curr->suivant;
        free(aSuppr);
        return;
    }
    while(curr!=NULL && curr->suivant!=NULL){
        if(curr->suivant->cle.x==cle.x && curr->suivant->cle.y==cle.y){
            aSuppr=curr->suivant;
            curr->suivant=curr->suivant->suivant;
        }
        curr = curr->suivant;
    }
    if(aSuppr!=NULL)free(aSuppr);
    else printf("Clé introuvable et dictionnaire non modifié...");
}

void detruireDico (Dictionnaire *dict) {
    if (dict != NULL) {
        while (dict->tete != NULL){
            detruireEntree(dict, dict->tete->cle);
        }
        dict->taille=0;
        free(dict);
    }
    else {
        printf("Dictionnaire déjà vide...");
    }
}

Pixel popEntree (Dictionnaire *dict, PointImage cle){
    Cellule_dict *curr = dict->tete;
    Cellule_dict *aSuppr = NULL;
    Pixel res;
    if(curr==NULL) {
        return -1;
    }
    if(curr->cle.x==cle.x && curr->cle.y==cle.y){
        aSuppr=curr;
        dict->tete=curr->suivant;
        res = aSuppr->valeur;
        free(aSuppr);
        return res;
    }
    while(curr!=NULL && curr->suivant!=NULL){
        if(curr->suivant->cle.x==cle.x && curr->suivant->cle.y==cle.y){
            aSuppr=curr->suivant;
            curr->suivant=curr->suivant->suivant;
        }
        curr = curr->suivant;
    }
    if(aSuppr!=NULL){
        res=aSuppr->valeur;
        free(aSuppr);
        return res;
    }
    else {
        ERREUR_FATALE("Clé introuvable et Pop impossible.\n");
    }

}

PointImage recupXminYmin(Dictionnaire *dict){
    Cellule_dict *curr = dict->tete;
    PointImage min;
    if(curr==NULL) {
        ERREUR_FATALE("Dictionnaire vide");
    }
    min.x=curr->cle.x;
    min.y=curr->cle.y;
    while(curr!=NULL){
        if(curr->cle.x<min.x)min.x=curr->cle.x;
        if(curr->cle.y<min.y)min.y=curr->cle.y;
        curr = curr->suivant;
    }
    return min;
}

PointImage recupXmaxYmax(Dictionnaire *dict){
    Cellule_dict *curr = dict->tete;
    PointImage max;
    if(curr==NULL) {
        ERREUR_FATALE("Dictionnaire vide");
    }
    max.x=curr->cle.x;
    max.y=curr->cle.y;
    while(curr!=NULL){
        if(curr->cle.x>max.x)max.x=curr->cle.x;
        if(curr->cle.y>max.y)max.y=curr->cle.y;
        curr = curr->suivant;
    }
    return max;
}

///Indice pixel 0<=x<=L-1 et 0<=y<=H-1
Image dictToImage(Dictionnaire *dict){
    Cellule_dict *curr = dict->tete;
    PointImage max = recupXmaxYmax(dict);
    PointImage min = recupXminYmin(dict);
    Image res = creer_image(max.x - min.x,max.y - min.y);
    while(curr!=NULL){
        res.tab[( curr->cle.x - min.x )+ ( curr->cle.y - min.y )*max.x]=curr->valeur;
    }
    return res;
}

TableauCoupleFlottant *creerTableauCoordonnees(UINT L,UINT H){
    TableauCoupleFlottant *tab = (TableauCoupleFlottant*)malloc(sizeof(TableauCoupleFlottant));
    tab->L = L;
    tab->H = H;
    tab->tab = (Point2D *)malloc(sizeof(Point2D)*L*H);

    /* test si le tableau a ete correctement alloue */
    if (tab->tab == (Point2D *)NULL)
    {
        ERREUR_FATALE("Impossible de creer une image");
    }

    return tab;
}