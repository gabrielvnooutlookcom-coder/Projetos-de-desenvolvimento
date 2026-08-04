package principalConta;

import contacorrente.*;

public class main {
    
    public static void main(String[] args) {
        
        Cliente cliente = new Cliente();

        cliente.setNome("Gabriel");
        cliente.setRga("190837");
        cliente.setCpf("091.804.491-07");

        contaCorrente conta = new contaCorrente();

        conta.setCliente(cliente);
        conta.setNumeroConta(1367);

        conta.receberPix(1000);
        conta.enviarPix(200, "092.087.345-09");

        double saldo = conta.mostrarSaldo();

        if (saldo == -1){
            System.out.println("É necessário um gerente com credenciais maiores para ver o valor do saldo do cliente");
        
        }else{
            System.out.println("Saldo: " + saldo);

        }

    }

}
