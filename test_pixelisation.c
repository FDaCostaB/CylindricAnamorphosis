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

    pixelisationPoint(T,res,0,0,55);
    afficherDict(res);

    /*        A = { 0.0 , 0.0  };         B = { 0.0 , 0.0 };         C = { };
            D = { 0.0 , 0.0  }; Point2D E = { 0.0 , 0.0 }; Point2D F = { };
    Point2D G = { -28.8, 10.4}; Point2D H = { }; Point2D I = { };

    TableauCoupleFlottant *T = creerTableauCoordonnees(2,2);

    T->tab[0+0*T->L] = A;T->tab[0+0*T->L] = A;T->tab[0+0*T->L] = A;
    T->tab[0+0*T->L] = A;T->tab[0+0*T->L] = A;T->tab[0+0*T->L] = A;
    T->tab[0+0*T->L] = A;T->tab[0+0*T->L] = A;T->tab[0+0*T->L] = A; */

}