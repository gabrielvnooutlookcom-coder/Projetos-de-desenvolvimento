package SistemaEmpresa;

public class Analista extends Funcionario {

    private boolean superior;
    private boolean mestrado;
    private int projetos;

    public Analista(String nome, String cpf,
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

        salario += projetos * 1000;

        return salario;
    }
}
