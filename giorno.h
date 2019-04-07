#ifndef GIORNO_H
#define GIORNO_H

typedef struct giorno_s* Giorno;

void setGiorno(Giorno* giorno, int g);
void stampaGiorno(Giorno giorno);
void incrementaGiorno(Giorno giorno, Mese* mese, Anno anno);
int getNumeroG(Giorno giorno);
void setGiornoAnnoBisestile(Giorno giorno);
void liberaGiorno(Giorno giorno);

#endif //GIORNO_H
