package Escolher;

import Avatar.*;

import java.util.ArrayList;
import java.util.Scanner;


public class menu{
    
    ArrayList<Personagem> personagens = new ArrayList<>();
    
    public void cadastrar(){
        Scanner teclado = new Scanner(System.in);
        

        System.out.println("Escolha uma calsse de personagem:");
        System.out.println("1- Cavaleiro");
        System.out.println("2 - Pirata");
        System.out.println("3 - Arqueiro");
        System.out.println("4 - Feiticeiro");
        int op = 0; 
        op = teclado.nextInt();
        
        System.out.print("Nome: ");
            String nome = teclado.next();

            System.out.print("Vida: ");
            int vida = teclado.nextInt();

            System.out.print("Inteligencia: ");
            int inteligencia = teclado.nextInt();

            System.out.print("Destreza: ");
            int destreza = teclado.nextInt();

            System.out.print("Forca: ");
            int forca = teclado.nextInt();

            System.out.print("Agilidade: ");
            int agilidade = teclado.nextInt();

            System.out.print("Sorte: ");
            int sorte = teclado.nextInt();


        if (op == 1){
             System.out.print("Impeto: ");
            int impeto = teclado.nextInt();

            System.out.print("Coragem: ");
            int coragem = teclado.nextInt();

            cavaleiro c = new cavaleiro(
                nome,
                vida,
                inteligencia,
                destreza,
                forca,
                agilidade,
                sorte,
                impeto,
                coragem
            );

            personagens.add(c);
        }else if(op == 2){
            System.out.print("Impeto: ");
            int impeto = teclado.nextInt();

            System.out.print("Astucia: ");
            int astucia = teclado.nextInt();

            pirata c = new pirata(
                nome,
                vida,
                inteligencia,
                destreza,
                forca,
                agilidade,
                sorte,
                impeto,
                astucia
            );

            personagens.add(c);
        }else if(op == 3){
            System.out.print("Mana: ");
            int mana = teclado.nextInt();

            System.out.print("Pontaria: ");
            int pontaria = teclado.nextInt();

            arqueiro c = new arqueiro(
                nome,
                vida,
                inteligencia,
                destreza,
                forca,
                agilidade,
                sorte,
                mana,
                pontaria
            );

            personagens.add(c);

        }else if(op == 4){
            System.out.print("Mana: ");
            int mana = teclado.nextInt();

            System.out.print("Poder arcano: ");
            int poderArcano = teclado.nextInt();

            feiticeiro c = new feiticeiro(
                nome,
                vida,
                inteligencia,
                destreza,
                forca,
                agilidade,
                sorte,
                mana,
                poderArcano
            );

            personagens.add(c);
        }
        
    }

    public void listar(){
       for (Personagem p : personagens) {

            System.out.println("Nome: " + p.getNome());
            System.out.println("Vida: " + p.getVida());
            System.out.println("Força: " + p.getForca());

              System.out.println("----------------");

        }
    }

    public void batalha(){
        Scanner teclado = new Scanner(System.in);

        for(int i = 0; i < personagens.size(); i++){

            System.out.println(i + " - " +personagens.get(i).getNome());

        }   

        System.out.print("Escolha o personagem A: ");
        int indiceA = teclado.nextInt();

        System.out.print("Escolha o personagem B: ");
        int indiceB = teclado.nextInt();

        Personagem personagemA = personagens.get(indiceA);

        Personagem personagemB = personagens.get(indiceB);

        int danoA = personagemA.atacar() - personagemB.defender();
        if(danoA < 0){
            danoA = 0;
        }

        int danoB = personagemB.atacar() - personagemA.defender();
        if(danoB < 0){
            danoB = 0;
        }

        System.out.println();
            if(danoA > danoB){
                System.out.println(personagemA.getNome() + " causou " + danoA + " de dano e ganhou a batalha!.");
            }else if(danoB > danoA){
                System.out.println(personagemB.getNome() + " causou " + danoB + " de dano.");
            }  
       
    }

    public static void main(String[] args) {
        
        Scanner teclado = new Scanner(System.in);

        int op = 0;
        menu menu = new menu();

        do{
            System.out.println("\n=== MENU ===");
            System.out.println("1 - Cadastrar personagem");
            System.out.println("2 - listar personagens");
            System.out.println("3 - Batalhar");
            System.out.println("4 - Sair");
            System.out.print("Escolha uma opção: ");

            
            op = teclado.nextInt();

            switch (op){
                
                case 1:
                   menu.cadastrar();
                    break;

                case 2:
                    menu.listar();
                    break;

                case 3:
                    menu.batalha();
                    break;

                case 4:
                    System.out.println("Encerrando programa...");
                    break;

                default:
                    System.out.println("Opção inválida!");
            }
        
            }while(op != 4);
                teclado.close();
    }
}
