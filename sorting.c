#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utility.h"
#include "distanza.h"
#include "sorting.h"

void QuickSortR(Distanza *A, int l, int r);
int partition(Distanza *A, int l, int r);
void Swap(Distanza *v, int n1, int n2);

void Sort(Distanza *A, int dim)
{
    int l=0, r=dim-1;

    QuickSortR(A, l, r);
}

void QuickSortR(Distanza *A, int l, int r)
{
    if (r <= l)     return;

    int q = partition(A, l, r);

    QuickSortR(A, l, q-1);
    QuickSortR(A, q+1, r);
}

int partition(Distanza *A, int l, int r)
{
    Distanza x = A[r];
    int i = l-1;
    int j = r;

    for ( ; ; )
    {
        while( DistanzaMinore(A[++i], x) );
        while( DistanzaMaggiore(A[--j], x) )
        {
            if (j==l)
            {
                break;
            }
        }

        if (i >= j)
        {
            break;
        }

        Swap(A, i, j);
    }

    Swap(A, i, r);

    return i;
}

void Swap(Distanza *v, int n1, int n2)
{
    Distanza tmp;

    tmp  = v[n1];
    v[n1] = v[n2];
    v[n2] = tmp;
}