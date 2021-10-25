#include "contabancaria.h"
#include "imprimivel.h"
#include <iostream>

using namespace std;

ContaBancaria::ContaBancaria():conta(0), saldo(0){};
ContaBancaria::ContaBancaria(int c, double s):conta(c), saldo(s){};

int ContaBancaria::getConta() const{
	return this->conta;
}

double ContaBancaria::getSaldo() const{
	return this->saldo;
}

void ContaBancaria::sacar(double valor){
	if(this->saldo - valor >= 0){
		this->saldo = this->saldo - valor;
		cout << "### Saque realizado com sucesso ###" << endl;
	}
	else{
		cout << "### Saldo insuficiente! ###" << endl;
	}
}

void ContaBancaria::depositar(double valor){
	this->saldo = this->saldo + valor;
	cout << "### Deposito realizado com sucesso ###" << endl;
}

void ContaBancaria::transferir(double valor, ContaBancaria* contaFinal){
	if(this->saldo - valor >= 0 && this->conta != contaFinal->conta){
		sacar(valor);
		contaFinal->depositar(valor);
		system("cls");
		cout << "\n\n### Valor transferido com sucesso ###\n" << endl;
	}
	else if(this->conta == contaFinal->conta){
		cout << "\n\n### Transicao nao permitida ###\n" << endl;
	}
	else{
		cout << "Saldo insuficiente!" << endl;
	}
}
