#ifndef __TERRENO
#define __TERRENO
#include "Imagem.h"
#include "Paleta.h"
#include <string>
static const int MAX_SIZE = 100;

class Terreno{
    int largura;
    int altura;
    int* altitudes;

    public:
    /**
    Construtor comum, recebe largura e altura e aloca um array de ponteiros de tamanho l*a
    @param l,a largura e altura do Terreno
    */
    Terreno(int l, int a);
    /**
    Destrutor, deleta a memória alocada para o array de ponteiros
    */
    ~Terreno();
    /**
      Cria uma matriz unidimensional de altitudes com base no algoritmo Diamond-Square
    @param n  será utilizado para determinar o tamanho da matriz, r 
    @param r determina a aleatoriedade, decai a cada iteração
      */
    void Gerar_terreno(int n, double r);
    /**
     Consulta a altitude em uma dada cordenada
     @param lin, col linnha e coluna que se deseja saber a altitude
     @return valor armazenado na determinada coordenada
    */
     int Consulta_alt(int lin, int col);
    /**
     Retorna a largura do terreno
     @return valor da largura(número de linhas)
    */
    int Consulta_lin();
    /**
     Retorna a altura do terreno
     @return valor da altura(número de colunas)
    */
    int Consulta_col();
    /**
     Salva o terreno em um arquivo
     @param arquivo nome do arquivo a ser criado ou modificado 
    */
     void Salvar_terreno(std::string arquivo);
    /**
        Lê uma matriz de altitudes de um arquivo
        @param arquivo nome do arquivo a ser lido
        */
     void Ler_arquivo(std::string arquivo);
     /**
      * Cria um mapa a partir de uma paleta
      * @param p Paleta a ser usada
      * @param n n usado para determinar o tamanho da imagem
      * @return Uma tipo imagem
      */
     Imagem* Gerar_mapa(Paleta p, int n);

};
#endif