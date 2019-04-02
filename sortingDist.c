#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utility.h"
#include "distanza.h"
#include "sortingDist.h"

void QuickSortDistR(Distanza *A, int l, int r);
int partitionDist(Distanza *A, int l, int r);
void SwapDist(Distanza *v, int n1, int n2);

void SortDist(Distanza *A, int dim)
{
    int l=0, r=dim-1;

    QuickSortDistR(A, l, r);
}

void QuickSortDistR(Distanza *A, int l, int r)
{
    if (r <= l)     return;

    int q = partitionDist(A, l, r);

    QuickSortDistR(A, l, q - 1);
    QuickSortDistR(A, q + 1, r);
}

int partitionDist(Distanza *A, int l, int r)
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

        SwapDist(A, i, j);
    }

    SwapDist(A, i, r);

    return i;
}

void SwapDist(Distanza *v, int n1, int n2)
{
    Distanza tmp;

    tmp  = v[n1];
    v[n1] = v[n2];
    v[n2] = tmp;
}