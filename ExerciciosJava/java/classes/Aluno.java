package classes;

public class Aluno {
   private String rga;
   private String nome;
   private Curso curso;
   private Professor orientador;

   public void setRga(String rga){
        this.rga = rga;
   }
    
   public String getRga(){
        return rga;
   }

    public void setNome(String nome){
        this.nome = nome;
   }
    
   public String getNome(){
        return nome;
   }

    public void setCurso(Curso curso){
        this.curso = curso;
   }
    
   public Curso getCurso(){
        return curso;
   }

    public void setOrientador(Professor orientador){
        this.orientador = orientador;
   }
    
   public Professor getOrientador(){
        return orientador;
   }

    public void exibirInformacoes(){
        System.out.println("Aluno: " + getRga() + " - " + getNome());
        System.out.println("Curso: " + curso.getCodigo() + " - " + curso.getNome() + " - " + curso.getNomeCampus());
        System.out.println("Orientador: " + orientador.getTitulacao() + " " + orientador.getNome());
    }

}
