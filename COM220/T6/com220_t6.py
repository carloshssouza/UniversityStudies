def mdc(m, n):
    while m%n != 0:
        oldm = m
        oldn = n
        m = oldn
        n = oldm%oldn
    return n

def separadorFrac(frac):
    novoNum = frac.getNum()
    inteiro = 0
    while novoNum > frac.getDen():
        novoNum -= frac.getDen()
        inteiro += 1

    return inteiro, novoNum

def somarInteiro(parteInteira, parteNum):
    inteiro = parteInteira + parteNum
    return inteiro
   

class Fracao:
    def __init__(self, num, den):
        self.__num = num
        self.__den = den

    def __str__(self):
        return str(self.__num) + "/" + str(self.__den)

    def getNum(self):
        return self.__num
    
    def getDen(self):
        return self.__den

    def simplifica(self):
        divComum = mdc(self.__num, self.__den)
        self.__num = self.__num // divComum
        self.__den = self.__den // divComum

    def __add__(self, outraFrac):
        novoNum = self.__num * outraFrac.getDen() + self.__den * outraFrac.getNum()
        novoDen = self.__den * outraFrac.getDen()
        divComum = mdc(novoNum, novoDen)
        return Fracao(novoNum//divComum, novoDen//divComum)

class fracaoMista(Fracao):
    def __init__(self, parteInteira, num, den):
         super().__init__(num, den)
         self.__parteInteira = parteInteira

    def getParteInteira(self):
         return self.__parteInteira

    def juntar(self):
        novoNum = (self.__parteInteira * self.getDen()) + self.getNum()
        return Fracao(novoNum, self.getDen()) 
        
    def __add__(self, outraFrac):
        novoNum = self.getNum() * outraFrac.getDen() + self.getDen() * outraFrac.getNum()
        novoDen = self.getDen() * outraFrac.getDen()
        divComum = mdc(novoNum, novoDen)
        return Fracao(novoNum//divComum, novoDen//divComum)

    def __str__(self):
        if self.__parteInteira > 0 and self.getNum() < self.getDen():
            return str(self.__parteInteira) + ' ' + str(self.getNum()) + '/' + str(self.getDen())
        
        elif self.__parteInteira >= 0 and self.getNum() == self.getDen():
            inteiro = somarInteiro(self.__parteInteira, 1)
            return str(inteiro)
        else:
            return str(self.getNum()) + '/' + str(self.getDen())

              
frac1 = Fracao(7,6)
frac2 = Fracao(13,7)
frac3 = frac1 + frac2
inteiro, numerador = separadorFrac(frac3)
print(fracaoMista(inteiro, numerador, frac3.getDen()))
print()

frac1 = Fracao(1,3)
frac2 = Fracao(2,3)
frac3 = frac1 + frac2
inteiro, numerador = separadorFrac(frac3)
print(fracaoMista(inteiro, numerador, frac3.getDen()))
print()

frac1 = fracaoMista(3, 1, 2)
frac2 = fracaoMista(4, 2, 3)
frac3 = frac1.juntar() + frac2.juntar()
inteiro, numerador = separadorFrac(frac3)
print(fracaoMista(inteiro, numerador, frac3.getDen()))




