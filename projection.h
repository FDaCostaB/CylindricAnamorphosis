//
// Created by tangu on 28/03/2020.
//

#ifndef PAN431_PROJECTION_H
#define PAN431_PROJECTION_H

#include "listes.h"
#include "image.h"
#include "geometrie3D.h"

///Renvoie la projection du point P
Point projection_point(Point P,Point V,double r);


void remplissage_tableau_proj(TableauCoupleFlottant *T, Point P, Point V, double r);

Dictionnaire *pixelisationResultat(TableauCoupleFlottant* Proj);

#endif //PAN431_PROJECTION_H
