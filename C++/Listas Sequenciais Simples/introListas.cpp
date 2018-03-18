#include <iostream>
#include <cstdlib>
#define tam 5

using namespace std;

int buscar(int vetor[], int valor, int total){
	int i = 0;
	//indiceValor inicializa com -1 ou seja, uma posição que não existe, caso não seja encontrado nenhum valor pela função
	//a execução do programa nem entra na lógica do while e já retorna para quem chamar a função o indiceValor = -1, ou seja
	//retorna que não há nenhum valor
	int indiceValor = -1;
	//enquando i for menor que o total de valores do vetor vai executar a seguinte lógica:
	while(i < total){
		//se na posição i do vetor for igual ao valor buscado
		if(vetor[i] == valor){
			//o indiceValor receberá a posição i e o i irá receber o total para que saia da execução do while
			//então o valor que será retornado da função buscar será agora o indice aonde o valor procurado foi encontrado
			indiceValor = i;
			i = total;
		}else{
			//caso a posição i não seja igual o valor buscado o i será incrementado para que seja verificado na próxima posição se o valor está lá
			i=i+1;
		}
	}
	return indiceValor;
}

//o inserir precisa passar o ponteiro de total por referência, pois o total será alterado
void inserir(int vetor[], int valor, int *total){
	if(*total < tam){
		//se a função buscar não encontrar o valor(posição -1)
		if(buscar(vetor, valor, *total) == -1){
			vetor[*total] = valor;
			//o valor da variável no ponteiro total é incrementado
			*total+=1;
			cout << "inserido com sucesso!" << endl;
		}else{
			cout << "O valor ja existe" << endl;
		}
	}else{
		cout << "Nao eh possivel adicionar mais na lista" << endl;
	}
}

//o remover precisa passar o ponteiro de total por referência, pois o total será alterado
void remover(int vetor[], int valor, int *total){
	//se o valor contido na variável do ponteiro total for diferente de 0
	if(*total != 0){
		//indice recebe o indice retornado da função buscar
		int indice = buscar(vetor, valor, *total);
		//se o valor desse indice existir(posicao != -1)
		if(indice != -1){
			//int valorRecuperado = vetor[indice];
			//for vai iterando até encontrar o indice aonde o valor será removido
			for(int i=0; i < *total; i++){
				//o indice do vetor irá receber o indice do vetor+1 isso fará com que todos os outros valores que estiverem
				//à frente da posição removida irão voltar uma posição no vetor.
				vetor[i] = vetor[i+1];
			}
			//após a execução do for, o valor do total será decrementado/diminuido já que um dos valores foi removido, o total precisa diminuir
			*total-=1;
			cout<<"Valor removido com sucesso !" <<endl;
		}else{
			cout<<"O elemento não está na lista! "<<endl;
		}
	}else{
		cout<<"Não há nenhum valor para ser removido! "<<endl;
	}
}

int main(){
	
	int total = 0;
	int vetor[5];
	
	//no inserir e no remover é passado o endereço de total para a função para que o valor do 
	//total seja alterado diretamente no valor da variável contida no endereço
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
