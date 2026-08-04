package SistemaEmpresa;


    public abstract class Funcionario {

        private String nome;
        private String cpf;
        private String matricula;
        private double salarioBase;
        private String setor;

        public Funcionario(String nome, String cpf,
                        String matricula,
                        double salarioBase,
                        String setor) {

            this.nome = nome;
            this.cpf = cpf;
            this.matricula = matricula;
            this.salarioBase = salarioBase;
            this.setor = setor;
        }

        public abstract double calcularSalario();

        public String getNome() {
            return nome;
        }

        public String getMatricula() {
            return matricula;
        }

        public String getSetor() {
            return setor;
        }

        public double getSalarioBase() {
            return salarioBase;
        }
}


