static const int MAX_SIZE = 100;

class Terreno{
    int largura;
    int altura;
    int altitudes[MAX_SIZE];

    public:
    Terreno(int l, int a, int altitude[]);
    
    void Gerar_terreno(int n, double r);

};