#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utility.h"
#include "comune.h"
#include "sortingCom.h"

void QuickSortComR(Comune *A, int l, int r);
int partitionCom(Comune *A, int l, int r);
void SwapCom(Comune *v, int n1, int n2);

void SortCom(Comune *A, int dim)
{
    int l=0, r=dim-1;

    QuickSortComR(A, l, r);
}

void QuickSortComR(Comune *A, int l, int r)
{
    if (r <= l)     return;

    int q = partitionCom(A, l, r);

    QuickSortComR(A, l, q - 1);
    QuickSortComR(A, q + 1, r);
}

int partitionCom(Comune *A, int l, int r)
{
    Comune x = A[r];
    int i = l-1;
    int j = r;

    for ( ; ; )
    {
        while( ComuneMinore(A[++i], x) );
        while( ComuneMaggiore(A[--j], x) )
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

        SwapCom(A, i, j);
    }

    SwapCom(A, i, r);

    return i;
}

void SwapCom(Comune *v, int n1, int n2)
{
    Comune tmp;

    tmp  = v[n1];
    v[n1] = v[n2];
    v[n2] = tmp;
}