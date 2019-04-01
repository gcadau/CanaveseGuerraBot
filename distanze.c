#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utility.h"
#include "distanze.h"

struct distanze_s
{
    double* elenco;
    int* comuni;
    int dimElenco;
    int actDim;
};

void leggiDistanze(Distanze* distanze)
{
    (*distanze) = malloc(sizeof(struct distanze_s));

    (*distanze)->dimElenco = 0;
    (*distanze)->actDim = 1;
    (*distanze)->elenco = malloc(((*distanze)->actDim)*sizeof(double));
    (*distanze)->comuni = malloc(((*distanze)->actDim)*sizeof(int));
}

void aggiungiElemento(Distanze distanze, int i, double d)
{
    if( (distanze->dimElenco) >= (distanze->actDim) )
    {
        distanze->actDim*=CRESCITA;
        distanze->elenco = realloc(distanze->elenco, (distanze->actDim)*sizeof(double));
        distanze->comuni = realloc(distanze->comuni, (distanze->actDim)*sizeof(int));
    }

    distanze->elenco[(distanze->dimElenco)] = d;
    distanze->comuni[(distanze->dimElenco)++] = i;
}

int getMinimo(Distanze distanze)
{
    double minimo = distanze->elenco[0];
    int m = 0;

    int i;
    for(i=1; i<distanze->dimElenco; i++)
    {
        if(distanze->elenco[i] < minimo)
        {
            minimo = distanze->elenco[i];
            m = i;
        }
    }

    return m;
}