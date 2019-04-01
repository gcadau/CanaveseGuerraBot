#ifndef COMUNE_H
#define COMUNE_H

typedef struct comune_s* Comune;

int leggiComune(Comune* comune, char* line, char** nomi, int DimNomi);
void stampaComune(Comune comune);
double distanza(Comune c1, Comune c2);
void aggiungiDistanza(Comune c, double d, int i);
int comunePiuVicino(Comune c);

#endif //COMUNE_H