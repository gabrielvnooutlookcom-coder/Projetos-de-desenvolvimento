package Avatar;

public class arqueiro extends Elfo{
    private int precisao;

    public arqueiro(String nome, int vida,
                  int inteligencia, int destreza,
                  int forca, int agilidade,
                  int sorte,int mana){

            super(nome, vida, inteligencia, destreza, forca, agilidade, sorte,mana);
    }


    public arqueiro(String nome, int vida,
                  int inteligencia, int destreza,
                  int forca, int agilidade,
                  int sorte,int mana, int precisão){

            super(nome, vida, inteligencia, destreza, forca, agilidade, sorte,mana);

        setPrecisao(precisao);
    }

    public int getPrecisao() {
        return precisao;
    }

    public void setPrecisao(int precisão) {

        if(precisao >= 0 && precisao <= 5){
            this.precisao = precisão;

        }else{
            System.out.println("Precisao deve estar entre 1 e 5");
        }
    }

    @Override
    public int atacar() {
        int dano = (super.atacar() + (getDestreza() * precisao) + getAgilidade())/2;
        return dano;
    }

    @Override
    public int defender() {
        int defesa = super.defender() + getAgilidade() + precisao;
        return defesa;
    }

    
}
