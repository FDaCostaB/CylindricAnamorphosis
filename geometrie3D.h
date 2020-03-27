//
// Created by tangu on 26/03/2020.
//

#ifndef PAN431_GEOMETRIE3D_H
#define PAN431_GEOMETRIE3D_H

#include <math.h>

typedef struct Point {
    double x , y , z ;
} Point ;

typedef struct Vecteur {
    double x , y , z ;
} Vecteur ;

typedef struct Coefs {
    double a , b , c ;
} Coefs ;

void affich_point(Point A);
void affich_vect(Vecteur A);

Point set_point(double x, double y, double z);
Point add_point(Point A, Point B);

Vecteur vect_bipoint(Point A, Point B);
Vecteur add_vect(Vecteur V1, Vecteur V2);
Vecteur mult_scal(double x, Vecteur V1);

double dist_point(Point A, Point B);

double prod_scal(Vecteur V1, Vecteur V2);
double norme(Vecteur V1);

Point equation_PV(Point P, Point V, double t); Point equation_droite(Point I, Vecteur R, double t);
double solution_quadratique(Coefs R, double r);
Coefs coef_r2(Point P, Point V);

Point intersect_point_cylindre(Point P, Point V, double r);

Vecteur vect_normal_intersect(Point P, Point V, double r);

Vecteur proj_orthogonale(Vecteur V,Vecteur N);
Vecteur reflexion_vect(Vecteur PV,Vecteur vect_normal);

Point intersection_feuille(Point I,Vecteur R)

#endif //PAN431_GEOMETRIE3D_H
