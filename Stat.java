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

        List<String> comuni = Stat.readData(file);

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

        if (lines == null) return null;

        String[] headers = lines.remove(0).split(",");

        return lines;
    }
}
