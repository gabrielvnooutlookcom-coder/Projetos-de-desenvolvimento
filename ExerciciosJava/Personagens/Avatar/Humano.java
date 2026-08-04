package Avatar;

public class Humano extends Personagem {
    
    private int impeto; 

    public Humano(String nome, int vida,
                  int inteligencia, int destreza,
                  int forca, int agilidade,
                  int sorte){

        super(nome, vida, inteligencia,
              destreza, forca,
              agilidade, sorte); 
    }

    public Humano(String nome, int vida,
                  int inteligencia, int destreza,
                  int forca, int agilidade,
                  int sorte,int impeto){

        super(nome, vida, inteligencia,
              destreza, forca,
              agilidade, sorte);            

        setImpeto(impeto);
    }

    public int getImpeto() {
        return impeto;
    }

    public void setImpeto(int impeto) {
        
        if(impeto >= 0 && impeto <= 5){
            this.impeto = impeto;
        }else{
            System.out.println("Ímpeto deve estar entre 1 e 5");
        }
    }

    @Override
    public int atacar() {
        int dano = (super.atacar()*impeto) / 2;
        return dano;
    }

    @Override
    public int defender() {
        int defesa = super.defender() + impeto;
        return defesa;
    }
    
}
