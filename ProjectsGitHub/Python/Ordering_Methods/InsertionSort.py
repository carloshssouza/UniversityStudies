def insertionSort(n, vet):
    cont = int(1)
    for cont in range(n):
        aux = vet[cont]
        j = cont-1
        while j>= 0 and aux < vet[j]:
            vet[j+1] = vet[j]
            j -= 1
        vet[j+1] = aux


n = 5
vet = []
for i in range(n):
    vet.append(input('Type a number: '))

insertionSort(n, vet)
for i in range(n):
        print(vet[i])