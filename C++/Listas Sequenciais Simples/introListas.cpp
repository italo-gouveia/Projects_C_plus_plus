#include <iostream>
#include <cstdlib>
#define tam 5

using namespace std;

int buscar(int vetor[], int valor, int total){
	int i = 0;
	//indiceValor inicializa com -1 ou seja, uma posi��o que n�o existe, caso n�o seja encontrado nenhum valor pela fun��o
	//a execu��o do programa nem entra na l�gica do while e j� retorna para quem chamar a fun��o o indiceValor = -1, ou seja
	//retorna que n�o h� nenhum valor
	int indiceValor = -1;
	//enquando i for menor que o total de valores do vetor vai executar a seguinte l�gica:
	while(i < total){
		//se na posi��o i do vetor for igual ao valor buscado
		if(vetor[i] == valor){
			//o indiceValor receber� a posi��o i e o i ir� receber o total para que saia da execu��o do while
			//ent�o o valor que ser� retornado da fun��o buscar ser� agora o indice aonde o valor procurado foi encontrado
			indiceValor = i;
			i = total;
		}else{
			//caso a posi��o i n�o seja igual o valor buscado o i ser� incrementado para que seja verificado na pr�xima posi��o se o valor est� l�
			i=i+1;
		}
	}
	return indiceValor;
}

//o inserir precisa passar o ponteiro de total por refer�ncia, pois o total ser� alterado
void inserir(int vetor[], int valor, int *total){
	if(*total < tam){
		//se a fun��o buscar n�o encontrar o valor(posi��o -1)
		if(buscar(vetor, valor, *total) == -1){
			vetor[*total] = valor;
			//o valor da vari�vel no ponteiro total � incrementado
			*total+=1;
			cout << "inserido com sucesso!" << endl;
		}else{
			cout << "O valor ja existe" << endl;
		}
	}else{
		cout << "Nao eh possivel adicionar mais na lista" << endl;
	}
}

//o remover precisa passar o ponteiro de total por refer�ncia, pois o total ser� alterado
void remover(int vetor[], int valor, int *total){
	//se o valor contido na vari�vel do ponteiro total for diferente de 0
	if(*total != 0){
		//indice recebe o indice retornado da fun��o buscar
		int indice = buscar(vetor, valor, *total);
		//se o valor desse indice existir(posicao != -1)
		if(indice != -1){
			//int valorRecuperado = vetor[indice];
			//for vai iterando at� encontrar o indice aonde o valor ser� removido
			for(int i=0; i < *total; i++){
				//o indice do vetor ir� receber o indice do vetor+1 isso far� com que todos os outros valores que estiverem
				//� frente da posi��o removida ir�o voltar uma posi��o no vetor.
				vetor[i] = vetor[i+1];
			}
			//ap�s a execu��o do for, o valor do total ser� decrementado/diminuido j� que um dos valores foi removido, o total precisa diminuir
			*total-=1;
			cout<<"Valor removido com sucesso !" <<endl;
		}else{
			cout<<"O elemento n�o est� na lista! "<<endl;
		}
	}else{
		cout<<"N�o h� nenhum valor para ser removido! "<<endl;
	}
}

int main(){
	
	int total = 0;
	int vetor[5];
	
	//no inserir e no remover � passado o endere�o de total para a fun��o para que o valor do 
	//total seja alterado diretamente no valor da vari�vel contida no endere�o
	inserir(vetor, 5, &total);
	inserir(vetor, 5, &total);
	inserir(vetor, 10, &total);
	inserir(vetor, 9, &total);
	inserir(vetor, 50, &total);
	inserir(vetor, 60, &total);
	inserir(vetor, -100, &total);
	remover(vetor, 10, &total);
	
	int indice = buscar(vetor, 60, total);
	if(indice != -1){
		cout << "indice: " << indice << endl;
		cout << "valor: " << vetor[indice] << endl;
	}else{
		cout << "O valor nao existe!" << endl;
	}
	
	return 1;
}
