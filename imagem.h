#include "cor_e_paleta.h"
#include <string>

class Imagem{
    int largura, altura;
    Cor* pixels = new Cor[largura*altura]; 
    public:
    Imagem(int l, int a);
    Cor Consulta_pixel(int x, int y);
    void Definir_pixel(int x, int y, Cor nova_cor);
    void Salvar_imagem(std::string arquivo);
};
