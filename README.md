Observações: 
Os includes dos arquivos foram feitos para windows, caso esteja em linux inverta a barra
Como é: 
#include "Arquivos_.h\Paleta.h"
#include "Arquivos_.h\Terreno.h"
#include "Arquivos_.h\Imagem.h"

Como fica:
#include "Arquivos_.h/Paleta.h"
#include "Arquivos_.h/Terreno.h"
#include "Arquivos_.h/Imagem.h"

Na compilação, compile apenas: Gerar_mapa.cpp imagem.cpp paleta.cpp
