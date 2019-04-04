#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utility.h"
#include "casualita.h"
#include "comune.h"
#include "comuni.h"
#include "CanaveseGuerraBot.h"

void Game()
{
    Comuni comuni;
    allocaComuni(&comuni);

    calcolaDistanze(comuni);

    while(!Vincitore(comuni))
    {
        conquista(comuni);
        if(insurrezioneRandomica())   insorgi(comuni);
    }

    stampaClassifica(comuni);
    stampaComuniIndipendenti(comuni);

    liberaComuni(comuni);
}


int insurrezioneRandomica()
{
    return generaSceltaCasuale(); 
}
