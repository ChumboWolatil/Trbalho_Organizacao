#include <iostream>
#include <fstream>
#include <string>


using namespace std;

/*
    Store (4 cycles)
    Load (5 cycles)
    I-type (4 cycles)
    R-type (4 cycles)
    Branch (3 cycles)
    Jump (3 cycles)
*/

int cpi( string binario){
    int bin = stoi(binario);
    switch (bin)
    {
    case 1100100:       //addi tipo I
        cout << "addi (4 ciclos) - ";
        return 4;
        break;

    case 1100110:       //add tipo R
        cout << "add (4 ciclos) - ";
        return 4;
        break;


    case 1100000:       //lw tipo I
        cout << "lw (5 ciclos) - ";
        return 5;
        break;

    case 1100010:       //sw tipo S
        cout << "sw (4 ciclos) - ";
        return 4;
        break;

    case 1100011:       //beq tipo B
        cout << "beq (3 ciclos) - ";
        return 3;
        break;

    case 1111011:       //jal tipo J
        cout << "jal (4 ciclos) - ";
        return 4;
        break;

    case 1110100:       //auipc tipo U
        cout << "auipc (3 ciclos) - ";
        return 3;
        break;

    case 1110011:       //jalr tipo I
        cout << "jalr (4 ciclos) - ";
        return 4;
        break;

    case 1100111:       //ecall tipo I
        cout << "ecall (ignorado) - ";
        return 0;
        break;

    default :
        return 0;
    }

}

int main (){
    ifstream arquivo("./Exercicio6Hex");
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

            if(comando != "1100111"){   //ignora ecall
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

