static const int MAX_SIZE = 100;

class Terreno{
    int largura;
    int altura;
    int altitudes[MAX_SIZE];

    public:
    Terreno(int l, int a, int altitude[])
    {
        largura = l;
        altura = a;

        for(int i = 0; MAX_SIZE > i; i++)
        {
            altitudes[i] = altitude[i];
        }
    }
    void Gerar_terreno(int n, double r);

};