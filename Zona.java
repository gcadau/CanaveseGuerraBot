package nazione;

import java.util.LinkedList;
import java.util.List;

public class Zona
{
    private String nome;

    private List<Regione> regioni;

    public Zona(String nome)
    {
        this.nome = nome;
        this.regioni = new LinkedList<>();
    }

    public String getNome()
    {
        return nome;
    }

    public void setNome(String nome)
    {
        this.nome = nome;
    }

    public void addRegione(Regione regione)
    {
        this.regioni.add(regione);
    }

    public List<Regione> getRegioni()
    {
        return new LinkedList<>(this.regioni);
    }

    public void stampaRegioni()
    {
        System.out.println("Regioni di " + this.nome + ":");
        for(Regione r: this.regioni)
        {
            System.out.println(r.toString());
        }
    }

    @Override
    public String toString()
    {
        return this.nome;
    }
}
