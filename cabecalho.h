

struct Cor
{
    unsigned int r, g, b;
};

class Paleta{
    int quantidade;
    Cor cores[100];
    int altura[100]; 
    public:
    Paleta(int q, Cor c[], int a[]);
    Paleta Ler_arquivo();
    Cor Consulta_cor(int a);
};