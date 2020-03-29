//
// Created by fabie on 29/03/2020.
//



#include "listes.h"
#include "image.h"
#include "geometrie3D.h"
#include "types_erreur.h"
#include "projection.h"

int main(int argc, char * argv[]){

    //void pixelisationPoint(TableauCoupleFlottant* Proj, Dictionnaire *res, int x, int y, Pixel val)
    TableauCoupleFlottant *T;
    Dictionnaire *res=nouveauDict();

    Point2D A = { 0.0 , 0.0 }; Point2D B = { 0.0 , 0.0 };
    Point2D C = { 0.0 , 0.0 }; Point2D D = { 0.0 , 0.0 };

    T = creerTableauCoordonnees(1,1);


    T->tab[0+0*T->L] = A;T->tab[1+0*T->L] = B;
    T->tab[0+1*T->L] = C;T->tab[1+1*T->L] = D;

    //pixelisationPoint(T,res,0,0,55);
    Image im = creer_image(1,1);
    res = pixelisationResultat(T,&im);
    afficherDict(res);

    A = (Point2D){ 1.2 , 0.2  };B = (Point2D){ -2.3 , 0.3 };C = (Point2D){ 3.3 ,- 0.2 };
    D = (Point2D){ -47.3 , -89.1  }; Point2D E = { 1.8 , 0.8 }; Point2D F = { 3.8 , -2.8 };
    Point2D G = { -28.8, 10.6}; Point2D H = { -0.5 , 0.5 }; Point2D I = { 12.0 , 12.0 };

    T = creerTableauCoordonnees(2,2);

    T->tab[0+0*T->L] = A;T->tab[1+0*T->L] = B;T->tab[2+0*T->L] = C;
    T->tab[0+1*T->L] = D;T->tab[1+1*T->L] = E;T->tab[2+1*T->L] = F;
    T->tab[0+2*T->L] = G;T->tab[1+2*T->L] = H;T->tab[2+2*T->L] = I;

    im = creer_image(2,2);
    res = pixelisationResultat(T,&im);
    //afficherDict(res);

}