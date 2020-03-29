//
// Created by fabie on 28/03/2020.
//

#include "listes.h"
#include "image.h"
#include "geometrie3D.h"
#include "types_erreur.h"

int main(int argc, char * argv[]){

    //Dictionnaire *nouveauDict (void) ;
    Dictionnaire * dico;
    dico = nouveauDict();
    SequencePix *p;
    Cellule_dict *cell = nouvelle_cellule_dict() ;
    PointImage minMax = {0,0};

    //void ajoutModifEntree(Dictionnaire *dict, PointImage cle,Pixel val);
    printf("\n###########################\n Test ajoutModifEntree (Ajout) \n###########################\n");

    PointImage A = {-84,6} ;
    PointImage B = {0,3} ;
    PointImage C = {32,-648} ;
    PointImage D = {162,-2048} ;
    PointImage Inconnu = {85,-12} ;

    ajoutModifEntree(dico, A, 55);
    ajoutModifEntree(dico, B, 0);
    ajoutModifEntree(dico, C, 255);
    ajoutModifEntree(dico, D, 14);

    //void afficherDict (Dictionnaire *dict);
    printf("\n###########################\n Test afficherDict \n###########################\n");
    afficherDict(dico);

    //Pixel recupValeur (Dictionnaire *dict, PointImage cle);
    printf("\n###########################\n Test recupValeur \n###########################\n");
    p = recupValeur(dico,B);
    printf("( %d, %d ) : ",B.x,B.y);
    afficher(p);
    printf("\n");

    p = recupValeur(dico,Inconnu);
    if(p!=NULL){
        printf("( %d, %d ) : ",Inconnu.x,Inconnu.y);
        afficher(p);
        printf("\n");
    }else{
        printf("-1\n");
    }


    p = recupValeur(dico,A);
    printf("( %d, %d ) : ",A.x,A.y);
    afficher(p);
    printf("\n");

    p = recupValeur(dico,D);
    printf("( %d, %d ) : ",D.x,D.y);
    afficher(p);
    printf("\n");

    //Cellule_dict *trouveCouple(Dictionnaire *dict, PointImage cle)
    printf("\n###########################\n Test trouveCouple \n###########################\n");

    cell = trouveCouple(dico,B);
    printf("( %d, %d ) : ",cell->cle.x,cell->cle.y);
    afficher(cell->valeur);
    printf("\n");

    cell = trouveCouple(dico,Inconnu);
    if(cell!=NULL)printf("PROBLEME ");
    else printf("-1\n");

    cell = trouveCouple(dico,A);
    printf("( %d, %d ) : ",cell->cle.x,cell->cle.y);
    afficher(cell->valeur);
    printf("\n");

    cell = trouveCouple(dico,D);
    printf("( %d, %d ) : ",cell->cle.x,cell->cle.y);
    afficher(cell->valeur);
    printf("\n");

    //void detruireEntree (Dictionnaire *dict, PointImage cle);
    printf("\n###########################\n Test detruireEntree \n###########################\n");

    detruireEntree(dico,B);
    afficherDict(dico);

    detruireEntree(dico,A);
    afficherDict(dico);

    detruireEntree(dico,D);
    afficherDict(dico);

    //void ajoutModifEntree(Dictionnaire *dict, PointImage cle,Pixel val);
    printf("\n###########################\n Test ajoutModifEntree (Ajout et Modif (32,-648) = 69 )\n###########################\n");
    ajoutModifEntree(dico, A, 55);
    ajoutModifEntree(dico, B, 0);
    ajoutModifEntree(dico, C, 69);
    ajoutModifEntree(dico, D, 14);

    afficherDict(dico);

    printf("\n###########################\n Test ajoutModifEntree (Modif (162,-2048) = 248 )\n###########################\n");

    ajoutModifEntree(dico, D, 248);

    afficherDict(dico);

    //Pixel popEntree (Dictionnaire *dict, PointImage cle);
    printf("\n###########################\n Test popEntree \n###########################\n");

    p = popEntree(dico,C);
    afficherDict(dico);
    printf("( %d, %d ) : ",C.x,C.y);
    afficher(p);
    printf("\n\n\n");


    p = popEntree(dico,D);
    afficherDict(dico);
    printf("( %d, %d ) : ",D.x,D.y);
    afficher(p);
    printf("\n\n\n");

    ajoutModifEntree(dico, C, 69);
    ajoutModifEntree(dico, D, 14);
    afficherDict(dico);

    p = popEntree(dico,A);
    afficherDict(dico);
    printf("( %d, %d ) : ",A.x,A.y);
    afficher(p);
    printf("\n\n\n");



    //PointImage recupXminYmin(Dictionnaire *dict);
    printf("\n###########################\n Test recupXminYmin \n###########################\n");
    ajoutModifEntree(dico, A, 55);
    afficherDict(dico);
    minMax = recupXminYmin(dico);
    printf("( %d, %d )\n",minMax.x, minMax.y);

    //PointImage recupXmaxYmax(Dictionnaire *dict);
    printf("\n###########################\n Test recupXmaxYmax \n###########################\n");
    minMax = recupXmaxYmax(dico);
    printf("( %d, %d )\n",minMax.x, minMax.y);

    //void detruireDico (Dictionnaire *dict );
    printf("\n###########################\n Test detruireDico \n###########################\n");
    detruireDico(dico);
    dico=nouveauDict();
    afficherDict(dico);

    printf("\n###########################\n Test recupXmaxYmax + recupXminYmin \n###########################\n");
    ajoutModifEntree(dico, A, 14);
    ajoutModifEntree(dico, B, 14);
    ajoutModifEntree(dico, C, 14);
    ajoutModifEntree(dico, D, 14);
    afficherDict(dico);

    minMax = recupXmaxYmax(dico);
    printf("( %d, %d )\n",minMax.x, minMax.y);

    minMax = recupXminYmin(dico);
    printf("( %d, %d )\n",minMax.x, minMax.y);

    printf("\n###########################\n Test detruireDico \n###########################\n");
    detruireDico(dico);
    dico=nouveauDict();
    afficherDict(dico);

    printf("\n###########################\n Test recupXmaxYmax + recupXminYmin \n###########################\n");
    ajoutModifEntree(dico, D, 14);
    ajoutModifEntree(dico, C, 14);
    ajoutModifEntree(dico, B, 14);
    ajoutModifEntree(dico, A, 14);
    afficherDict(dico);

    minMax = recupXmaxYmax(dico);
    printf("( %d, %d )\n",minMax.x, minMax.y);

    minMax = recupXminYmin(dico);
    printf("( %d, %d )\n",minMax.x, minMax.y);

    printf("\n###########################\n Test detruireDico \n###########################\n");
    detruireDico(dico);
    dico=nouveauDict();
    afficherDict(dico);

    printf("\n###########################\n Test moyenneSeqPix \n###########################\n");

    Pixel res;

    ajoutModifEntree(dico, D, 0);ajoutModifEntree(dico, D, 0);ajoutModifEntree(dico, D, 0);ajoutModifEntree(dico, D, 0);
    ajoutModifEntree(dico, D, 0);ajoutModifEntree(dico, D, 0);ajoutModifEntree(dico, D, 0);ajoutModifEntree(dico, D, 0);

    ajoutModifEntree(dico, C, 15);ajoutModifEntree(dico, C, 78);ajoutModifEntree(dico, C, 22);ajoutModifEntree(dico, C, 255);

    ajoutModifEntree(dico, B, 255);ajoutModifEntree(dico, B, 255);ajoutModifEntree(dico, B, 255);

    ajoutModifEntree(dico, A, 75);ajoutModifEntree(dico, A, 184);

    afficherDict(dico);

    p = popEntree(dico,D);
    res = moyenneSeqPix(p);
    afficher(p);
    printf("Moyenne : %d \n\n",res);

    p = popEntree(dico,C);
    res = moyenneSeqPix(p);
    afficher(p);
    printf("Moyenne : %d \n\n",res);

    p = popEntree(dico,B);
    res = moyenneSeqPix(p);
    afficher(p);
    printf("Moyenne : %d \n\n",res);

    p = popEntree(dico,A);
    res =moyenneSeqPix(p);
    afficher(p);
    printf("Moyenne : %d \n\n",res);

    ajoutModifEntree(dico, C, 0);

    p = popEntree(dico,C);
    res = moyenneSeqPix(p);
    afficher(p);
    printf("Moyenne : %d \n\n",res);

    p = popEntree(dico,D);
    res = moyenneSeqPix(p);
    afficher(p);
    printf("Moyenne : %d \n\n",res);

    ajoutModifEntree(dico, B, 214);ajoutModifEntree(dico, B, 168);ajoutModifEntree(dico, B, 3);

    p = popEntree(dico,B);
    res = moyenneSeqPix(p);
    afficher(p);
    printf("Moyenne : %d \n\n",res);

    /* NON TESTE
     *
     * Image dictToImage(Dictionnaire *dict);
     *
     * */

}