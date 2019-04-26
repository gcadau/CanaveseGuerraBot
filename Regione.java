package stat;

import java.util.LinkedList;
import java.util.List;

public class Regione
{
    private String nome;

    private Zona zona;

    private List<Provincia> province;

    public Regione(String nome)
    {
        this.nome = nome;
        this.province = new LinkedList<>();
        this.zona = null;
    }

    public void addProvincia(Provincia provincia)
    {
        this.province.add(provincia);
    }

    public String getNome()
    {
        return nome;
    }

    public void setNome(String nome)
    {
        this.nome = nome;
    }

    public Zona getZona()
    {
        return zona;
    }

    public void setZona(Zona zona)
    {
        this.zona = zona;
    }

    public List<Provincia> getProvince()
    {
        return new LinkedList<>(this.province);
    }
}
