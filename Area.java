package nazione;

import java.util.LinkedList;
import java.util.List;

public class Area
{
    private String nome;

    private List<Comune> comuni;

    public Area(String nome)
    {
        this.nome = nome;
        this.comuni = new LinkedList<>();
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
        return this.nome;
    }
}
