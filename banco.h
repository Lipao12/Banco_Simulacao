#ifndef BANCO_H
#define BANCO_H
#include "imprimivel.h"
#include "contabancaria.h"
#include <vector>

using namespace std;

class Menu;

class Banco: public Imprimivel{
public:
	void inserirConta(ContaBancaria*);
	void removerConta(ContaBancaria*);
	~Banco();
	ContaBancaria *procurarConta(int) const;
	int bancoSize() const;
	virtual void mostrarDados() const;
private:
	vector<ContaBancaria*> dados;
	friend class Menu;
};

#endif