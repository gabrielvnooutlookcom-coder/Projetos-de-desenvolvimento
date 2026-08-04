package SistemaEmpresa;

public class Desenvolvedor extends Funcionario {

    private boolean superior;
    private boolean mestrado;
    private int projetos;

    public Desenvolvedor(String nome, String cpf,
                         String matricula,
                         double salarioBase,
                         String setor,
                         boolean superior,
                         boolean mestrado,
                         int projetos) {

        super(nome, cpf, matricula,
              salarioBase, setor);

        this.superior = superior;
        this.mestrado = mestrado;
        this.projetos = projetos;
    }

    @Override
    public double calcularSalario() {

        double salario = getSalarioBase();

        if (superior) {
            salario += getSalarioBase() * 0.25;
        }

        if (mestrado) {
            salario += getSalarioBase() * 0.50;
        }

        salario += projetos * 2000;

        return salario;
    }
}
