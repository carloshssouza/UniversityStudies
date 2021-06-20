class Pessoa {
    constructor(nome, dataNasc, sexo) {
        this._nome = nome;
        this._dataNasc = dataNasc;
        this._sexo = sexo;
    }
    get nome() { return this._nome; }
    ;
    get dataNasc() { return this._dataNasc; }
    ;
    get sexo() { return this._sexo; }
    ;
}
class Aluno extends Pessoa {
    constructor(nome, dataNasc, sexo, matricula) {
        super(nome, dataNasc, sexo);
        this.matricula = matricula;
    }
    getRelativeNome() { return this.nome; }
    ;
    getRelativeDataNasc() { return this.dataNasc; }
    ;
    getRelativeSexo() { return this.sexo; }
    ;
    get Matricula() { return this.matricula; }
    ;
}
class Professor extends Pessoa {
    constructor(nome, dataNasc, sexo, categoria) {
        super(nome, dataNasc, sexo);
        this.categoria = categoria;
    }
    getRelativeNome() { return this.nome; }
    ;
    getRelativeDataNasc() { return this.dataNasc; }
    ;
    getRelativeSexo() { return this.sexo; }
    ;
    get Categoria() { return this.categoria; }
    ;
}
class Turma {
    constructor(nome, ano, alunos) {
        this.nome = nome;
        this.ano = ano;
        this.alunos = alunos;
    }
    get Nome() { return this.nome; }
    ;
    get Ano() { return this.ano; }
    ;
    get Alunos() { return this.alunos; }
    ;
    get Professor() { return this.professor; }
    ;
    set Professor(value) { this.professor = value; }
}
class Disciplina {
    constructor(nome, professor) {
        this.nome = nome;
        this.professor = professor;
        this.turmas = [];
    }
    get Nome() { return this.nome; }
    ;
    get Professor() { return this.professor; }
    ;
    get Turmas() { return this.turmas; }
    ;
    addTurmas(turmas) {
        this.turmas.push(turmas);
    }
}
let aluno1 = new Aluno('Carlos', '20/09/1994', 'M', '2019015979');
let aluno2 = new Aluno('Henrique', '20/09/1993', 'M', '1111111');
let aluno3 = new Aluno('Souza', '20/09/1992', 'M', '22222');
let aluno4 = new Aluno('Silva', '20/09/1991', 'M', '333333');
let aluno5 = new Aluno('Carl', '20/09/1990', 'M', '44444');
let arrayAlunos = [aluno1, aluno2, aluno3, aluno4, aluno5];
let professor1 = new Professor('Baldochi', '09/09/1990', 'M', 'TI');
let turma1 = new Turma('SIN', '2019.1', arrayAlunos);
let disciplina1 = new Disciplina('COM222', professor1);
disciplina1.addTurmas(turma1);
for (let i = 0; i < disciplina1.Turmas.length; i++) {
    disciplina1.Turmas[i].professor = disciplina1.professor;
}
console.log('-----INFORMAÇÕES SOBRE A DISCIPLINA, TURMA, ALUNOS E PROFESSOR-----');
console.log('----DISCIPLINA----');
console.log(`
    Nome: ${disciplina1.nome}
    
    Nome do professor e categoria: ${disciplina1.professor.nome} / ${disciplina1.professor.categoria}
`);
for (let i = 0; i < disciplina1.Turmas.length; i++) {
    console.log('-----TURMA----');
    console.log(`
        Alunos da Turma: ${disciplina1.Turmas[i].nome}
        Ano: ${disciplina1.Turmas[i].ano}
    `);
    console.log('-----ALUNOS----');
    for (let j = 0; j < disciplina1.turmas[i].alunos.length; j++) {
        console.log(`
        Nome: ${disciplina1.Turmas[i].Alunos[j].nome}
        Data de nascimento: ${disciplina1.Turmas[i].Alunos[j].dataNasc}
        Sexo: ${disciplina1.Turmas[i].Alunos[j].sexo}
        Matricula: ${disciplina1.Turmas[i].Alunos[j].matricula}
        -----------------------------------------
    `);
    }
}
