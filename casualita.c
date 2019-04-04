#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#include "casualita.h"

#define PROBABILITA 40
#define SUCCESSO 20

int count = 0;

int generaNumeroCasuale(int range)
{
    int i;
    srand(time(NULL)+count++);
    srand(rand());

    i = rand() % range;

    return i;
}

int generaSceltaCasuale()
{
    int scelta = generaNumeroCasuale(PROBABILITA+1);
    
    return (scelta==SUCCESSO); 
}
