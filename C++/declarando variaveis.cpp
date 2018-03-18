#include <iostream>

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int n1, n2, opcao; 
	
	cout<<"Digite um valor ";
	cin>>n1;
	
	cout<<"Digite outro valor ";
	cin>>n2;
	
	cout<<"Digite a operacao ";
	cout<<"1 - Soma ";
	cout<<"2 - Subtracao ";
	cout<<"3 - Divisao ";
	cout<<"4 - Multiplicacao ";
	cin>>opcao;
	
	switch(opcao)
	{
	case 1:
		cout<< (float) n1+n2;
		break;
	case 2:
		cout<< (float) n1-n2;
		break;
	case 3:
		cout<< (float) n1/n2;
		break;
	case 4:
		cout<< (float) n1*n2;
		break;
	default:
		break;
	}
	
	

	return 0;
}
