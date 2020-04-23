def insertionSort(vet):
    cont = 1
    for cont in range(len(vet)):
        aux = vet[cont]
        j = cont-1
        while j>= 0 and aux < vet[j]:
            vet[j+1] = vet[j]
            j -= 1
        vet[j+1] = aux


n = 5
vet = []
for i in range(n):
    vet.append(int(input('Type a number: ')))

insertionSort(n, vet)
print(vet)