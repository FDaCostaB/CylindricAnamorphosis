/****************************************************************************** 
  Interface du module image
******************************************************************************/

#ifndef _IMAGE_H_
#define _IMAGE_H_

#include <stdbool.h>
#include "types_erreur.h"
#include "geometrie3D.h"

/// Macro donnant l'indice d'un pixel de coordonnées (_x,_y) de l'image _I
#define INDICE_PIXEL(_I,_x,_y) ((_x))+(_I).L*((_y))

/// Type entier positif
typedef unsigned int UINT;

/// Type enuméré Pixel avec BLANC=255 et NOIR=0
typedef UINT Pixel;

/// Point 2d de |N
typedef struct PointImage {
    int x , y ;
}PointImage ;

/// Point 2d de |R
typedef struct Point2D {
    double x , y ;
}Point2D ;

/// Type Image
typedef struct Image_
{
	UINT L,H; /* largeur et hauteur de l'image */
	Pixel* tab; /*  tableau de pixels */
	/* le pixel d'abscisse x et d'ordonn�e y avec 1<=x<=L et 1<=y<=H 
	   est tab[x-1+L*(y-1)] */
} Image;

/// Création d'une image PBM de dimensions L x H avec tous les pixels blancs
Image creer_image(UINT L, UINT H);

/// Suppression de l'image I = *p_I
void supprimer_image(Image *p_I);

/// renvoie la valeur du pixel (x,y) de l'image I si (x,y) est hors de l'image la fonction renvoie BLANC
Pixel get_pixel_image(Image I, int x, int y);

/// change la valeur du pixel (x,y) de l'image I avec la valeur v si (x,y) est hors de l'image la fonction ne fait rien
void set_pixel_image(Image I, int x, int y, Pixel v);

/// Renvoie la largeur de l'image I
UINT largeur_image(Image I);

/// Renvoie la hauteur de l'image I
UINT hauteur_image(Image I);

void entete_fichier_pbm(FILE *f);

/// Lire l'image dans le fichier nommé nom_f s'il y a une erreur dans le fichier le programme s'arrete en affichant
/// un message
Image lire_fichier_image(char *nom_f);

/// écrire l'image I dans le fichier f
void ecrire_image(Image I,FILE *f);

///Test si l'image est toute blanche
bool est_vide(Image I);

void affich_point_2D(Point2D A);

#endif /* _IMAGE_H_ */
