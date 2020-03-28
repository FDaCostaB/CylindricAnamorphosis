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

Vecteur mult_scal(double x, Vecteur V1){
    Vecteur V = {V1.x * x, V1.y * x, V1.z * x};
    return V;
}

double dist_point(Point A, Point B){
    double val = sqrt((A.x-B.x)*(A.x-B.x) + (A.y-B.y)*(A.y-B.y) + (A.z-B.z)*(A.z-B.z));
    return val;
}

double prod_scal(Vecteur V1, Vecteur V2){
    double val = (V1.x * V2.x) + (V1.y * V2.y) + (V1.z * V2.z);
    return val;
}

double norme(Vecteur V1){
    double val = sqrt((V1.x*V1.x + V1.y*V1.y + V1.z*V1.z));
    return val;
}

Point equation_PV(Point P, Point V, double t){
    Point L = { P.x + t*(V.x - P.x) , P.y + t*(V.y - P.y) , P.z + t*(V.z - P.z) };
    return L;
}

Point equation_droite(Point I, Vecteur R, double t){
    Point L = { I.x + t * R.x , I.y + t * R.y , I.z + t * R.z };
    return L;
}

double solution_quadratique(Coefs R, double r){ //r est le diamètre du cylindre
    double a = R.a;
    double b = R.b;
    double c = R.c;

    double ti = (double)(-b + sqrt(b*b - 4*a*( c- r*r )))/(double)(2*a);

    return ti;
}

Coefs coef_r2(Point P, Point V){

    Coefs R;
    R.a = P.x*P.x + P.y*P.y - 2*P.x*V.x- 2*P.y*V.y + V.x*V.x +V.y*V.y ;
    R.b = 2*P.x*V.x + 2*P.y*V.y - 2*P.x*P.x - 2*P.y*P.y;
    R.c = P.x*P.x + P.y*P.y;
    return R;
}

Point intersect_point_cylindre(Point P, Point V, double r){ // r est le diamètre du cylindre
    Coefs R = coef_r2(P,V);
    double ti = solution_quadratique(R, r);
    Point I = equation_PV(P, V, ti);
    return I;
}

Vecteur vect_normal_intersect(Point P, Point V, double r) { // r est le diamètre du cylindre
    Point inter = intersect_point_cylindre(P,V,r);
    Vecteur N = {inter.x, inter.y, 0};
    return N;
}

Vecteur proj_orthogonale(Vecteur V,Vecteur N){
    double lambda = prod_scal(V,N) / norme(N) ;
    Vecteur proj = mult_scal(lambda,N) ;
    return proj;
}

Vecteur reflexion_vect(Vecteur PV,Vecteur vect_normal){
    Vecteur proj = proj_orthogonale(PV,vect_normal);
    Vecteur reflexion = add_vect(mult_scal(2,proj),mult_scal(-1,PV));
    return reflexion;
}

Point intersection_feuille(Point I,Vecteur R){
    double t = -1 * (I.z / R.z);
    Point res = equation_droite(I,R,t);
    return res;
}