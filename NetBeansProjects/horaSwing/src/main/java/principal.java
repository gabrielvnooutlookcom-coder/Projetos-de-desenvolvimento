import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.SQLException;

public class principal{
    public static void main(String[] args) {
        // Dados para a ligação
        String url = "jdbc:mysql://localhost:3306/empresa";
        String usuario = "root";
        String senha = "1e2e3e4e5e";
        
        String sql = "INSERT INTO clientes (nome, cpf, rg, telefone, email) VALUES (?, ?)";

        // Tenta fazer a ligação (Connection) e preparar a ficha (PreparedStatement)
        try (Connection conn = DriverManager.getConnection(url, usuario, senha);
             PreparedStatement stmt = conn.prepareStatement(sql)) {
            
            // Se a ligação deu certo, preenchemos a ficha
            stmt.setString(1, "Eduardo");
            stmt.setString(2, "091.567.436-06");
            stmt.setString(3, "045884");
            stmt.setString(3, "65 99341731");
            stmt.setString(3, "eduardo.lima@gmail.com");
            
            // Envia o pedido para o banco salvar
            stmt.executeUpdate();
            System.out.println("Cliente cadastrado com sucesso!");
            
        } catch (SQLException e) {
            // Se o telefone estiver ocupado, senha errada ou o banco fora do ar, cai aqui
            System.out.println("Não consegui falar com a pizzaria/banco. Motivo: " + e.getMessage());
        }
        
        // FIM DO BLOCO: Aqui o Java já desligou a conexão automaticamente para você!
    }
}