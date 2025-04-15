def mergeSort(vetor, inicio, fim):
    if inicio < fim:
        meio = (inicio + fim) // 2
        mergeSort(vetor, inicio, meio)
        mergeSort(vetor, meio + 1, fim)
        merge(vetor, inicio, meio, fim)

def merge(vetor, inicio, meio, fim):
    aux = []
    P1 = inicio
    P2 = meio + 1

    while P1 <= meio and P2 <= fim:
        if vetor[P1] < vetor[P2]:#se for menor armazenar em vetor aux
            aux.append(vetor[P1])
            P1 += 1#incremento
        else:#caso contrario armazenar P2 em aux
            aux.append(vetor[P2])
            P2 += 1#incremento
 
    while P1 <= meio:#enquanto nao estourar meio
        aux.append(vetor[P1])#copiar p1 em aux
        P1 += 1

  
    while P2 <= fim:#no p2 enquanto nao estourar compia em aux
        aux.append(vetor[P2])
        P2 += 1


    for i in range(len(aux)):
        vetor[inicio + i] = aux[i]#para definir tamanho do aux  
            
  
  
vetor = [72, 30, -10, -49, -45, 59, 59, 53, -95, -4, 45, -3, 85, 3, 38]
N = len(vetor)
mergeSort(vetor, 0, N - 1)
print("Vetor ordenado:", vetor)
