//
// Created by fabie on 26/03/2020.
//

#include "listes.h"
#include "image.h"
#include "geometrie3D.h"

int main(int argc, char * argv[]){

    Point P; //starting position (image)
    Point V; //Viewer position
    float r; //cylinder diameter

    if(argc != 3 ) ERREUR_FATALE("Utilisation commande : ./main fichier_image fichier_resultat\n");
    f = fopen(argv[2],"w");
    if(f==NULL) {
        printf("Impossible d'ouvrir le fichier résultat en écriture.\n");
        return -1;
    }
    //Image vide = creer_image();
    Image imageLu = lire_fichier_image(argv[1]);
    ecrire_image(imageLu,f);
}