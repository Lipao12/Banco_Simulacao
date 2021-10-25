#include "imprimivel.h"
#include "menu.h"
#include "banco.h"
#include <iostream>
#include <vector>

using namespace std;

Banco::~Banco(){
	for(auto ptr : this->dados){
		delete ptr;
	}
}

void Banco::inserirConta(ContaBancaria* nConta){
	bool encontrou = false;
	for (int i = 0; i < this->dados.size(); ++i)
	{
		if(this->dados[i]->getConta() == nConta->getConta()){
			encontrou = true;
			cout << "\n ### Essa conta ja existe! ###" << endl;
			break;
		}
	}
	if(!encontrou){
		dados.push_back(nConta);
		system("cls");
		cout << "### Conta criada com sucesso ###\n" << endl;
	}
	system("pause");
}

void Banco::removerConta(ContaBancaria* nConta){
	bool encontrou=false;
	for (int i = 0; i < this->dados.size(); ++i)
	{
		if(this->dados[i]->getConta() == nConta->getConta()){
			this->dados.erase(this->dados.begin() + i);
			cout << "\n\t\t.\n\t\t.\n\t\t.\n" << endl;
			cout << "### Conta removida com sucesso ###\n" << endl;
			encontrou=true;
		}
	}
}

ContaBancaria* Banco::procurarConta(int nConta) const{
	for (int i = 0; i < this->dados.size(); ++i)
	{
		if(this->dados[i]->getConta() == nConta){
			Banco mBanco;
			ContaBancaria conta;
			ContaBancaria* ptrDados;
			return this->dados[i];
		}
	}
	system("cls");
	cout << "### Conta inesistente! ###" << endl;
	return NULL;
}

int Banco::bancoSize() const{
	return this->dados.size();
}

void Banco::mostrarDados() const{//ContaBancaria* cb
	for (int i = 0; i < this->dados.size(); ++i)
	{
		if(ContaPoupanca* conta = dynamic_cast<ContaPoupanca*>(this->dados[i])){
   			conta->mostrarDados();
		}
		else if (ContaCorrente* conta = dynamic_cast<ContaCorrente*>(this->dados[i])){
			conta->mostrarDados();
		}
		cout << "\n ---- ---- ---- ---- ---- ----" << endl;
	}
	
}
