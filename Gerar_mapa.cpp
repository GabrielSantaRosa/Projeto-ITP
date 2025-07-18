#include "Arquivos_.h\Paleta.h"
#include "Arquivos_.h\Terreno.h"
#include "Arquivos_.h\Imagem.h"
#include "terreno.cpp"
#include <cmath>

#include <iostream>

Imagem* Terreno::Gerar_mapa(Paleta p, int n){
    int tamanho = pow(2,n) + 1;
    Imagem* nova_imagem =  new Imagem(tamanho, tamanho);

    Cor cor_temp;
    for(int i = 0; i < tamanho; i++){
        for(int j = 0; j < tamanho; j++){
            cor_temp = p.Consulta_cor(altitudes[Array_uni(i,j,tamanho)]);
            nova_imagem->Definir_pixel(i,j,cor_temp);
        }
    }

    for(int i = 1; i < tamanho ; i++){
        for(int j = 1; j < tamanho; j++){
            if(altitudes[Array_uni(i-1,j-1,tamanho)] > altitudes[Array_uni(i,j,tamanho)]){
                cor_temp = p.Consulta_cor(altitudes[Array_uni(i,j,tamanho)]);
                cor_temp.b *= sqrt(0.5); 
                cor_temp.g *= sqrt(0.5);
                cor_temp.r *= sqrt(0.5);
                nova_imagem->Definir_pixel(i,j,cor_temp);
            }
        }
    }
    nova_imagem->Salvar_imagem("imagem.ppm");
    return nova_imagem;
}

int main(){
    Paleta p;
    //Imagem* img(9,9);
    Terreno t(513,513);
    t.Gerar_terreno(9, 0.5);
    p.Ler_arquivo("paleta.txt");

    t.Gerar_mapa(p, 9);
    return 0;
}