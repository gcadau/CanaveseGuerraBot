package stat;

import utility.*;

import nazione.*;

import java.util.*;

import static java.util.stream.Collectors.*;

public class Stat
{

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

    public static void classificaSaldoComuniControllatiProvincia(Nazione nazione)
    {
        Map<String, Long> m = new HashMap<>();

        for(Provincia p: nazione.getProvince())
        {
            m.put(p.getNome(), p.saldoComuniControllati());
        }

        m.entrySet().stream().sorted( (e1, e2) -> {
                                                      return - ( e1.getValue().intValue() - e2.getValue().intValue() );
                                                  } ).forEach( e -> {
                                                                        System.out.println(e.getKey() + ", saldo = " + e.getValue());
                                                                    } );
    }

    public static void classificaSaldoComuniControllatiProvinciaLong(Nazione nazione)
    {
        Map<Provincia, Long> m = new HashMap<>();

        for(Provincia p: nazione.getProvince())
        {
            m.put(p, p.saldoComuniControllati());
        }

        m.entrySet().stream().sorted( (e1, e2) -> {
                                                      return - ( e1.getValue().intValue() - e2.getValue().intValue() );
                                                  } ).forEach( e -> {
                                                                        System.out.println(e.getKey().getNome() + ", saldo = " + e.getValue());
                                                                        System.out.println("\tComuni stranieri controllati: " + e.getKey().comuniStranieriControllati() + ", comuni controllati da stranieri: " + e.getKey().comuniControllatiDaStranieri());
                                                                        System.out.println("\tPercentuale di comuni stranieri controllati: " + e.getKey().comuniStranieriControllati_Percentuale(nazione) + "%, percentuale di comuni caduti sotto il dominio straniero: " + e.getKey().comuniControllatiDaStranieri_Percentuale() + "%");
                                                                    } );
    }

}
