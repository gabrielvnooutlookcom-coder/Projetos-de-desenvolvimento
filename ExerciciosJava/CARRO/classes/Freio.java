package classes;

public class Freio {
    
    private String tipo;
    private int taxaFrenagem;

    public Freio(String tipo, int taxaFrenagem) {
        this.tipo = tipo;
        this.taxaFrenagem = taxaFrenagem;
    }

    public String getTipo() {
        return tipo;
    }

    public int getTaxaFrenagem(){
        return taxaFrenagem;
    } 
}
