import tkinter as tk
from tkinter import ttk
from tkinter import messagebox
import os.path
import pickle
import sys

class OpcaoVazia(Exception):
    pass

class CodigoIgual(Exception):
    pass

class NomeIgual(Exception):
    pass

class HorasNegativa(Exception):
    pass

class AnoSemestreIncorreto(Exception):
    pass

class CursoNaoCriado(Exception):
    pass


class Disciplina:
    def __init__(self, codigo, nome, cargaHoraria, grade):
        self.__codigo = codigo
        self.__nome = nome
        self.__cargaHoraria = cargaHoraria
        self.__grade = grade
        self.__nota = 0
        self.__anoSemestre = ''

    def getCodigo(self):
        return self.__codigo

    def getNome(self):
        return self.__nome

    def getCargaHoraria(self):
        return self.__cargaHoraria

    def getGrade(self):
        return self.__grade

    def getNota(self):
        return self.__nota
    
    def getAnoSemestre(self):
        return self.__anoSemestre

    def addNota(self, nota):
        self.__nota = nota

    def addAnoSemestre(self, texto):
        self.__anoSemestre = texto
        

class LimiteInsereDisciplinas(tk.Toplevel):
    def __init__(self, controle, listaNomeGrades):

        tk.Toplevel.__init__(self)
        self.geometry('250x150')
        self.title("Disciplina")
        self.controle = controle

        self.frameNome = tk.Frame(self)
        self.frameCodigo = tk.Frame(self)
        self.frameCargaHoraria = tk.Frame(self)
        self.frameAnoSemestre = tk.Frame(self)
        self.frameGrade = tk.Frame(self)
        self.frameButton = tk.Frame(self)
        
        self.frameCodigo.pack()
        self.frameNome.pack()
        self.frameCargaHoraria.pack()
        self.frameAnoSemestre.pack()
        self.frameGrade.pack()
        self.frameButton.pack()
      
        self.labelCodigo = tk.Label(self.frameCodigo,text="Código: ")
        self.labelCodigo.pack(side="left")
        self.inputCodigo = tk.Entry(self.frameCodigo, width=20)
        self.inputCodigo.pack(side="left")

        self.labelNome = tk.Label(self.frameNome,text="Nome: ")
        self.labelNome.pack(side="left")
        self.inputNome = tk.Entry(self.frameNome, width=20)
        self.inputNome.pack(side="left")

        self.labelCargaHoraria = tk.Label(self.frameCargaHoraria, text="Carga Horaria")            
        self.labelCargaHoraria.pack(side="left")
        self.inputCargaHoraria = tk.Entry(self.frameCargaHoraria, width=20)
        self.inputCargaHoraria.pack(side="left")

        self.labelAnoSemestre = tk.Label(self.frameAnoSemestre,text="Ano e semestre(ex:2018.1): ")
        self.labelAnoSemestre.pack(side="left")
        self.inputAnoSemestre = tk.Entry(self.frameAnoSemestre, width=20)
        self.inputAnoSemestre.pack(side="left")
        
        self.labelGrade = tk.Label(self.frameGrade,text="Escolha a Grade: ")
        self.labelGrade.pack(side="left")
        self.escolhaCombo = tk.StringVar()
        self.combobox = ttk.Combobox(self.frameGrade, width = 15 , textvariable = self.escolhaCombo)
        self.combobox.pack(side="left")
        self.combobox['values'] = listaNomeGrades       
      
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
        messagebox.showinfo(titulo, msg)

class LimiteMostraDisciplinas():
    def __init__(self, str):
        messagebox.showinfo('Lista de disciplinas', str)

      
class CtrlDisciplina():       
    def __init__(self, controlePrincipal):
        self.ctrlPrincipal = controlePrincipal

    def getDisciplina(self, nome):
        discRet = None
        for disc in self.ctrlPrincipal.ctrlCurso.getListaDisciplinas():
            if disc.getNome() == nome:
                print("TUdo certo")
                discRet = disc
        return discRet

    def getListaCodDisciplinas(self):
        listaCod = []
        for disc in self.ctrlPrincipal.ctrlCurso.getListaDisciplinas():
            listaCod.append(disc.getCodigo())
        return listaCod

    def getListaNomeDisciplinas(self):
        listaNomeDisciplina = []
        for disc in self.ctrlPrincipal.ctrlGrade.getLista():
            listaNomeDisciplina.append(disc.getNome())
        return listaNomeDisciplina

    def insereDisciplinas(self):        
        listaNomeGrades = self.ctrlPrincipal.ctrlGrade.getListaNomeGrades()
        self.limiteIns = LimiteInsereDisciplinas(self, listaNomeGrades)
     

    def mostraDisciplinas(self):
        str = 'Código -- Nome -- Carga H\n'
        for disc in self.ctrlPrincipal.ctrlCurso.getListaDisciplinas():
            str += disc.getCodigo() + ' -- ' + disc.getNome() + f' -- {disc.getCargaHoraria()}\n'
            str += disc.getGrade().getNome() + '\n\n'
        self.limiteLista = LimiteMostraDisciplinas(str)

    def enterHandler(self, event):
        codigo = self.limiteIns.inputCodigo.get()
        nome = self.limiteIns.inputNome.get()
        cargah = self.limiteIns.inputCargaHoraria.get()
        anoSemestre = self.limiteIns.inputAnoSemestre.get()
        gradeSel = self.limiteIns.escolhaCombo.get()
        grade = self.ctrlPrincipal.ctrlGrade.getGrade(gradeSel)
        try:
            if codigo == '' or nome == '' or anoSemestre == '' or cargah == '' or gradeSel == '':
                raise OpcaoVazia
            if codigo in self.getListaCodDisciplinas():
                raise CodigoIgual
            if nome in self.getListaNomeDisciplinas():
                raise NomeIgual
            if int(cargah) <= 0:
                raise HorasNegativa

            palavra = anoSemestre.split('.')
            if len(palavra) != 2 or not palavra[0] or not palavra[1]:
                raise AnoSemestreIncorreto

            if len(self.ctrlPrincipal.ctrlCurso.listaCursos) == 0:
                raise CursoNaoCriado

            

        except OpcaoVazia:
            self.limiteIns.mostraJanela('Alerta', 'Campo vazio')
        except CodigoIgual:
            self.limiteIns.mostraJanela('Alerta', 'Codigo já existente')
        except NomeIgual:
            self.limiteIns.mostraJanela('Alerta', 'Nome já existente')
        except HorasNegativa:
            self.limiteIns.mostraJanela('Alerta', 'Horas negativas ou zeradas não são permitidas')
        except AnoSemestreIncorreto:
            self.limiteIns.mostraJanela('Alerta', 'Digite como mostrado no exemplo')
        except CursoNaoCriado:
            self.limiteIns.mostraJanela('Alerta', 'É necessario criar um curso antes de adicionar')
        
        else:
            
            for curso in self.ctrlPrincipal.ctrlCurso.listaCursos:
                if curso.getGrade().getNome() == grade.getNome():
                    disciplina = Disciplina(codigo, nome, int(cargah), grade)
                    disciplina.addAnoSemestre(anoSemestre)
                    curso.getGrade().addDisciplina(disciplina)
            self.ctrlPrincipal.ctrlGrade.addDisciplina(disciplina)
            self.limiteIns.mostraJanela('Sucesso', 'Disciplina cadastrada com sucesso')
            self.clearHandler(event)

                
    
        
    def clearHandler(self, event):
        self.limiteIns.inputCodigo.delete(0, len(self.limiteIns.inputCodigo.get()))
        self.limiteIns.inputNome.delete(0, len(self.limiteIns.inputNome.get()))
        self.limiteIns.inputCargaHoraria.delete(0, len(self.limiteIns.inputCargaHoraria.get()))
        

    def fechaHandler(self, event):
        self.limiteIns.destroy()
    