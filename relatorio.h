#ifndef RELATORIO_H
#define RELATORIO_H

#include "contabancaria.h"
#include "contapoupanca.h"

class Imprimivel;

template<typename T>
class Relatorio{
public:
	void gerarRelatorios(T*) const;	
};

#endif