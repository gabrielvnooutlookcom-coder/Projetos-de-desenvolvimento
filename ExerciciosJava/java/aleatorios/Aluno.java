package aleatorios;

public class Aluno {
    
    private String nome;
    private int rga;

    public Aluno(String nome, int rga){
        this.nome = nome;
        this.rga = rga;
    
    }

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public int getRga() {
        return rga;
    }

    public void setRga(int rga) {
        this.rga = rga;
    }

    
  
}

