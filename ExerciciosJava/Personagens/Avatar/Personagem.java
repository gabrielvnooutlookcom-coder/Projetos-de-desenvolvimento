package Avatar;

public class Personagem {
    private String nome;

    private int vida;
    private int inteligencia;
    private int destreza;
    private int forca;
    private int agilidade;
    private int sorte;


    public Personagem() {

    }


    public Personagem(String nome) {

        this.nome = nome;
    }




    public Personagem(String nome,int vida,int inteligencia,
                        int destreza,int força,
                        int agilidade,int sorte){
        this.nome = nome;
    
        setVida(vida);
        setInteligencia(inteligencia);
        setDestreza(destreza);
        setForça(força);
        setAgilidade(agilidade);
        setSorte(sorte);

     }



     
    public String getNome() {
        return nome;
    }
    public void setNome(String nome) {

        this.nome = nome;
    }


    public int getVida() {
        return vida;
    }

    public void setVida(int vida) {

        if(vida >= 0 && vida <= 100){
            this.vida = vida;
        
        }else{
            System.out.println("A vida deve estar entre 0 e 100.");
        }
    }

    public int getInteligencia() {
        return inteligencia;
    }

    public void setInteligencia(int inteligencia) {

        if(inteligencia >= 0 && inteligencia <= 10){
            this.inteligencia = inteligencia;

        }else{
            System.out.println("A inteligencia deve estar entre 0 e 10.");
        }
    }

    public int getDestreza() {
        return destreza;
    }

    public void setDestreza(int destreza) {

       if(destreza >= 0 && destreza <= 10){
            this.destreza = destreza;

        }else{
            System.out.println("A destreza deve estar entre 0 e 10.");
        }
    }


    public int getForca() {
        return forca;
    }

    public void setForça(int força) {

        if(força >= 0 && força <= 10){
            this.forca = força;

        }else{
            System.out.println("A força deve estar entre 0 e 10.");
        }
    
    }


    public int getAgilidade() {
        return agilidade;
    }

    public void setAgilidade(int agilidade) {

        if(agilidade >= 0 && agilidade <= 10){
            this.agilidade = agilidade;

        }else{
            System.out.println("A agilidade deve estar entre 0 e 10.");
        }

    }


    public int getSorte() {
        return sorte;
    }

    public void setSorte(int sorte) {

        if(sorte >= 0 && sorte <= 10){
            this.sorte = sorte;

        }else{
            System.out.println("A sorte deve estar entre 0 e 10.");
        }
    
    }
  
    public int atacar(){
         int dano = forca + destreza;

         return dano;
    }

    public int defender(){
        int defesa = destreza + agilidade;

        return defesa;
    }


}
