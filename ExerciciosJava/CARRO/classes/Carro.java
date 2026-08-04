package classes;

public class Carro {
   
    private String marca;
   private String modelo;
   private int anoFabricacao;

   private Motor mot;
   private Freio parando;

   private int velocidadeAtual;
   private boolean On;

   public Carro(String marca,String modelo,int anoFabricacao,String tipoMotor,String tipoFreio){

        this.marca = marca;
        this.modelo = modelo;
        this.anoFabricacao = anoFabricacao;
        
     

        if (tipoMotor.equals("1.0")){
            mot = new Motor("1.0", 160, 20);

        }else if (tipoMotor.equals("1.6")){
            mot = new Motor("1.6", 220, 30);

        }else{
            mot = new Motor("2.0", 260, 40);

        }

     

        if (tipoFreio.equals("Tambor")){
            parando = new Freio("Tambor", 20);

        }else if (tipoFreio.equals("Disco")){
            parando = new Freio("Disco", 30);

        }else{
            parando = new Freio("ABS", 40);

        }

        On = false;
        velocidadeAtual = 0;
    }

 
   public void ligar(){
        if(On){
            System.out.println("O carro já está ligado.");

        }else{
            On = true;
            System.out.println("Carro ligado.");

        }
   }

   public void desligar(){

        if (!On){
            System.out.println("O carro já tá desligado.");
        }else if (velocidadeAtual > 0){
            System.out.println("Não tem como desligar o carro em movimento!");
        } else{
            On = false;
            System.out.println("Carro desligado.");
        }
   }

   public void acelerar(){
        if (!On){
            System.out.println("O carro está desligado.");

        }else if(velocidadeAtual >= mot.getVelocidadeMAX()){
            System.out.println("Velocidade máxima foi atingida!");

        }else{
            int velocidadeAnterior = velocidadeAtual;

            velocidadeAtual += mot.getTaxaAceleração();

            if(velocidadeAtual > mot.getVelocidadeMAX()){
                velocidadeAtual = mot.getVelocidadeMAX();
            }

            System.out.println("Velocidade anterior: " + velocidadeAnterior + " km/h");

            System.out.println("Velocidade atual: " + velocidadeAtual + " km/h");

        }
   }

   public void frear(){

         if (!On){
            System.out.println("O carro está desligado.");

        }else if (velocidadeAtual == 0){
             System.out.println("O carro já está parado.");

        }else{

            int velocidadeAnterior = velocidadeAtual;

            velocidadeAtual -= parando.getTaxaFrenagem();

            if (velocidadeAtual < 0){
                velocidadeAtual = 0;
            }

            System.out.println("Velocidade anterior: " + velocidadeAnterior + " km/h");

            System.out.println("Velocidade atual: " + velocidadeAtual + " km/h");
        }
   }

   public void status(){
         System.out.println("Marca: " + marca);
        System.out.println("Modelo: " + modelo);
        System.out.println("Ano: " + anoFabricacao);

        System.out.println("Motor: " + mot.getTipo());
        System.out.println("Freio: " + parando.getTipo());

        if (On){
            System.out.println("Status: Ligado");
        }else{
            System.out.println("Status: Desligado");
        }

        if (velocidadeAtual == 0){
            System.out.println("Carro parado");
        }else{
            System.out.println("Carro em movimento");
        }

        System.out.println("Velocidade Atual: " + velocidadeAtual + " km/h");

        System.out.println("Velocidade Máxima: " + mot.getVelocidadeMAX() + " km/h");

        System.out.println("---------------------------");
   }
}