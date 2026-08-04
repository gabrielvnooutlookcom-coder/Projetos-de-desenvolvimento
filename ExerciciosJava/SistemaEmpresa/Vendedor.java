package SistemaEmpresa;

public class Vendedor extends Funcionario {

    private double comissao;
    private double totalVendas;

    public Vendedor(String nome, String cpf,
                    String matricula,
                    double salarioBase,
                    String setor,
                    double comissao,
                    double totalVendas) {

        super(nome, cpf, matricula,
              salarioBase, setor);

        this.comissao = comissao;
        this.totalVendas = totalVendas;
    }

    @Override
    public double calcularSalario() {

        return getSalarioBase() +
               (comissao * totalVendas);
    }
}
