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
};

char* parsificaStringa(char* l, char** ptr);
int trovato(char** v, char* e, int dim);

int leggiComune(Comune* comune, char* line, char** nomi, int dimNomi)
{
    char* ptr = line;

    char* provincia = parsificaStringa(ptr, &ptr);
    free(provincia);

    ptr++;
    char* nome = parsificaStringa(ptr, &ptr);

    if(!trovato(nomi, nome, dimNomi))
    {
        free(nome);
        return 0;
    }

    *comune = malloc(sizeof(struct comune_s));

    (*comune)->nome = nome;

    ptr++;
    double c1, c2;
    sscanf(ptr, "%lf,%lf", &c1, &c2);

    Centroide c;
    leggiCentroide(&c, c1, c2);
    (*comune)->centroide = c;

    Distanze d;
    leggiDistanze(&d);
    (*comune)->distanze = d;

    return 1;
}

void stampaComune(Comune comune)
{
    printf("Comune di %s\n", comune->nome);
    printf("\t");
    stampaCentroide(comune->centroide);
}

double distanza(Comune c1, Comune c2)
{
    double distanza = distanzaCentroide(c1->centroide, c2->centroide);

    return distanza;
}

void aggiungiDistanza(Comune c, double d, int i)
{
    aggiungiElemento(c->distanze, i, d);
}

int comunePiuVicino(Comune c)
{
    return getMinimo(c->distanze);
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

int trovato(char** v, char* e, int dim)
{
    int i;
    for(i=0; i<dim; i++)
    {
        if(strcmp(v[i], e)==0)
        {
            return 1;
        }
    }

    return 0;
}