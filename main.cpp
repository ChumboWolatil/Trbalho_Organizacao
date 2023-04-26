#include <iostream>
#include <fstream>
#include <string>
enum {
    TYPEi=1100100,
    TYPEb=1100011,
    TYPEr=1100110,
    TYPEs=1100010,
    TYPEj=1111011,
    TYPEu=1110100

};

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


string verifica_registrador(rd, rs1, rs2){

}

int cpi(string binario, string rd, string rs1){
    int bin = stoi(binario);
    string x;
    switch (bin)
    {
    case TYPEi:
        x = verifica_registrador(rd);
        x = verifica_registrador(rs1);

    case TYPEr:
        x = verifica_registrador(rd);
        x = verifica_registrador(rs1);
        x = verifica_registrador(rs2);
        break;

    case TYPEb:
    case TYPEs
        x = verifica_registrador(rs1);
        x = verifica_registrador(rs2);
        break;

    case TYPEj:
    case TYPEu
        x = verifica_registrador(rd);
        break;
}

int main (){
    ifstream arquivo("./hazardHEX");
    string linha, comando;
    float total_de_ciclos = 0;
    int instrucao = 0;

    if(arquivo.is_open()){
        while (getline(arquivo, linha))
        {
            for (int i = 31; i >= 25; i--){
                comando = comando + linha[i];
            }
            total_de_ciclos += cpi(comando);
            cout << comando << endl;

            if(comando != "1100111"){
                comando = "";
                instrucao++;
            }
        }
    }
    cout << "\nTOTAL DE CICLOS: " << total_de_ciclos << endl;
    cout << "INSTRUCOES: " << instrucao << endl;
    cout << "CPI = " << (total_de_ciclos)/(instrucao) << endl;

    return 0;
}
