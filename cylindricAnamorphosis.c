//
// Created by fabie on 29/03/2020.
//

#include "listes.h"
#include "image.h"
#include "geometrie3D.h"
#include "types_erreur.h"
#include "projection.h"
#include <math.h>

int main(int argc, char * argv[]){

    Point P; //starting position (image)
    Point V; //Viewer position
    double r; //cylinder diameter

    if(argc != 2 ) ERREUR_FATALE("Utilisation commande : ./main fichier_image \n");

    Image imageLue = lire_fichier_image(argv[1]);

    double L = (double)largeur_image(imageLue);
    double H = (double)hauteur_image(imageLue);
    printf("Hauteur = %lf et largeur = %lf\n",H,L);
    P.x = 0;
    P.y = -L/2.0;
    P.z = H;

    V.x = 5*H;
    V.y = 0;
    V.z = 3*H;

    r = 1.20 * L;

    //Vecteur N = vect_normal_intersect(P,V,r);

    //Vecteur R = reflexion_vect(vect_bipoint(P,V),N);

    //Point res = intersection_feuille(intersect_point_cylindre(P,V,r),R);

    TableauCoupleFlottant *T = creerTableauCoordonnees(L,H);
    remplissage_tableau_proj(T,P,V,r);


}
