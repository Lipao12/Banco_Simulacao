#ifndef CONTABANCARIA_H
#define CONTABANCARIA_H
#include "imprimivel.h"

class ContaBancaria{
public:
	ContaBancaria();
	ContaBancaria(int, double);
	int getConta() const;
	double getSaldo() const;
	virtual void sacar(double);
	virtual void depositar(double);
	void transferir(double, ContaBancaria*);
protected:
	int conta;
	double saldo;
};

#endif
