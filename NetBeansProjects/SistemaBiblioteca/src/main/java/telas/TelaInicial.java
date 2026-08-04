
package telas;

import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class TelaInicial extends JFrame {

    public TelaInicial() {
        setTitle("Sistema de Controle de Biblioteca");
        setSize(500, 400);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLocationRelativeTo(null); 

        
        JMenuBar barraMenu = new JMenuBar();

      
        JMenu menuNavegacao = new JMenu("Opções");
        JMenu menuSair = new JMenu("Sair");

        
        JMenuItem itemCadastro = new JMenuItem("Cadastrar Livro");
        JMenuItem itemListagem = new JMenuItem("Listar e Excluir");
        JMenuItem itemFechar = new JMenuItem("Fechar Sistema");

       
        menuNavegacao.add(itemCadastro);
        menuNavegacao.add(itemListagem);
        menuSair.add(itemFechar);

        barraMenu.add(menuNavegacao);
        barraMenu.add(menuSair);
        setJMenuBar(barraMenu);

        
        JLabel labelBoasVindas = new JLabel("Bem-vindo ao Sistema da Biblioteca!", SwingConstants.CENTER);
        add(labelBoasVindas);

       
        itemCadastro.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                new TelaCadastro().setVisible(true); // Abre o cadastro
            }
        });

        itemListagem.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                new TelaListagem().setVisible(true); 
            }
        });

        itemFechar.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                System.exit(0); 
            }
        });
    }

    public static void main(String[] args) {
        
        SwingUtilities.invokeLater(() -> {
            new TelaInicial().setVisible(true);
        });
    }
}