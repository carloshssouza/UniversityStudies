from abc import ABC, abstractmethod

class EmpDomestica(ABC):
    def __init__(self, nome, telefone):
        self.__nome = nome
        self.__telefone = telefone

    def getNome(self):
        return self.__nome

    def getTelefone(self):
        return self.__telefone

    @abstractmethod
    def getSalario():
        pass

class Horista(EmpDomestica):
    def __init__(self, nome, telefone, horasTrabalhadas, valorPorHora):
        super().__init__(nome, telefone)
        self.__horasTrabalhadas = horasTrabalhadas
        self.__valorPorHora = valorPorHora

    def getHorasTrabalhadas(self):
        return self.__horasTrabalhadas

    def getValorPorHora(self):
        return self.__valorPorHora

    def getSalario(self):
        return self.getHorasTrabalhadas() * self.getValorPorHora()
        
class Diarista(EmpDomestica):
    def __init__(self, nome, telefone, diasTrabalhados, valorPorDia):
        super().__init__(nome, telefone)
        self.__diasTrabalhados = diasTrabalhados
        self.__valorPorDia = valorPorDia

    def getDiasTrabalhados(self):
        return self.__diasTrabalhados

    def getValorPorDia(self):
        return self.__valorPorDia

    def getSalario(self):
        return self.getDiasTrabalhados() * self.getValorPorDia()
        
class Mensalista(EmpDomestica):
    def __init__(self, nome, telefone, valorMensal):
        super().__init__(nome, telefone)
        self.__valorMensal = valorMensal

    def getValorMensal(self):
        return self.__valorMensal

    def getSalario(self):
        return self.getValorMensal()
        
     
horista = Horista('Maria', '98989898', 160, 10)
diarista = Diarista('Benedita', '95959595', 20, 55)
mensalista = Mensalista('Fatima', '94949494', 1000)

lista = [horista, diarista, mensalista]
menor = lista[0].getSalario()

print('Lista de empregadas: ')
for i in range(len(lista)):
    print(f'Nome: {lista[i].getNome()}')
    print(f'Telefone: {lista[i].getTelefone()}')
    print(f'Salario: R${lista[i].getSalario()},00')
    print()
    if lista[i].getSalario() < menor:
        menor = lista[i].getSalario()
        melhorEmp = lista[i]

print('A empregada com o melhor preço de serviço para a republica é: ')    
print(f'Nome: {melhorEmp.getNome()}')
print(f'Telefone: {melhorEmp.getTelefone()}')
print(f'Salario: R${melhorEmp.getSalario()},00')
 





    