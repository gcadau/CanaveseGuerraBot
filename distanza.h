#ifndef DISTANZA_H
#define DISTANZA_H

typedef struct distanza_s* Distanza;

void allocaDistanza(Distanza *dis, void* c, double d);
void* getComune(Distanza distanza);
int DistanzaMaggiore(Distanza A, Distanza B);
int DistanzaMinore(Distanza A, Distanza B);
void liberaDistanza(Distanza distanza);

#endif //DISTANZA_H
