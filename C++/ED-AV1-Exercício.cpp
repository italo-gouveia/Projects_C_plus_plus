#include <iostream>
//definindo uma variável global de tamanho 2
#define tam 2

//definindo duas variáveis que serão utilizadas para verificar as posições para deletar e alterar no vetor
int posicaoAlterada, posicaoDeletada;

using namespace std;

struct Carro{
	string cor, chassi, placa, modelo, marca;
	int ano;
	bool existe; 
};

//função cadastrar recebe o vetor de carros por paramêtros e um objeto carro que será cadastrado
bool cadastrar(Carro carros[], Carro novoCarro){
	//o for percorre o vetor de carros e verifica pelo if se o atributo: "existe" da posição[i] for false 
	//então ele fará que naquela posição que está vazia receba o novo carro que foi recebido por parametro,
	//após isso a execução retornará verdadeiro para o método que chamou a função cadastrar, nesse caso o main
	//pois assim não acontecerá o erro de o for continuar executando e preencher todas as posições do vetor com
	//o mesmo carro.
	//Caso o for percorra todo o vetor verificando que já existe um carro cadastrado em todas as posições 
	//a execução retornará false para o método que chamou a função cadastrar, nesse caso o main. 
	//pois o return é um comando que termina a execução de um método e retorna algo para quem chamou a função
	for(int i = 0; i < tam; i++){
		if(carros[i].existe == false){
			carros[i] = novoCarro;
			return true;
		}
	}
	
	return false;
}

//função listar recebe o vetor de carros por paramêtros
void listar(Carro carros[]){
	//o for percorre o vetor de carros e verifica pelo if se o atributo: "existe" da posição[i] for false
	//então ele irá exibir os dados do carro na posição[i] apenas se aquele carro estiver cadastrado
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

//função alterar recebe o vetor de carros por paramêtro, um objeto do tipo carro com os novos dados do carro que será alterado
//e também recebe a posição do vetor em que o carro será alterado
int alterar(Carro carros[], Carro carroAlterado, int posicaoAlterada){
	//definindo uma variável local que será utilizada para verificar mais tarde se o usuário quer cadastrar um novo carro
	int opcaoCadastro;
	
	//o for percorre o vetor de carros verificando pelo if se o atributo: "existe" da posição[i] for true e verificando também
	//se a variavel posicaoAlterada recebida por paramêtro é igual a posição i caso as duas condições sejam verdadeiras então
	//na posição[i] do vetor eu farei receber o objeto carroAlterado, pois assim eu faço com que a posição do vetor só seja 
	//alterada se já existir um carro cadastrado naquela posição e após essa execução a execução retornará 0 para o método
	//que chamou a função alterar, nesse caso o main. 
	//Dessa forma não acontecerá o erro de preencher todas as posições do vetor com o carroAlterado
	//pois o return é um comando que termina a execução de um método e retorna algo para quem chamou a função
	//caso a execução entre no else pergunta-se ao usuário se ele quer cadastrar um novo carro, armazenando na variável 
	//opcaoCadastro e será verificado se essa operação for sim irá chamar a função cadastrar.
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

//função deletar recebe um vetor de carros por paramêtro e a posição do vetor em que se quer deletar o carro
bool deletar(Carro carros[], int posicaoDeletada){
	//o for percorre o vetor de carros e verifica a condição se a posição[i] é igual a variável posicaoDeletada
	//caso seja verdade o atributo: "existe" do carro na posição[i] irá receber false
	//ao final da execução retornará true para o método que chamou a função deletar, nesse caso o main
	//dessa forma, não haverá perigo de setar o atributo: "existe" para false em todas as posições do vetor
	//pois o return é um comando que termina a execução de um método e retorna algo para quem chamou a função
	for(int i = 0; i < tam; i++){
		if(i == posicaoDeletada){
			carros[i].existe = false;
			return true;
		}
	}
	return false;
}

int main(){
	//declarado um vetor de carros, um objeto carro e uma variável verif e outra opc que serão usadas durante maior parte
	//do código
	Carro carros[tam];
	Carro carro;
	bool verif;
	int opc;
	
	//o for abaixo irá criar um objeto Carro e setar o atributo: "existe" para false e adicionar em todas as posições do vetor
	for(int i = 0; i < tam; i++){
		Carro c;
		c.existe = false;
		carros[i] = c;
	}
	
	//comando do-while que executará o menu pelo menos uma vez e continuará executando até o usuário digitar uma opção para sair
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
		
		//switch case para verificar a opção digita
		switch(opc){
			case 1:
				//o caso 1 armazena os dados no objeto carro e depois passa ele por paramêtro para a função cadastrar
				//a função cadastrar recebe também o vetor de carros
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
				//como cadastrar é uma função do tipo boolean, armazeno o retorno dela numa variável e verifico seu retorno
				//em caso de true exibo a mensagem de cadastrado com sucesso
				//e em caso de false exibo a mensagem de não cadastrado
				verif = cadastrar(carros, carro);
				if(verif == true){
					cout << "Carro cadastrado com sucesso" << endl;
				}else{
					cout << "O carro não pode ser cadastrado" << endl;
				}
				break;
			case 2:
				//o case 2 altera um carro no vetor
				//o for percorre o vetor de carros exibindo o modelo e a posição perguntando ao usuário qual ele deseja alterar
				//armazenando a resposta na variável posicaoAlterada que será passada por paramêtro juntamente com o objeto carro
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
				//case 3 apenas lista o vetor, recebe por paramêtro o vetor de carros
				listar(carros);
				break;
			case 4:
				//case 4 deleta um carro do vetor
				//o for percorre o vetor exibindo o modelo e a posição do carro, pedindo ao usuário que escolha qual deletar
				//armazenando na variável posicaoDeletada que será passada por paramêtro juntamente com o vetor de carros
				cout<<"Deseja deletar um carro ? Selecione qual deles voce quer deletar: "<<endl;
				for(int i = 0; i < tam; i++){
					if(carros[i].existe == true){
						cout<<"Carro: "<< carros[i].modelo << " Numero do carro: "<<i<<endl;	
					}
				}
				cin>>posicaoDeletada;
				//como deletar é uma função lógica armazendo o retorno dela numa variável apenas para exibir mensagem de 
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
