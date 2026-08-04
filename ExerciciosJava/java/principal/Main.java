package principal;

import classes.*;

public class Main {
    public static void main(String[] args){
        
        Curso curso = new Curso();
        curso.setCodigo("CC01");
        curso.setNome("Ciência da Computação");
        curso.setNomeCampus("Campus Cuiabá");

        Professor prof = new Professor();
        prof.setNome("João Silva");
        prof.setTitulacao("Doutor");

        Aluno aluno = new Aluno();
        aluno.setRga("2023001");
        aluno.setNome("Gabriel");
        aluno.setCurso(curso);
        aluno.setOrientador(prof);
        
        aluno.exibirInformacoes();
    }
}
