#Função para somar a carga horária das disciplinas obrigatórias e eletivas
def somarHoras(historico, grade):
    carga_obrigatoria = 0
    carga_eletiva = 0

    #Laço para percorrer a lista de disciplinas da grade, comparando com a lista de disciplinas do histórico
    for hist in historico.getDisciplina():
        
        for grad in grade.getDisciplina():
            #Comparando o código das disciplinas do histórico, com as disciplinas da grade
            #Se o código for igual, soma a carga horária obrigatória
            #Se não for igual, vai somar a carga horária eletiva
            if hist.getCodigo() in grad.getCodigo():
                carga_obrigatoria += hist.getCargaHoraria()
                break
            
        else:
            carga_eletiva += hist.getCargaHoraria()
               
            
    return carga_obrigatoria, carga_eletiva

class Curso:
    def __init__(self, nome):
        self.__nome = nome
        self.__grade = None

    def getNome(self):
        return self.__nome

    def getAlunos(self):
        return self.__alunos

    def getGrade(self):
        return self.__grade

class Grade:
    def __init__(self, ano, curso):
        self.__ano = ano
        self.__curso = curso
        self.__disciplina = []


    def getAno(self):
        return self.__ano

    def getDisciplina(self):
        return self.__disciplina

    #Função para adicionar disciplinas na grade
    def addDisciplina(self, codigo, nome, cargaHoraria):
        disci = Disciplina(codigo, nome, cargaHoraria)
        self.__disciplina.append(disci)

class Disciplina:
    def __init__(self, codigo, nome, cargaHoraria):
        self.__codigo = codigo
        self.__nome = nome
        self.__cargaHoraria = cargaHoraria

    def getCodigo(self):
        return self.__codigo

    def getNome(self):
        return self.__nome

    def getCargaHoraria(self):
        return self.__cargaHoraria

class Aluno:
    def __init__(self, nome, nroMatricula, curso):
        self.__nome = nome
        self.__nroMatricula = nroMatricula
        self.__curso = curso

    def getNome(self):
        return self.__nome

    def getNroMatricula(self):
        return self.__nroMatricula

    def getCurso(self):
        return self.__curso

class Historico:
    def __init__(self, aluno, curso, grade):
        self.__aluno = aluno
        self.__disciplina = []
        self.__curso = curso
        self.__grade = grade

    def getAluno(self):
        return self.__aluno

    def getDisciplina(self):
        return self.__disciplina

    def getCurso(self):
        return self.__curso

    def getGrade(self):
        return self.__grade

    #Função para adicionar disciplina no histórico
    def addDisciplina(self, codigo, nome, cargaHoraria):
        disci = Disciplina(codigo, nome, cargaHoraria)
        self.__disciplina.append(disci)

    #Gerando o historico, printando na tela as informações
    def gerarHistorico(self, carga_obrigatoria, carga_eletiva):
        print('*********HISTORICO********')
        print(f'Aluno: {self.__aluno.getNome()} - Matricula: {self.__aluno.getNroMatricula()}')
        print(f'Curso: {self.__curso.getNome()}')
        print()
        print('----Disciplinas----')
        for disci in self.__disciplina:
            print(disci.getNome())
        print()

        print(f'Carga horária de disciplina obrigatória: {carga_obrigatoria} horas')
        if carga_eletiva > 0:
            print(f'Carga horária de disciplina eletiva: {carga_eletiva} horas')
        print('____________________________________________________________')
        print()

#Criando o curso, grade e adicionando as disciplinas na grade
curso1 = Curso('Sistemas de Informação')
grade1 = Grade(2019, curso1)
grade1.addDisciplina('SI1', 'POO', 64)
grade1.addDisciplina('SI2', 'AED2', 64)
grade1.addDisciplina('SI3', 'Introdução a Sistemas de Informação', 72)
grade1.addDisciplina('SI4', 'Probabilidade', 72)

#Criando outro curso, outra grade e adicionando disciplinas na grade
curso2 = Curso('Ciencia da computação')
grade2 = Grade(2018, curso2)
grade2.addDisciplina('CC1', 'Introdução a CCO', 64)
grade2.addDisciplina('CC2', 'Fundamentos de física para computação', 64)
grade2.addDisciplina('CC3', 'GA e algebra linear', 64)
grade2.addDisciplina('CC4', 'Fundamentos de Matemática', 72)

#Criando um aluno e adicionando disciplinas no seu histórico
aluno1 = Aluno('Carlos', 10101010, curso1)
historico1 = Historico(aluno1, curso1, grade1)
historico1.addDisciplina('SI1', 'POO', 64)
historico1.addDisciplina('SI2', 'AED2', 64)
historico1.addDisciplina('SI3', 'Matemática Discreta', 72)
historico1.addDisciplina('DDJ', 'Desenvolvimento de jogos', 64)
historico1.addDisciplina('SI4', 'Probabilidade', 72)

#Criando outro aluno e adicionando disciplinas no seu histórico
aluno2 = Aluno('Henrique', 12121212, curso2)
historico2 = Historico(aluno2, curso2, grade2)
historico2.addDisciplina('CC1', 'Introdução a CCO', 64)
historico2.addDisciplina('CC2', 'Fundamentos de física para computação', 64)
historico2.addDisciplina('CC3', 'GA e algebra linear', 64)
historico2.addDisciplina('LIB', 'Libras', 72)
historico2.addDisciplina('CC4', 'Fundamentos de Matemática', 72)

#Chamando a função para somar a carga horária obrigatória e eletiva
#Aluno 1
carga_obrigatoria, carga_eletiva = somarHoras(historico1, grade1)
historico1.gerarHistorico(carga_obrigatoria, carga_eletiva)

#Aluno2
carga_obrigatoria, carga_eletiva = somarHoras(historico2, grade2)
historico2.gerarHistorico(carga_obrigatoria, carga_eletiva)
