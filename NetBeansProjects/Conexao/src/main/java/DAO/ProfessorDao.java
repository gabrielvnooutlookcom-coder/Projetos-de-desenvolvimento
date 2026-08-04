/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package DAO;

import entidades.Professor;
import java.sql.*;
import java.util.ArrayList;

public class ProfessorDao{

    
    private Connection obterConexao() throws SQLException {
        String url = "jdbc:mysql://localhost:3306/cadastro";
        String usuario = "root";
        String senha = "1e2e3e4e5e"; 
        return DriverManager.getConnection(url, usuario, senha);
    }

    public void cadastrar(Professor novoProfessor) {
        String sql = "INSERT INTO professor (nome, siape, unidade_academica, curso) VALUES (?, ?, ?, ?)";

        try (Connection conn = obterConexao();
             PreparedStatement stmt = conn.prepareStatement(sql)) {

            stmt.setString(1, novoProfessor.getNome());
            stmt.setString(2, novoProfessor.getSiape());
            stmt.setString(3, novoProfessor.getUnidadeAcademica());
            stmt.setString(4, novoProfessor.getCurso());

            stmt.executeUpdate();
            System.out.println("Professor(a) cadastrado com sucesso!");

        } catch (SQLException e) {
            System.err.println("Erro ao cadastrar professor: " + e.getMessage());
        }
    }

    public ArrayList<Professor> listarProfessores() {
        ArrayList<Professor> lista = new ArrayList<>();
        String sql = "SELECT * FROM professor";

        try (Connection conn = obterConexao();
             PreparedStatement stmt = conn.prepareStatement(sql);
             ResultSet rs = stmt.executeQuery()) {

            while (rs.next()) {
                Professor prof = new Professor();
                prof.setId(rs.getInt("id"));
                prof.setNome(rs.getString("nome"));
                prof.setSiape(rs.getString("siape"));
                prof.setUnidadeAcademica(rs.getString("unidade_academica"));
                prof.setCurso(rs.getString("curso"));
                lista.add(prof);
            }

        } catch (SQLException e) {
            System.err.println("Erro ao listar professores: " + e.getMessage());
        }
        return lista;
    }

    public void deletar(int professor_id) {
        String sql = "DELETE FROM professor WHERE id = ?";

        try (Connection conn = obterConexao();
             PreparedStatement stmt = conn.prepareStatement(sql)) {

            stmt.setInt(1, professor_id);
            int linhasAfetadas = stmt.executeUpdate();

            if (linhasAfetadas > 0) {
                System.out.println("Professor(a) excluído com sucesso!");
            } else {
                System.out.println("Nenhum professor encontrado com o ID informado.");
            }

        } catch (SQLException e) {
            System.err.println("Erro ao deletar professor: " + e.getMessage());
        }
    }
}
