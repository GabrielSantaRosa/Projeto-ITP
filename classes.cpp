#include "cabecalho.h"
#include <fstream>
#include <string>
#include <iostream>

using namespace std;

int Paleta::getquantidade(){
    return quantidade;
}

Paleta::Paleta(int q, Cor c[], int a[]){
    quantidade = q;

    for(int i = 0; i < q; i++){
        cores[i] = c[i];
    }
    for(int i = 0; i < q; i++){
     altura[i] = a[i];
    }

}

void Paleta::Ler_arquivo(string arquivo){
    fstream canal(arquivo);
    canal >> quantidade;

    for(int i = 0; i < quantidade; i++){
        canal >> altura[i];
        Cor temporaria;
        int unsigned r, g, b;
        canal >> r >> g >> b;
        temporaria = {r, g, b};
        cores[i] = temporaria;
    }

}


int main(){
    Paleta x;
    string teste = "teste.txt";
    x.Ler_arquivo(teste);
    cout << x.getquantidade() << endl;

    return 0;
}