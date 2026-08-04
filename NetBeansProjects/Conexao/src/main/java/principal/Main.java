/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package principal;


import DAO.*;
import entidades.*;
import java.util.ArrayList;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        AlunoDao alunoDAO = new AlunoDao();
        ProfessorDao profDAO = new ProfessorDao();
        int opcao = -1;

        while (opcao != 0) {
            System.out.println("\n===== SISTEMA DE CADASTRO =====");
            System.out.println("1 - Cadastrar Aluno(a)");
            System.out.println("2 - Listar Alunos(as)");
            System.out.println("3 - Excluir Aluno(a)");
            System.out.println("4 - Cadastrar Professor(a)");
            System.out.println("5 - Listar Professores(as)");
            System.out.println("6 - Excluir Professor(a)");
            System.out.println("0 - Sair");
            System.out.print("Escolha uma opção: ");
            
            try {
                opcao = Integer.parseInt(scanner.nextLine());
            } catch (NumberFormatException e) {
                System.out.println("Por favor, digite um número válido!");
                continue;
            }

            switch (opcao) {
                case 1:
                    System.out.println("\n--- Cadastrar Aluno(a) ---");
                    System.out.print("Nome: ");
                    String nomeA = scanner.nextLine();
                    System.out.print("RGA: ");
                    String rga = scanner.nextLine();
                    System.out.print("E-mail: ");
                    String email = scanner.nextLine();
                    System.out.print("Curso: ");
                    String cursoA = scanner.nextLine();

                    Aluno novoAluno = new Aluno(nomeA, rga, email, cursoA);
                    alunoDAO.cadastrar(novoAluno);
                    break;

                case 2:
                    System.out.println("\n--- Lista de Alunos(as) ---");
                    ArrayList<Aluno> alunos = alunoDAO.listarAlunos();
                    if (alunos.isEmpty()) {
                        System.out.println("Nenhum aluno cadastrado.");
                    } else {
                        for (Aluno a : alunos) {
                            System.out.printf("ID: %d | Nome: %s | RGA: %s | E-mail: %s | Curso: %s\n", 
                                    a.getId(), a.getNome(), a.getRga(), a.getEmail(), a.getCurso());
                        }
                    }
                    break;

                case 3:
                    System.out.println("\n--- Excluir Aluno(a) ---");
                    System.out.print("Digite o ID do(a) Aluno(a) que deseja excluir: ");
                    int idA = Integer.parseInt(scanner.nextLine());
                    alunoDAO.deletar(idA);
                    break;

                case 4:
                    System.out.println("\n--- Cadastrar Professor(a) ---");
                    System.out.print("Nome: ");
                    String nomeP = scanner.nextLine();
                    System.out.print("SIAPE: ");
                    String siape = scanner.nextLine();
                    System.out.print("Unidade Acadêmica: ");
                    String unidade = scanner.nextLine();
                    System.out.print("Curso: ");
                    String cursoP = scanner.nextLine();

                    Professor novoProf = new Professor(nomeP, siape, unidade, cursoP);
                    profDAO.cadastrar(novoProf);
                    break;

                case 5:
                    System.out.println("\n--- Lista de Professores(as) ---");
                    ArrayList<Professor> professores = profDAO.listarProfessores();
                    if (professores.isEmpty()) {
                        System.out.println("Nenhum professor cadastrado.");
                    } else {
                        for (Professor p : professores) {
                            System.out.printf("ID: %d | Nome: %s | SIAPE: %s | Unidade: %s | Curso: %s\n", 
                                    p.getId(), p.getNome(), p.getSiape(), p.getUnidadeAcademica(), p.getCurso());
                        }
                    }
                    break;

                case 6:
                    System.out.println("\n--- Excluir Professor(a) ---");
                    System.out.print("Digite o ID do(a) Professor(a) que deseja excluir: ");
                    int idP = Integer.parseInt(scanner.nextLine());
                    profDAO.deletar(idP);
                    break;

                case 0:
                    System.out.println("Saindo do sistema. Até mais!");
                    break;

                default:
                    System.out.println("Opção inválida! Escolha uma opção de 0 a 6.");
                    break;
            }
        }
        scanner.close();
    }
}
