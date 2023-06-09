#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

enum {
    TYPEi=0010011,
    TYPEb=1100011,
    TYPEr=0110011,
    TYPEs=0100011,
    TYPEj=1101111,
    TYPEu=0010111
};

enum {
    RD = 0,
    RS1 = 1,
    RS2 = 2
};

/*

struct instrucao {  //ADICIONADO PELO PROFESSOR
    int binario;
    int rd, rs1, rs2;
    TIPO t;
};

*/

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


bool *verifica_tipo(int binario, string rd, string rs1, string rs2){
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
    cout << linha << endl;
}

void verifica_hazard(){

}

int main () {
    ifstream arquivo("./hazardHEX");
    string linha;
    string  rd , rs1, rs2;
    string comando;
    bool  * hazard;


    if(arquivo.is_open()){

        while (!arquivo.eof())  //adicionado pelo professor
        {

            cout << linha << endl;
            for (int i = 25; i <= 31; i++){
                comando = comando + linha[i];
            }
            //cout << endl << comando << endl;
            for (int i = 22; i<= 26; i++){
                rd = rd +linha[i];

            }
            //cout << rd << endl;
            for (int i = 12; i<= 16; i++){
                rs1 = rs1 +linha[i];

            }
            //cout << rs1 << endl;
            for (int i = 17; i<= 21; i++){
                rs2 = rs2 + linha[i];
            }
            //cout << rs2 << endl;
            /*
            hazard = verifica_tipo(stoi(comando), rd, rs1, rs2);
            rd = rs1 = rs2 = comando = "";
            if (hazard[0] || hazard[1] || hazard[3]){
                inserir_bolha(linha);
            }
            */
        }
    }


    return 0;
}
