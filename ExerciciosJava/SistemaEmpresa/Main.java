package SistemaEmpresa;

import java.util.ArrayList;

public class Main {

    public static void main(String[] args) {

        ArrayList<Funcionario> funcionarios =
                new ArrayList<>();

        funcionarios.add(
                new Vendedor(
                        "Ana",
                        "111",
                        "001",
                        3000,
                        "Vendas",
                        10,
                        100));

        funcionarios.add(
                new Analista(
                        "Bruno",
                        "222",
                        "002",
                        5000,
                        "Tecnologia",
                        true,
                        false,
                        2));

        funcionarios.add(
                new Desenvolvedor(
                        "Carlos",
                        "333",
                        "003",
                        6000,
                        "Tecnologia",
                        true,
                        true,
                        3));

        funcionarios.add(
                new DesenvolvedorSenior(
                        "Marcos",
                        "444",
                        "004",
                        8000,
                        "Tecnologia",
                        true,
                        true,
                        4,
                        20));

        funcionarios.add(
                new GerenteDeProjetos(
                        "Pedro",
                        "555",
                        "005",
                        7000,
                        "Gestao",
                        3));

        FolhaDePagamento.calcularFolha(
                funcionarios,
                5,
                2026);
    }
}
