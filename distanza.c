#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utility.h"
#include "distanza.h"

struct distanza_s
{
    double distanza;
    void* comune;
};

void allocaDistanza(Distanza *dis, void* c, double d)
{
    (*dis) = malloc(sizeof(struct distanza_s));

    (*dis)->distanza = d;
    (*dis)->comune = c;
}

void* getComune(Distanza distanza)
{
    return distanza->comune;
}

int DistanzaMaggiore(Distanza A, Distanza B)
{
    return (A->distanza > B->distanza);
}

int DistanzaMinore(Distanza A, Distanza B)
{
    return (A->distanza < B->distanza);
}

void liberaDistanza(Distanza distanza)
{
    free(distanza);
}
