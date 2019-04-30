package interf;

import utility.*;
import nazione.*;
import stat.*;

public class Client
{
    public static void main(String[] args)
    {
        Nazione italia = Stat.caricaDB(Utility.LUOGHI);
        if(italia==null)
        {
            System.err.println("Errore nel caricamento dati.");
        }
        else
        {
            if(!Stat.caricaSituazione(italia, Utility.DETTAGLI))
            {
                System.err.println("Errore nel caricamento dettagli. Non tutti i comuni sono stati riconosciuti");
            }
            
            /* USO DEI METODI DELLA CLASSE stat PER STAMPARE LE STATISTICHE */

        }
    }
}
