class Registrador:
    
    
    def __init__(self, reg_bin):
        self.vezes = 0
        self.reg_bin = reg_bin

    def maisUm(self):
        self.vezes = self.vezes + 1

def separaLinha(linha):
    comando = rd = rs1= rs2 = ''
    
    for i in range(25, 31 + 1):
        comando += linha[i]
    for i in range(22, 26 + 1):
        rd += linha[i]
    for i in range(12, 16 + 1):
        rs1 += linha[i]
    for i in range(17, 21 + 1):
        rs2 += linha[i]

    return comando, rd, rs1, rs2

vetorHazard = []

def verificaRegistrador(reg):
    reg.maisUm()
    if not vetorHazard:
        vetorHazard.append(reg)
        return False
    for i in vetorHazard:
        
        if i.reg_bin == reg.reg_bin:
            reg.vezes = 0
            return True
        elif i.vezes == 2: 
            vetorHazard.pop(i)
            return False
        
        else : 
            vetorHazard.append(reg)
            return False

def registradoresUsados(comando, rd, rs1, rs2):
    hazard = [False,False, False]
    reg_rd = Registrador(rd)
    reg_rs1 = Registrador(rs1)
    reg_rs2 = Registrador(rs2)
    if comando == '0010011':
        #TYPEi
        hazard[0] = verificaRegistrador(reg_rd)
        hazard[1] = verificaRegistrador(reg_rs1)
    elif comando == '1100011':
        #TYPEb
        hazard[0] = verificaRegistrador(reg_rs2)
        hazard[1] = verificaRegistrador(reg_rs1)
    elif comando =='0110011':
        #TYPEr
        hazard[1] = verificaRegistrador(reg_rd)
        hazard[0] = verificaRegistrador(reg_rs1)
        hazard[2] = verificaRegistrador(reg_rs2)
    elif comando =='0100011':
       # TYPEs 
       hazard[0] =verificaRegistrador(reg_rs1)
       hazard[1] = verificaRegistrador(reg_rs2)
    elif comando == '1101111':
       # TYPEj
       hazard[0] = verificaRegistrador(reg_rd)
    elif comando == '0010111':
       # TYPEu
       hazard[0] = verificaRegistrador(reg_rd)
    return hazard[0] , hazard[1], hazard[2]


with open("hazardHEX", "r") as arquivo :
    comando = rd = rs1= rs2 = ''
    
    for linha in arquivo:
        
        comando, rd , rs1, rs2 = separaLinha(linha)
        print(linha)
        x, y, z = registradoresUsados(comando, rd, rs1, rs2)
        print(x)
        print(y)
        print(z)
        if x or z or y:
            print('00000000000000000000000000010011')
            print('00000000000000000000000000010011')
            
            
        
        

