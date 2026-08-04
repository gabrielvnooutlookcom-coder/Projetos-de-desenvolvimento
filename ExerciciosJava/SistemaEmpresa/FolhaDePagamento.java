package SistemaEmpresa;

import java.util.ArrayList;

public class FolhaDePagamento {

    public static void calcularFolha(
            ArrayList<Funcionario> funcionarios,
            int mes,
            int ano) {

        double total = 0;

        System.out.println(
                "FOLHA DE PAGAMENTO "
                        + mes + "/" + ano);

        for (Funcionario f : funcionarios) {

            double salario =
                    f.calcularSalario();

            total += salario;

            System.out.println();
            System.out.println(
                    "Nome: "
                            + f.getNome());

            System.out.println(
                    "Matricula: "
                            + f.getMatricula());

            System.out.println(
                    "Setor: "
                            + f.getSetor());

            System.out.println(
                    "Tipo: "
                            + f.getClass()
                            .getSimpleName());

            System.out.println(
                    "Salario: R$ "
                            + salario);
        }

        System.out.println();
        System.out.println(
                "Total da folha: R$ "
                        + total);
    }
}
