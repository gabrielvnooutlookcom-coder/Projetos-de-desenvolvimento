/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 */

package entidades;

public class Aluno {
    private int id;
    private String nome;
    private String rga;
    private String email;
    private String curso;

    public Aluno() {}

    public Aluno(String nome, String rga, String email, String curso) {
        this.nome = nome;
        this.rga = rga;
        this.email = email;
        this.curso = curso;
    }

    public int getId() { return id; }
    public void setId(int id) { this.id = id; }

    public String getNome() { return nome; }
    public void setNome(String nome) { this.nome = nome; }

    public String getRga() { return rga; }
    public void setRga(String rga) { this.rga = rga; }

    public String getEmail() { return email; }
    public void setEmail(String email) { this.email = email; }

    public String getCurso() { return curso; }
    public void setCurso(String curso) { this.curso = curso; }
}
