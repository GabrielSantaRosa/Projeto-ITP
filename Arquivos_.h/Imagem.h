#ifndef __IMAGEM
#define __IMAGEM
#include "Paleta.h"
#include <string>

class Imagem{
    int largura, altura;
    Cor* pixels;
    
    public:
    /**
     * Construtor do tipo imagem
     * @param l, a Largura e altura da imagem
     */
    Imagem(int l, int a);
    /**
     * Consulta a cor de um dado pixel
     * @param linha,coluna Linha e coluna do determinado pixel
     * @return Cor do pixel dado 
     */
    Cor Consulta_pixel(int linha, int coluna);
    /**
     * Define a cor de um dado pixel
     * @param linha, coluna Linha e coluna do determinado pixel
     * @param nova_cor Cor que será atribuida a esse pixel
     */
    void Definir_pixel(int linha, int coluna, Cor nova_cor);
    /**
     * Salva a imagem em um arquivo
     * @param arquivo Nome do arquivo a ser criado ou modificado
     */
    void Salvar_imagem(std::string arquivo);
};
#endif
