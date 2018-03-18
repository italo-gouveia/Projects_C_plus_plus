#include <iostream>

using namespace std;

int main(){
	int horasExtras, horasFalt;
	float bonificacao;
	
	cout<<"Informe a quantidade de horas extras: ";
	cin>>horasExtras;
	
	cout<<"Informe a quantidade de horas faltadas: ";
	cin>>horasFalt;
	
	bonificacao = (float)horasExtras/3 * horasFalt;
	
	if(bonificacao < 600){
		cout<<"O valor da bonficacao sera de 100 reias";
	}else if(bonificacao < 1200){
		cout<<"O valor da bonificacao sera de 200 reais"; 
	}else if(bonificacao < 1800){
		cout<<"O valor da bonificacao sera de 300 reais";
	}else if(bonificacao < 2400){
		cout<<"O valor da bonificacao sera de 400 reais";
	}else{
		cout<<"O valor da bonificacao sera de 500 reais";
	}
	
	return 0;
}