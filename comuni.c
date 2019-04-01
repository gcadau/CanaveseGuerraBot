#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utility.h"
#include "comune.h"
#include "comuni.h"

struct comuni_s
{
    Comune* elenco;
    int dimElenco;
    int actDim;
};

int leggiComuni(Comuni* comuni)
{
    (*comuni) = malloc(sizeof(struct comuni_s));

    FILE* g;
    if((g=fopen(FILE_NOMI, "r"))==NULL)
    {
        return 0;
    }

    int actDim = 1;
    int dimNomi = 0;
    char** nomi = malloc(actDim*sizeof(char*));
    char line[N];
    while(fgets(line, N, g)!=NULL)
    {
        char line_pulita[N];
        strncpy(line_pulita, line, strlen(line)-1);
        line_pulita[strlen(line)-1] = '\0';
        if(dimNomi >= actDim)
        {
            actDim*=CRESCITA;
            nomi = realloc(nomi, actDim*sizeof(char*));
        }
        nomi[dimNomi++] = strdup(line_pulita);
    }

    fclose(g);

    FILE* f;
    if((f=fopen(FILE_DATI, "r"))==NULL)
    {
        return 0;
    }

    (*comuni)->dimElenco = 0;
    (*comuni)->actDim = 1;
    (*comuni)->elenco = malloc(((*comuni)->actDim)*sizeof(Comune));

    fgets(line, N, f);
    while(fgets(line, N, f)!=NULL)
    {
        Comune c;
        if(leggiComune(&c, line, nomi, dimNomi))
        {
            if( ((*comuni)->dimElenco) >= ((*comuni)->actDim) )
            {
                (*comuni)->actDim*=CRESCITA;
                (*comuni)->elenco = realloc((*comuni)->elenco, (((*comuni)->actDim)*sizeof(Comune)));
            }
            (*comuni)->elenco[((*comuni)->dimElenco)++] = c;
        }
    }

    fclose(f);

    int i;
    for(i=0; i<dimNomi; i++)
    {
        free(nomi[i]);
    }

    free(nomi);

    return 1;
}

void stampaComuni(Comuni comuni)
{
    int i;
    for(i=0; i<comuni->dimElenco; i++)
    {
        stampaComune(comuni->elenco[i]);
    }
}

void calcolaDistanze(Comuni comuni)
{
    int i, j;
    for(i=0; i<comuni->dimElenco; i++)
    {
        for(j=0; j<comuni->dimElenco; j++)
        {
            if(i!=j)
            {
                double d = distanza(comuni->elenco[i], comuni->elenco[j]);
                aggiungiDistanza(comuni->elenco[i], d, j);
            }
        }
    }
}
