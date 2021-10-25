#include "contabancaria.h"
#include "imprimivel.h"
#include "contacorrente.h"
#include "contapoupanca.h"
#include "relatorio.h"
#include "executavel.h"
#include <iostream>

using namespace std;

void Executavel::work() const{
	ContaCorrente mContaCorrente(1312, 1000);
	ContaCorrente* ptrmContaCorrente;
	ContaPoupanca mContaPoupanca(1122, 1000);
	ContaPoupanca* ptrmContaPoupanca; 
	Relatorio<ContaCorrente> mRelCorrente;
	Relatorio<ContaPoupanca> mRelPoupanca;

	ptrmContaPoupanca = &mContaPoupanca;
	ptrmContaCorrente = &mContaCorrente;

	cout << "########### Antes do Deposito ###########";
	mRelCorrente.gerarRelatorios(ptrmContaCorrente);
	mRelPoupanca.gerarRelatorios(ptrmContaPoupanca);
	system("pause");

	system("cls");
	cout << "Sera realizado na CONTA CORRENTE um deposito de R$ 200,00\nE na CONTA POUPANCA um deposito de R$ 100,00" << endl;
	system("pause");

	system("cls");
	cout << "\n########### Durante o Deposito ###########\n";
	cout << "\n### ### Conta Corrente ### ###\n" << endl;
	ptrmContaCorrente->depositar(200);
	cout << "\n### ### Conta Poupanca ### ###\n" << endl;
	ptrmContaPoupanca->depositar(100);
	system("pause");

	system("cls");
	cout << "########### Antes do Saque ###########";
	mRelCorrente.gerarRelatorios(ptrmContaCorrente);
	mRelPoupanca.gerarRelatorios(ptrmContaPoupanca);
	system("pause");

	system("cls");
	cout << "Sera realizado na CONTA CORRENTE um saque de R$ 500,00\nE na CONTA POUPANCA um saque de R$ 1200,00" << endl;
	system("pause");

	system("cls");
	cout << "\n########### Durante o Saque ###########\n";
	cout << "\n### ### Conta Corrente ### ###\n" << endl;
	ptrmContaCorrente->sacar(500);
	cout << "\n### ### Conta Poupanca ### ###\n" << endl;
	ptrmContaPoupanca->sacar(1200);
	system("pause");

	system("cls");
	cout << "\n########### Depois do Saque ###########";
	mRelCorrente.gerarRelatorios(ptrmContaCorrente);
	mRelPoupanca.gerarRelatorios(ptrmContaPoupanca);
}
