#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

enum TIPO{
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
    string bin = "";
    int vezes = 0;
};

reg mem[6];


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
struct instrucao {
    int binario;
    int rd, rs1, rs2;
    TIPO t;
};

bool verifica_registrador(string r, int registrador){
    reg item;
    item.bin = r;
    item.vezes=0;

    for (int i = 0; i < 6; i++){
        if (mem[i].bin == ""){
            mem[i] = item;
            break;
        }
    }
    for (int i = 0; i < 6; i++){

         if(mem[i].bin != ""){
             mem[i].vezes++;
         }

    }

    for(int i = 0; i < 6; i++){
        if(mem[i].vezes == 2){
            mem[i].bin = 2;
            mem[i].vezes = 0;
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


bool *verifica_tipo(int binario, string rd, string rs1, string rs2){
    bool x[3] = {false};
    switch (binario){
    case TYPEi:
        x[0] = verifica_registrador(rd , RD);
        x[1] = verifica_registrador(rs1, RS1);
        cout << "tipo i" << endl;
        break;

    case TYPEr:
        x[0] = verifica_registrador(rd, RD);
        x[1] = verifica_registrador(rs1, RS1);
        x[2] = verifica_registrador(rs2, RS2);
        cout << "tipo r" << endl;
        break;

    case TYPEb:
    case TYPEs:
        x[0] = verifica_registrador(rs1, RS1);
        x[1] = verifica_registrador(rs2, RS2);
        cout << "tipo b / s" << endl;
        break;

    case TYPEj:
    case TYPEu:
        x[2] = verifica_registrador(rd, RD);
        cout << "tipo j / u" << endl;
        break;
    }
    return x;
}

void inserir_bolha(string linha){
    cout << linha << endl;
}

void verifica_hazard(){

}

int main () {
    ifstream arquivo;
    arquivo.open ("./hazardHEX");
    string linha;
    string  rd , rs1, rs2;
    string comando = "";
    //bool * hazard;
    int nlinha = 0;

    if(arquivo.is_open()){

        while (!arquivo.eof())
        {
            arquivo >> linha;
            nlinha++;
            cout << "\nLinha[" << nlinha << "]: " << linha;
            cout << "\nOpcode[" << nlinha << "]: ";

            for (int i = 25; i <= 31; i++){
                cout << linha[i];
                comando += linha[i];
            }
            //cout << endl;

            /*
            if (hazard[0] || hazard[1] || hazard[3]){
                inserir_bolha(linha);
            }
            */
        }
    }


    return 0;
}
