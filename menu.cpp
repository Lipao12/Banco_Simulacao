#include "menu.h"
#include "banco.h"
#include "contabancaria.h"
#include "contapoupanca.h"
#include "contacorrente.h"
#include "relatorio.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

void Menu::work(){
	Banco mBanco;
	int opc;
	string opc_string;
	bool sair=false;
	while(!sair){
		system("cls");
		cout << "############## MENU ##############\n" << endl;
		cout << "\t1-Criar Conta\n\t2-Selecionar Conta\n\t3-Remover Conta" << endl;
		cout << "\t4-Gerar Relatorio\n\t5-Finalizar\n" << endl;
		cout << "Digite o que deseja realizar: ";
		getline(cin, opc_string);
		opc = stringParaInteiro(opc_string);

		switch (opc){
			case 1:{
				criarConta(&mBanco);
				break;
			}
			case 2:{
				selecionarConta(&mBanco);
				break;
			}
			case 3:{
				removerConta(&mBanco);
				fflush(stdin);	
				break;
			}
			case 4:{
				system("cls");
				cout << "######## CONTAS NO BANCO #########" << endl;
				mBanco.mostrarDados();
				system("pause");
				//getchar();
				break;
			}	
			case 5:{
				sair=true;
				break;
			}
			default:{
				cout << "Opcao invalida" << endl;
				system("pause");
			}
		}
	}	 
}


void criarConta(Banco* mBanco){
	int numConta;
	int opc;
	string opc_string;
	double saldoIni;
	bool sair=false;
	
	while(!sair){
		system("cls");
		cout << "########### CRIAR CONTA ##########" << endl;			
		cout << "    1-Poupanca       2-Corrente\n" << endl;
		cout << "Selecione uma das opcoes acima: ";
		getline(cin, opc_string);
		opc = stringParaInteiro(opc_string);

		switch(opc){
			case 1:{
				cout << "\n #### CONTA POUPANCA ####" << endl;
				cout << " Digite o numero da conta:";
				getline(cin, opc_string);
				numConta = stringParaInteiro(opc_string);

				if(numConta == 0 || numConta < 100000000 || numConta > 999999999){ //numConta deve ter 9 digitos
					cout << "\n --- Erro ao criar conta ---" << endl;
					system("pause");
					break;
				}

				cout << " Digite o valor a ser depositado:";
				cin >> saldoIni;

				if(saldoIni < 0){ //numConta deve ter 9 digitos
					cout << "\n --- Erro ao criar conta ---" << endl;
					system("pause");
					break;
				}

				ContaPoupanca* ptrmPoupanca;
				ptrmPoupanca = new ContaPoupanca(numConta, saldoIni);
				mBanco->inserirConta(ptrmPoupanca);
				break;
			}
			case 2:{
				cout << "\n #### CONTA CORRENTE ####" << endl;
				cout << " Digite o numero da conta:";
				getline(cin, opc_string);
				numConta = stringParaInteiro(opc_string);

				if(numConta == 0 || numConta < 100000000 || numConta > 999999999){ //numConta deve ter 9 digitos
					cout << "\n --- Erro ao criar conta ---" << endl;
					system("pause");
					break;
				}

				cout << " Digite o valor a ser depositado:";
				cin >> saldoIni;

				if(saldoIni < 0){ //numConta deve ter 9 digitos
					cout << "\n --- Erro ao criar conta ---" << endl;
					system("pause");
					break;
				}

				ContaCorrente* ptrmCorrente;
				ptrmCorrente = new ContaCorrente(numConta, saldoIni);
				mBanco->inserirConta(ptrmCorrente);
				break;
			}
			default:{
				cout << "Opcao invalida!" << endl;
				break;
			}
		}
		fflush(stdin);

		while(true)
		{
			system("cls");
			cout << "Deseja criar outra conta?\n   1-SIM   2-NAO" << endl;
			getline(cin, opc_string);
			opc = stringParaInteiro(opc_string);
			if(opc == 2)
			{
				sair = true;
				break;
			}
			else if( opc != 1){
				cout << "Opcao invalida" << endl;
			}
			else{
				break;
			}
		}
		
	}
	
}


void selecionarConta(Banco* mBanco){
	int valor;
	int opc;
	string opc_string;
	int numConta;
	bool sair_case2 = false;
	
	while(!sair_case2){
		system("cls");
		cout << "######## SELECIONAR CONTA ########\n" << endl;
		cout << "\t1-Depositar\n\t2-Sacar\n\t3-Transferir" << endl;
		cout << "\t4-Gerar relatorio\n\t5-Finalizar\n" << endl;
		cout << "Digite o que deseja realizar: ";
		getline(cin, opc_string);
		opc = stringParaInteiro(opc_string);

		if(opc == 5){
			break;
		}

		cout << "\n#### #### #### #### #### #### ####\n" << endl;
		cout << "Digite o numero da sua conta: ";
		getline(cin, opc_string);
		numConta = stringParaInteiro(opc_string);

		ContaBancaria* ptrConta;
		ptrConta = mBanco->procurarConta(numConta);

		if(ptrConta != NULL){
			switch(opc){
				case 1:{
					cout << "Digite o valor que deseja depositar: ";
					cin >> valor;
					ptrConta->depositar(valor);
					break;
				}
				case 2:{
					cout << "Digite o valor que deseja sacar:";
					cin >> valor;
					ptrConta->sacar(valor);
					break;
				}
				case 3:{
					ContaBancaria* transferirPTRconta;
					int contaPtransferir;
					int valor;

					cout << "\nDigite a conta que deseja transferir o dinheiro: ";
					getline(cin, opc_string);
					contaPtransferir = stringParaInteiro(opc_string);

					cout << "\nDigite o valor que deseja ser transferido: ";
					cin >> valor;

					transferirPTRconta = mBanco->procurarConta(contaPtransferir);
					if(transferirPTRconta != NULL)
						ptrConta->transferir(valor, transferirPTRconta);
					break;
				}
				case 4:{
					
					if(ContaPoupanca* conta = dynamic_cast<ContaPoupanca*>(ptrConta)){
   						Relatorio<ContaPoupanca> mRelatorio;
   						mRelatorio.gerarRelatorios(conta);
					}
					else if (ContaCorrente* conta = dynamic_cast<ContaCorrente*>(ptrConta)){
						Relatorio<ContaCorrente> mRelatorio;
   						mRelatorio.gerarRelatorios(conta);
					}
					break;
				}
				default:{
					cout << "Opcao invalida!" << endl;
					system("pause");
					break;
				}
			}
					
		}
	fflush(stdin);	
	system("pause");	
	}
}

void removerConta(Banco* mBanco){
	int numConta;
	ContaBancaria* ptrConta;
	string conta_string;

	system("cls");
	cout << "######### REMOVER CONTA ##########\n" << endl;	
	cout << "Digite o numero da conta: ";
	getline(cin, conta_string);
	numConta = stringParaInteiro(conta_string);
	
	ptrConta = mBanco->procurarConta(numConta);
	if(ptrConta != NULL)
		mBanco->removerConta(ptrConta);
	system("pause");
}

int stringParaInteiro(string opc_string){
	int x=0;

	if(opc_string.empty()){
		return 0;
	}

	string::iterator it;
	for (int i = 0; i < opc_string.size(); ++i)
	{
		if((opc_string[i] != '0'&& opc_string[i] != '1'&& opc_string[i] != '2'&& opc_string[i] != '3'&&opc_string[i] != '4')&&
		   (opc_string[i] != '5'&& opc_string[i] != '6'&& opc_string[i] != '7'&& opc_string[i] != '8'&& opc_string[i] != '9')){
		   		return 0;
		   }
	}
	x = stoi(opc_string);
	return x;	
}