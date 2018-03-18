#include <iostream>
//definindo uma vari�vel global de tamanho 2
#define tam 2

//definindo duas vari�veis que ser�o utilizadas para verificar as posi��es para deletar e alterar no vetor
int posicaoAlterada, posicaoDeletada;

using namespace std;

struct Carro{
	string cor, chassi, placa, modelo, marca;
	int ano;
	bool existe; 
};

//fun��o cadastrar recebe o vetor de carros por param�tros e um objeto carro que ser� cadastrado
bool cadastrar(Carro carros[], Carro novoCarro){
	//o for percorre o vetor de carros e verifica pelo if se o atributo: "existe" da posi��o[i] for false 
	//ent�o ele far� que naquela posi��o que est� vazia receba o novo carro que foi recebido por parametro,
	//ap�s isso a execu��o retornar� verdadeiro para o m�todo que chamou a fun��o cadastrar, nesse caso o main
	//pois assim n�o acontecer� o erro de o for continuar executando e preencher todas as posi��es do vetor com
	//o mesmo carro.
	//Caso o for percorra todo o vetor verificando que j� existe um carro cadastrado em todas as posi��es 
	//a execu��o retornar� false para o m�todo que chamou a fun��o cadastrar, nesse caso o main. 
	//pois o return � um comando que termina a execu��o de um m�todo e retorna algo para quem chamou a fun��o
	for(int i = 0; i < tam; i++){
		if(carros[i].existe == false){
			carros[i] = novoCarro;
			return true;
		}
	}
	
	return false;
}

//fun��o listar recebe o vetor de carros por param�tros
void listar(Carro carros[]){
	//o for percorre o vetor de carros e verifica pelo if se o atributo: "existe" da posi��o[i] for false
	//ent�o ele ir� exibir os dados do carro na posi��o[i] apenas se aquele carro estiver cadastrado
	for(int i = 0; i < tam; i++){
		if(carros[i].existe == true){
			cout<<"Dados do veiculo: "<<endl;
			cout<<"Modelo: "<<carros[i].modelo<<endl;
			cout<<"Marca: " <<carros[i].marca<<endl;
			cout<<"Cor: " <<carros[i].cor<<endl;
			cout<<"Chassi: "<<carros[i].chassi<<endl;
			cout<<"Placa: "<<carros[i].placa<<endl;
			cout<<"Ano: "<<carros[i].ano<<endl;
			cout<<" "<<endl;	
		}
	}
}

//fun��o alterar recebe o vetor de carros por param�tro, um objeto do tipo carro com os novos dados do carro que ser� alterado
//e tamb�m recebe a posi��o do vetor em que o carro ser� alterado
int alterar(Carro carros[], Carro carroAlterado, int posicaoAlterada){
	//definindo uma vari�vel local que ser� utilizada para verificar mais tarde se o usu�rio quer cadastrar um novo carro
	int opcaoCadastro;
	
	//o for percorre o vetor de carros verificando pelo if se o atributo: "existe" da posi��o[i] for true e verificando tamb�m
	//se a variavel posicaoAlterada recebida por param�tro � igual a posi��o i caso as duas condi��es sejam verdadeiras ent�o
	//na posi��o[i] do vetor eu farei receber o objeto carroAlterado, pois assim eu fa�o com que a posi��o do vetor s� seja 
	//alterada se j� existir um carro cadastrado naquela posi��o e ap�s essa execu��o a execu��o retornar� 0 para o m�todo
	//que chamou a fun��o alterar, nesse caso o main. 
	//Dessa forma n�o acontecer� o erro de preencher todas as posi��es do vetor com o carroAlterado
	//pois o return � um comando que termina a execu��o de um m�todo e retorna algo para quem chamou a fun��o
	//caso a execu��o entre no else pergunta-se ao usu�rio se ele quer cadastrar um novo carro, armazenando na vari�vel 
	//opcaoCadastro e ser� verificado se essa opera��o for sim ir� chamar a fun��o cadastrar.
	for(int i = 0; i < tam; i++){
		if(carros[i].existe == true && i == posicaoAlterada){
			carros[i] = carroAlterado;
			cout<<"Carro alterado com sucesso! "<< endl;
			return 0;
		}else if(carros[i].existe == false){
			cout<<"Nao ha carro na posicao escolhida, deseja cadastrar ? "<<endl;
			cout<<"1 - SIM: "<<endl;
			cout<<"2 - NAO: "<<endl;
			cin>>opcaoCadastro;
			if(opcaoCadastro == 1){
				cadastrar(carros, carroAlterado);
			}else{
				cout<<"Ok, nao irei cadastrar: "<<endl;
			}
			return 0;	
		}
	}
}

//fun��o deletar recebe um vetor de carros por param�tro e a posi��o do vetor em que se quer deletar o carro
bool deletar(Carro carros[], int posicaoDeletada){
	//o for percorre o vetor de carros e verifica a condi��o se a posi��o[i] � igual a vari�vel posicaoDeletada
	//caso seja verdade o atributo: "existe" do carro na posi��o[i] ir� receber false
	//ao final da execu��o retornar� true para o m�todo que chamou a fun��o deletar, nesse caso o main
	//dessa forma, n�o haver� perigo de setar o atributo: "existe" para false em todas as posi��es do vetor
	//pois o return � um comando que termina a execu��o de um m�todo e retorna algo para quem chamou a fun��o
	for(int i = 0; i < tam; i++){
		if(i == posicaoDeletada){
			carros[i].existe = false;
			return true;
		}
	}
	return false;
}

int main(){
	//declarado um vetor de carros, um objeto carro e uma vari�vel verif e outra opc que ser�o usadas durante maior parte
	//do c�digo
	Carro carros[tam];
	Carro carro;
	bool verif;
	int opc;
	
	//o for abaixo ir� criar um objeto Carro e setar o atributo: "existe" para false e adicionar em todas as posi��es do vetor
	for(int i = 0; i < tam; i++){
		Carro c;
		c.existe = false;
		carros[i] = c;
	}
	
	//comando do-while que executar� o menu pelo menos uma vez e continuar� executando at� o usu�rio digitar uma op��o para sair
	do{
		cout<< " "<<endl;
		cout<<"MENU DE OPCOES: "<<endl;
		cout << "1 - Cadastrar" << endl;
		cout << "2 - Alterar" << endl;
		cout << "3 - Listar" << endl;
		cout << "4 - Remover" << endl;
		cout << "5 - Sair" << endl;
		cout << "Digite a opcao desejada: ";
		cin >> opc;
		cout<<" "<<endl;
		
		//switch case para verificar a op��o digita
		switch(opc){
			case 1:
				//o caso 1 armazena os dados no objeto carro e depois passa ele por param�tro para a fun��o cadastrar
				//a fun��o cadastrar recebe tamb�m o vetor de carros
				cout << "Inserir Carro: " << endl;
				cout << "Digite a cor do carro: ";
				cin >> carro.cor;
				cout << "Digite o chassi do carro: ";
				cin >> carro.chassi;
				cout << "Digite a placa do carro: ";
				cin >> carro.placa;
				cout << "Digite o modelo do carro: ";
				cin >> carro.modelo;
				cout << "Digite a marca do carro: ";
				cin >> carro.marca;
				cout << "Digite o ano do carro: ";
				cin >> carro.ano;
				carro.existe = true;
				//como cadastrar � uma fun��o do tipo boolean, armazeno o retorno dela numa vari�vel e verifico seu retorno
				//em caso de true exibo a mensagem de cadastrado com sucesso
				//e em caso de false exibo a mensagem de n�o cadastrado
				verif = cadastrar(carros, carro);
				if(verif == true){
					cout << "Carro cadastrado com sucesso" << endl;
				}else{
					cout << "O carro n�o pode ser cadastrado" << endl;
				}
				break;
			case 2:
				//o case 2 altera um carro no vetor
				//o for percorre o vetor de carros exibindo o modelo e a posi��o perguntando ao usu�rio qual ele deseja alterar
				//armazenando a resposta na vari�vel posicaoAlterada que ser� passada por param�tro juntamente com o objeto carro
				//e o vetor de carros
				cout<<"Deseja alterar um carro ? Selecione qual deles voce quer alterar: "<<endl;
				for(int i = 0; i < tam; i++){
					if(carros[i].existe == true){
						cout<<"Carro: "<< carros[i].modelo << " Numero do carro: "<<i<<endl;	
					}
				}
				cin>>posicaoAlterada;
				cout<<" "<<endl;
				
				cout << "Alterar Carro: " << endl;
				cout << "Digite a cor do carro: ";
				cin >> carro.cor;
				cout << "Digite o chassi do carro: ";
				cin >> carro.chassi;
				cout << "Digite a placa do carro: ";
				cin >> carro.placa;
				cout << "Digite o modelo do carro: ";
				cin >> carro.modelo;
				cout << "Digite a marca do carro: ";
				cin >> carro.marca;
				cout << "Digite o ano do carro: ";
				cin >> carro.ano;
				carro.existe = true;
				alterar(carros, carro, posicaoAlterada);
				break;
			case 3:
				//case 3 apenas lista o vetor, recebe por param�tro o vetor de carros
				listar(carros);
				break;
			case 4:
				//case 4 deleta um carro do vetor
				//o for percorre o vetor exibindo o modelo e a posi��o do carro, pedindo ao usu�rio que escolha qual deletar
				//armazenando na vari�vel posicaoDeletada que ser� passada por param�tro juntamente com o vetor de carros
				cout<<"Deseja deletar um carro ? Selecione qual deles voce quer deletar: "<<endl;
				for(int i = 0; i < tam; i++){
					if(carros[i].existe == true){
						cout<<"Carro: "<< carros[i].modelo << " Numero do carro: "<<i<<endl;	
					}
				}
				cin>>posicaoDeletada;
				//como deletar � uma fun��o l�gica armazendo o retorno dela numa vari�vel apenas para exibir mensagem de 
				//sucesso em caso de true, ou de erro em caso de false
				verif = deletar(carros, posicaoDeletada);
				if(verif == true){
					cout<<"Carro deletado com sucesso! "<<endl;
				}else{
					cout<<"Ocorreu um erro ao deletar o carro! "<<endl;
				}
				break;
			case 5:
				break;
			default:
				cout << "Digite uma opcao valida (1-5)!" << endl;
			
		}
		
	}while(opc!=5);
	
	cout << carros[0].cor << endl;
	
	return 0;
}
