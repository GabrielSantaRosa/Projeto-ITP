#ifndef __TERRENO
#define __TERRENO
#include <string>
static const int MAX_SIZE = 100;

class Terreno{
    int largura;
    int altura;
    int* altitudes;

    public:
    /**
    Construtor comum, recebe largura e altura e aloca um array de ponteiros de tamanho l*a
    @param l,a: largura e altura do Terreno
    */
    Terreno(int l, int a);
    /**
    Destrutor, deleta a memória alocada para o array de ponteiros
    */
    ~Terreno();
    /**Recebe um n, definindo largura e altura como 2^n + 1, e uma rugosidade, cria uma matriz de altitudes com base no algoritmo Diamond-Square
    */
    void Gerar_terreno(int n, double r);
    //Recebe uma coordenada e retorna qual o valor da altitude armazenada nela
    int Consulta_alt(int lin, int col);
    //Retorna a largura do terreno
    int Consulta_lin();
    //Retorna a altura do terreno
    int Consulta_col();
    //Recebe uma string e salva a largura, altura e matriz desse terreno no arquivo com nome dessa string
    void Salvar_terreno(std::string arquivo);
    //Recebe uma string e le uma matriz de altitudes de um arquivo com o nome dessa string
    void Ler_arquivo(std::string arquivo);

};
#endif