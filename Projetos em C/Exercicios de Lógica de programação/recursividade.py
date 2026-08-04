def soma_lista(lista, i = 0):
    
    if i == len(lista):
        return 0 
    
    return lista[i] + soma_lista(lista,i + 1)

n = int(input("Digite quantos numeros quer somar:"))
vetor = []
i = 0 

for i in range(n):
    numero = int(input(f"Digite o {i + 1}° numero:"))
    vetor.append(numero)

print(soma_lista(vetor))