
package telas;

import DAO.LivroDao;
import entidades.Livro;
import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class TelaCadastro extends JFrame {
    private JTextField txtTitulo, txtAutor, txtIsbn, txtAno;
    private JButton btnSalvar;

    public TelaCadastro() {
        setTitle("Cadastrar Novo Livro");
        setSize(400, 300);
        setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE); 
        setLocationRelativeTo(null);
        setLayout(new GridLayout(5, 2, 10, 10)); 

       
        add(new JLabel(" Título:"));
        txtTitulo = new JTextField();
        add(txtTitulo);

        add(new JLabel(" Autor:"));
        txtAutor = new JTextField();
        add(txtAutor);

        add(new JLabel(" ISBN:"));
        txtIsbn = new JTextField();
        add(txtIsbn);

        add(new JLabel(" Ano de Publicação:"));
        txtAno = new JTextField();
        add(txtAno);

        btnSalvar = new JButton("Salvar no Banco");
        add(btnSalvar);

        
        btnSalvar.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                try {
                    String titulo = txtTitulo.getText();
                    String autor = txtAutor.getText();
                    String isbn = txtIsbn.getText();
                    int ano = Integer.parseInt(txtAno.getText());

                    Livro novoLivro = new Livro(titulo, autor, isbn, ano);
                    LivroDao dao = new LivroDao();
                    dao.cadastrar(novoLivro);

                    JOptionPane.showMessageDialog(null, "Livro cadastrado com sucesso!");
                    
                   
                    txtTitulo.setText("");
                    txtAutor.setText("");
                    txtIsbn.setText("");
                    txtAno.setText("");

                } catch (NumberFormatException ex) {
                    JOptionPane.showMessageDialog(null, "Por favor, digite um ano válido!");
                }
            }
        });
    }
}