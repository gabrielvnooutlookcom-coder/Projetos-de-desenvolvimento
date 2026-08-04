package Avatar;

public class feiticeiro extends Elfo {
    private int poderArcano;
   
    
    public feiticeiro(String nome, int vida,
                  int inteligencia, int destreza,
                  int forca, int agilidade,
                  int sorte,int mana){
                
            super(nome, vida, inteligencia, destreza, forca, agilidade, sorte, mana);
    }


    public feiticeiro(String nome, int vida,
                  int inteligencia, int destreza,
                  int forca, int agilidade,
                  int sorte,int mana, int poderArcano){
                
            super(nome, vida, inteligencia, destreza, forca, agilidade, sorte, mana);

            setPoderArcano(poderArcano);
    }

    public int getPoderArcano() {
        return poderArcano;
    }

    public void setPoderArcano(int poderArcano) {
         if(poderArcano >= 0 && poderArcano <= 5){
            this.poderArcano = poderArcano;

        }else{
            System.out.println("Poder arcano deve estar entre 1 e 5");
        }
    }

    @Override
    public int atacar() {
        int dano = (super.atacar() + (getInteligencia() * poderArcano) + getAgilidade())/2;
        return dano;
    }

    @Override
    public int defender() {
        int defesa = super.defender() + getInteligencia() + poderArcano;
        return defesa;
    }
    
}
