#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utility.h"
#include "distanza.h"
#include "sorting.h"
#include "distanze.h"

struct distanze_s
{
    Distanza* elenco;
    int dimElenco;
    int actDim;
    int ordinato;
};

void allocaDistanze(Distanze *distanze)
{
    (*distanze) = malloc(sizeof(struct distanze_s));

    (*distanze)->dimElenco = 0;
    (*distanze)->actDim = 1;
    (*distanze)->elenco = malloc(((*distanze)->actDim)*sizeof(Distanza));
    (*distanze)->ordinato = 0;
}

void aggiungiElemento(Distanze distanze, void* i, double d)
{
    if( (distanze->dimElenco) >= (distanze->actDim) )
    {
        distanze->actDim*=CRESCITA;
        distanze->elenco = realloc(distanze->elenco, (distanze->actDim)*sizeof(Distanza));
    }

    Distanza distanza;
    allocaDistanza(&distanza, i, d);
    distanze->elenco[(distanze->dimElenco)++] = distanza;
    distanze->ordinato = 0;
}

void* getMinimoX(Distanze distanze, int x)
{
    if(!distanze->ordinato)
    {
        Sort(distanze->elenco, distanze->dimElenco);
        distanze->ordinato = 1;
    }

    Distanza distanza = distanze->elenco[x];

    return getComune(distanza);
}

void liberaDistanze(Distanze distanze)
{
    int i;
    for(i=0; i<distanze->dimElenco; i++)
    {
        liberaDistanza(distanze->elenco[i]);
    }
    free(distanze->elenco);

    free(distanze);
}