#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main (){
    ifstream arquivo("./Exercicio1Hex");
    string linha;
    if(arquivo.is_open()){
        while (getline(arquivo, linha))
        {
            cout << linha;   
        }
        
    }


    return 0;
}


