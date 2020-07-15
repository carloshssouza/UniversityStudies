import tkinter as tk
from tkinter import ttk
from tkinter import messagebox
from disciplina import Disciplina
import os.path
import pickle
import sys

class OpcaoVazia(Exception):
    pass

class Historico:
    
    def __init__(self):
        self.__disciplinasEletivas = []
        self.__disciplinasObrigatorias = []
        self.__horasEletivas = 0
        self.__horasObrigatorias = 0

    def getDisciplinasEletivas(self):
        return self.__disciplinasEletivas

    def getDisciplinasObrigatorias(self):
        return self.__disciplinasObrigatorias
    
    def addDisciplina(self, disciplina, aluno):
        if disciplina in aluno.getCurso().getGrade().getDisciplina():
            self.__horasObrigatorias += disciplina.getCargaHoraria()
            self.__disciplinasObrigatorias.append(disciplina)
            
        else:
            self.__horasEletivas = self.__horasEletivas + disciplina.getCargaHoraria()
            self.__disciplinasEletivas.append(disciplina)
            
    def getHorasEletivas(self):
        return self.__horasEletivas

    def getHorasObrigatorias(self):
        return self.__horasObrigatorias

class LimiteInsereHistoricos(tk.Toplevel):
    def __init__(self, controle, listaNroMatric):
        tk.Toplevel.__init__(self)
        self.geometry('250x130')
        self.title('Historico')
        self.controle = controle
        
        self.frameAluno = tk.Frame(self)
        self.frameButton = tk.Frame(self)

        self.frameAluno.pack()
        self.frameButton.pack()
      
        self.labelAluno = tk.Label(self.frameAluno,text="Escolha o aluno: ")
        self.labelAluno.pack(side="left")
        self.escolhaCombo = tk.StringVar()
        self.combobox = ttk.Combobox(self.frameAluno, width = 15 , textvariable = self.escolhaCombo)
        self.combobox.pack(side="left")
        self.combobox['values'] = listaNroMatric

        self.buttonSubmit = tk.Button(self.frameButton ,text="Gerar historico")      
        self.buttonSubmit.pack(side="left")
        self.buttonSubmit.bind("<Button>", controle.enterHandler)  

        self.buttonFecha = tk.Button(self.frameButton ,text="Concluído")      
        self.buttonFecha.pack(side="left")
        self.buttonFecha.bind("<Button>", controle.fechaHandler)

    def mostraJanela(self, titulo, msg):
        messagebox.showinfo(titulo,msg)

class LimiteMostraHistoricos():
    def __init__(self, str):
        messagebox.showinfo('Historico', str)

class CtrlHistorico():
    def __init__(self, controlePrincipal):
        self.ctrlPrincipal = controlePrincipal
        self.listaHistorico = []

    def addHistorico(self, aluno):
        self.listaHistorico.append(aluno.getHistorico())


    def insereHistoricos(self):
        listaNroMatric = self.ctrlPrincipal.ctrlCurso.getListaNroMatric()
        self.limiteIns = LimiteInsereHistoricos(self, listaNroMatric)
    
    def enterHandler(self, event):
        str = ''
        str2 = 'Aprovado'
        str3 = 'Reprovado'
        alunoSel = self.limiteIns.escolhaCombo.get()
        aluno = self.ctrlPrincipal.ctrlCurso.getEstudante(alunoSel)
        try:
            if alunoSel == '':
                raise OpcaoVazia

        except OpcaoVazia:
            self.limiteIns.mostraJanela('Alerta', 'Campo Vazio')    
      
        for alu in self.ctrlPrincipal.ctrlCurso.listaAlunos:
            if alu.getNroMatric() == aluno.getNroMatric():
                str += '--------------------------------------------'
                str += 'Aluno: ' + alu.getNome() + '\n'
                str += 'Curso:' + alu.getCurso().getNome() 
                str += 'Grade:' + alu.getCurso().getGrade().getNome() + '\n\n'
                str += 'Disciplinas Obrigatorias:\n'

                listaOrdenada = alu.getHistorico().getDisciplinasObrigatorias()
                listaRecebe = sorted(listaOrdenada, key=Disciplina.getAnoSemestre)

                listaOrdenada2 = alu.getHistorico().getDisciplinasEletivas()
                listaRecebe2 = sorted(listaOrdenada2, key=Disciplina.getAnoSemestre)

                for disci in listaRecebe:
                    if disci.getNota() >= 6:
                        str += disci.getNome() +  '--' + f'Nota: {disci.getNota()}' + '\n'
                        str += 'Ano: ' + disci.getAnoSemestre() + '-Aprovado\n\n'
                    else:
                        str += disci.getNome() + '--' + f'Nota: {disci.getNota()}' + '\n'
                        str += 'Ano: ' + disci.getAnoSemestre() + '-Reprovado\n\n'

                str += '\nCarga horaria obrigatoria total: ' + f'{alu.getHistorico().getHorasObrigatorias()}\n\n'

                str += 'Disciplinas Eletivas:\n'
                for disci in listaRecebe2:
                    if disci.getNota() >= 6:
                        str += disci.getNome() +  '--' + f'Nota: {disci.getNota()}' + '\n'
                        str += 'Ano: ' + disci.getAnoSemestre() + '-Aprovado\n\n'
                    else:
                        str += disci.getNome() + '--' + f'Nota: {disci.getNota()}' + '\n'
                        str += 'Ano: ' + disci.getAnoSemestre() + '-Reprovado\n\n'

                str += 'Carga horaria eletiva total: ' + f'{alu.getHistorico().getHorasEletivas()}\n'
                str +='----------------------------'

        self.limiteIns.mostraJanela('HISTORICO', str)
    
    def fechaHandler(self, event):
        self.limiteIns.destroy()