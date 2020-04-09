def bubbleSort(n, vet):
    stop = 0
    aux = 0
    end = n
    while stop == 0:
        stop = 1
        for i in range(end-1):
            if vet[i] > vet[i+1]:
                aux = vet[i]
                vet[i] = vet[i+1]
                vet[i+1] = aux
                stop = 0

        end-= 1

    

#n é o tamanho do vetor
n = 5
vet = []
for i in range(n):
    vet.append(input('Type a number: '))
bubbleSort(n, vet)      

for i in range(n):
        print(vet[i])