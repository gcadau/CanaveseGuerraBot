#ifndef MESE_H
#define MESE_H

typedef struct mese_s* Mese;

void setMesi();
void setMese(Mese* mese, int m);
void stampaMese(Mese mese);
int getGiorni(Mese mese);
void incrementaMese(Mese* mese, Anno anno);
int getNumeroM(Mese mese);
void liberaMesi();

#endif //MESE_H
