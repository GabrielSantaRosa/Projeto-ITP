#include "Arquivos_.h\Imagem.h"
#include <iostream>
#include <fstream>

using namespace std;

Imagem::Imagem(int l, int a){
    largura = l;
    altura = a;
    pixels = new Cor [l*a];
    Cor padrao = {0,0,0};

    for(int i = 0; l * a > i; i++)
    {
        pixels[i] = padrao;
    }
}

Cor Imagem::Consulta_pixel(int linha, int coluna){
    Cor resultado = pixels[linha*largura + coluna];
    return resultado;
}

void Imagem::Definir_pixel(int linha, int coluna, Cor nova_cor){
    pixels[linha*largura + coluna] = nova_cor;
}

void Imagem::Salvar_imagem(std::string arquivo){
    ofstream canal(arquivo);
    canal << "P3" << endl;
    canal << largura << " " << altura << endl;
    canal << 255 << endl;
    for(int i = 0; i < largura*altura; i++){
        canal << pixels[i].r << " " << pixels[i].g << " " << pixels[i].b << " "; 
    }
    canal.close();
}