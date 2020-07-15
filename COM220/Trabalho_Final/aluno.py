import tkinter as tk
from tkinter import ttk
from tkinter import messagebox
import os.path
import pickle
from historico import Historico
import sys

class OpcaoVazia(Exception):
    pass

class MatriculaIgual(Exception):
    pass

class NotaInvalida(Exception):
    pass

class NotaNegativa(Exception):
    pass

class DisciplinaRepetida(Exception):
    pass

class Aluno:
    def __init__(self, nroMatric, nome, curso, historico):
        self.__nroMatric = nroMatric
        self.__nome = nome
        self.__curso = curso
        self.__historico = historico
        
    
    def getNroMatric(self):
        return self.__nroMatric

    def getNome(self):
        return self.__nome

    def getCurso(self):
        return self.__curso

    def getHistorico(self):
        return self.__historico


class LimiteInsereAlunos(tk.Toplevel):
    def __init__(self, controle, listaNomeCursos):
        tk.Toplevel.__init__(self)
        self.geometry('250x130')
        self.title('Aluno')
        self.controle = controle

        self.frameNro = tk.Frame(self)
        self.frameNome = tk.Frame(self)
        self.frameCurso = tk.Frame(self)
        self.frameHistorico = tk.Frame(self)
        self.frameButton = tk.Frame(self)

        self.frameNro.pack()
        self.frameNome.pack()
        self.frameCurso.pack()
        self.frameHistorico.pack()
        self.frameButton.pack()

        self.labelNro = tk.Label(self.frameNro,text="Nro Matrícula: ")
        self.labelNro.pack(side="left")
        self.inputNro = tk.Entry(self.frameNro, width=20)
        self.inputNro.pack(side='left')

        self.labelNome = tk.Label(self.frameNome,text="Nome: ")
        self.labelNome.pack(side="left")
        self.inputNome = tk.Entry(self.frameNome, width=20)
        self.inputNome.pack(side='left')

        self.labelCurso = tk.Label(self.frameCurso,text="Escolha o Curso: ")
        self.labelCurso.pack(side="left")
        self.escolhaCombo = tk.StringVar()
        self.combobox = ttk.Combobox(self.frameCurso, width = 15 , textvariable = self.escolhaCombo)
        self.combobox.pack(side="left")
        self.combobox['values'] = listaNomeCursos

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

class LimiteDisciplinaAlunos(tk.Toplevel):
    def __init__(self, controle, listaNroMatric, listaNomeDisciplina):

        tk.Toplevel.__init__(self)
        self.geometry('300x250')
        self.title("Aluno")
        self.controle = controle

        self.frameAluno = tk.Frame(self)
        self.frameNota = tk.Frame(self)
        self.frameDiscip = tk.Frame(self)
        self.frameButton = tk.Frame(self)
        
        self.frameAluno.pack()
        self.frameNota.pack()
        self.frameDiscip.pack()
        self.frameButton.pack()     

        self.labelAluno = tk.Label(self.frameAluno,text="Escolha o Aluno(nro da matricula): ")
        self.labelAluno.pack(side="left")
        self.escolhaCombo = tk.StringVar()
        self.combobox = ttk.Combobox(self.frameAluno, width = 15 , textvariable = self.escolhaCombo)
        self.combobox.pack(side="left")
        self.combobox['values'] = listaNroMatric

        self.labelNota = tk.Label(self.frameNota,text="Nota: ")
        self.labelNota.pack(side="left")
        self.inputNota = tk.Entry(self.frameNota, width=20)
        self.inputNota.pack(side='left')

        self.labelDiscip = tk.Label(self.frameDiscip,text="Escolha a Disciplina: ")
        self.labelDiscip.pack(side="left") 
        self.listbox = tk.Listbox(self.frameDiscip)
        self.listbox.pack(side="left")
        for disc in listaNomeDisciplina:
            self.listbox.insert(tk.END, disc)

        self.buttonInsere = tk.Button(self.frameButton ,text="Inserir")           
        self.buttonInsere.pack(side="left")
        self.buttonInsere.bind("<Button>", controle.enterHandler2)

        self.buttonFecha = tk.Button(self.frameButton ,text="Concluído")      
        self.buttonFecha.pack(side="left")
        self.buttonFecha.bind("<Button>", controle.fechaHandler2)
    
    def mostraJanela(self, titulo, msg):
        messagebox.showinfo(titulo, msg)       

class LimiteMostraAlunos():
    def __init__(self, str):
        messagebox.showinfo('Lista de alunos', str)

class CtrlAluno():
    def __init__(self, controlePrincipal):
        self.ctrlPrincipal = controlePrincipal

    def insereAlunos(self):
        listaNomeCursos = self.ctrlPrincipal.ctrlCurso.getListaNomeCursos()
        self.limiteIns = LimiteInsereAlunos(self, listaNomeCursos)
    
    def mostraAlunos(self):
        str = 'Nro Matric. -- Nome\n'
        for est in self.ctrlPrincipal.ctrlCurso.listaAlunos:
            str += est.getNroMatric() + ' -- ' + est.getNome() + '\n'       
        self.limiteLista = LimiteMostraAlunos(str)

    def enterHandler(self, event):
        nroMatric = self.limiteIns.inputNro.get()
        nome = self.limiteIns.inputNome.get()
        cursoSel = self.limiteIns.escolhaCombo.get()
        curso = self.ctrlPrincipal.ctrlCurso.getCurso(cursoSel)
        try:
            if nroMatric == '' or nome == '' or cursoSel == '':
                raise OpcaoVazia
                
            mat = ''
            for matricula in self.ctrlPrincipal.ctrlCurso.getListaNroMatric():
                if matricula == nroMatric:
                    mat = 'Erro'
            if mat == 'Erro':
                raise MatriculaIgual
        
        except OpcaoVazia:
            self.limiteIns.mostraJanela('Alerta', 'Campo vazio')
        except MatriculaIgual:
            self.limiteIns.mostraJanela('Alerta', 'Matricula já existente')

        else:
            historico = Historico()
            aluno = Aluno(nroMatric, nome, curso, historico)
            self.ctrlPrincipal.ctrlCurso.listaAlunos.append(aluno)
            self.limiteIns.mostraJanela('Sucesso', 'Aluno cadastrado com sucesso')
            self.clearHandler(event)

    def clearHandler(self, event):
        self.limiteIns.inputNro.delete(0, len(self.limiteIns.inputNro.get()))
        self.limiteIns.inputNome.delete(0, len(self.limiteIns.inputNome.get()))

    def fechaHandler(self, event):
        self.limiteIns.destroy()

    def insereAlunosDisciplina(self):
        listaNroMatric = self.ctrlPrincipal.ctrlCurso.getListaNroMatric()
        listaNomeDisciplina = self.ctrlPrincipal.ctrlDisciplina.getListaNomeDisciplinas()
        self.limiteIns2 = LimiteDisciplinaAlunos(self, listaNroMatric, listaNomeDisciplina)
        
    def enterHandler2(self, event):
        alunoSel = self.limiteIns2.escolhaCombo.get()
        aluno = self.ctrlPrincipal.ctrlCurso.getEstudante(alunoSel)
        nota = float(self.limiteIns2.inputNota.get())
        disciSel = self.limiteIns2.listbox.get(tk.ACTIVE)
        disciplina = self.ctrlPrincipal.ctrlDisciplina.getDisciplina(disciSel)
        try:
            if alunoSel == '' or nota == '' or disciSel == '':
                raise OpcaoVazia
            if nota < 0:
                raise NotaNegativa
            if nota > 10:
                raise NotaInvalida
                
            
        except OpcaoVazia:
            self.limiteIns2.mostraJanela('Alerta', 'Campo vazio')
        except NotaNegativa:
            self.limiteIns2.mostraJanela('Alerta', 'Nota negativa não permitida')
        except NotaInvalida:
            self.limiteIns2.mostraJanela('Alerta', 'Nota acima de 10 não permitido')
        

        else: 
            for alu in self.ctrlPrincipal.ctrlCurso.listaAlunos:
                if alu.getNroMatric() == aluno.getNroMatric() and alu.getCurso().getGrade().getNome() == disciplina.getGrade().getNome():
                    disciplina.addNota(nota)
                    alu.getCurso().getGrade().addDisciplina(disciplina)
                    alu.getHistorico().addDisciplina(disciplina, alu)
                    
                else:
                    disciplina.addNota(nota)
                    alu.getHistorico().addDisciplina(disciplina, alu)
                    
        
            self.limiteIns2.mostraJanela('Sucesso', 'Aluno matriculado')
            self.limiteIns2.listbox.delete(tk.ACTIVE)


    def fechaHandler2(self, event):
        self.limiteIns2.destroy()






