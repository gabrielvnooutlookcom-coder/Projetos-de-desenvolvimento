package classes;

public class Curso {
    private String codigo;
    private String nome;
    private String nomeCampus;

    public void setCodigo(String codigo){
        this.codigo = codigo;
    }

    public String getCodigo(){
        return codigo;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public String getNome() {
        return nome;
    }

    public void setNomeCampus(String nomeCampus) {
        this.nomeCampus = nomeCampus;
    }

    public String getNomeCampus() {
        return nomeCampus;
    }
}