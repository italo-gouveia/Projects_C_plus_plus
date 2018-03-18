#include <iostream>
#include <cstdlib>

using namespace std;

//a struct Elemento tem um ponteiro de elemento que utilizaremos para indicar o pr�ximo
struct Elemento{
	int valor;
	Elemento *prox;
};

//declara��o de dois ponteiros que utilizaremos para indicar o inicio e o fim da lista
Elemento *inicio;
Elemento *fim;

//a fun��o criarLista faz os ponteiros de inicio e fim inicializarem com null para que dessa forma indique que n�o h� inicio
//nem fim pois ainda n�o adicionamos elementos
void criarLista(){
	inicio = NULL;
	fim = NULL;
}

//a fun��o inserir no inicio recebe o valor que ser� inserido
void inserirInicio(int valor){
	
	//aloca memoria/declara um novo objeto do tipo elemento
	Elemento *novo = new Elemento;
	//faz com que o valor dentro da struct receba o valor que recemos por param�tro
	//(para alterar na memoria o valor � necess�rio utilizar o operador "->")
	novo->valor = valor;
	
	//depois verificamos a seguinte condi��o:
	//se o inicio estiver igual � null(ou seja, se a lista estiver vazia)
	if(inicio == NULL){
		//o inicio ir� receber o objeto novo, consequentemente ir� receber o endere�o onde ele se encontra por ser uma struct
		//dessa forma o ponteiro inicio ir� agora apontar para o objeto que acabamos de inserir
		inicio = novo;
		//o mesmo ir� acontecer com o fim
		fim = novo;
		//ap�s tudo isso o atributo/ponteiro prox contido no objeto que est� no fim da lista ir� receber null indicando que 
		//ap�s ele n�o h� mais nenhum valor 
		fim->prox = NULL;
	}else{
		//caso o inicio n�o esteja igual a null(ou seja, caso a lista n�o esteja vazia)
		//o atributo/ponteiro prox contido no objeto que est� no novo ir� receber inicio
		//ou seja ir� apontar pra o objeto que estiver no inicio(que deixar� de ser inicio e se tornar� o prox do elemento 
		//que acabamos de adicionar) e depois inicio receber� o novo, assim sempre ser� adicionado o elemento novo no inicio
		novo->prox = inicio;
		inicio = novo;
	}
}

//para inserir no fim, recebe o valor por param�tro
void inserirFim(int valor){
	
	//aloca memoria/declara um novo objeto do tipo elemento
	Elemento *novo = new Elemento;
	//faz com que o valor dentro da struct receba o valor que recemos por param�tro
	//(para alterar na memoria o valor � necess�rio utilizar o operador "->")
	novo->valor = valor;
	
	//depois verificamos a seguinte condi��o
	//se o inicio estiver igual � null(ou seja, se a lista estiver vazia)
	if(inicio == NULL){
		//o inicio ir� receber o objeto novo, consequentemente ir� receber o endere�o onde ele se encontra por ser uma struct
		//dessa forma o ponteiro inicio ir� agora apontar para o objeto que acabamos de inserir		
		inicio = novo;
		//o mesmo ir� acontecer com o fim
		fim = novo;
		//ap�s tudo isso o atributo/ponteiro prox contido no objeto que est� no fim da lista ir� receber null indicando que 
		//ap�s ele n�o h� mais nenhum valor 
		fim->prox = NULL;
	}else{
		//caso inicio n�o esteja igual a null(lista n�o estiver vazia)
		//o atributo/ponteiro prox contido no objeto fim ir� receber novo ou seja
		//ir� apontar para o objeto que est� no fim da lista ir� apontar agora para o prox que acabamos de criar
		fim->prox = novo;
		//o fim ir� receber ent�o o novo objeto criado que agora ser� o objeto adicionado no fim
		fim=novo;
		//o atributo/ponteiro prox do fim(que agora � objeto que adicionamos) ir� apontar pra null indicando que acabou a lista
		fim->prox = NULL;
	}
}

//fun��o para listar
void listar(){
	
	//se o inicio estiver igual a null significa que a lista est� vazia
	if(inicio == NULL){
		cout << "A lista esta vazia!" << endl;
	}else{
		//caso contr�rio ent�o declaramos um ponteiro que ir� nos auxiliar no processo
		//faremos ele receber o inicio
		Elemento *aux = inicio;
		
		//E verificaremos que enquanto esse ponteiro for diferente de null 
		while(aux!=NULL){
			//iremos exibir o valor contido nele
			cout << aux->valor << endl;
	
			//e ap�s exibir faremos que ele agore aponte pra o pr�ximo elemento da lista
			aux = aux->prox;
			//o programa ir� executar at� que passe por toda lista(ou seja quando o prox for igual a null)
		}
	
		//depois da execu��o desalocaremos o ponteiro auxiliar da mem�ria pois n�o precisaremos mais dele
		delete aux;
	}
}

//fun��o deletar recebe o valor que queremos deletar
void deletar(int valor){
	
	//vari�vel acum que utilizaremos para saber quantos valores foram removidos
	int achou = 0;
	
	//se o inicio estiver igual a null significa que a lista est� vazia
	if(inicio == NULL){
		cout << "A lista esta vazia!" << endl;
	}else{
		//caso contr�rio declaramos o ponteiro aux que ir� nos ajudar na execu��o do c�digo, ele ir� apontar para o inicio da lista
		Elemento *aux = inicio;
		//e outro ponteiro anterior que ir� apontar pra null
		Elemento *anterior = NULL;
		
		//enquanto o elemento auxiliar for diferente de null o programa executar�
		while(aux!=NULL){
			//verificaremos a seguinte condi��o agora se o valor contido no ponteiro/posi��o da lista for igual ao que queremos remover
			if(aux->valor == valor){
				//o acumulador receber� +1 e ir� acumular a quantidade de elementos removidos enquanto o while executar)
				achou += 1;
				//ap�s isso iremos verificar se o valor encontrado na lista est� no inicio, fim ou no meio da lista
				//se estiver no inicio
				if(aux == inicio){
					//o inicio ir� apontar para o proximo
					inicio = aux->prox;
					//iremos desalocar mem�ria para o ponteiro que estava no inicio
					delete aux;
					//e o aux ir� receber o inicio agora
					aux = inicio;
				//se estiver no fim	
				}else if(aux == fim){
					//o ponteiro que for o prox do anterior ir� apontar para null(indicando o fim da lista)
					anterior->prox = NULL;
					//o fim ir� receber o objeto anterior
					fim = anterior;
					//desalocaremos mem�ria para o aux
					delete aux;
					//faremos ele apontar para null(pois ir� indicar que a lista acabou)
					aux = NULL;
				//caso n�o seja no inicio ou no fim da lista
				}else{
					//o proximo do anterior ir� apontar pra o pr�ximo do auxiliar ou seja, ir� substituir o auxiliar que ser� removido
					anterior->prox = aux->prox;
					//desalocaremos mem�ria para o auxiliar
					delete aux;
					//e o auxiliar receber� o proximo do anterior a ele para poder atualizar
					aux = anterior->prox;
				}
			}else{
				//se n�o tiver valores na lista igual o valor que procuramos
				//anterior ir� receber o auxiliar
				anterior = aux;
				//e auxiliar ir� receber o objeto que fica depois do auxiliar
				aux = aux->prox;
			}
		}
		//ap�s a execu��o do while desalocaremos da mem�ria os ponteiros auxiliares
		delete aux, anterior;
		//e exibiremos a quantidade de itens que removemos
		cout << "Foi deletado " << achou << " elementos"<<endl;
	}
}


bool buscar(int valor){
	//se o inicio estiver igual a null significa que a lista est� vazia
	if(inicio == NULL){
		cout << "A lista esta vazia!" << endl;			
		return false;
	}else{
		//caso contr�rio ent�o declaramos um ponteiro que ir� nos auxiliar no processo
		//faremos ele receber o inicio
		Elemento *aux = inicio;
		
		//E verificaremos que enquanto esse ponteiro for diferente de null 
		while(aux!=NULL){
			if(aux->valor == valor){
				cout<<"Valor j� existe!" << endl;
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
