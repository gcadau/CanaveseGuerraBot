#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#include "casualita.h"

int count = 0;

int generaNumeroCasuale(int range)
{
    int i;
    srand(time(NULL)+count++);
    srand(rand());

    i = rand() % range;

    return i;
}
