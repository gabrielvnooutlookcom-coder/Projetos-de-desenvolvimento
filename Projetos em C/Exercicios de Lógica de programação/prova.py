def encaixa(a, b):
    a = str(a)
    b = str(b)

    if len(b) > len(a):
        return False
    
    i = 1
    while i <= len(b):
        if a[-i] != b[-i]:
            return False
        i += 1

a,b = map(int, input().split())

str_a = str(a)
str_b = str(b)

if len(str_a) <= len(str_b):
    menor = str_a
    maior = str_b
    nome = "a"
else:
    menor = str_b
    maior = str_a
    nome = "b"

if menor in maior:
    print(f"{nome} é segmento do outro")
else:
    print("um não é segmento do outro")