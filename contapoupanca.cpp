#include "contapoupanca.h"
#include "contabancaria.h"
#include <iostream>
using namespace std;

ContaPoupanca::ContaPoupanca():ContaBancaria(0, 0), credito(0){};
ContaPoupanca::ContaPoupanca(int conta, double saldo):ContaBancaria(conta, saldo), credito(100){};

void ContaPoupanca::sacar(double valor){
	if(this->saldo - valor >= 0){
		this->saldo = this->saldo - valor;
		cout << "### Saque realizado com sucesso ###" << endl;
	}
	else{
		valor = valor - this->saldo;
		if(verificarCredito(&this->credito, valor)){
			this->saldo = 0;
			cout << "Credito debitado" << endl;
			cout << "Credito atual: R$" << this->credito << endl;
			cout << "### Saque realizado com sucesso ###" << endl;
		}
	}
}

void ContaPoupanca::mostrarDados() const {
	cout << "\n\n### ### Conta Popanca ### ###" << endl << endl;
	cout << "Numero da conta..........: " << this->conta << endl;
	cout << "Saldo da conta...........: R$ " << this->saldo << endl;
	cout << "Credito disponivel.......: R$ " << this->credito << endl;
}

bool verificarCredito(double* credito, double valor){
	if (*credito >= valor){
		*credito = *credito - valor;
		return true;
	}
	cout << "Credito insuficiente!" << endl;
	cout << "\n### Nao foi possivel realizar a operacao ###" << endl;
	return false;
}