//
// Created by tangu on 26/03/2020.
//


void affich_point(Point A){
    printf("Coordinates of the point : (%lf ; %lf ; %lf) \n",A.x,A.y,A.z);
}

void affich_vect(Vecteur A){
    printf("Coordinates of the vector : (%lf ; %lf ; %lf) \n",A.x,A.y,A.z);
}



Point set_point(double x, double y, double z){

}

Point add_point(Point A, Point B){

}
Point sub_point(Point A, Point B){

}

Vecteur vect_bipoint(Point A, Point B){

}

Vecteur add_vect(Vecteur V1, Vecteur V2){

}

Vecteur mult_scal(int x, Vecteur V1){

}

float dist_point(Point A, Point B){}

float prod_scal(Vecteur V1, Vecteur V2);
float norme(Vecteur V1);

float dist_point_cylindre(Point A);