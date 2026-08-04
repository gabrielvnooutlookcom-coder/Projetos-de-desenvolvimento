package contas;

public class ContaCorrent{
    
    private int numConta;
    private int numAgencia;
    private String nomeAgen;
    private double saldo;
    
    private Cliente cliente;


    public int getNumConta() {
        return numConta;
    }
    public void setNumConta(int numConta) {
        this.numConta = numConta;
    }
    public int getNumAgencia() {
        return numAgencia;
    }
    public void setNumAgencia(int numAgencia) {
        this.numAgencia = numAgencia;
    }
    public String getNomeAgen() {
        return nomeAgen;
    }
    public void setNomeAgen(String nomeAgen) {
        this.nomeAgen = nomeAgen;
    }
    public double getSaldo() {
        return saldo;
    }
    public void setSaldo(double saldo) {
        this.saldo = saldo;
    }
    
    public Cliente getCliente(){
        return cliente;
    }
    public void setCliente(Cliente cliente){
        this.cliente = cliente;
    }


    public void enviaPix(double valor, String chavePix){

        if(saldo >= valor){

            saldo -= valor;

            System.out.println("Pix enviado com sucesso!");
            System.out.println("Cliente: " + cliente.getNome());
            System.out.println("CPF: " + cliente.getCpf());

        }else{
            System.out.println("Saldo insuficiente");
        }
    }
    
    public void receberPix(double valor){

        saldo += valor;

        System.out.println("PIX recebido");
    }

    public void mostrarSaldo(){
        System.out.println("Cliente: "+ cliente.getNome());

        if(saldo > 5000000){
            System.out.println("É necesserário um gerente com credencial maiores ");

        }else{
            System.out.println("Saldo"+ saldo);
        }
    }
    
    
    

}
