#ifndef CONTACORRENTE_H
#define CONTACORRENTE_H

#include "contabancaria.h"
#include "imprimivel.h"

class ContaCorrente: public ContaBancaria, public Imprimivel{
public:
	ContaCorrente();
	ContaCorrente(int, double);

	virtual void sacar(double);
	virtual void depositar(double);
	virtual void mostrarDados() const;
private:
	double taxaOperacao;
	friend class Imprimivel;	
};

#endif