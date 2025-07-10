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

    int quantidade; //Quantidade de cores que a paleta possui
    Cor cores[100]; 
    int altura[100];

    public:
    Paleta();
    Paleta(int q, Cor c[], int a[]);
    int Consulta_quantidade();
    void Ler_arquivo(std::string arquivo);
    Cor Consulta_cor(int a);
};

#endif