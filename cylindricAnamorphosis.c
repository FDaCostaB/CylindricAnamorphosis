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

    if(argc != 3 ) ERREUR_FATALE("Command use : ./main image_file result_file\n");
    res = fopen(argv[2],"w");
    if(res == NULL) ERREUR_FATALE("Can't open result file");

    Image imageLue = lire_fichier_image(argv[1]);

    double L = (double)largeur_image(imageLue);
    double H = (double)hauteur_image(imageLue);
    printf("Height = %lf, Width = %lf\n",H,L);
    P.x = 0;
    P.y = -L/2.0;
    P.z = H;

    V.x = 5*H;
    V.y = 0;
    V.z = 2*H;

    r = 0.57 * L;

    TableauCoupleFlottant *T = creerTableauCoordonnees(L,H);
    remplissage_tableau_proj(T,P,V,r);
    printf("\nProjection finished\n");

    LinkedList *list = nouvelleLinkedL();
    list = pixelisationResultat(T,&imageLue);
    printf("\nPixelisation finished\n");

    Image image_modifiee;
    TabSeqPix *tab;
    tab = convertLinkedLToTabSeqPix(list);
    image_modifiee = tabSeqPixToImage(tab);
    printf("Picture transformation finished\n");

    ecrire_image(image_modifiee,res);
    printf("Creation of the new image finished. Open %s to see the result (if it doesn't look like anything, it's successful !).\n",argv[2]);
}
