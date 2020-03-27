//
// Created by fabie on 27/03/2020.
//

#ifndef CYLINDRICANAMORPHOSIS_TYPES_ERREUR_H
#define CYLINDRICANAMORPHOSIS_TYPES_ERREUR_H

#include <stdio.h>
#include <stdlib.h>

#define ERREUR_FATALE(_m_) \
{ \
fprintf(stderr, "%s\n", _m_); \
exit(1); \
}

#endif //CYLINDRICANAMORPHOSIS_TYPES_ERREUR_H
