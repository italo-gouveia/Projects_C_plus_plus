#include <iostream>

using namespace std;

int main()
{
	float produto;
	float novoValor;
	
	cout<<"Digite o valor do produto ";
	cin>>produto;
	
	if(produto < 50){
		novoValor = produto + ((produto/100) * 5);
		cout<<novoValor;
	}else if(produto < 120){
		novoValor = produto + ((produto/100) * 10);
		cout<<novoValor;
	}else{
		novoValor = produto + ((produto/100) * 15);
		cout<<novoValor;
	}
	
	if(novoValor < 80){
		cout<<"barato";
	}else if(novoValor < 120){
		cout<<"normal";
	}else if(novoValor < 200){
		cout<<"caro";
	}else{
		cout<<"muito caro";
	}
	
	return 0;
}