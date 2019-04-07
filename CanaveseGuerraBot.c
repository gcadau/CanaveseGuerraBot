#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utility.h"
#include "casualita.h"
#include "comune.h"
#include "comuni.h"
#include "CanaveseGuerraBot.h"
#include "data.h"

#define CADENZA 24

void Game()
{
    enableData(); initData("1/1/2021");

    Comuni comuni;
    allocaComuni(&comuni);

    calcolaDistanze(comuni);

    int count = 0;
    while(!Vincitore(comuni))
    {
        stampaData(); printf(".  ");    conquista(comuni);  incrementaData();     stampaClassificaBreve(comuni);      stampaComuniIndipendenti(comuni);
        if(insurrezioneRandomica())
        {
            stampaData(); printf(".  ");   insorgi(comuni);    incrementaData();      stampaClassificaBreve(comuni);      stampaComuniIndipendenti(comuni);
        }
        if(count%CADENZA==0)
        {
            stampaDettagli(comuni);
        }
        count++;
    }

    stampaClassifica(comuni);
    stampaComuniIndipendenti(comuni);

    liberaComuni(comuni);

    disableData();
}


int insurrezioneRandomica()
{
    return generaSceltaCasuale(); 
}
