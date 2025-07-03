#include "cabecalho.h"
#include <fstream>
using namespace std;

Paleta::Paleta(int q, Cor c[], int a[]){
    quantidade = q;
    for(int i = 0; i < q; i++){
        altura[i] = a[i];
        cores[i] = c[i];
    }
}

Paleta Ler_arquivo(fstream arquivo){   
    Paleta x; //Problema de inicialização
    ios::in;
    x << arquivo; //Problema de definição
    return x;

}

Cor Consulta_cor(Paleta paleta, int valor){ 
    for(int i = 0; i < paleta.quantidade //Valor privado
        if
    }

}

int main(){
    
    return 0;
}