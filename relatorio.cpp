#include "relatorio.h"
#include "imprimivel.h"
#include "contabancaria.h"
#include "contapoupanca.h"
#include "contacorrente.h"

template<typename T>
void Relatorio<T>::gerarRelatorios(T* obj) const{
	obj->mostrarDados();
}

template class Relatorio<ContaPoupanca>;
template class Relatorio<ContaCorrente>;