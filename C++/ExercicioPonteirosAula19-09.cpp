#include <iostream>

using namespace std;

struct Aluno{
	string nome, matricula;
	int idade;
	float n1, n2, media;
	
	void imprimir(){
		cout<<"nome: " << nome << endl;
		cout<<"matricula: " << matricula << endl;
		cout<<"idade: " << idade << endl;
		cout<<"primeira nota: " << n1 << endl;
		cout<<"segunda nota: " << n2 << endl;
		cout<<"media: " << media << endl;
	}
};
void alterar(Aluno *a){
	cout<< "digite deu nome: " << endl;
	cin>>a->nome;
	cout<< "digite sua matricula: " << endl;
	cin>>a->matricula;
	cout<< "digite sua idade: " << endl;
	cin>>a->idade;
	cout<<"digite a primeira nota: " << endl;
	cin>>a->n1;
	cout<<"digite a segunda nota: " << endl;	
	cin>>a->n2;
	a->media = (a->n1 + a->n2)/2;
	a->imprimir();
}

//criei essa função para verificar se os endereços de memória dos atributos da struct mudadaram
void verificarPonteiros(Aluno *a){
	cout<<"valor de ponteiro a->nome: " << a->nome<<endl;
	cout<<"Endereco de memoria de a->nome: " <<&a->nome<<endl;
	cout<<"valor de ponteiro a->matricula: " <<a->matricula<<endl;
	cout<<"Endereco de memoria de a->matricula: " <<&a->matricula<<endl;
	cout<<"valor de ponteiro a->idade: " << a->idade<<endl;
	cout<<"Endereco de memoria de a->idade: " <<&a->idade<<endl;
	cout<<"valor de ponteiro a->n1: " << a->n1<<endl;
	cout<<"Endereco de memoria de a->n1: " <<&a->n1<<endl;
	cout<<"valor de ponteiro a->n2: " << a->n2<<endl;
	cout<<"Endereco de memoria de a->n2: " <<&a->n2<<endl;
	cout<<"valor de ponteiro a->media: " << a->media<<endl;
	cout<<"Endereco de memoria de a->media: " <<&a->media<<endl;
}
int main(){
	
	Aluno a;
	 
	cout<< "digite deu nome: " << endl;
	cin>>a.nome;
	cout<< "digite sua matricula: " << endl;
	cin>>a.matricula;
	cout<< "digite sua idade: " << endl;
	cin>>a.idade;
	cout<<"digite a primeira nota: " << endl;
	cin>>a.n1;
	cout<<"digite a segunda nota: " << endl;	
	cin>>a.n2;
	a.media = (a.n1 + a.n2)/2;
	a.imprimir();
	verificarPonteiros(&a);
	
	int escolha;
	cout<<"voce deseja alterar os dados do aluno ? "<<endl;
	cout<<"se sim digite 1, se não, digite 2: "<<endl;
	cin>>escolha;
	
	if(escolha == 1){
		alterar(&a);	 
		verificarPonteiros(&a); 		
	}else if(escolha == 2){
		cout<<"tudo bem então, não irei alterar "<<endl;
	}else{
		cout<<"Valor invalido "<<endl;
	}
			
	return 0;
}