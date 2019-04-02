#ifndef COMUNE_H
#define COMUNE_H

typedef struct comune_s* Comune;

int allocaComune(Comune *comune, char *line, char **nomi, int dimNomi);
void stampaComune(Comune comune);
double distanza(Comune c1, Comune c2);
void aggiungiDistanza(Comune c, double d, void* i);
void* XesimoComunePiuVicino(Comune c, int x);
Comune getControllore(Comune comune);
Comune Conquista(Comune controllato, Comune conquistante);
void liberaComune(Comune comune);
void cambiaControllore(Comune comune, Comune nuovoControllore);
void aggiungiConquista(Comune comune, Comune conquista);
void sottraiConquista(Comune comune, Comune perdita);

#endif //COMUNE_H