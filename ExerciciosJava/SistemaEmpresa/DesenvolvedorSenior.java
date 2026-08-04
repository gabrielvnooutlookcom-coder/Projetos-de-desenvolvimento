package SistemaEmpresa;

public class DesenvolvedorSenior extends Desenvolvedor
        implements Autenticavel {

    private int pullRequests;

    public DesenvolvedorSenior(String nome,
                               String cpf,
                               String matricula,
                               double salarioBase,
                               String setor,
                               boolean superior,
                               boolean mestrado,
                               int projetos,
                               int pullRequests) {

        super(nome, cpf, matricula,
              salarioBase, setor,
              superior, mestrado,
              projetos);

        this.pullRequests = pullRequests;
    }

    @Override
    public double calcularSalario() {

        double salario = super.calcularSalario();

        salario += getSalarioBase() * 0.60;

        salario += pullRequests * 200;

        return salario;
    }

    @Override
    public boolean autenticar() {

        System.out.println("Desenvolvedor Senior autenticado");

        return true;
    }
}
