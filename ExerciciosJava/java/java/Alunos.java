public class Alunos{
    String rga;
    String nome;
    Curso curso;
    Professor orientador;

    void exibirInformacoes(){
        System.out.println("Aluno: " + rga + " - " + nome);
        System.out.println("Curso: " + curso.codigo + " - " + curso.nome + " - " + curso.nomeCampus);
        System.out.println("Orientador: " + orientador.titulacao + " " + orientador.nome);
    }
}
