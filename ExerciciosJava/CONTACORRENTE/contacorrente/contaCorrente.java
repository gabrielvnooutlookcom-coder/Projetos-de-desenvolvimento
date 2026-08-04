package contacorrente;

public class contaCorrente {
    
    private Cliente cliente;
    private int numeroConta;
    private double saldo;


    public void setCliente(Cliente cliente){
        this.cliente = cliente;
    }

    public Cliente getCliente(){
        return cliente;
    }

    public void setNumeroConta(int numeroConta){
        this.numeroConta = numeroConta;
    }

    public int getRga(){
        return numeroConta;
    }

     public void setCpf(double saldo){
        this.saldo = saldo;
    }

    public double getCpf(){
        return saldo;
    }

    public void enviarPix(double valor, String chavePix){
        if (saldo >= valor){
            saldo -= valor;

            System.out.println("----------------------------------");
            System.out.println("PIX enviado com sucesso!");
            System.out.println("Destinatário: " + cliente.getNome());
            System.out.println("CPF: " + cliente.getCpf());
            System.out.println("Chave: " + chavePix);
            System.out.println("Valor: " + valor);

        }else{
            System.out.println("Não a valor suficiente na conta!!");
        }
        
    }

    public void receberPix(double valor){
        saldo += valor;

        System.out.printf("PIX recebido no valor de: %f$ \n", valor);
        System.out.println("Cliente: " + cliente.getNome());
        System.out.println("CPF: " + cliente.getCpf());

    }

    public double mostrarSaldo(){
        System.out.println("-----------------------------");
        System.out.println("Cliente: " + cliente.getNome());
        System.out.println("CPF: " + cliente.getCpf());

         if(saldo > 5000000){
                return -1;
         }

         return saldo;
    }

}
