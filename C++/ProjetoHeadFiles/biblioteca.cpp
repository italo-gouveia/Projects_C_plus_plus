#include <iostream>
#include "biblioteca.h"

using namespace std;

void inserir(Pessoa *vetor){
	for(int i = 0; i < tam; i++){
		cout << "Digite o nome da pessoa: ";
		cin >> vetor[i].nome;
		cout << "Digite a idade da pessoa: ";
		cin >> vetor[i].idade;
	}
}

void imprimir(Pessoa *vetor){
	for(int i = 0; i < tam; i++){
		cout << "vetor[" << i << "]: " << vetor[i].nome<< endl;
		cout << "vetor[" << i << "]: " << vetor[i].idade<< endl;
	}
}
