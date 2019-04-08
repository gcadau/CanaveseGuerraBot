#ifndef COMUNE_H
#define COMUNE_H

typedef struct comune_s* Comune;

int allocaComune(Comune *comune, char *line);
void stampaComune(Comune comune);
void stampaComuneBreve(Comune comune);
void stampaComuneVeloce(Comune comune);
void stampaStatistiche(Comune comune);
double distanza(Comune c1, Comune c2);
void aggiungiDistanza(Comune c, double d, void* i);
void* XesimoComunePiuVicino(Comune c, int x);
Comune getControllore(Comune comune);
Comune Conquista(Comune controllato, Comune conquistante);
int indipendente(Comune comune);
int ComuneMaggiore(Comune A, Comune B);
int ComuneMinore(Comune A, Comune B);
int ComuneMaggiore_Alf(Comune A, Comune B);
int ComuneMinore_Alf(Comune A, Comune B);
void liberaComune(Comune comune);
void cambiaControllore(Comune comune, Comune nuovoControllore);
void aggiungiConquista(Comune comune, Comune conquista);
void sottraiConquista(Comune comune, Comune perdita);

#endif //COMUNE_H