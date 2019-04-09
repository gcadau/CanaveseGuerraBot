#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "anno.h"
#include "mese.h"
#include "giorno.h"
#include "data.h"

#define MESI 12

typedef struct data_s
{
    Anno anno;
    Mese mese;
    Giorno giorno;
}* Data;

int gestisciAnnoBisestile();

Data data;

void enableData()
{
    data = malloc(sizeof(struct data_s));

    setMesi();
}

void initData(char* str)
{
    int a, m, g;

    sscanf(str, "%d/%d/%d", &g, &m, &a);

    setAnno(&(data->anno), a);
    setMese(&(data->mese), m);
    setGiorno(&data->giorno, g);
}

void stampaData()
{
    stampaGiorno(data->giorno);
    printf(" ");
    stampaMese(data->mese);
    printf(" ");
    stampaAnno(data->anno);
    //printf(" ");
}

void incrementaData()
{
    if(annoBisestile(data->anno))
    {
        if (gestisciAnnoBisestile())    return ;
    }

    incrementaGiorno(data->giorno, &(data->mese), data->anno);
}

void disableData()
{
    liberaAnno(data->anno);
    liberaGiorno(data->giorno);

    free(data);

    liberaMesi();
}

int gestisciAnnoBisestile()
{
    if( (getNumeroG(data->giorno)==28) && (getNumeroM(data->mese)==2) )
    {
        setGiornoAnnoBisestile(data->giorno);
        return 1;
    }

    return 0;
}

