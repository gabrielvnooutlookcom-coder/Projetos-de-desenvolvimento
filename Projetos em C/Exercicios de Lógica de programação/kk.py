pessoas = []
soma_idade = 0
while True:
  
    lista = {}
    lista["nome"] = input("Digite seu nome: ").strip()
    lista["sexo"] = input("Digite seu sexo(M ou F):").strip().upper()
    lista["idade"] = int(input("Digite a sua idade:"))

   
    pessoas.append(lista)
    
    soma_idade += lista["idade"]

    continuar = input("Quer continuar? [S/N]: ").strip().upper()
    if continuar == "N":
        break

print("-" * 40)

print(f"A quantide de pessoas cadastradas foram {len(pessoas)}")

media = soma_idade / len(pessoas)
print(f"A media da idade do grupo é: {media:.2f}")

print("Cadastros femininos:")
for i in pessoas:
    if i["sexo"] == 'F':
        print(f"Nome: {i['nome']}")
        print(f"Idade: {i['idade']}")

print("Cadastros de pessoas com idade maior que a media das idades:")
for i in pessoas:
    if i["idade"] > media:
        print(f"Nome: {i['nome']}")
        print(f"Sexo: {i['sexo']}")
        print(f"Idade: {i['idade']}")


