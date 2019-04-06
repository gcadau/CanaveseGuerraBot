#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "anno.h"
#include "mese.h"
#include "giorno.h"

struct giorno_s
{
    int numero;
};

void setGiorno(Giorno* giorno, int g)
{
    *giorno = malloc(sizeof(struct giorno_s));

    (*giorno)->numero = g;
}

void stampaGiorno(Giorno giorno)
{
    printf("%d", giorno->numero);
}

void incrementaGiorno(Giorno giorno, Mese* mese, Anno anno)
{
    giorno->numero++;

    if(getGiorni(*mese) < giorno->numero)
    {
        incrementaMese(mese, anno);
        giorno->numero=1;
    }
}

int getNumeroG(Giorno giorno)
{
    return giorno->numero;
}

void setGiornoAnnoBisestile(Giorno giorno)
{
    giorno->numero = 29;
}

void liberaGiorno(Giorno giorno)
{
    free(giorno);
}