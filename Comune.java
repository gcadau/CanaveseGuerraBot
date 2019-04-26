package stat;

public class Comune
{
    private String nome;

    private Provincia provincia;


    public Comune(String nome)
    {
        this.nome = nome;
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
}

