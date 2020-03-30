//
// Created by tangu on 28/03/2020.
//

#include "projection.h"
#include "geometrie3D.h"
#include "listes.h"


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

    UINT L = (T->L) - 1; //J'ai modifié creerTableauCoordonnees(L,H) il crée un tableau de (L+1) * (H+1)
    UINT H = (T->H) - 1; // L pixel il y a L+1 point sur une ligne. De même pour la colonne donc j'ai ajusté ici.
                         // Donc ici L=xmax et H=ymax et j'ai laissé les "<=" plus bas
    double val = P.y;

    for (int i=0;i<=H;i++){
        for (int j=0;j<=L;j++){

            Point res = projection_point(P,V,r);
            Point2D E;
            E.x = res.x;
            E.y = res.y;
            T->tab[j+i*T->L] = E;

            P.y += 1;
        }
        P.z -=1;
        P.y = val;
    }
}

void pixelisationPoint(TableauCoupleFlottant* Proj, Dictionnaire *res, int x, int y, Pixel val){
    Point2D min;
    Point2D max;
    PointImage minInt;
    PointImage maxInt;

    min.x = Proj->tab[ (x) + (y) * Proj->L].x;
    min.y = Proj->tab[ (x) + (y) * Proj->L].y;
    max.x = Proj->tab[ (x) + (y) * Proj->L].x;
    max.y = Proj->tab[ (x) + (y) * Proj->L].y;

    for(int i = x; i <= x+1; i++){
        for(int j = y; j <= y+1; j++){
            if(Proj->tab[ i + j * Proj->L ].x < min.x) min.x = Proj->tab[ i + j * Proj->L].x ;
            if(Proj->tab[ i + j * Proj->L ].x > max.x) max.x = Proj->tab[ i + j * Proj->L].x ;
            if(Proj->tab[ i + j * Proj->L ].y < min.y) min.y = Proj->tab[ i + j * Proj->L].y ;
            if(Proj->tab[ i + j * Proj->L ].y > max.y) max.y = Proj->tab[ i + j * Proj->L].y ;
        }
    }
    if(min.x>=0 && min.y>=0) minInt = (PointImage) { (int) min.x , (int) min.y  };
    if(min.x<0 && min.y>=0) minInt = (PointImage) { (int) min.x - 1 , (int) min.y  };
    if(min.x>=0 && min.y<0) minInt = (PointImage) { (int) min.x , (int) min.y - 1 };
    if(min.x<0 && min.y<0) minInt = (PointImage) { (int) min.x - 1 , (int) min.y -1 };

    if(max.x>=0 && max.y>=0) maxInt = (PointImage) { (int) max.x + 1 , (int) max.y + 1 };
    if(max.x<0 && max.y>=0) maxInt = (PointImage) { (int) max.x , (int) max.y +1  };
    if(max.x>=0 && max.y<0) maxInt = (PointImage) { (int) max.x +1 , (int) max.y };
    if(max.x<0 && max.y<0) maxInt = (PointImage) { (int) max.x , (int) max.y };

    /*for(int i = x; i <= x+1; i++) {
        for (int j = y; j <= y + 1; j++) {
            printf("(%f , %f) , ", Proj->tab[ i + j * Proj->L ].x, Proj->tab[ i + j * Proj->L ].y);
        }
    }
    printf("\nMin : ( %d , %d) , Max : ( %d , %d)\n",minInt.x,minInt.y,maxInt.x,maxInt.y);*/
    for(int i = minInt.x; i < maxInt.x; i++){
        for(int j = minInt.y; j < maxInt.y; j++){
            ajoutModifEntree(res, (PointImage) {i,j}, val);
        }
    }
    /*printf(" Point : ( %d, %d ) \n  Rectangle : ( %d , %d ) ( %d , %d )\n Valeur : %d \n", x , y, minInt.x, minInt.y, maxInt.x, maxInt.y,val);
    printf(" Projection des coins : ");
    for(int i = x; i <= x+1; i++){
        for(int j = y; j <= y+1; j++){
            printf(" ( %f , %f ) ", Proj->tab[ i + j * Proj->L ].x, Proj->tab[ i + j * Proj->L ].y);
        }
    }
    printf("\n");*/
}

Dictionnaire *pixelisationResultat(TableauCoupleFlottant* Proj, Image *image){
    Dictionnaire *res=nouveauDict();
    for(int y = 0; y < image->H; y++){
        for(int x = 0; x < image->L; x++){
            pixelisationPoint(Proj, res, x, y, image->tab[ x + (y * image->L) ]);
        }
        printf("Ligne : %d\n",y);
    }
    return res;
}