package Avatar;

public class pirata extends Humano {
    
    private int astucia;


    public pirata(String nome, int vida,
                  int inteligencia, int destreza,
                  int forca, int agilidade,
                  int sorte,int impeto){

                super(nome, vida, inteligencia, destreza, forca, agilidade, sorte, impeto);

    }

    public pirata(String nome, int vida,
                  int inteligencia, int destreza,
                  int forca, int agilidade,
                  int sorte,int impeto, int astucia){

                super(nome, vida, inteligencia, destreza, forca, agilidade, sorte, impeto);

                setAstucia(astucia);
    }

    public int getAstucia() {
        return astucia;
    }

    public void setAstucia(int astucia) {

        if(astucia >= 0 && astucia <= 5){
            this.astucia = astucia;
        }else{
            System.out.println("Astucia deve estar entre 1 e 5");
        }

    }
    
    @Override
    public int atacar() {
        int dano = (super.atacar() + (getForca() * astucia) + getSorte()) / 2;
        return dano;
    }

    @Override
    public int defender() {
        int defesa = super.defender() + getAgilidade() + astucia;
        return defesa;
    }

}
