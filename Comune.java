package nazione;

import utility.*;
import java.util.LinkedList;
import java.util.List;

public class Comune
{
    private String nome;

    private Provincia provincia;

    private int cons;

    private Comune controllore;
    private List<Comune> conquiste;
    private int nConquiste;

    private Area area;

    public Comune(String nome)
    {
        this.nome = nome;
        this.cons  = 0;
        this.controllore = this;
        this.conquiste = new LinkedList<>();
        this.nConquiste = 0;
        this.area = null;
    }

    public void considera()
    {
        this.cons = 1;
    }

    public void aggiungiConquista(Comune c)
    {
        this.nConquiste++;
        this.conquiste.add(c);
    }

    public Provincia getProvincia()
    {
        return provincia;
    }

    public void setProvincia(Provincia provincia)
    {
        this.provincia = provincia;
    }

    public String getNome()
    {
        return nome;
    }

    public void setNome(String nome)
    {
        this.nome = nome;
    }

    public Comune getControllore()
    {
        return controllore;
    }

    public void setControllore(Comune controllore)
    {
        this.controllore = controllore;
    }

    public List<Comune> getConquiste()
    {
        return new LinkedList<>(this.conquiste);
    }

    public int getnConquiste()
    {
        return nConquiste;
    }

    public boolean isCons()
    {
        return (cons==1);
    }

    public Area getArea()
    {
        return area;
    }

    public void setArea(Area area)
    {
        this.area = area;
    }

    public void stampaConquiste()
    {
        if(this.nConquiste==0)
        {
            System.out.println("Comune non indipendente, controllore: " + this.controllore.toString());
        }
        else
        {
            if(this.nConquiste==1)
            {
                System.out.println("1 comune controllato: ");
            }
            else
            {
                System.out.println(this.nConquiste + " comuni controllati: ");
            }
            for(Comune c: this.conquiste)
            {
                System.out.println("\t" + c.toString());
            }
        }
    }

    public boolean controlloStraniero(String straniero)
    {
        if(this.provincia==null || this.controllore.getProvincia()==null)
        {
            if(!straniero.equals(Utility.AREA)  )    return false;
        }

        switch(straniero)
        {
            case Utility.ZONA:

                Zona zT = this.getProvincia().getRegione().getZona();
                Zona zC = this.controllore.getProvincia().getRegione().getZona();
                return (zT!=zC);
            case Utility.REGIONE:
                Regione rT = this.getProvincia().getRegione();
                Regione rC = this.controllore.getProvincia().getRegione();
                return (rT!=rC);
            case Utility.PROVINCIA:
                Provincia pT = this.getProvincia();
                Provincia pC = this.controllore.getProvincia();
                return (pT!=pC);
            case Utility.AREA:
                Area aT = this.getArea();
                Area aC = this.controllore.getArea();
                if(aT==null || aC==null)
                return (aT!=aC);
            default:
                return false;
        }
    }

    public long stranieriControllati(String straniero)
    {
        if(this.provincia==null)
        {
            if(!straniero.equals(Utility.AREA)  )    return 0;
        }

        switch(straniero)
        {
            case Utility.ZONA:
                Zona zT = this.getProvincia().getRegione().getZona();
                return this.getConquiste().stream().filter( c -> {
                                                                    if(c.getProvincia()==null)    return false;
                                                                    else return (c.getProvincia().getRegione().getZona()!=zT);
                                                                 }).count();
            case Utility.REGIONE:
                Regione rT = this.getProvincia().getRegione();
                return this.getConquiste().stream().filter( c -> {
                                                                    if(c.getProvincia()==null)    return false;
                                                                    else return (c.getProvincia().getRegione()!=rT);
                                                                 }).count();
            case Utility.PROVINCIA:
                Provincia pT = this.getProvincia();
                return this.getConquiste().stream().filter( c -> {
                                                                    if(c.getProvincia()==null)    return false;
                                                                    else return (c.getProvincia()!=pT);
                                                                 }).count();
            case Utility.AREA:
                Area aT = this.getArea();
                if(aT==null)    return 0;
                return this.getConquiste().stream().filter( c -> {
                                                                    if(c.getArea()==null)    return false;
                                                                    else return (c.getArea()!=aT);
                                                                 }).count();
            default:
                return 0;
        }
    }

    @Override
    public String toString()
    {
        if (this.getProvincia()==null)      return this.nome + "( " + "N.D" + " )";
        if (this.getArea()==null)           return this.nome + " (" + this.provincia.toString() + ") ";
        return this.nome + " (" + this.provincia.toString() + ") " + "// in " + this.area.toString();
    }
}

