
package DAO;

import entidades.Livro;
import java.sql.*;
import java.util.ArrayList;

public class LivroDao {

    private Connection obterConexao() throws SQLException {
        String url = "jdbc:mysql://localhost:3306/biblioteca";
        String usuario = "root";
        String senha = "1e2e3e4e5e";
        return DriverManager.getConnection(url, usuario, senha);
    }

    public void cadastrar(Livro livro) {
        String sql = "INSERT INTO livro (titulo, autor, isbn, ano_publicacao) VALUES (?, ?, ?, ?)";
        try (Connection conn = obterConexao();
             PreparedStatement stmt = conn.prepareStatement(sql)) {

            stmt.setString(1, livro.getTitulo());
            stmt.setString(2, livro.getAutor());
            stmt.setString(3, livro.getIsbn());
            stmt.setInt(4, livro.getAnoPublicacao());
            stmt.executeUpdate();

        } catch (SQLException e) {
            System.err.println("Erro ao cadastrar livro: " + e.getMessage());
        }
    }

    public ArrayList<Livro> listarTodos() {
        ArrayList<Livro> lista = new ArrayList<>();
        String sql = "SELECT * FROM livro";
        try (Connection conn = obterConexao();
             PreparedStatement stmt = conn.prepareStatement(sql);
             ResultSet rs = stmt.executeQuery()) {

            while (rs.next()) {
                Livro livro = new Livro();
                livro.setId(rs.getInt("id"));
                livro.setTitulo(rs.getString("titulo"));
                livro.setAutor(rs.getString("autor"));
                livro.setIsbn(rs.getString("isbn"));
                livro.setAnoPublicacao(rs.getInt("ano_publicacao"));
                lista.add(livro);
            }

        } catch (SQLException e) {
            System.err.println("Erro ao listar livros: " + e.getMessage());
        }
        return lista;
    }

    public void deletar(int id) {
        String sql = "DELETE FROM livro WHERE id = ?";
        try (Connection conn = obterConexao();
             PreparedStatement stmt = conn.prepareStatement(sql)) {

            stmt.setInt(1, id);
            stmt.executeUpdate();

        } catch (SQLException e) {
            System.err.println("Erro ao deletar livro: " + e.getMessage());
        }
    }
}