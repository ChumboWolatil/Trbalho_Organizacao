#include <iostream>
#include <fstream>
#include <string>
#include <bitset>

using namespace std;

int main (){
    ifstream arquivo("./Exercicio1Hex");
    string linha;
    if(arquivo.is_open()){
        while (getline(arquivo, linha))
        {
            cout << bitset<32>(linha);   
        }
        
    }


    return 0;
}

