/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package DAO;

import entidades.Aluno;
import java.sql.*;
import java.util.ArrayList;

public class AlunoDao{

   
    private Connection obterConexao() throws SQLException {
        String url = "jdbc:mysql://localhost:3306/cadastro";
        String usuario = "root";
        String senha = "1e2e3e4e5e"; 
        return DriverManager.getConnection(url, usuario, senha);
    }

    public void cadastrar(Aluno novoAluno) {
        String sql = "INSERT INTO aluno (nome, rga, email, curso) VALUES (?, ?, ?, ?)";

        try (Connection conn = obterConexao();
             PreparedStatement stmt = conn.prepareStatement(sql)) {

            stmt.setString(1, novoAluno.getNome());
            stmt.setString(2, novoAluno.getRga());
            stmt.setString(3, novoAluno.getEmail());
            stmt.setString(4, novoAluno.getCurso());

            stmt.executeUpdate();
            System.out.println("Aluno(a) cadastrado com sucesso!");

        } catch (SQLException e) {
            System.err.println("Erro ao cadastrar aluno: " + e.getMessage());
        }
    }

    public ArrayList<Aluno> listarAlunos() {
        ArrayList<Aluno> lista = new ArrayList<>();
        String sql = "SELECT * FROM aluno";

        try (Connection conn = obterConexao();
             PreparedStatement stmt = conn.prepareStatement(sql);
             ResultSet rs = stmt.executeQuery()) {

            while (rs.next()) {
                Aluno aluno = new Aluno();
                aluno.setId(rs.getInt("id"));
                aluno.setNome(rs.getString("nome"));
                aluno.setRga(rs.getString("rga"));
                aluno.setEmail(rs.getString("email"));
                aluno.setCurso(rs.getString("curso"));
                lista.add(aluno);
            }

        } catch (SQLException e) {
            System.err.println("Erro ao listar alunos: " + e.getMessage());
        }
        return lista;
    }

    public void deletar(int aluno_id) {
        String sql = "DELETE FROM aluno WHERE id = ?";

        try (Connection conn = obterConexao();
             PreparedStatement stmt = conn.prepareStatement(sql)) {

            stmt.setInt(1, aluno_id);
            int linhasAfetadas = stmt.executeUpdate();
            
            if (linhasAfetadas > 0) {
                System.out.println("Aluno(a) excluído com sucesso!");
            } else {
                System.out.println("Nenhum aluno encontrado com o ID informado.");
            }

        } catch (SQLException e) {
            System.err.println("Erro ao deletar aluno: " + e.getMessage());
        }
    }
}
