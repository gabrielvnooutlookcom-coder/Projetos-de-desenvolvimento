package Avatar;

public class cavaleiro extends Humano {
    
    private int coragem;


     public cavaleiro(String nome, int vida,
                  int inteligencia, int destreza,
                  int forca, int agilidade,
                  int sorte,int impeto){
            
            super(nome,vida,inteligencia,destreza,forca,agilidade,sorte,impeto);
    }

    public cavaleiro(String nome, int vida,
                  int inteligencia, int destreza,
                  int forca, int agilidade,
                  int sorte,int impeto, int coragem){
            
            super(nome,vida,inteligencia,destreza,forca,agilidade,sorte,impeto);

            setCoragem(coragem);
        }

    public int getCoragem() {
        return coragem;
    }

    public void setCoragem(int coragem) {

        if(coragem >= 0 && coragem <= 5){
            this.coragem = coragem;
        }else{
            System.out.println("Coragem deve estar entre 1 e 5");
        }

    }

    @Override
    public int atacar() {
        int dano = (super.atacar() + (getForca() * coragem)) / 2;
        return dano;
    }

    @Override
    public int defender() {
        int defesa = super.defender() + getAgilidade() + coragem;
        return defesa;
    }

        
}
