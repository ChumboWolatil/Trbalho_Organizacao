#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

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


bool *verifica_tipo(char * binario, string rd, string rs1, string rs2)
    bool x[3] = {false};
    switch (binario)
    {
    case TYPEi:
        x[0] = verifica_registrador(rd , RD);
        x[1] = verifica_registrador(rs1, RS1);
        cout << "i" << endl;
        break;

    case TYPEr:
        x[0] = verifica_registrador(rd, RD);
        x[1] = verifica_registrador(rs1, RS1);
        x[2] = verifica_registrador(rs2, RS2);
        cout << "r" << endl;
        break;

    case TYPEb:
    case TYPEs:
        x[0] = verifica_registrador(rs1, RS1);
        x[1] = verifica_registrador(rs2, RS2);
        cout << "b / s" << endl;
        break;

    case TYPEj:
    case TYPEu:
        x[2] = verifica_registrador(rd, RD);
        cout << "j / u" << endl;
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
    string  rd , rs1, rs2;
    char * comando;
    bool  * hazard;


    if(arquivo.is_open()){

        while (getline(arquivo, linha))
        {

            cout << linha << endl;
            for (int i = 31; i >= 25; i--){
                comando = comando + linha[i];
            }
            cout << endl << comando << endl;
            for (int i = 26; i>= 22; i--){
                rd = rd +linha[i];

            }
            cout << rd << endl;
            for (int i = 16; i>= 12; i--){
                rs1 = rs1 +linha[i];

            }
            cout << rs1 << endl;
            for (int i = 21; i>= 17; i--){
                rs2 = rs2 + linha[i];
            }
            cout << rs2 << endl;
            hazard = verifica_tipo(comando, rd, rs1, rs2);
            if (hazard[0] || hazard[1] || hazard[3]){
                //inserir_bolha(linha);
                cout << "chegou la" << endl;
            }
        }
    }


    return 0;
}
