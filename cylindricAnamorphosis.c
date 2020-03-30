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
    FILE *res;

    if(argc != 3 ) ERREUR_FATALE("Utilisation commande : ./main fichier_image fichier_résultat\n");
    res = fopen(argv[2],"w");
    if(res == NULL) ERREUR_FATALE("Fichier resultat compromis");

    Image imageLue = lire_fichier_image(argv[1]);

    double L = (double)largeur_image(imageLue);
    double H = (double)hauteur_image(imageLue);
    printf("Hauteur = %lf et largeur = %lf\n",H,L);
    P.x = 0;
    P.y = -L/2.0;
    P.z = H;

    V.x = 5*H;
    V.y = 0;
    V.z = 2*H;

    r = 1.20 * L;

    TableauCoupleFlottant *T = creerTableauCoordonnees(L,H);
    remplissage_tableau_proj(T,P,V,r);
    printf("\nProjection terminée\n");

    Dictionnaire *dict = nouveauDict();
    dict = pixelisationResultat(T,&imageLue);
    printf("\nPixelisation terminée\n");
    //afficherDict(dict);

    Image image_modifiee;
    image_modifiee = dictToImage(dict);
    printf("Transformation en image terminée\n");

    ecrire_image(image_modifiee,res);
    printf("Creation of the new image finished. Open %s to see the result (if it doesn't look like anything, it's successful !).\n",argv[2]);
}
