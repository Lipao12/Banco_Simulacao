#ifndef MENU_H
#define MENU_H

#include "menu.h"
#include "banco.h"
#include "contapoupanca.h"
#include "contacorrente.h"
#include "relatorio.h"
#include <iostream>
#include <string>

using namespace std;

class Banco;
void criarConta(Banco*);
void selecionarConta(Banco*);
void removerConta(Banco*);
int verificarOpc();
int stringParaInteiro(string);

class Menu{
public:
	void work();
};

#endif