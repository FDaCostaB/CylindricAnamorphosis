//
// Created by tangu on 28/03/2020.
//

#include "projection.h"
#include "geometrie3D.h"

Point projection_point(Point P,Point V,double r){

    Vecteur N = vect_normal_intersect(P,V,r);

    Vecteur R = reflexion_vect(vect_bipoint(P,V),N);

    Point res = intersection_feuille(intersect_point_cylindre(P,V,r),R);

    if (P.z==0 && P.y==105) {
        printf("Point v :");
        affich_point(V);
        printf("vecteur n :");
        affich_vect(N);
        printf("vecteur r :");
        affich_vect(R);
    }
    return res;
}


void remplissage_tableau_proj(TableauCoupleFlottant *T, Point P, Point V, double r){

    UINT L = T->L;
    UINT H = T->H;
    double val = P.y;

    for (int i=0;i<=H;i++){
        for (int j=0;j<=L;j++){

            Point res = projection_point(P,V,r);
            Point2D E;
            E.x = res.x;
            E.y = res.y;
            T->tab[j+i*T->L] = E;
            if (j==(L-1)){
                if (i==(H-1)){
                    affich_point_2D(T->tab[j + i * T->L]);
                    affich_point(P);
                }
            }
            P.y += 1;
        }
        P.z -=1;
        P.y = val;
    }
}

Dictionnaire *pixelisationResultat(TableauCoupleFlottant* Proj);