def eh_primo(x):
    if x < 2:
        return False
    for i in range(2, int(x**0.5) + 1):
        if x % i == 0:
            return False
    return True

N = int(input())

for p in range(N, 2, -1):
    if eh_primo(p) and eh_primo(p - 2):
        print(p - 2, p)
        break