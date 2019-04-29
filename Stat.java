package stat;

import nazione.*;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.List;

import static java.util.stream.Collectors.toList;

public class Stat
{
    public static Nazione caricaDB(String file)
    {
        Nazione nazione = new Nazione();

        String headers = null;
        List<String> comuni = Stat.readData(file, headers);

        if(comuni==null)    return null;

        for(String c: comuni)
        {
            String[] comuneInfo = c.split(";");

            String com = comuneInfo[0];
            String zona = comuneInfo[1];
            String reg = comuneInfo[2];
            String prov = comuneInfo[3];

            nazione.add(com, prov, reg, zona);
        }

        return nazione;
    }


    private static List<String> readData(String file)
    {
        List<String> lines = null;
        try (BufferedReader in = new BufferedReader(new FileReader(file)))
        {
            lines = in.lines().collect(toList());
        }
        catch (IOException e)
        {
            System.err.println(e.getMessage());
        }

        return lines;
    }

    private static List<String> readData(String file, String h)
    {
        List<String> lines = null;
        try (BufferedReader in = new BufferedReader(new FileReader(file)))
        {
            lines = in.lines().collect(toList());
        }
        catch (IOException e)
        {
            System.err.println(e.getMessage());
        }

        if (lines == null) return null;

        h = lines.remove(0);

        String[] headers = h.split(",");

        return lines;
    }

    public static boolean caricaSituazione(Nazione nazione, String file)
    {
        List<String> linee = Stat.readData(file);

        if(linee==null)    return false;

        int ok=1;
        int i=0;
        Comune c = null;
        while(i<linee.size())
        {
            String linea = linee.get(i);
            if(!linea.contains("\t"))
            {
                String[] pars = linea.split("- ");
                String comune = pars[0].substring(0, pars[0].length()-1);
                c = nazione.consideraComune(comune);

                if(c==null)
                {
                    ok=0;
                    c = nazione.addComuneRestante(comune);
                }
                if(linea.contains("controllore"))
                {
                    String[] contr = linea.split(":");
                    String controllore = contr[1].substring(1);
                    Comune comuneControllore = nazione.getComune(controllore);
                    if(comuneControllore==null)     comuneControllore = nazione.addComuneRestante(controllore);
                    c.setControllore(comuneControllore);
                }
            }
            else
            {
                String pars = linea.substring(1);
                Comune conquista = nazione.getComune(pars);
                if(conquista==null)     conquista = nazione.addComuneRestante(pars);
                if (c!=null)    c.aggiungiConquista(conquista);
            }

            i++;
        }

        return (ok==1);
    }

    public static void method(Nazione nazione)
    {
        System.out.println(nazione.getComuni().stream().filter(c->c.isCons()).count());
    }
}
