package aleatorios;

import java.util.ArrayList;



public class MAIN {

      public static void main(String[] args) {

        Aluno joao = new Aluno("João", 203482025);
        Aluno maria = new Aluno("Maria", 806522025);
        Aluno pedro = new Aluno("Pedro", 942752025);

        ArrayList<Aluno> alunos = new ArrayList<>();
        alunos.add(joao);
        alunos.add(maria);
        alunos.add(pedro);

        for (Aluno aluno : alunos) {
            System.out.println(aluno.getNome());
            System.out.println(aluno.getRga());
        }


       
    }
}
