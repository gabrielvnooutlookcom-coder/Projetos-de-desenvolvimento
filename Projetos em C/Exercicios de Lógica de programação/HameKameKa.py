C = int(input())

for _ in range(C):
    ataque = input().strip()

    pos_h = ataque.find('h')
    
    count_a = 0
    i = pos_h + 1
    while i < len(ataque) and ataque[i] == 'a':
        count_a += 1
        i += 1

   
    print('k' + 'a' * (2 * count_a))