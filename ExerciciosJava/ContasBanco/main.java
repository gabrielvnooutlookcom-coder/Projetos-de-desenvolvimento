import contas.Cliente;
import contas.ContaEspecial;

public class main {
    public static void main(String[] args) {

        Cliente cliente = new Cliente();

        cliente.setNome("Gabriel");
        cliente.setRg("123456");
        cliente.setCpf("999.999.999-99");

        ContaEspecial conta =
                new ContaEspecial();

        conta.setCliente(cliente);

        conta.setNumConta(1001);

        conta.setNumAgencia(10);

        conta.setNomeAgen("Banco Central");

        conta.setSaldo(100);

        conta.setLimite(500);

        conta.mostrarSaldo();

        System.out.println();

        conta.enviaPix(300,
                "gabriel@email.com");

        conta.mostrarSaldo();

        System.out.println();

        conta.receberPix(400);

        conta.mostrarSaldo();
    } 
}
