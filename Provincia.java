package nazione;

import java.util.LinkedList;
import java.util.List;

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

    @Override
    public String toString()
    {
        String regione = this.regione.toString();

        return this.nome + " in " + regione;
    }
}

