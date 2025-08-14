# Geração procedural de mapas
![Exemplo de imagem](https://github.com/GabrielSantaRosa/Projeto-ITP/blob/master/Imagens_exemplo/imagem_exemplo_1.png)
## Introdução
Esse projeto foi desenvolvido por Arthur Felipe e Gabriel Santa Rosa como avaliação final da disciplina Introdução às Técnicas de Programação ministrada pelo professor André Maurício.
O projeto gera, após a execução de seu executável, uma imagem em formato ppm que representa um terreno gerado proceduralmente, as cores dessa imagem são determinadas por uma paleta armazenada em um txt.
![Exemplo de imagem](https://github.com/GabrielSantaRosa/Projeto-ITP/blob/master/Imagens_exemplo/imagem_exemplo_2.png)
## Observações: 
Os includes dos arquivos foram feitos para windows, caso esteja em linux inverta a barra
```
Como é: 
#include "Arquivos_.h\Paleta.h" 
#include "Arquivos_.h\Terreno.h" 
#include "Arquivos_.h\Imagem.h" 

Como fica:
#include "Arquivos_.h/Paleta.h"
#include "Arquivos_.h/Terreno.h"
#include "Arquivos_.h/Imagem.h"
```
Na compilação, compile apenas: Gerar_mapa.cpp imagem.cpp paleta.cpp
