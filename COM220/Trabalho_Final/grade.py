import tkinter as tk
from tkinter import messagebox
import os.path
import pickle
import sys

class NomeIgual(Exception):
    pass

class OpcaoVazia(Exception):
    pass


class Grade:
    def __init__(self, nome):
        self.__nome = nome
        self.__ListaDisciplina = []
        self.__cargaHorariaTotal = 0

    def getNome(self):
        return self.__nome

    def getDisciplina(self):
        return self.__ListaDisciplina

    def addDisciplina(self, disciplina):
        self.__cargaHorariaTotal = self.__cargaHorariaTotal + disciplina.getCargaHoraria()
        self.__ListaDisciplina.append(disciplina)

class LimiteInsereGrade(tk.Toplevel):
    def __init__(self, controle):
        tk.Toplevel.__init__(self)
        self.geometry('250x130')
        self.title('Grade')
        self.controle = controle
        
        self.frameNome = tk.Frame(self)
        self.frameButton = tk.Frame(self)

        self.frameNome.pack()
        self.frameButton.pack()

      
        self.labelNome = tk.Label(self.frameNome,text="Nome: ")
        self.labelNome.pack(side="left")
       

        self.inputNome = tk.Entry(self.frameNome, width=20)
        self.inputNome.pack(side='left')

        self.buttonSubmit = tk.Button(self.frameButton ,text="Enter")      
        self.buttonSubmit.pack(side="left")
        self.buttonSubmit.bind("<Button>", controle.enterHandler)
      
        self.buttonClear = tk.Button(self.frameButton ,text="Clear")      
        self.buttonClear.pack(side="left")
        self.buttonClear.bind("<Button>", controle.clearHandler)  

        self.buttonFecha = tk.Button(self.frameButton ,text="Concluído")      
        self.buttonFecha.pack(side="left")
        self.buttonFecha.bind("<Button>", controle.fechaHandler)

    def mostraJanela(self, titulo, msg):
        messagebox.showinfo(titulo,msg)

class LimiteMostraGrades():
    def __init__(self, str):
        messagebox.showinfo('Lista de grades', str)

class CtrlGrade():
    def __init__(self, controlePrincipal):

        self.ctrlPrincipal = controlePrincipal

        

        if not os.path.isfile("grade.pickle"):
            self.listaGrades = []
        else:
            with open("grade.pickle", "rb") as f:
                self.listaGrades = pickle.load(f)

        if not os.path.isfile("listaAux.pickle"):
            self.listaD = []
        else:
            with open("listaAux.pickle", "rb") as f:
                self.listaD = pickle.load(f)        
        
        
    def salvaGrade(self):
        if len(self.listaGrades) != 0:
            with open("grade.pickle","wb") as f:
                pickle.dump(self.listaGrades, f)
        
        if len(self.listaD) != 0:
            with open("listaAux.pickle", "wb") as f:
                pickle.dump(self.listaD, f)

    def addDisciplina(self, disciplina):
        self.listaD.append(disciplina)
    
    def getLista(self):
        return self.listaD

    def getListaGrades(self):
        return self.listaGrades

    def insereGrades(self):
        self.limiteIns = LimiteInsereGrade(self)
        

    def getCodigoDisciplina(self, codigo):
        disciplinaOk = None
        for disci in self.ListaDisciplina:
            if disci.getCodigo() == codigo:
                disciplinaOk = codigo

        return disciplinaOk

        
    def getGrade(self, nome):
        gradeOk = None
        for grad in self.listaGrades:
            if grad.getNome() == nome:
                gradeOk = grad
        return gradeOk    
        
    def getListaNomeGrades(self):
        listaNomeGrades = []
        for grad in self.listaGrades:
            listaNomeGrades.append(grad.getNome())
        return listaNomeGrades

    def mostraGrades(self):
        str = 'Grades: \n'
        for grad in self.listaGrades:
            str += grad.getNome() + '\n'
        self.limiteLista = LimiteMostraGrades(str)

    def enterHandler(self, event):
        nome = self.limiteIns.inputNome.get()
        grade = Grade(nome)
        try:
            if nome == '':
                raise OpcaoVazia
            
            if grade.getNome() in self.getListaNomeGrades():
                raise NomeIgual

        except OpcaoVazia:
            self.limiteIns.mostraJanela('Alerta', 'Campo vazio')
        except NomeIgual:
            self.limiteIns.mostraJanela('Alerta', 'Grade já existente')
        
        else:
            self.listaGrades.append(grade)
            self.limiteIns.mostraJanela('Sucesso', 'Grade inserida com sucesso')
            self.clearHandler(event)
            self.limiteIns.destroy()

    def clearHandler(self, event):
        self.limiteIns.inputNome.delete(0, len(self.limiteIns.inputNome.get()))
       

    def fechaHandler(self, event):
        self.limiteIns.destroy()
        
