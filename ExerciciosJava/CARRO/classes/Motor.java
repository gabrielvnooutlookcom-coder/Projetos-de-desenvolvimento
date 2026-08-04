package classes;

public class Motor {
    
    private String tipo;
    private int velocidadeMAX;
    private int taxaAceleracao;

    public Motor(String tipo, int velocidadeMaxima, int taxaAceleracao) {
        this.tipo = tipo;
        this.velocidadeMAX = velocidadeMaxima;
        this.taxaAceleracao = taxaAceleracao;
    }
    
    public String getTipo() {
        return tipo;
    }

    public int getVelocidadeMAX(){
        return velocidadeMAX;
    } 

    
    public int getTaxaAceleração(){
        return taxaAceleracao;
    }
}


