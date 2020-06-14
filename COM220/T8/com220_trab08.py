from abc import ABC, abstractmethod

#Definição de exceptions
class TitulacaoNaoPermitida(Exception):
    pass

class IdadeInvalida(Exception):
    pass

class CursoNaoPermitido(Exception):
    pass

class CpfDuplicado(Exception):
    pass


#Classes
class Pessoa(ABC):
    def __init__(self, nome, endereco, idade, cpf):
        self.__nome = nome
        self.__endereco = endereco
        self.__idade = idade
        self.__cpf = cpf
    
    def getNome(self):
        return self.__nome

    def getEndereco(self):
        return self.__endereco

    def getIdade(self):
        return self.__idade

    def getCpf(self):
        return self.__cpf

    @abstractmethod
    def printDescricao(self):
        pass

class Professor(Pessoa):
    def __init__(self, nome, endereco, idade, cpf, titulacao):
        super().__init__(nome, endereco, idade, cpf)
        self.__titulacao = titulacao

    def getTitulacao(self):
        return self.__titulacao

    def printDescricao(self):
        print()
        print('----------PROFESSOR CADASTRADO---------')
        print(f'Nome: {self.getNome()}')
        print(f'Endereco: {self.getEndereco()}')
        print(f'Idade: {self.getIdade()}')
        print(f'CPF: {self.getCpf()}')
        print(f'Titulação: {self.getTitulacao()}')
        print('------------------------------------')
        print()
 

class Aluno(Pessoa):
    def __init__(self, nome, endereco, idade, cpf, curso):
        super().__init__(nome, endereco, idade, cpf)
        self.__curso = curso

    def getCurso(self):
        return self.__curso

    def printDescricao(self):
        print()
        print('----------ALUNO CADASTRADO---------')
        print(f'Nome: {self.getNome()}')
        print(f'Endereco: {self.getEndereco()}')
        print(f'Idade: {self.getIdade()}')
        print(f'CPF: {self.getCpf()}')
        print(f'Titulação: {self.getCurso()}')
        print('------------------------------------')
        print()

#Criando a lista de professores
listaDeProfessores = [
    ('Elisa', 'Rua 1', 33, '10101010', 'Doutor'),
    ('Baldochi', 'Rua 2', 34, '12121212', 'Doutor'),
    ('Alysson', 'Rua 3', 30, '13131313', 'Mestre'),
    ('Flávio', 'Rua 4', 28, '14141414', 'Doutor'),
    ('Adriana', 'Rua 5', 35, '10101010', 'Doutor')
]    

#Criando a lista de alunos
listaDeAlunos = [
    ('Carlos', 'Rua 10', 25, '91919191', 'SIN'),
    ('Henrique', 'Rua 11', 20, '92929292', 'CCO'),
    ('João', 'Rua 12', 20, '93939393', 'SIN'),
    ('José', 'Rua 13', 18, '94949494', 'ADM'),
    ('Maria', 'Rua 14', 28, '93939393', 'SIN'),
    ('Letícia', 'Rua 15', 17, '98989898', 'SIN')
]

cadastro = {}

#
for nome, endereco, idade, cpf, titulacao in listaDeProfessores:
    try:
        if cpf in cadastro:
            raise CpfDuplicado
        if idade < 30:
            raise IdadeInvalida
        if titulacao != 'Doutor':
            raise TitulacaoNaoPermitida
        
    except CpfDuplicado:
        print(f'CPF {cpf} do professor {nome} já existe um igual cadastrado')

    except IdadeInvalida:
        print(f'Idade do professor {nome} não permitida')

    except TitulacaoNaoPermitida:
        print(f'Titulação do professor {nome} não permitido')

    else:
        cadastro[cpf] = Professor(nome, endereco, idade, cpf, titulacao)
        cadastro[cpf].printDescricao()
      

for nome, endereco, idade, cpf, curso in listaDeAlunos:
    try:
        if cpf in cadastro:
            raise CpfDuplicado
        if idade < 18:
            raise IdadeInvalida
        if curso != 'SIN' and curso != 'CCO':
            raise CursoNaoPermitido
        
    except CpfDuplicado:
        print(f'CPF {cpf} do aluno {nome} já existe um igual cadastrado')

    except IdadeInvalida:
        print(f'Idade do aluno {nome} não permitida')

    except CursoNaoPermitido:
        print(f'Curso do aluno {nome} não permitido')

    else:
        cadastro[cpf] = Aluno(nome, endereco, idade, cpf, curso)
        cadastro[cpf].printDescricao()
