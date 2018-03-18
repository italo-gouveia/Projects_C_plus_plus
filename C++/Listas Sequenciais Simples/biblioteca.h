#include <iostream>
#include <cstdlib>
#define tam 3

using namespace std;

struct Pessoa{
	string nome;
	int idade;
};

void inserir(Pessoa *vetor){
	for(int i = 0; i < tam; i++){
		cout << "Digite um nome: ";
		cin >> vetor[i].nome;
		cout << "Digite um numero: ";
		cin >> vetor[i].idade;
	}
}

void imprimir(Pessoa *vetor){
	for(int i = 0; i < tam; i++){
		cout << "vetor[" << i << "]: " << vetor[i].nome << endl;
		cout << "vetor[" << i << "]: " << vetor[i].idade << endl;
	}
}
