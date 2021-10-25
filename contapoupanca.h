#ifndef CONTAPOUPANCA_H
#define CONTAPOUPANCA_H

#include "contabancaria.h"
#include "imprimivel.h"

#include <iostream>
using namespace std;

bool verificarCredito(double*, double);

class ContaPoupanca: public ContaBancaria, public Imprimivel{
public:
	ContaPoupanca();
	ContaPoupanca(int, double);
	virtual void sacar(double);
	virtual void mostrarDados() const;
private:	
	double credito;
};

#endif