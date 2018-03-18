#include <iostream>

using namespace std;

int main()
{
	float num1, num2;
	int opcao;
	
	cout<<"Digite o primeiro numero: ";
	cin>>num1;
	
	cout<<"Digite o segundo numero "; 
	cin>>num2;
	
	cout<<"Informe a operação desejada ";
	cout<<"1 - Media dos numeros ";
	cout<<"2 - Diferenca entre os numeros ";
	cout<<"3 - Produto entre os numeros ";
	cout<<"4 - Divisao entre os numeros ";
	cin>>opcao;
	
	switch(opcao)
	{
	case 1:
		cout<<(num1+num2)/2;
		break;
	case 2:
		if(num1 > num2){
			cout<<num1-num2;
		}else{
			cout<<num2-num1;
		}
		break;
	case 3:
		cout<<num1*num2;
		break;
	case 4:
		if(num2 == 0){
			cout<<"Impossivel dividir por zero";
		}else{
			cout<<num1/num2;
		}
	default:
		break;
	}
		
	system('PAUSE');
	return 0;
}