#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "anno.h"

struct anno_s
{
    int numero;
};

void setAnno(Anno* anno, int a)
{
    *anno = malloc(sizeof(struct anno_s));

    (*anno)->numero = a;
}

void stampaAnno(Anno anno)
{
    printf("%d", anno->numero);
}

void incrementaAnno(Anno anno)
{
    anno->numero++;
}

int annoBisestile(Anno anno)
{
    if (anno->numero%100==0)
    {
        if (anno->numero%400==0)
        {
            return 1;
        }
    }
    else
    {
        if (anno->numero%4==0)
        {
            return 1;
        }
    }

    return 0;
}

void liberaAnno(Anno anno)
{
    free(anno);
}