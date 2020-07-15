import tkinter as tk
from tkinter import messagebox
import aluno as alu
import curso as crs
import grade as grd
import disciplina as disc
import historico as his

class LimitePrincipal():
    def __init__(self, root, controle):
        self.controle = controle
        self.root = root   
        self.root.geometry('350x250')
        self.root["bg"] = "red"        
        self.menubar = tk.Menu(self.root)
        self.alunoMenu = tk.Menu(self.menubar)
        self.cursoMenu = tk.Menu(self.menubar)
        self.discipMenu = tk.Menu(self.menubar)
        self.cursoMenu = tk.Menu(self.menubar)
        self.gradeMenu = tk.Menu(self.menubar)
        self.historicoMenu = tk.Menu(self.menubar)
        self.sairMenu = tk.Menu(self.menubar)

        self.alunoMenu.add_command(label="Cadastrar Aluno", \
                    command=self.controle.insereAlunos)
        self.alunoMenu.add_command(label="Inserir aluno em disciplina", \
                    command=self.controle.insereAlunosDisciplina)
        self.alunoMenu.add_command(label="Mostra", \
                    command=self.controle.mostraAlunos)
        self.menubar.add_cascade(label="Aluno", \
                    menu=self.alunoMenu)

        self.cursoMenu.add_command(label="Insere", \
                    command=self.controle.insereCursos)
        self.cursoMenu.add_command(label="Mostra", \
                    command=self.controle.mostraCursos)
        self.menubar.add_cascade(label="Curso", \
                    menu=self.cursoMenu)

        self.gradeMenu.add_command(label="Criar Grade", \
                    command=self.controle.insereGrades)
        self.gradeMenu.add_command(label="Mostra", \
                    command=self.controle.mostraGrades)
        self.menubar.add_cascade(label="Grade", \
                    menu=self.gradeMenu)
        
        self.discipMenu.add_command(label="Insere", \
                    command=self.controle.insereDisciplinas)
        self.discipMenu.add_command(label="Mostra", \
                    command=self.controle.mostraDisciplinas)
        self.menubar.add_cascade(label="Disciplina", \
                    menu=self.discipMenu)

        self.historicoMenu.add_command(label="Gerar Historico", \
                    command=self.controle.insereHistoricos)
        
        self.menubar.add_cascade(label="Historico", \
                    menu=self.historicoMenu)

        self.sairMenu.add_command(label="Salva", \
                    command=self.controle.salvaDados)
        self.menubar.add_cascade(label="Sair", \
                    menu=self.sairMenu)

        self.root.config(menu=self.menubar)

        self.root.config(menu=self.menubar)

class ControlePrincipal():
    def __init__(self):
        self.root = tk.Tk()

        self.ctrlAluno = alu.CtrlAluno(self)
        self.ctrlCurso = crs.CtrlCurso(self)
        self.ctrlGrade = grd.CtrlGrade(self)
        self.ctrlDisciplina = disc.CtrlDisciplina(self)
        self.ctrlHistorico = his.CtrlHistorico(self)

        

        self.limite = LimitePrincipal(self.root, self) 

        self.root.title("Trabalho Final")
       
        # Inicia o mainloop
        self.root.mainloop()


    def insereAlunos(self):
        self.ctrlAluno.insereAlunos()
    def insereAlunosDisciplina(self):
        self.ctrlAluno.insereAlunosDisciplina()
    def mostraAlunos(self):
        self.ctrlAluno.mostraAlunos()

    def insereCursos(self):
        self.ctrlCurso.insereCursos()
    def mostraCursos(self):
        self.ctrlCurso.mostraCursos()

    def insereGrades(self):
        self.ctrlGrade.insereGrades()
    def mostraGrades(self):
        self.ctrlGrade.mostraGrades()

    def insereDisciplinas(self):
        self.ctrlDisciplina.insereDisciplinas()
    def mostraDisciplinas(self):
        self.ctrlDisciplina.mostraDisciplinas()

    def insereHistoricos(self):
        self.ctrlHistorico.insereHistoricos()

    def salvaDados(self):
        self.ctrlGrade.salvaGrade()
        self.ctrlCurso.salvaCursoAluno()
        self.root.destroy()
    


if __name__ == '__main__':
    c = ControlePrincipal()