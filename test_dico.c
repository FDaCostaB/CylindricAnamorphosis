//
// Created by fabie on 28/03/2020.
//

#include "listes.h"
#include "image.h"
#include "geometrie3D.h"
#include "types_erreur.h"

int main(int argc, char * argv[]){
    
    FILE *f;

    if(argc != 3 ) ERREUR_FATALE("Utilisation commande : ./main fichier_image fichier_resultat\n");
    f = fopen(argv[2],"w");
    if(f==NULL) ERREUR_FATALE("Impossible d'ouvrir le fichier résultat en écriture.\n");

    //Image vide = creer_image();
    Image imageLu = lire_fichier_image(argv[1]);
    ecrire_image(imageLu,f);
}