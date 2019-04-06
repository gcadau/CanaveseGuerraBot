#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "anno.h"
#include "mese.h"

#define MESI 12

Mese* mesi;

struct mese_s
{
    int numero;
    char* nome;
    int giorni;
};

void setMesi()
{
    mesi = malloc(MESI*sizeof(Mese));

    int i;
    for(i=0; i<MESI; i++)
    {
        mesi[i] = malloc(sizeof(struct mese_s));
    }

    mesi[0]->nome = strdup("Gennaio");
    mesi[0]->numero = 1;
    mesi[0]->giorni = 31;

    mesi[1]->nome = strdup("Febbraio");
    mesi[1]->numero = 2;
    mesi[1]->giorni = 28;

    mesi[2]->nome = strdup("Marzo");
    mesi[2]->numero = 3;
    mesi[2]->giorni = 31;

    mesi[3]->nome = strdup("Aprile");
    mesi[3]->numero = 4;
    mesi[3]->giorni = 30;

    mesi[4]->nome = strdup("Maggio");
    mesi[4]->numero = 5;
    mesi[4]->giorni = 31;

    mesi[5]->nome = strdup("Giugno");
    mesi[5]->numero = 6;
    mesi[5]->giorni = 30;

    mesi[6]->nome = strdup("Luglio");
    mesi[6]->numero = 7;
    mesi[6]->giorni = 31;

    mesi[7]->nome = strdup("Agosto");
    mesi[7]->numero = 8;
    mesi[7]->giorni = 31;

    mesi[8]->nome = strdup("Settembre");
    mesi[8]->numero = 9;
    mesi[8]->giorni = 30;

    mesi[9]->nome = strdup("Ottobre");
    mesi[9]->numero = 10;
    mesi[9]->giorni = 31;

    mesi[10]->nome = strdup("Novembre");
    mesi[10]->numero = 11;
    mesi[10]->giorni = 30;

    mesi[11]->nome = strdup("Dicembre");
    mesi[11]->numero = 12;
    mesi[11]->giorni = 31;
}

void setMese(Mese* mese, int m)
{
    *mese = mesi[m-1];
}

void stampaMese(Mese mese)
{
    printf("%s", mese->nome);
}

int getGiorni(Mese mese)
{
    return mese->giorni;
}

void incrementaMese(Mese* mese, Anno anno)
{
    int m = (*mese)->numero;
    m++;
    if(m > MESI)
    {
        incrementaAnno(anno);
        m %= MESI;
    }

    *mese = mesi[m-1];
}

int getNumeroM(Mese mese)
{
    return mese->numero;
}

void liberaMesi()
{
    int i;
    for(i=0; i<MESI; i++)
    {
        free(mesi[i]->nome);
        free(mesi[i]);
    }

    free(mesi);
}