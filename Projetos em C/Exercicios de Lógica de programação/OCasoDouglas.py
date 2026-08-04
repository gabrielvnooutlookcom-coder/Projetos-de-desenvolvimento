def primo(x):
    if x < 2:
        return False

    for i in range(2, int(x**0.5) + 1):
        if x % i == 0:
            return False

    return True

N = int(input())

for i in range(N):
    c = int(input()) + 1

    if c % 7 == 0 and c % 2 != 0 and primo(c+2):
        print("Yes")
    else:
        print("No")
    

