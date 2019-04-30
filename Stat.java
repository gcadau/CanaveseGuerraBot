package stat;

import utility.*;

import nazione.*;

import javax.sound.midi.SysexMessage;
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.*;

import static java.util.stream.Collectors.*;

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

    public static void comuniPotenti(Nazione nazione, int conquiste)
    {
        nazione.getComuni().stream().filter(c -> c.getnConquiste()>= conquiste).collect(groupingBy(Comune::getnConquiste)).entrySet().stream().sorted( (m1, m2) -> m1.getKey()-m2.getKey() ).forEach(e -> {
                                                                                                                                                                                                             int n = e.getKey();
                                                                                                                                                                                                             System.out.println("Comuni con " + n + " territori controllati: ");
                                                                                                                                                                                                             for(Comune c: e.getValue())
                                                                                                                                                                                                             {
                                                                                                                                                                                                                 System.out.println("\t" + c.toString());
                                                                                                                                                                                                             }
                                                                                                                                                                                                          });
    }

    public static void comuniPotentiperZona(Nazione nazione, String zona, int conquiste)
    {
        nazione.getZona(zona).getRegioni().stream().flatMap(r -> r.getProvince().stream()).flatMap(p -> p.getComuni().stream()).filter(c -> c.getnConquiste()>= conquiste).collect(groupingBy(Comune::getnConquiste)).entrySet().stream().sorted( (m1, m2) -> m1.getKey()-m2.getKey() ).forEach(e -> {
                                                                                                                                                                                                                                                                                                        int n = e.getKey();
                                                                                                                                                                                                                                                                                                        System.out.println("Comuni con " + n + " territori controllati: ");
                                                                                                                                                                                                                                                                                                        for(Comune c: e.getValue())
                                                                                                                                                                                                                                                                                                        {
                                                                                                                                                                                                                                                                                                            System.out.println("\t" + c.toString());
                                                                                                                                                                                                                                                                                                        }
                                                                                                                                                                                                                                                                                                     });
    }

    public static void comuniPotentiperRegione(Nazione nazione, String regione, int conquiste)
    {
        nazione.getRegione(regione).getProvince().stream().flatMap(p -> p.getComuni().stream()).filter(c -> c.getnConquiste()>= conquiste).collect(groupingBy(Comune::getnConquiste)).entrySet().stream().sorted( (m1, m2) -> m1.getKey()-m2.getKey() ).forEach(e -> {
                                                                                                                                                                                                                                                                        int n = e.getKey();
                                                                                                                                                                                                                                                                        System.out.println("Comuni con " + n + " territori controllati: ");
                                                                                                                                                                                                                                                                        for(Comune c: e.getValue())
                                                                                                                                                                                                                                                                        {
                                                                                                                                                                                                                                                                            System.out.println("\t" + c.toString());
                                                                                                                                                                                                                                                                        }
                                                                                                                                                                                                                                                                     });
    }

    public static void comuniPotentiperProvincia(Nazione nazione, String provincia, int conquiste)
    {
        nazione.getProvincia(provincia).getComuni().stream().filter(c -> c.getnConquiste()>= conquiste).collect(groupingBy(Comune::getnConquiste)).entrySet().stream().sorted( (m1, m2) -> m1.getKey()-m2.getKey() ).forEach(e -> {
                                                                                                                                                                                                                                        int n = e.getKey();
                                                                                                                                                                                                                                        System.out.println("Comuni con " + n + " territori controllati: ");
                                                                                                                                                                                                                                        for(Comune c: e.getValue())
                                                                                                                                                                                                                                        {
                                                                                                                                                                                                                                            System.out.println("\t" + c.toString());
                                                                                                                                                                                                                                        }
                                                                                                                                                                                                                                  });
    }

    public static void comuniPotentiperArea(Nazione nazione, String area, int conquiste)
    {
        nazione.getArea(area).getComuni().stream().filter(c -> c.getnConquiste()>= conquiste).collect(groupingBy(Comune::getnConquiste)).entrySet().stream().sorted( (m1, m2) -> m1.getKey()-m2.getKey() ).forEach(e -> {
                                                                                                                                                                                                                            int n = e.getKey();
                                                                                                                                                                                                                            System.out.println("Comuni con " + n + " territori controllati: ");
                                                                                                                                                                                                                            for(Comune c: e.getValue())
                                                                                                                                                                                                                            {
                                                                                                                                                                                                                                System.out.println("\t" + c.toString());
                                                                                                                                                                                                                            }
                                                                                                                                                                                                                        });
    }

    public static void provinceConComuniPotenti(Nazione nazione, int conquiste)
    {
        Contatore counter = new Contatore(1);
        nazione.getProvince().stream().map( p -> p.getComuni().stream().filter(c -> c.getnConquiste()>=conquiste).collect(groupingBy(Comune::getnConquiste)) ).filter(m -> !m.isEmpty()).sorted( (m1, m2) -> {
                                                                                                                                                                                                                int max1 = m1.keySet().stream().reduce(Math::max).get();
                                                                                                                                                                                                                int max2 = m2.keySet().stream().reduce(Math::max).get();
                                                                                                                                                                                                                int max = Math.max(max1, max2);
                                                                                                                                                                                                                for(int i=max; i>=conquiste; i--)
                                                                                                                                                                                                                {
                                                                                                                                                                                                                    int size1, size2;
                                                                                                                                                                                                                    if(m1.get(i)==null)     size1 = 0;
                                                                                                                                                                                                                    else                    size1 = m1.get(i).size();
                                                                                                                                                                                                                    if(m2.get(i)==null)     size2 = 0;
                                                                                                                                                                                                                    else                    size2 = m2.get(i).size();

                                                                                                                                                                                                                    int size = size1-size2;
                                                                                                                                                                                                                    if(size!=0)
                                                                                                                                                                                                                    {
                                                                                                                                                                                                                        return -size;
                                                                                                                                                                                                                    }
                                                                                                                                                                                                                }
                                                                                                                                                                                                                return 0;
                                                                                                                                                                                                             } ).forEach( m -> {
                                                                                                                                                                                                                                    Provincia p = null;
                                                                                                                                                                                                                                    for(List<Comune> c: m.values())
                                                                                                                                                                                                                                    {
                                                                                                                                                                                                                                        for(Comune cc: c)
                                                                                                                                                                                                                                        {
                                                                                                                                                                                                                                            p = cc.getProvincia();
                                                                                                                                                                                                                                        }
                                                                                                                                                                                                                                    }
                                                                                                                                                                                                                                    int posto = counter.getValore();
                                                                                                                                                                                                                                    counter.setValore(posto+1);
                                                                                                                                                                                                                                    System.out.println(posto + "o posto: " + "Provincia di " + p.toString());
                                                                                                                                                                                                                                    m.entrySet().stream().sorted( (m1, m2) -> -(m1.getKey()-m2.getKey()) ).forEach( e -> {
                                                                                                                                                                                                                                                                                                                             System.out.println("\t" + e.getValue().size() + " comuni con " + e.getKey() + " territori controllati:");
                                                                                                                                                                                                                                                                                                                             for(Comune c: e.getValue())
                                                                                                                                                                                                                                                                                                                             {
                                                                                                                                                                                                                                                                                                                                 System.out.println("\t\t" + c.toString());
                                                                                                                                                                                                                                                                                                                             }
                                                                                                                                                                                                                                                                                                                         });
                                                                                                                                                                                                                               } );
    }

    public static void comuniControllatiDaStranieriProvincia(Nazione nazione, String provincia)
    {
        Provincia p = nazione.getProvincia(provincia);

        System.out.println("Comuni controllati da stranieri: " + p.comuniControllatiDaStranieri());
    }

    public static void comuniStranieriControllatiProvincia(Nazione nazione, String provincia)
    {
        Provincia p = nazione.getProvincia(provincia);

        System.out.println("Comuni stranieri controllati: " + p.comuniStranieriControllati());
    }

    public static void comuniControllatiDaStranieri_PercentualeProvincia(Nazione nazione, String provincia)
    {
        Provincia p = nazione.getProvincia(provincia);

        System.out.println("Comuni controllati da stranieri: " + p.comuniControllatiDaStranieri_Percentuale() + "%");
    }

    public static void comuniStranieriControllati_PercentualeProvincia(Nazione nazione, String provincia)
    {
        Provincia p = nazione.getProvincia(provincia);

        System.out.println("Comuni stranieri controllati: " + p.comuniStranieriControllati_Percentuale(nazione) + "%");
    }

    public static void saldoComuniControllatiProvincia(Nazione nazione, String provincia)
    {
        Provincia p = nazione.getProvincia(provincia);

        System.out.println("Saldo: " + p.saldoComuniControllati());
    }

}
