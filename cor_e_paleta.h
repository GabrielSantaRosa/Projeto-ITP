#ifndef __PALETA
#define __PALETA
#include <string>
struct Cor
{
    unsigned int r, g, b;
};

class Paleta{
    int quantidade;
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