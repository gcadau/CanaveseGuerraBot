#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utility.h"
#include "casualita.h"
#include "comune.h"
#include "sortingCom.h"
#include "sortingCom_Alf.h"
#include "comuni.h"

#define BREVE 100

struct comuni_s
{
    Comune* elenco;
    int dimElenco;
    int actDim;
};

int comuniIndipendenti(Comuni comuni);
Comune sceltaComuneCasuale(Comuni comuni);

int allocaComuni(Comuni *comuni)
{
    (*comuni) = malloc(sizeof(struct comuni_s));

    FILE* f;
    if((f=fopen(FILE_DATI, "r"))==NULL)
    {
        return 0;
    }

    (*comuni)->dimElenco = 0;
    (*comuni)->actDim = 1;
    (*comuni)->elenco = malloc(((*comuni)->actDim)*sizeof(Comune));

    char line[N];
    fgets(line, N, f);
    while(fgets(line, N, f)!=NULL)
    {
        Comune c;
        allocaComune(&c, line);

        if( ((*comuni)->dimElenco) >= ((*comuni)->actDim) )
        {
            (*comuni)->actDim*=CRESCITA;
            (*comuni)->elenco = realloc((*comuni)->elenco, (((*comuni)->actDim)*sizeof(Comune)));
        }
        (*comuni)->elenco[((*comuni)->dimElenco)++] = c;
    }

    fclose(f);

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

void ordinaComuniAlfabeticamente(Comuni comuni)
{
    SortCom_Alf(comuni->elenco, comuni->dimElenco);
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
                Comune c = comuni->elenco[j];
                aggiungiDistanza(comuni->elenco[i], d, c);
            }
        }
    }
}

void conquista(Comuni comuni)
{
    Comune scelto = sceltaComuneCasuale(comuni);
    Comune conquistatore = getControllore(scelto);
    Comune conquistato = Conquista(scelto, conquistatore);
    Comune sconfitto = getControllore(conquistato);

    sottraiConquista(sconfitto, conquistato);
    cambiaControllore(conquistato, conquistatore);
    aggiungiConquista(conquistatore, conquistato);

    stampaComuneVeloce(conquistatore);
    printf(" ha conquistato il territorio di ");
    stampaComuneVeloce(conquistato);
    if(conquistato!=sconfitto)
    {
        printf(" precedentemente occupato da ");
        stampaComuneVeloce(sconfitto);
    }
    printf("\n");
    if(!indipendente(sconfitto))
    {
        stampaComuneVeloce(sconfitto);
        printf(" ha perso completamente la sua indipendenza\n");
    }
}

void insorgi(Comuni comuni)
{
    Comuni dipendenti = malloc(sizeof(struct comuni_s));
    dipendenti->actDim = comuni->dimElenco;
    dipendenti->elenco = malloc(dipendenti->actDim*sizeof(Comune));

    int dimDipendenti = 0;
    int i;
    for(i=0; i<comuni->dimElenco; i++)
    {
        if(!indipendente(comuni->elenco[i]))
        {
            dipendenti->elenco[dimDipendenti++] = comuni->elenco[i];
        }
    }

    dipendenti->dimElenco = dimDipendenti;

    Comune scelto = sceltaComuneCasuale(dipendenti);
    Comune sconfitto = getControllore(scelto);

    sottraiConquista(sconfitto, scelto);
    cambiaControllore(scelto, scelto);
    aggiungiConquista(scelto, scelto);

    printf("La popolazione di ");
    stampaComuneVeloce(scelto);
    printf(" e' insorta rendendo la citta' indipendente da ");
    stampaComuneVeloce(sconfitto);
    printf("\n");

    free(dipendenti);
}

void stampaClassifica(Comuni comuni)
{
    Comune* classifica = malloc(comuni->dimElenco*sizeof(Comune));

    int i;
    for(i=0; i<comuni->dimElenco; i++)
    {
        classifica[i] = comuni->elenco[i];
    }

    SortCom(classifica, comuni->dimElenco);

    for(i=comuni->dimElenco-1; i>=0; i--)
    {
        stampaComune(classifica[i]);
    }

    free(classifica);
}

void stampaClassificaBreve(Comuni comuni)
{
    Comune* classifica = malloc(comuni->dimElenco*sizeof(Comune));

    int i;
    for(i=0; i<comuni->dimElenco; i++)
    {
        classifica[i] = comuni->elenco[i];
    }

    SortCom(classifica, comuni->dimElenco);

    int count = 0;
    for(i=comuni->dimElenco-1; i>=0 && count<BREVE; i--)
    {
        stampaComuneBreve(classifica[i]);
        count++;
    }

    free(classifica);
}

void stampaComuniIndipendenti(Comuni comuni)
{
    printf("%d comuni rimasti indipendenti\n", comuniIndipendenti(comuni));
}

void stampaDettagli(Comuni comuni)
{
    int i;
    for(i=0; i<comuni->dimElenco; i++)
    {
        stampaStatistiche(comuni->elenco[i]);
    }

}

int Vincitore(Comuni comuni)
{
    return (comuniIndipendenti(comuni)==1); 
}

int comuniIndipendenti(Comuni comuni)
{
    int indipendenti = 0; 
    int i; 
    for(i=0; i<comuni->dimElenco; i++)
    {
        if(indipendente(comuni->elenco[i]))
        {
            indipendenti++; 
        }
    }
    return indipendenti; 
}

void liberaComuni(Comuni comuni)
{
    int i;
    for(i=0; i<comuni->dimElenco; i++)
    {
        liberaComune(comuni->elenco[i]);
    }

    free(comuni->elenco);

    free(comuni);
}

Comune sceltaComuneCasuale(Comuni comuni)
{
    int i = generaNumeroCasuale(comuni->dimElenco);

    Comune comune = comuni->elenco[i];

    return comune;
}
