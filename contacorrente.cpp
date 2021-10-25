#include "contacorrente.h"
#include "contabancaria.h"
#include <iostream>
using namespace std;

ContaCorrente::ContaCorrente():ContaBancaria(0, 0),taxaOperacao(0){};
ContaCorrente::ContaCorrente(int conta, double saldo):ContaBancaria(conta, saldo),taxaOperacao(0.05){};

void ContaCorrente::sacar(double valor){
	if(this->saldo - valor - valor * this->taxaOperacao >= 0){
		this->saldo = this->saldo - valor - valor * this->taxaOperacao;
		cout << "### Saque realizado com sucesso ###" << endl;
	}
	else{
		cout << "Saldo insuficiente!" << endl;
	}
}
void ContaCorrente::depositar(double valor){
	this->saldo = this->saldo + valor - valor * this->taxaOperacao;
	cout << "### Deposito realizado com sucesso ###" << endl;
}

void ContaCorrente::mostrarDados() const {
	cout << "\n\n### ### Conta Corrente ### ###" << endl << endl;
	cout << "Numero da conta..........: " << this->conta<< endl;
	cout << "Saldo da conta...........: R$ " << this->saldo << endl;
	cout << "Taxa de operacao.........: " << this->taxaOperacao * 100 << "%" << endl;
}