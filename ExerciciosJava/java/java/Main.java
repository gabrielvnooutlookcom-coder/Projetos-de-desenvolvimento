
public class Main{
    public static void main(String[] args) {
        
        Curso curso = new Curso();
        curso.codigo = "CC09";
        curso.nome = "Engenharia Elétrica";
        curso.nomeCampus = "Campus Cuibá";

        Professor prof = new Professor();
        prof.titulacao = "Doutor";
        prof.nome = "Robson";

        Alunos aluno = new Alunos();
        aluno.nome = "Enzo da Silva Pinto";
        aluno.rga = "202538937018";
        aluno.curso = curso;
        aluno.orientador = prof;

        aluno.exibirInformacoes();
    }
}
