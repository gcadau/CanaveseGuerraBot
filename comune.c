#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utility.h"
#include "centroide.h"
#include "distanze.h"
#include "comune.h"

#define VIRGOLA 44
#define VIRGOLETTE 34

struct comune_s
{
    char* nome;

    Centroide centroide;

    Distanze distanze;

    Comune controllore;

    Comune* conquiste;
    int dimConquiste;
    int actDim;
    int nConquiste;
};

char* parsificaStringa(char* l, char** ptr);
int giaConquistato(Comune comune, Comune conquistabile);

int allocaComune(Comune *comune, char *line)
{
    char* ptr = line;

    char* provincia = parsificaStringa(ptr, &ptr);
    free(provincia);

    ptr++;
    char* nome = parsificaStringa(ptr, &ptr);

    *comune = malloc(sizeof(struct comune_s));

    (*comune)->nome = nome;

    ptr++;
    double c1, c2;
    sscanf(ptr, "%lf,%lf", &c1, &c2);

    Centroide c;
    allocaCentroide(&c, c1, c2);
    (*comune)->centroide = c;

    Distanze d;
    allocaDistanze(&d);
    (*comune)->distanze = d;

    (*comune)->controllore = *comune;

    (*comune)->dimConquiste = 0;
    (*comune)->actDim = 1;
    (*comune)->nConquiste = 1;
    (*comune)->conquiste = malloc(((*comune)->actDim)*sizeof(Comune));

    (*comune)->conquiste[((*comune)->dimConquiste)++] = *comune;

    return 1;
}

void stampaComune(Comune comune)
{
    printf("Comune di %s\n", comune->nome);
    printf("\t");
    stampaCentroide(comune->centroide);
    printf("\t");

    if(comune->nConquiste==1)   printf("%d comune controllato\n", comune->nConquiste);
    else                        printf("%d comuni controllati\n", comune->nConquiste);
}

void stampaComuneVeloce(Comune comune)
{
    printf("%s", comune->nome);
}

double distanza(Comune c1, Comune c2)
{
    double distanza = distanzaCentroide(c1->centroide, c2->centroide);

    return distanza;
}

void aggiungiDistanza(Comune c, double d, void* i)
{
    aggiungiElemento(c->distanze, i, d);
}

void* XesimoComunePiuVicino(Comune c, int x)
{
    return getMinimoX(c->distanze, x);
}

Comune getControllore(Comune comune)
{
    return comune->controllore;
}

Comune Conquista(Comune controllato, Comune conquistante)
{
    int x = 0;
    Comune conquistato = (Comune) XesimoComunePiuVicino(controllato, x++);

    while(giaConquistato(conquistante, conquistato))
    {
        conquistato = (Comune) XesimoComunePiuVicino(controllato, x++);
    }

    return conquistato;
}

int indipendente(Comune comune)
{
    if(comune->nConquiste>0)
    {
        return 1;
    }
    return 0;
}

int ComuneMaggiore(Comune A, Comune B)
{
    return (A->nConquiste > B->nConquiste);
}

int ComuneMinore(Comune A, Comune B)
{
    return (A->nConquiste < B->nConquiste);
}

void liberaComune(Comune comune)
{
    free(comune->nome);
    liberaCentroide(comune->centroide);
    liberaDistanze(comune->distanze);

    free(comune);
}

void cambiaControllore(Comune comune, Comune nuovoControllore)
{
    comune->controllore = nuovoControllore;
}

void aggiungiConquista(Comune comune, Comune conquista)
{
    int i;
    for(i=0; i<comune->dimConquiste; i++)
    {
        if( comune->conquiste[i]==NULL )
        {
            comune->conquiste[i] = conquista;
            comune->nConquiste++;
            return;
        }
    }

    if( (comune->dimConquiste) >= (comune->actDim) )
    {
        comune->actDim*=CRESCITA;
        comune->conquiste = realloc(comune->conquiste, (comune->actDim)*sizeof(Comune));
    }
    comune->conquiste[(comune->dimConquiste)++] = conquista;
    comune->nConquiste++;
}

void sottraiConquista(Comune comune, Comune perdita)
{
    int i;
    for(i=0; i<comune->dimConquiste; i++)
    {
        if( comune->conquiste[i]==perdita )
        {
            comune->conquiste[i] = NULL;
            comune->nConquiste--;
        }
    }
}

char* parsificaStringa(char* l, char** ptr)
{
    char acc[N];

    int i = 0;
    while((*l)!=VIRGOLA)
    {
        if((*l)!=VIRGOLETTE)    acc[i++] = (*l);
        l++;
    }

    acc[i] = '\0';

    (*ptr) = l;

    return strdup(acc);
}

int giaConquistato(Comune comune, Comune conquistabile)
{
    int i;
    for(i=0; i<comune->dimConquiste; i++)
    {
        if (conquistabile==comune->conquiste[i])
        {
            return 1;
        }
    }

    return 0;
}