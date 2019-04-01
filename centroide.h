#ifndef CENTROIDE_H
#define CENTROIDE_H

typedef struct centroide_s *Centroide;

void leggiCentroide(Centroide* centroide, double x, double y);
void stampaCentroide(Centroide c);
double distanzaCentroide(Centroide c1, Centroide c2);

#endif //CENTROIDE_H
