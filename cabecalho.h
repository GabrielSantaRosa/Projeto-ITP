
struct Cor
{
    unsigned int r, g, b;
};

class Paleta{
    int quantidade;
    Cor cores[100];
    int altura[100];

    public:
    int getquantidade();
    Cor getcor();
    Paleta(int q, Cor c[], int a[]);
    void Ler_arquivo(string arquivo);
    Cor Consulta_cor(int a);
};