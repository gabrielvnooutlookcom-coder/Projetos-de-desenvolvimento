
package telas;

import DAO.LivroDao;
import entidades.Livro;
import javax.swing.*;
import javax.swing.table.DefaultTableModel;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.ArrayList;

public class TelaListagem extends JFrame {
    private JTable tabela;
    private DefaultTableModel modelo;
    private JButton btnExcluir, btnAtualizar;
    private LivroDao dao = new LivroDao();

    public TelaListagem() {
        setTitle("Gerenciamento de Livros");
        setSize(600, 400);
        setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
        setLocationRelativeTo(null);
        setLayout(new BorderLayout());

        
        modelo = new DefaultTableModel();
        modelo.addColumn("ID");
        modelo.addColumn("Título");
        modelo.addColumn("Autor");
        modelo.addColumn("ISBN");
        modelo.addColumn("Ano");

        tabela = new JTable(modelo);
        JScrollPane scrollPane = new JScrollPane(tabela);
        add(scrollPane, BorderLayout.CENTER);

        
        JPanel painelBotoes = new JPanel();
        btnAtualizar = new JButton("Atualizar Tabela");
        btnExcluir = new JButton("Excluir Selecionado");
        painelBotoes.add(btnAtualizar);
        painelBotoes.add(btnExcluir);
        add(painelBotoes, BorderLayout.SOUTH);

       
        carregarDados();

        
        btnAtualizar.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                carregarDados();
            }
        });

        
        btnExcluir.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                int linhaSelecionada = tabela.getSelectedRow();
                
                if (linhaSelecionada >= 0) {
                   
                    int id = (int) tabela.getValueAt(linhaSelecionada, 0);
                    
                    int resposta = JOptionPane.showConfirmDialog(null, "Tem certeza que deseja excluir este livro?");
                    if (resposta == JOptionPane.YES_OPTION) {
                        dao.deletar(id);
                        JOptionPane.showMessageDialog(null, "Livro excluído!");
                        carregarDados(); 
                    }
                } else {
                    JOptionPane.showMessageDialog(null, "Selecione uma linha da tabela para excluir!");
                }
            }
        });
    }

   
    private void carregarDados() {
        modelo.setRowCount(0); 
        ArrayList<Livro> livros = dao.listarTodos();
        for (Livro l : livros) {
            modelo.addRow(new Object[]{l.getId(), l.getTitulo(), l.getAutor(), l.getIsbn(), l.getAnoPublicacao()});
        }
    }
}