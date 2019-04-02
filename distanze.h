#ifndef DISTANZE_H
#define DISTANZE_H

typedef struct distanze_s* Distanze;

void allocaDistanze(Distanze *distanze);
void aggiungiElemento(Distanze distanze, void* i, double d);
void* getMinimoX(Distanze distanze, int x);
void liberaDistanze(Distanze distanze);

#endif //DISTANZE_H
