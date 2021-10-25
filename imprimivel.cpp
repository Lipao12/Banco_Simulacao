#include "contabancaria.h"
#include "contacorrente.h"
#include "contapoupanca.h"
#include "imprimivel.h"
#include <iostream>
using namespace std;

void Imprimivel::mostrarDados() const{
	ContaBancaria mConta;
	cout << "Numero da conta..........: " << mConta.getConta() << endl;
	cout << "Saldo da conta...........: R$" << mConta.getSaldo() << endl;
}	