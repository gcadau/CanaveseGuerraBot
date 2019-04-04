#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "utility.h"
#include "comune.h"
#include "comuni.h"
#include "CanaveseGuerraBot.h"

#define CONQUISTA 'C'

void Game()
{
    Comuni comuni;
    allocaComuni(&comuni);

    calcolaDistanze(comuni);

    while(mossa())      conquista(comuni);

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
    
    if(r==CONQUISTA)    return 1; 
    
    return 0; 
}
        
    
