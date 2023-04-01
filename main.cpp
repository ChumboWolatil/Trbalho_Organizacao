#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int cpi(string binario){
    switch (stoi(binario))
    {
    case 1100100:
        return 4;
        break;
    default : 
        return 0;
    }
   


}


int main (){
    ifstream arquivo("./Execicio1Hex");
    string linha;
    char * comando;
    int total_de_ciclos = 0;

    if(arquivo.is_open()){
        while (getline(arquivo, linha))
        {

            for (int i = 32; i >= 25; i--){
                comando = comando + linha[i];

            }
            total_de_ciclos += cpi(comando);
            cout << comando << endl;

            comando = "";

        }
    }
    cout << total_de_ciclos << endl;

    return 0;
}

