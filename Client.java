package interf;

import utility.*;
import nazione.*;
import stat.*;

public class Client
{
    public static void main(String[] args)
    {
        String file = "C:\\Users\\Giovanni\\IdeaProjects\\untitled3\\Dettaglio_luoghi.csv.txt";
        String situazione = "C:\\Users\\Giovanni\\IdeaProjects\\untitled3\\Dettagli.txt";
        Nazione italia = Stat.caricaDB(file);

        if(italia==null)
        {
            System.err.println("Errore");
        }
        else
        {
            Stat.caricaSituazione(italia, situazione);
            Stat.provinceConComuniPotenti(italia, 0);
            //Stat.comuniPotentiperProvincia(italia, "Bergamo", 5);
        }
    }
}

