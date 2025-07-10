#include "Imagem.h"
#include <iostream>
Imagem::Imagem(int l, int a){
    largura = l;
    altura = a;
    Cor* matriz = new Cor [l*a];

    for(int i = 0; l * a > i; i++)
    {
        pixels[i] = Cor();
    }
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