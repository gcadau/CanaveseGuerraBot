package nazione;

import java.util.HashMap;
import java.util.Map;

public class Nazione
{
    private Map<String, Comune> comuni;
    private Map<String, Zona> zone;
    private Map<String, Regione> regioni;
    private Map<String, Provincia> province;

    public Nazione()
    {
        this.comuni = new HashMap<>();
        this.province = new HashMap<>();
        this.regioni = new HashMap<>();
        this.zone = new HashMap<>();
    }

    public void add(String c, String p, String r, String z)
    {
        Comune comune = new Comune(c);

        Provincia provincia = this.province.get(p);
        if(provincia==null)
        {
            provincia = new Provincia(p);
            this.province.put(p, provincia);
        }

        comune.setProvincia(provincia);
        provincia.addComune(comune);

        Regione regione = this.regioni.get(r);
        if(regione==null)
        {
            regione = new Regione(r);
            this.regioni.put(r, regione);
        }

        if(provincia.getRegione()==null)
        {
            provincia.setRegione(regione);
            regione.addProvincia(provincia);
        }

        Zona zona = this.zone.get(z);
        if(zona==null)
        {
            zona = new Zona(z);
            this.zone.put(z, zona);
        }

        if(regione.getZona()==null)
        {
            regione.setZona(zona);
            zona.addRegione(regione);
        }

        this.comuni.put(c, comune);
    }

    public Comune consideraComune(String comune)
    {
        Comune c = this.comuni.get(comune);
        if(c!=null)
        {
            c.considera();
            return c;
        }

        return null;
    }

    public Comune getComune(String comune)
    {
        return this.comuni.get(comune);
    }

    public void stampaComuni()
    {
        for(Comune c: this.comuni.values())
        {
            System.out.println(c.toString());
        }
    }

    public void stampaProvince()
    {
        for(Provincia p: this.province.values())
        {
            System.out.println(p.toString());
        }
    }

    public void stampaRegioni()
    {
        for(Regione r: this.regioni.values())
        {
            System.out.println(r.toString());
        }
    }

    public void stampaZone()
    {
        for(Zona z: this.zone.values())
        {
            System.out.println(z.toString());
        }
    }

    public void stampaComuniPerProvincia(String provincia)
    {
        Provincia p = this.province.get(provincia);

        p.stampaComuni();
    }

    public void stampaProvincePerRegione(String regione)
    {
        Regione r = this.regioni.get(regione);

        r.stampaProvince();
    }

    public void stampaRegioniPerZona(String zona)
    {
        Zona z = this.zone.get(zona);

        z.stampaRegioni();
    }

    public void stampaConquisteComune(String comune)
    {
        Comune c = this.comuni.get(comune);

        c.stampaConquiste();
    }
}
