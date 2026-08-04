import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;

public class primeiraConexao{

    // 1. Definimos as configurações do banco como constantes (final) e estáticas
    private static final String URL = "jdbc:mysql://localhost:3307/saudade";
    private static final String USUARIO = "root";
    private static final String SENHA = "";

    // 2. Método estático para obter a conexão
    public static Connection conectar() {
        try {
            // O DriverManager analisa a URL e escolhe o Driver correto para abrir a conexão
            return DriverManager.getConnection(URL, USUARIO, SENHA);
        } catch (SQLException e) {
            // Tratamento de erro obrigatório se a conexão falhar (senha errada, banco desligado, etc.)
            System.err.println("Erro ao conectar ao banco de dados: " + e.getMessage());
            return null;
        }
    }
}
