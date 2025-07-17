#include <string>
static const int MAX_SIZE = 100;

class Terreno{
    int largura;
    int altura;
    int altitudes[MAX_SIZE];

    public:
    Terreno(int l, int a);
    ~Terreno();
    void Gerar_terreno(int n, double r);
    int Consulta_alt(int lin, int col);
    int Consulta_lin();
    int Consulta_col();
    void Salvar_terreno(std::string arquivo);
    void Ler_arquivo(std::string arquivo);

};