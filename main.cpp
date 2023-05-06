#include <iostream>
#include <fstream>
#include <string>
#include <vector>

enum {
    TYPEi=1100100,
    TYPEb=1100011,
    TYPEr=1100110,
    TYPEs=1100010,
    TYPEj=1111011,
    TYPEu=1110100

};

enum {
    RD = 0,
    RS1 = 1,
    RS2 = 2
};

struct reg {
    char * bin;
    int vezes;
};
reg mem[6];



using namespace std;

/*falta arrumar
0010111   la auipc type U
0010011   la addi type I
0010011   addi    type I
0010011   addi    type I
1100011   addi    type I
0010011   beq     type B
0110011   slli    type R
0100011   add     type R
0010011   sw      type S
1101111   addi    type I
0010011   jal     type J
0000011    addi    type I
*/

/*
type I rd rs1
*type R rd rs1 rs2

type B rs1 rs2
type S rs1 rs2

type J rd
type U rd
*/


bool verifica_registrador(char * r, int registrador){
    reg vazio, item;
    item.bin = r;
    item.vezes=0;
    vazio.bin = nullptr;
    vazio.vezes = 0;
    for (int i = 0; i < 6; i++){
        if (mem[i].bin == nullptr){
            mem[i] = item;
            break;
        }
    }
    for (int i = 0; i < 6; i++){

         if(mem[i].bin != nullptr){
             mem[i].vezes++;
         }

    }

    for(int i = 0; i < 6; i++){
        if(mem[i].vezes == 2){
            mem[i] = vazio;
        }
        if (mem[i].bin == r && registrador == RD){
            mem[i].vezes = 0;
            return true;
        } else if (mem[i].bin == r){
            return true;
        }
        else {
            return false;
        }

    }
}


bool *verifica_tipo(char * binario, char *rd, char *rs1, char *rs2){
    int bin = stoi(binario);
    bool x[3] = {false};
    switch (bin)
    {
    case TYPEi:
        x[0] = verifica_registrador(rd , RD);
        x[1] = verifica_registrador(rs1, RS1);
        break;

    case TYPEr:
        x[0] = verifica_registrador(rd, RD);
        x[1] = verifica_registrador(rs1, RS1);
        x[2] = verifica_registrador(rs2, RS2);
        break;

    case TYPEb:
    case TYPEs:
        x[0] = verifica_registrador(rs1, RS1);
        x[1] = verifica_registrador(rs2, RS2);
        break;

    case TYPEj:
    case TYPEu:
        x[2] = verifica_registrador(rd, RD);
        break;
    }
    return x;
}

void inserir_bolha(string linha){
    cout << linha;
}

void verifica_hazard(){

}

int main () {
    ifstream arquivo("./hazardHEX");
    string linha;
    char * comando, rd, rs1, rs2;
    bool  hazard[3];
    

    if(arquivo.is_open()){
        while (getline(arquivo, linha))
        {
            for (int i = 31; i >= 25; i--){
                comando = comando + linha[i];
            }
            for (int i = 26; i>= 22; i--){
                rd = rd +linha[i];
            }
            for (int i = 16; i>= 12; i--){
                rs1 = rs1 +linha[i];
            }
            for (int i = 21; i>= 17; i--){
                rs2 = rs2 +linha[i];
            }
            hazard = verifica_tipo(comando, &rd, &rs1, &rs2);
            if (hazard[1] || hazard[2] || hazard[3]){
                inserir_bolha(linha);
            }


        }
    }
    cout << "\nTOTAL DE CICLOS: " << total_de_ciclos << endl;
    cout << "INSTRUCOES: " << instrucao << endl;
    cout << "CPI = " << (total_de_ciclos)/(instrucao) << endl;

    return 0;
}
