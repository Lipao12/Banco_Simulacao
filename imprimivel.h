#ifndef IMPRIMIVEL_H
#define IMPRIMIVEL_H

#include "contabancaria.h"

class ContaBancaria;

class Imprimivel{
public:
	virtual void mostrarDados() const = 0;
};

#endif