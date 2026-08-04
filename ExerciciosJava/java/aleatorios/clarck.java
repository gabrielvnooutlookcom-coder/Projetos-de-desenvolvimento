package aleatorios;
import java.util.Scanner;


public class clarck {
    
    public static void main(String[] args){
       
        Scanner entrada = new Scanner(System.in);
        System.out.print("Digite o nome do aluno");
        String nome = entrada.nextLine();
        System.out.println("Digite a nota do aluno:");
        float nota = entrada.nextFloat();
        System.out.printf("A nota de %s é %.1f \n", nome, nota);

        
    
    }
}
