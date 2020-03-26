//
// Created by tangu on 26/03/2020.
//

#ifndef PAN431_GEOMETRIE3D_H
#define PAN431_GEOMETRIE3D_H

typedef struct Point {
    double x , y , z ;
} Point ;

typedef struct Vecteur {
    double x , y , z ;
} Vecteur ;


void affich_point(Point A);
void affich_vect(Vecteur A);

Point set_point(double x, double y, double z);
Point add_point(Point A, Point B);

Vecteur vect_bipoint(Point A, Point B);
Vecteur add_vect(Vecteur V1, Vecteur V2);
Vecteur mult_scal(int x, Vecteur V1);

float dist_point(Point A, Point B);

float prod_scal(Vecteur V1, Vecteur V2);
float norme(Vecteur V1);
float equation_P-V(Point P, Point V, float t);

float dist_point_cylindre(Point A);

#endif //PAN431_GEOMETRIE3D_H
