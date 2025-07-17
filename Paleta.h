#ifndef __PALETA
#define __PALETA
#include <string>

struct Cor
{
    unsigned int r; 
    unsigned int g;
    unsigned int b;
};

class Paleta{

    static const int MAX_CORES = 100;
    int quantidade; 
    Cor cores[MAX_CORES]; 
    int altura[MAX_CORES];

    public:
    /**Construtor vazio
    */
    Paleta();
    /**
     Construtor com seus valores dados pelo usuário
     @param q quantidade de cores
     @param c cores da paleta
     @param a alturas da paleta
     */
    Paleta(int q, Cor c[], int a[]);
    /**
     * Consulta a quantidade de cores
     * @return Quantidade de cores da paleta
     */
    int Consulta_quantidade();
    /**
     * Le uma paleta a partir de um arquivo
     * @param arquivo nome do arquivo a ser lido
     */
    void Ler_arquivo(std::string arquivo);
    /**
     * Consulta qual a cor de de determinado valor
     * @param a Valor de consulta
     * @return Cor em que a se ecnontra
     */
    Cor Consulta_cor(int a);
};

#endif