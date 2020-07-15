import tkinter as tk
from tkinter import ttk
from tkinter import messagebox
import os.path
import pickle
import sys

class OpcaoVazia(Exception):
    pass

class NomeIgual(Exception):
    pass

class Curso:
    def __init__(self, nome, grade):
        self.__nome = nome
        self.__grade = grade
        
    def getNome(self):
        return self.__nome

    def getGrade(self):
        return self.__grade

class LimiteInsereCursos(tk.Toplevel):
    def __init__(self, controle, listaNomeGrades):
        tk.Toplevel.__init__(self)
        self.geometry('250x130')
        self.title('Curso')
        self.controle = controle
        
        self.frameNome = tk.Frame(self)
        self.frameGrade = tk.Frame(self)
        self.frameButton = tk.Frame(self)

        self.frameNome.pack()
        self.frameGrade.pack()
        self.frameButton.pack()

        self.labelNome = tk.Label(self.frameNome,text="Nome do curso: ")
        self.labelNome.pack(side="left")
        self.inputNome = tk.Entry(self.frameNome, width=20)
        self.inputNome.pack(side='left')


        self.labelGrade = tk.Label(self.frameGrade,text="Escolha a Grade: ")
        self.labelGrade.pack(side="left")
        self.escolhaCombo = tk.StringVar()
        self.combobox = ttk.Combobox(self.frameGrade, width = 15 , textvariable = self.escolhaCombo)
        self.combobox.pack(side="left")
        self.combobox['values'] = listaNomeGrades

        self.buttonCria = tk.Button(self.frameButton ,text="Cria Curso")           
        self.buttonCria.pack(side="left")
        self.buttonCria.bind("<Button>", controle.criaCurso)  

        self.buttonFecha = tk.Button(self.frameButton ,text="Concluído")      
        self.buttonFecha.pack(side="left")
        self.buttonFecha.bind("<Button>", controle.fechaHandler)

    def mostraJanela(self, titulo, msg):
        messagebox.showinfo(titulo,msg)

class LimiteMostraCursos():
    def __init__(self, str):
        messagebox.showinfo('Lista de cursos', str)
    
class CtrlCurso():
    def __init__(self, controlePrincipal):
        self.ctrlPrincipal = controlePrincipal
        
        if not os.path.isfile("curso.pickle"):
            self.listaCursos = []
        else:
            with open("curso.pickle", "rb") as f:
                self.listaCursos = pickle.load(f)

        if not os.path.isfile("aluno.pickle"):
            self.listaAlunos = []
        else:
            with open("aluno.pickle", "rb") as f:
                self.listaAlunos = pickle.load(f)

        
    def salvaCursoAluno(self):
        if len(self.listaCursos) != 0:
            with open("curso.pickle","wb") as f:
                pickle.dump(self.listaCursos, f)

        if len(self.listaAlunos) != 0:
            with open("aluno.pickle", "wb") as f:
                pickle.dump(self.listaAlunos, f)
       
    def insereCursos(self):        
        listaNomeGrades = self.ctrlPrincipal.ctrlGrade.getListaNomeGrades()
        self.limiteIns = LimiteInsereCursos(self, listaNomeGrades)

    def getCurso(self, nome):
        cursoRet = None
        for curs in self.listaCursos:
            if curs.getNome() == nome:
                cursoRet = curs
        return cursoRet

    def getListaNroMatric(self):
        listaNro = []
        for alu in self.listaAlunos:
            listaNro.append(alu.getNroMatric())
        return listaNro

    def getListaDisciplinas(self):
        listaDisciplinas = []
        for curso in self.listaCursos:
            for disciplina in curso.getGrade().getDisciplina():
                listaDisciplinas.append(disciplina)

        return listaDisciplinas

    def getListaNomeCursos(self):
        listaNomeCursos = []
        for curs in self.listaCursos:
            listaNomeCursos.append(curs.getNome())
        return listaNomeCursos

    def getEstudante(self, nroMatric):
        aluRet = None
        for alu in self.listaAlunos:
            if alu.getNroMatric() == nroMatric:
                aluRet = alu
        return aluRet

    def mostraCursos(self):
        str = 'Cursos --- Grade \n'
        for curso in self.listaCursos:
            str += curso.getNome() + '---' + curso.getGrade().getNome() + '\n'
        self.limiteLista = LimiteMostraCursos(str)

    def criaCurso(self, event):
        nome = self.limiteIns.inputNome.get()
        gradeSel = self.limiteIns.escolhaCombo.get()
        grade = self.ctrlPrincipal.ctrlGrade.getGrade(gradeSel)
        curso = Curso(nome, grade)
        try:
            if nome == '' or gradeSel == '':
                raise OpcaoVazia

            if curso.getNome() in self.getListaNomeCursos():
                raise NomeIgual
        except OpcaoVazia:
            self.limiteIns.mostraJanela('Alerta', 'Campo vazio')
        except NomeIgual:
            self.limiteIns.mostraJanela('Alerta', 'Curso já existente')
        
        else:
            self.listaCursos.append(curso)
            self.limiteIns.mostraJanela('Sucesso', 'Curso criado com sucesso')
            self.clearHandler(event)

    def clearHandler(self, event):
        self.limiteIns.inputNome.delete(0, len(self.limiteIns.inputNome.get()))
        

    def fechaHandler(self, event):
        self.limiteIns.destroy()
        