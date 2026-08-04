/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package entidades;

public class Professor {
    private int id;
    private String nome;
    private String siape;
    private String unidadeAcademica;
    private String curso;

    public Professor() {}

    public Professor(String nome, String siape, String unidadeAcademica, String curso) {
        this.nome = nome;
        this.siape = siape;
        this.unidadeAcademica = unidadeAcademica;
        this.curso = curso;
    }

    public int getId() { return id; }
    public void setId(int id) { this.id = id; }

    public String getNome() { return nome; }
    public void setNome(String nome) { this.nome = nome; }

    public String getSiape() { return siape; }
    public void setSiape(String siape) { this.siape = siape; }

    public String getUnidadeAcademica() { return unidadeAcademica; }
    public void setUnidadeAcademica(String unidadeAcademica) { this.unidadeAcademica = unidadeAcademica; }

    public String getCurso() { return curso; }
    public void setCurso(String curso) { this.curso = curso; }
}
