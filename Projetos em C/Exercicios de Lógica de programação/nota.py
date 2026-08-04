alunos = {}
for i in range(5):
    nome = input(f"Digite o nome do {i + 1}° aluno:")
    RGA = int(input(f"Digite o RGA do {i + 1}° aluno:"))
    nota = float(input(f"Digite a nota do {i + 1}° aluno:"))

    alunos[nome] = {
        "RGA":RGA, 
        "nota": nota
    }


for nome, info in alunos.items():
    if nota >= 7:
        print(f"Nome: {nome}")
        print(f"  RGA: {info['RGA']}")
        print(f"  Nota: {info['nota']}")
        print()

