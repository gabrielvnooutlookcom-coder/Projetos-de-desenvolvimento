package contas;

public class ContaEspecial extends ContaCorrent {
    private double limite;

    public double getLimite() {
        return limite;
    }

    public void setLimite(double limite) {
        this.limite = limite;
    }

    @Override
    public void enviaPix(double valor, String chavePix) {
        
        double totalDisponivel = getSaldo() + limite;

        if(totalDisponivel >= valor){

            if(getSaldo() >= valor){
                setSaldo (getSaldo() - valor);
            }else{

                double restante = valor - getSaldo();

                setSaldo(0);

                limite -= restante;
            }

            System.out.println("PIX enviado");
            System.out.println("Cliente: "+ getCliente().getNome());
        
        }else{
            System.out.println("Saldo + limite insuficiente");
        }

    }

    @Override
    public void receberPix(double valor) {
        double limiteMaximo = 500;

        if(limite < limiteMaximo){

            double valorUsadoLimite = limiteMaximo - limite;

            if(valor >= valorUsadoLimite){
                limite += valorUsadoLimite;
                valor -= valorUsadoLimite;

                setSaldo(getSaldo() + valor);

            }else{
                limite += valor;
            }

        }else{
            setSaldo(getSaldo() + valor);
        }

        System.out.println("PIX recebido");
    }
}
