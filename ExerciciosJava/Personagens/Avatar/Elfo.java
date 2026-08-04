package Avatar;

public class Elfo extends Personagem{
    
    private int mana;

    public Elfo(String nome, int vida,
                  int inteligencia, int destreza,
                  int forca, int agilidade,
                  int sorte){
        
        super(nome, vida, inteligencia, destreza, forca, agilidade, sorte);
    }

    public Elfo(String nome, int vida,
                  int inteligencia, int destreza,
                  int forca, int agilidade,
                  int sorte,int mana){
        
        super(nome, vida, inteligencia, destreza, forca, agilidade, sorte);

        setMana(mana);
    }

    public int getMana() {
        return mana;
    }

    public void setMana(int mana) {

        if(mana >= 0 && mana <= 5){
            this.mana = mana;
        }else{
            System.out.println("A mana deve estar entre 1 e 5");
        }

    }

    @Override
    public int atacar() {
        int dano = super.atacar() + mana;
        return dano;
    }

    @Override
    public int defender() {
        int defesa = super.defender() + (mana/2);
        return defesa;
    }
    

}
