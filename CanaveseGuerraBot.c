#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utility.h"
#include "comune.h"
#include "comuni.h"
#include "CanaveseGuerraBot.h"

void Game()
{
    Comuni comuni;
    allocaComuni(&comuni);

    calcolaDistanze(comuni);

    while(!Vincitore(comuni))     conquista(comuni);

    stampaClassifica(comuni);
    stampaComuniIndipendenti(comuni);

    liberaComuni(comuni);
}
