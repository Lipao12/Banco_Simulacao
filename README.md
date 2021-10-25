# Banco_Simulacao

Crie uma classe abstrata ContaBancaria que contém como atributos o número da
conta e o saldo, e como métodos virtuais sacar e depositar que recebem um
parâmetro do tipo double.

Crie as classes ContaCorrente e ContaPoupanca que herdam da ContaBancaria. A
primeira possui um atributo taxaDeOperacao que é descontado sempre que um saque
e um depósito são feitos. A segunda possui um atributo limite que dá crédito a mais para
o correntista caso ele precise sacar mais que o saldo. Neste caso, o saldo pode ficar
negativo desde que não ultrapasse o limite. Contudo isso não pode acontecer na classe
ContaCorrente.

Crie uma classe puramente abstrata Imprimivel que declara um método mostrarDados. Faça as classes ContaCorrente e ContaPoupança herdarem de Imprimivel e na implementação do método, mostre os atributos de cada conta.

Crie uma classe Relatorio que possui um método gerarRelatorio, que receba um
objeto Imprimível e executa o método mostrarDados do objeto.
Crie uma classe Executavel na qual você instancia duas contas (uma de cada tipo),
credita algum valor para elas e efetua um saque (obs: no objeto conta poupança, faça
um saque maior que o saldo atual). Crie um objeto Relatório e execute o método gerar
relatório para cada conta criada. 

Crie um arquivo chamado “main.cpp”, onde você deverá implementar sua função main(), e esta deve apenas criar uma instância desse objeto Executavel, e rodá-lo.

Incremente a classe ContaBancaria com o método transferir, que recebe o
parâmetro valor (double) e um objeto ContaBancaria e transfere o valor desejado da
conta atual para cada conta informada. Use os métodos sacar e depositar para isso.

Crie uma classe Banco que possui um std::vector de contas bancárias e implemente
os métodos inserir, remover e procurarConta. O primeiro e o segundo recebem um
objeto ContaBancaria(que pode ser corrente ou poupança) e o insere e remove no vetor,
respectivamente. O terceiro recebe um inteiro como parâmetro representando o
número da conta e retorna um objeto conta bancária, caso essa conta exista no vetor,
ou null, caso contrário.

Faça a classe Banco herdar da classe Imprimível, onde a implementação de
método consiste em executar método mostrar dados de cada conta.

Crie uma classe Menu que instancie um banco e ofereça o seguinte menu
para o usuário:
Criar conta: o usuário informa se é conta poupança ou corrente e os dados da conta. O objeto correspondente é criado e inserido no banco através do método inserir. Exibir uma mensagem de sucesso.
Selecionar conta: o usuário informa o número da conta. Se a conta existir, mostra o menu abaixo. Caso contrário, mostra mensagem de conta inexistente.
Remover conta: o usuário informa o número da conta. Se a conta existe, então ela é excluída e uma mensagem de sucesso é informada. Caso contrário, uma mensagem de conta inexistente é informada.
Gerar relatório: mostra os dados de todas as contas cadastradas no banco.
Finalizar: termina a aplicação.

Se o usuário escolher “Selecionar Conta”, o seguinte menu deve aparecer:
Depositar: recebe um valor e deposita na conta.
Sacar: recebe um valor e tenta sacar da conta.
Transferir: recebe um valor e o número de outra conta. Caso a conta exista, transfere o valor de uma conta para a outra. Caso contrário, informar mensagem de conta inexistente.
Gerar relatório: mostra os dados da conta selecionada. Utilize o método mostraDados criado anteriormente.
Retornar ao menu anterior: exibe o menu anterior (opções 1 a 5).

11. Crie uma nova função main() num arquivo “main2.cpp” que instancie a classe Menu e a execute.

Dica: Caso vocês tenham dificuldades com o método mostrarDados, devido a este não estar na ContaBancária, e sim nas classes derivadas, vocês podem contornar este problema declarando mostrarDados como uma função virtual na classe ContaBancaria.
