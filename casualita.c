#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#include "casualita.h"

#define PROBABILITA 40
#define SUCCESSO 20

#define DIM 10000

#define FILE_IN "randomOffset.txt"


int count = 0;

int* offset; int n = 0;

int set = 0;

int generaNumeroCasuale(int range)
{
    if(!set)
    {
        set = 1;

        offset = malloc(DIM*sizeof(int));

        FILE* f;
        if((f=fopen(FILE_IN, "r"))==NULL)   return -1;
        int i;
        for(i=0; i<DIM; i++)
        {
            fscanf(f, "%d", &(offset[i]));
        }
        fclose(f);
    }

    int i;
    srand(time(NULL)+count++);
    srand(rand());

    i = rand() % range;

    i+=offset[n++];
    i%=range;

    return i;
}

int generaSceltaCasuale()
{
    int scelta = generaNumeroCasuale(PROBABILITA+1);

    return (scelta==SUCCESSO);
}
