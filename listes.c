//
// Created by tangu on 21/01/2020.
//
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "listes.h"

void ajoute_queue(SequencePix *S, Pixel P) {
    CellulePix *curr;
    CellulePix *c;
    c = (CellulePix *) malloc(sizeof(CellulePix));
    c->P = P;
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
    CellulePix *curr;
    if(seq==NULL) return;
    curr = seq->tete;
    printf("[ ");
    while(curr != NULL){
        if(curr->suivant != NULL)printf("%d ,", curr->P);
        else printf("%d ]", curr->P);
        curr = curr->suivant;
    }

}

CellulePix* nouvelleCellule (void){
    CellulePix *cel =(CellulePix*)malloc(sizeof(CellulePix));
    cel->suivant = NULL;
    return cel;
}


void detruireCellule (CellulePix* cel){
    free(cel);
}

void detruireSequencePix (SequencePix* seq){
    CellulePix *curr = seq->tete;
    CellulePix *aSuppr;
    while(curr != NULL){
        aSuppr = curr;
        curr = curr->suivant;
        detruireCellule(aSuppr);
    }
    seq->tete=NULL;
    seq->taille=0;
    free(seq);
}

CelluleLinkedList* nouvelleCelluleLinkedL (void){
    CelluleLinkedList *cel = (CelluleLinkedList*)malloc(sizeof(CelluleLinkedList));
    cel->suivant = NULL;
    return cel;
}

LinkedList *nouvelleLinkedL (void){
    LinkedList* list = (LinkedList *)malloc(sizeof(LinkedList));
    list->tete = NULL;
    list->taille = 0;
    return list;
}

SequencePix * nouvelleSequencePix (void){
    SequencePix * seq = (SequencePix*)malloc(sizeof(SequencePix));
    seq->taille=0;
    seq->tete=NULL;
    return seq;
}

void afficherLinkedL (LinkedList *list){
    CelluleLinkedList *curr = list->tete;
    if(curr==NULL) {
        printf("Linked list is empty...\n");
    } else{
        printf("{ ");
        while(curr!=NULL){
            if(curr->suivant==NULL){
                printf(" ( %d, %d ) : %d }\n\n", curr->cle.x, curr->cle.y,curr->valeur);
            }else{
                printf(" ( %d, %d ) : %d ,", curr->cle.x, curr->cle.y,curr->valeur);
            }
            curr = curr->suivant;
        }
    }
}

void ajoutEntree(LinkedList *list, PointImage cle,Pixel val){
    CelluleLinkedList *nouv = nouvelleCelluleLinkedL();
    nouv->cle.x=cle.x;
    nouv->cle.y=cle.y;
    nouv->valeur=val;
    nouv->suivant = list->tete;
    list->tete=nouv;
    list->taille ++;
}

void ajouteTete(SequencePix *S, Pixel P) {
    CellulePix * nouv= (CellulePix *) malloc(sizeof(CellulePix));
    nouv->P = P;
    nouv->suivant=S->tete;
    S->tete=nouv;
    S->taille ++;
    return;
}

void detruireTete (LinkedList *list){
    CelluleLinkedList *curr = list->tete;
    CelluleLinkedList *aSuppr = NULL;
    if(curr==NULL) {
        printf("Head null pointer...");
        return;
    }
    else{
        aSuppr=curr;
        list->tete=curr->suivant;
        free(aSuppr);
        return;
    }
}

void detruireLinkedL (LinkedList *list ) {
    if (list != NULL) {
        while (list->tete != NULL){
            detruireTete(list);
        }
        free(list);
    }
    else {
        printf("Dictionnaire déjà vide...");
    }
}

PointImage recupXminYmin(LinkedList *list){
    CelluleLinkedList *curr = list->tete;
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

PointImage recupXmaxYmax(LinkedList *list){
    CelluleLinkedList *curr = list->tete;
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

/// Indice pixel 0<=x<=L-1 et 0<=y<=H-1
TabSeqPix *convertLinkedLToTabSeqPix(LinkedList *list){
    CelluleLinkedList *curr = list->tete;
    CelluleLinkedList *aSuppr;
    PointImage max = recupXmaxYmax(list);
    PointImage min = recupXminYmin(list);
    TabSeqPix *res = creerTableauSeqPixel(max.x - min.x + 1,max.y - min.y + 1);
    while(curr!=NULL){
        ajouteTete(res->tab[( curr->cle.x - min.x ) + ( curr->cle.y - min.y ) * (max.x - min.x + 1) ],curr->valeur);
        aSuppr = curr;
        curr = curr->suivant;
        free(aSuppr);

    }
    free(list);
    return res;
}

Image tabSeqPixToImage(TabSeqPix *tab){
    Image res = creer_image(tab->L,tab->H);
    for(int x = 0 ; x < tab->L ; x++){
        for(int y = 0 ; y < tab->H ; y++){
            if(tab->tab[x+y*tab ->L]->tete !=NULL)
                res.tab[(x + ((tab->H -1) - y) * tab->L) ] = moyenneSeqPix(tab->tab[x + y * tab->L  ]);
        }
    }
    return res;
}

Pixel moyenneSeqPix(SequencePix * seq){
    int taille = 0;
    double moyenne = 0;
    if(seq==NULL) return 0;
    CellulePix *curr = seq->tete;
    while(curr!=NULL){
        moyenne += curr->P;
        taille++;
        curr = curr->suivant;
    }
    moyenne = (double)moyenne / (double)taille;

    return (int)round(moyenne);
}

TableauCoupleFlottant *creerTableauCoordonnees(UINT L,UINT H){
    TableauCoupleFlottant *tab = (TableauCoupleFlottant*)malloc(sizeof(TableauCoupleFlottant));
    tab->L = L+1;
    tab->H = H+1;
    tab->tab = (Point2D *)malloc(sizeof(Point2D)*(L+1)*(H+1));

    /* test si le tableau a ete correctement alloue */
    if (tab->tab == (Point2D *)NULL){
        ERREUR_FATALE("Impossible de creer une image");
    }

    return tab;
}

TabSeqPix *creerTableauSeqPixel(UINT L,UINT H){
    TabSeqPix *tab = (TabSeqPix*)malloc(sizeof(TabSeqPix));
    tab->L = L;
    tab->H = H;
    tab->tab = (SequencePix **) malloc(sizeof(SequencePix*)*L*H);

    /* test si le tableau a ete correctement alloue */
    if (tab->tab == (SequencePix **)NULL){
        ERREUR_FATALE("Impossible de creer une image");
    }
    for(int x=0;x<L;x++){
        for(int y=0;y<H;y++){
            tab->tab[x + y*L]=nouvelleSequencePix();
        }
    }
    return tab;
}
