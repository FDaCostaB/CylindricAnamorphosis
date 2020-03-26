//
// Created by tangu on 26/03/2020.
//

#include "geometrie3D.h"

void affich_point(Point A){
    printf("Coordinates of the point : (%lf ; %lf ; %lf) \n",A.x,A.y,A.z);
}

void affich_vect(Vecteur A){
    printf("Coordinates of the vector : (%lf ; %lf ; %lf) \n",A.x,A.y,A.z);
}

Point set_point(double x, double y, double z){
    Point P = {x,y,z};
    return P;
}

Point add_point(Point A, Point B){
    Point P = {A.x + B.x, A.y + B.y, A.z + B.z} ;
    return P;
}


Vecteur vect_bipoint(Point A, Point B){
    Vecteur V = {B.x - A.x, B.y - A.y, B.z - A.z} ;
    return V;
}

Vecteur add_vect(Vecteur V1, Vecteur V2){
    Vecteur V = {V1.x + V2.x, V1.y + V2.y, V1.z + V2.z} ;
    return V;
}

Vecteur mult_scal(int x, Vecteur V1){
    Vecteur V = {V1.x * x, V1.y * x, V1.z * x};
    return V;
}

float dist_point(Point A, Point B){
    float val = sqrt((A.x-B.x)*(A.x-B.x) + (A.y-B.y)*(A.y-B.y) + (A.z-B.z)*(A.z-B.z));
    return val;
}

float prod_scal(Vecteur V1, Vecteur V2){
    float val = (V1.x * V2.x) + (V1.y * V2.y) + (V1.z * V2.z);
    return val;
}

float norme(Vecteur V1){
    float val = sqrt((V1.x*V1.x + V1.y*V1.y + V1.z*V1.z));
    return val;
}

float dist_point_cylindre(Point A){

}