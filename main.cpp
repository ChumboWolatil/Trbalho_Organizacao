#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main (){
    ifstream arquivo("./Execicio1Hex");
    string linha, comando;

    if(arquivo.is_open()){
        while (getline(arquivo, linha))
        {

            for (int i = 32; i >= 25; i--){
                comando = comando + linha[i];

            }
            cout << comando << endl;
            comando = "";

        }
    }

    return 0;
}

