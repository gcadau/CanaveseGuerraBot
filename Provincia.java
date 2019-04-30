package nazione;

import utility.Contatore;
import utility.Utility;

import java.util.LinkedList;
import java.util.List;
import java.util.stream.Collectors;

public class Provincia
{
    private String nome;

    private Regione regione;

    private List<Comune> comuni;

    public Provincia(String nome)
    {
        this.nome = nome;
        this.comuni = new LinkedList<>();
        this.regione = null;
    }

    public void addComune(Comune comune)
    {
        this.comuni.add(comune);
    }

    public String getNome()
    {
        return nome;
    }

    public void setNome(String nome)
    {
        this.nome = nome;
    }

    public Regione getRegione()
    {
        return regione;
    }

    public void setRegione(Regione regione)
    {
        this.regione = regione;
    }

    public List<Comune> getComuni()
    {
        return new LinkedList<>(this.comuni);
    }

    public void stampaComuni()
    {
        System.out.println("Comuni di " + this.nome + ":");
        for(Comune c: this.comuni)
        {
            System.out.println(c.toString());
        }
    }

    public long comuniControllatiDaStranieri()
    {
        return this.getComuni().stream().filter( c -> c.controlloStraniero(Utility.PROVINCIA)).count();
    }

    public long comuniStranieriControllati()
    {
        Contatore count = new Contatore(0);
        this.getComuni().stream().mapToLong( c -> c.stranieriControllati(Utility.PROVINCIA)).forEach( l -> {
                                                                                                                int v = count.getValore();
                                                                                                                v+=l;
                                                                                                                count.setValore(v);
                                                                                                           });

        return count.getValore();
    }

    public float comuniControllatiDaStranieri_Percentuale()
    {
        long tot = this.getComuni().size();
        long part = this.comuniControllatiDaStranieri();
        return ( (float) part /tot) * 100;
    }

    public float comuniStranieriControllati_Percentuale(Nazione nazione)
    {
        long part = this.comuniStranieriControllati();
        long tot = nazione.getComuni().size();
        return ( (float) part /tot) * 100;
    }

    public long saldoComuniControllati()
    {
        return (this.comuniStranieriControllati() - this.comuniControllatiDaStranieri());
    }

    @Override
    public String toString()
    {
        String regione = this.regione.toString();

        return this.nome + " in " + regione;
    }
}

