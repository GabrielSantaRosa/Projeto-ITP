#include "Imagem.h"
#include <iostream>
Imagem::Imagem(int l, int a){
    largura = l;
    altura = a;
    // Cor* matriz = new Cor [l*a];
    // for(int largura_i = 0; largura_i < l; largura_i++){
    //     for(int altura_j = 0; altura_j < a; altura_j++){
    //         pixels[largura_i] = matriz[largura_i*a + altura_j];
    //     }
    // }
}

Cor Imagem::Consulta_pixel(int x, int y){
    Cor resultado = pixels[x*altura + y];
    return resultado;
}


int main(){
    Imagem img(5,5);
    Cor teste = img.Consulta_pixel(3,3);
    int r = teste.r;
    int g = teste.g;
    int b = teste.b;
    std::cout << r << " " << g << " " << b << std::endl;

    return 0;
}