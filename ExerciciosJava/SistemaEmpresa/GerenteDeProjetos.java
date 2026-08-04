package SistemaEmpresa;

public class GerenteDeProjetos extends Funcionario
        implements Autenticavel {

    private int projetosGerenciados;

    public GerenteDeProjetos(String nome,
                             String cpf,
                             String matricula,
                             double salarioBase,
                             String setor,
                             int projetosGerenciados) {

        super(nome, cpf, matricula,
              salarioBase, setor);

        this.projetosGerenciados =
                projetosGerenciados;
    }

    @Override
    public double calcularSalario() {

        return getSalarioBase() *
               projetosGerenciados;
    }

    @Override
    public boolean autenticar() {

        System.out.println("Gerente autenticado");

        return true;
    }
}
