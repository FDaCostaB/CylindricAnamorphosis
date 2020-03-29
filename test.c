//
// Created by fabie on 26/03/2020.
//

#include "listes.h"
#include "image.h"
#include "geometrie3D.h"
#include "types_erreur.h"

int main(int argc, char * argv[]){

    Point P; //starting position (image)
    Point V; //Viewer position
    float r; //cylinder diameter
    FILE *f;

    if(argc != 3 ) ERREUR_FATALE("Utilisation commande : ./main fichier_image fichier_resultat\n");
    f = fopen(argv[2],"w");
    if(f==NULL) ERREUR_FATALE("Impossible d'ouvrir le fichier résultat en écriture.\n");

    //Image vide = creer_image();
    Image imageLue = lire_fichier_image(argv[1]);

    double L = (double)largeur_image(imageLue);
    double H = (double)hauteur_image(imageLue);

    printf("Hauteur = %lf et largeur = %lf\n",H,L);
    P.x = 0;
    P.y = -(L-1)/2.0;
    P.z = H-1;

    V.x = 5*H;
    V.y = 0;
    V.z = 3*H;

    r = 1.20 * L;

    TableauCoupleFlottant *T = creerTableauCoordonnees(L,H);


}