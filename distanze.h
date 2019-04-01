#ifndef DISTANZE_H
#define DISTANZE_H

typedef struct distanze_s* Distanze;

void leggiDistanze(Distanze* distanze);
void aggiungiElemento(Distanze distanze, int i, double d);
int getMinimo(Distanze distanze);

#endif //DISTANZE_H
