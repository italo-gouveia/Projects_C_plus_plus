#include <iostream>
#include <cstdlib>

using namespace std;

struct Elemento{
	int valor;
	Elemento *prox;
};

Elemento *inicio;
Elemento *fim;

void criarLista(){
	inicio = NULL;
	fim = NULL;
}

bool buscar(int valor){
	if(inicio == NULL){
		//cout << "A lista esta vazia!" << endl;			
		return false;
	}else{
		Elemento *aux = inicio;
		while(aux!=NULL){
			if(aux->valor == valor){
				//cout<<"Valor ja existe!" << endl;
				return true;
			}else{
				aux = aux->prox;
			}
			//cout<<"Nenhum valor encontrado!" << endl;
			return false;
		}	
	}
}

/*bool buscar(int valor){
	if(inicio == NULL){
		//cout << "A lista esta vazia!" << endl;			
		return false;
	}else{
		//Elemento *aux = inicio;
		while(inicio!=NULL){
			if(inicio->valor == valor){
				//cout<<"Valor ja existe!" << endl;
				return true;
			}else{
				inicio = inicio->prox;
			}
			//cout<<"Nenhum valor encontrado!" << endl;
			return false;
		}	
	}
}*/

void inserirInicio(int valor){
	bool existe = buscar(valor);
	if(existe == false){	   
		Elemento *novo = new Elemento;
		novo->valor = valor;
		if(inicio == NULL){
			inicio = novo;
			fim = novo;
			fim->prox = NULL;
		}else{
			novo->prox = inicio;
			inicio = novo;
		}	
	}else{
		cout<<"O valor ja existe! " << endl;
	}
}

void inserirFim(int valor){	
	bool existe = buscar(valor);
	if(existe == false){
		Elemento *novo = new Elemento;
		novo->valor = valor;
		if(inicio == NULL){	
			inicio = novo;
			fim = novo;
			fim->prox = NULL;
		}else{
			fim->prox = novo;
			fim=novo;
			fim->prox = NULL;
		}	
	}else{
		cout<<"O valor ja existe! " << endl;
	}
}

void listar(){
	if(inicio == NULL){
		cout << "A lista esta vazia!" << endl;
	}else{
		Elemento *aux = inicio;
		while(aux!=NULL){
			cout << aux->valor << endl;
			aux = aux->prox;
		}
		delete aux;
	}
}

void deletar(int valor){
	int achou = 0;
	if(inicio == NULL){
		cout << "A lista esta vazia!" << endl;
	}else{
		Elemento *aux = inicio;
		Elemento *anterior = NULL;
		while(aux!=NULL){
			if(aux->valor == valor){
				achou += 1;
				if(aux == inicio){
					inicio = aux->prox;
					delete aux;
					aux = inicio;
				}else if(aux == fim){
					anterior->prox = NULL;
					fim = anterior;
					delete aux;
					aux = NULL;
				}else{
					anterior->prox = aux->prox;
					delete aux;
					aux = anterior->prox;
				}
			}else{
				anterior = aux;
				aux = aux->prox;
			}
		}
		delete aux, anterior;
		cout << "Foi deletado " << achou << " elementos"<<endl;
	}
}


int main(){
	
	criarLista();
	inserirInicio(10);
	inserirInicio(5);
	inserirInicio(10);
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
