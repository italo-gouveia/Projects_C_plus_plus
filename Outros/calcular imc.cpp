#include <iostream>
#include <cmath>
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(void){
	float peso, altura, imc;
	
	for (int n=1; n<=5; n++){
	
	/* Inicio da repetição*/
	cout<<"Digite o peso:";
	cin>>peso;
	cout<<"Digite a altura:";
	cin>>altura;
	
	imc = peso/(pow(altura,2));
	
	if (imc<17){
	    cout<<"\n\nIMC="<<imc<<".Situacao: Muito abaixo do peso"<<endl;
	}
	if (imc>17 &&imc<=18.49){
		cout<<"\n\nIMC="<<imc<<".Situacao: Abaixo do peso"<<endl;
	}
	if (imc>=18.5 &&imc<=24.99){
		cout<<"\n\nIMC="<<imc<<".Situacao: Peso Normal"<<endl;
	}
	if (imc>25 &&imc<=29.99){
		cout<<"\n\nIMC="<<imc<<".Situacao: Acima do peso"<<endl;
	}
	if (imc>=30 &&imc<=34.99){
		cout<<"\n\nIMC="<<imc<<".Situacao: Obesidade I"<<endl;
	}
	if (imc>=35 &&imc<=39.99){
		cout<<"n\nIMC="<<imc<<".Situacao: Obesidade II"<<endl;
	}
	if (imc>=40){
		cout<<"\n\nIMC="<<imc<<".Situacao: Obesidade III"<<endl;
	}
    }   
/* Final da repetição */

	return 0;
}
