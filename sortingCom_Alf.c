#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utility.h"
#include "comune.h"
#include "sortingCom_Alf.h"

void QuickSortCom_AlfR(Comune *A, int l, int r);
int partitionCom_Alf(Comune *A, int l, int r);
void SwapCom_Alf(Comune *v, int n1, int n2);

void SortCom_Alf(Comune *A, int dim)
{
    int l=0, r=dim-1;

    QuickSortCom_AlfR(A, l, r);
}

void QuickSortCom_AlfR(Comune *A, int l, int r)
{
    if (r <= l)     return;

    int q = partitionCom_Alf(A, l, r);

    QuickSortCom_AlfR(A, l, q - 1);
    QuickSortCom_AlfR(A, q + 1, r);
}

int partitionCom_Alf(Comune *A, int l, int r)
{
    Comune x = A[r];
    int i = l-1;
    int j = r;

    for ( ; ; )
    {
        while( ComuneMinore_Alf(A[++i], x) );
        while( ComuneMaggiore_Alf(A[--j], x) )
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

        SwapCom_Alf(A, i, j);
    }

    SwapCom_Alf(A, i, r);

    return i;
}

void SwapCom_Alf(Comune *v, int n1, int n2)
{
    Comune tmp;

    tmp  = v[n1];
    v[n1] = v[n2];
    v[n2] = tmp;
}