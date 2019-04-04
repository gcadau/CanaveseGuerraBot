#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utility.h"
#include "comune.h"
#include "comuni.h"
#include "CanaveseGuerraBot.h"

#define CONQUISTA 'C'
#define INSURREZIONE 'R'

void Game()
{
    Comuni comuni;
    allocaComuni(&comuni);

    calcolaDistanze(comuni);

    int m;  
    while(m=mossa())
    {
        if (m>0)    conquista(comuni);
        if (m<0)    insorgi(comuni);
    }

    stampaClassifica(comuni);
    stampaComuniIndipendenti(comuni);

    liberaComuni(comuni);
}


int mossa()
{
    char r; 
    scanf("%c", &r);
    scanf("%*c");
    r = toupper(r); 

    if(r==CONQUISTA)        return 1; 
    if(r==INSURREZIONE)     return -1; 
    
    return 0; 
}
