def bubbleSort(vet):
    for numpass in range(len(vet)-1, 0, -1):
        for i in range(numpass):
            if vet[i] > vet[i+1]:
                vet[i], vet[i+1] = vet[i+1], vet[i]


#n é o tamanho do vetor
n = 10
vet = []
for i in range(n):
    vet.append(int(input('Type a number: ')))

bubbleSort(vet)    
print(vet)