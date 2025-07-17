#include "Arquivos_.h\Paleta.h"
#include "Arquivos_.h\Terreno.h"
#include "Arquivos_.h\Imagem.h"
#include "terreno.cpp"
#include <cmath>

Imagem* Terreno::Gerar_mapa(Paleta p, int n){
    int tamanho = pow(2,n) + 1;
    Imagem* nova_imagem =  new Imagem(tamanho, tamanho);
    for(int i = 0; i < tamanho; i++){
        for(int j = 0; j < tamanho; j++){
            Cor cor_temp = p.Consulta_cor(altitudes[Array_uni(i,j,tamanho)]);
            nova_imagem->Definir_pixel(i,j,cor_temp);

        }
    }
    nova_imagem->Salvar_imagem("imagem.ppm");
    return nova_imagem;

}

int main(){
    Paleta p;
    //Imagem* img(9,9);
    Terreno t(9,9);
    t.Gerar_terreno(3, 0.4);
    p.Ler_arquivo("paleta.txt");

    t.Gerar_mapa(p, 3);
    return 0;
}