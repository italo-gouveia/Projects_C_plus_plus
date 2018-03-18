#include <iostream>
#include <cstdlib>

using namespace std;

//a struct Elemento tem um ponteiro de elemento que utilizaremos para indicar o próximo
struct Elemento{
	int valor;
	Elemento *prox;
};

//declaração de dois ponteiros que utilizaremos para indicar o inicio e o fim da lista
Elemento *inicio;
Elemento *fim;

//a função criarLista faz os ponteiros de inicio e fim inicializarem com null para que dessa forma indique que não há inicio
//nem fim pois ainda não adicionamos elementos
void criarLista(){
	inicio = NULL;
	fim = NULL;
}

//a função inserir no inicio recebe o valor que será inserido
void inserirInicio(int valor){
	
	//aloca memoria/declara um novo objeto do tipo elemento
	Elemento *novo = new Elemento;
	//faz com que o valor dentro da struct receba o valor que recemos por paramêtro
	//(para alterar na memoria o valor é necessário utilizar o operador "->")
	novo->valor = valor;
	
	//depois verificamos a seguinte condição:
	//se o inicio estiver igual à null(ou seja, se a lista estiver vazia)
	if(inicio == NULL){
		//o inicio irá receber o objeto novo, consequentemente irá receber o endereço onde ele se encontra por ser uma struct
		//dessa forma o ponteiro inicio irá agora apontar para o objeto que acabamos de inserir
		inicio = novo;
		//o mesmo irá acontecer com o fim
		fim = novo;
		//após tudo isso o atributo/ponteiro prox contido no objeto que está no fim da lista irá receber null indicando que 
		//após ele não há mais nenhum valor 
		fim->prox = NULL;
	}else{
		//caso o inicio não esteja igual a null(ou seja, caso a lista não esteja vazia)
		//o atributo/ponteiro prox contido no objeto que está no novo irá receber inicio
		//ou seja irá apontar pra o objeto que estiver no inicio(que deixará de ser inicio e se tornará o prox do elemento 
		//que acabamos de adicionar) e depois inicio receberá o novo, assim sempre será adicionado o elemento novo no inicio
		novo->prox = inicio;
		inicio = novo;
	}
}

//para inserir no fim, recebe o valor por paramêtro
void inserirFim(int valor){
	
	//aloca memoria/declara um novo objeto do tipo elemento
	Elemento *novo = new Elemento;
	//faz com que o valor dentro da struct receba o valor que recemos por paramêtro
	//(para alterar na memoria o valor é necessário utilizar o operador "->")
	novo->valor = valor;
	
	//depois verificamos a seguinte condição
	//se o inicio estiver igual à null(ou seja, se a lista estiver vazia)
	if(inicio == NULL){
		//o inicio irá receber o objeto novo, consequentemente irá receber o endereço onde ele se encontra por ser uma struct
		//dessa forma o ponteiro inicio irá agora apontar para o objeto que acabamos de inserir		
		inicio = novo;
		//o mesmo irá acontecer com o fim
		fim = novo;
		//após tudo isso o atributo/ponteiro prox contido no objeto que está no fim da lista irá receber null indicando que 
		//após ele não há mais nenhum valor 
		fim->prox = NULL;
	}else{
		//caso inicio não esteja igual a null(lista não estiver vazia)
		//o atributo/ponteiro prox contido no objeto fim irá receber novo ou seja
		//irá apontar para o objeto que está no fim da lista irá apontar agora para o prox que acabamos de criar
		fim->prox = novo;
		//o fim irá receber então o novo objeto criado que agora será o objeto adicionado no fim
		fim=novo;
		//o atributo/ponteiro prox do fim(que agora é objeto que adicionamos) irá apontar pra null indicando que acabou a lista
		fim->prox = NULL;
	}
}

//função para listar
void listar(){
	
	//se o inicio estiver igual a null significa que a lista está vazia
	if(inicio == NULL){
		cout << "A lista esta vazia!" << endl;
	}else{
		//caso contrário então declaramos um ponteiro que irá nos auxiliar no processo
		//faremos ele receber o inicio
		Elemento *aux = inicio;
		
		//E verificaremos que enquanto esse ponteiro for diferente de null 
		while(aux!=NULL){
			//iremos exibir o valor contido nele
			cout << aux->valor << endl;
	
			//e após exibir faremos que ele agore aponte pra o próximo elemento da lista
			aux = aux->prox;
			//o programa irá executar até que passe por toda lista(ou seja quando o prox for igual a null)
		}
	
		//depois da execução desalocaremos o ponteiro auxiliar da memória pois não precisaremos mais dele
		delete aux;
	}
}

//função deletar recebe o valor que queremos deletar
void deletar(int valor){
	
	//variável acum que utilizaremos para saber quantos valores foram removidos
	int achou = 0;
	
	//se o inicio estiver igual a null significa que a lista está vazia
	if(inicio == NULL){
		cout << "A lista esta vazia!" << endl;
	}else{
		//caso contrário declaramos o ponteiro aux que irá nos ajudar na execução do código, ele irá apontar para o inicio da lista
		Elemento *aux = inicio;
		//e outro ponteiro anterior que irá apontar pra null
		Elemento *anterior = NULL;
		
		//enquanto o elemento auxiliar for diferente de null o programa executará
		while(aux!=NULL){
			//verificaremos a seguinte condição agora se o valor contido no ponteiro/posição da lista for igual ao que queremos remover
			if(aux->valor == valor){
				//o acumulador receberá +1 e irá acumular a quantidade de elementos removidos enquanto o while executar)
				achou += 1;
				//após isso iremos verificar se o valor encontrado na lista está no inicio, fim ou no meio da lista
				//se estiver no inicio
				if(aux == inicio){
					//o inicio irá apontar para o proximo
					inicio = aux->prox;
					//iremos desalocar memória para o ponteiro que estava no inicio
					delete aux;
					//e o aux irá receber o inicio agora
					aux = inicio;
				//se estiver no fim	
				}else if(aux == fim){
					//o ponteiro que for o prox do anterior irá apontar para null(indicando o fim da lista)
					anterior->prox = NULL;
					//o fim irá receber o objeto anterior
					fim = anterior;
					//desalocaremos memória para o aux
					delete aux;
					//faremos ele apontar para null(pois irá indicar que a lista acabou)
					aux = NULL;
				//caso não seja no inicio ou no fim da lista
				}else{
					//o proximo do anterior irá apontar pra o próximo do auxiliar ou seja, irá substituir o auxiliar que será removido
					anterior->prox = aux->prox;
					//desalocaremos memória para o auxiliar
					delete aux;
					//e o auxiliar receberá o proximo do anterior a ele para poder atualizar
					aux = anterior->prox;
				}
			}else{
				//se não tiver valores na lista igual o valor que procuramos
				//anterior irá receber o auxiliar
				anterior = aux;
				//e auxiliar irá receber o objeto que fica depois do auxiliar
				aux = aux->prox;
			}
		}
		//após a execução do while desalocaremos da memória os ponteiros auxiliares
		delete aux, anterior;
		//e exibiremos a quantidade de itens que removemos
		cout << "Foi deletado " << achou << " elementos"<<endl;
	}
}


bool buscar(int valor){
	//se o inicio estiver igual a null significa que a lista está vazia
	if(inicio == NULL){
		cout << "A lista esta vazia!" << endl;			
		return false;
	}else{
		//caso contrário então declaramos um ponteiro que irá nos auxiliar no processo
		//faremos ele receber o inicio
		Elemento *aux = inicio;
		
		//E verificaremos que enquanto esse ponteiro for diferente de null 
		while(aux!=NULL){
			if(aux->valor == valor){
				cout<<"Valor já existe!" << endl;
				return true;
			}else{
				aux = aux->prox;
			}
			cout<<"Nenhum valor encontrado!" << endl;
			return false;
		}	
	}
}


int main(){
	
	criarLista();
	inserirInicio(10);
	inserirInicio(5);
	inserirFim(8);
	
	listar();
	
	deletar(10);
	deletar(8);
	
	listar();
	
	buscar(5);
	/*cout << inicio->valor << endl;
	cout << inicio->prox->valor << endl;
	cout << inicio->prox->prox->valor << endl;
	cout << inicio->prox->prox->prox << endl;*/
	
	system("pause");
	return 0;
}
