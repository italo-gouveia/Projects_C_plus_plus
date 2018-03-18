#include <iostream>

using namespace std;

int main(int argc, char** argv)
{
	int y, *p, x;//declarei a variavel y e x e o ponteiro p
	y = 0; //atribui o valor 0 a vari�vel y
	cout<<"valor de y: " << y <<endl;
	cout<<"endereco de memoria de y: "<< &y << endl;
	
	
	cout<<p <<endl;
	cout<<"valor da variavel no ponteiro p: " << *p <<endl;
	cout<<"endereco de memoria de p: " << &p <<endl;
	
	p = &y; //atribui o endere�o de mem�ria de y ao valor da variavel do ponteiro p
	//ao receber o endere�o de mem�ria de y se fizermos a opera��o *p(que verifica o valor da vari�vel p)
	//a opera��o ir� passar pelo endere�o de mem�ria de p e ver que ele est� apontando para o endere�o de mem�ria de y
	//e verificar que o endere�o de mem�ria de y aponta para um valor 0 
	//que foi declarado anteriormente pela atribui��o y = 0 na linha 8 
	//endereco de memoria de p n�o muda apenas recebe um valor ponteiro para outro endere�o de mem�ria
	
	cout<<p<<endl;
	cout<<"valor da variavel no ponteiro p: " << *p <<endl;
	cout<<"endereco de memoria de p: " << &p <<endl;
	
	x = *p;//atribuindo a x o valor da vari�vel p
	//o endere�o de mem�ria de x n�o muda
	cout<<"valor da variavel de x: " << x <<endl;
	cout<<"endereco de memoria de x: "<< &x <<endl;
	
	x = 4;//atribuindo a variavel x o valor 4
	cout<<"valor da variavel de x: " << x <<endl;
	
	(*p)++;//pegando o valor da vari�vel do ponteiro p e incrementando ela com o operador ++
	//assim o valor se tornar� 1, o endere�o de mem�ria n�o muda
	cout<<p <<endl;
	cout<<"valor da variavel no ponteiro p: " << *p <<endl;
	cout<<"endereco de memoria de p: " << &p <<endl;
	cout<<"o valor de y se tornou: "<< y <<endl;
	x--;//decrementando o valor da vari�vel x, assim o valor se tornar� 3
	//o endere�o de mem�ria n�o muda
	(*p) += x;//pegando o valor da vari�vel do ponteiro p e somando com o valor da vari�vel x, tornando se assim 4
	cout << "valor final da execucao do programa: "<<y;//como p recebeu o endere�o de mem�ria de y ent�o
	//ao modificar o valor de p, modifica-se tamb�m o valor de y
	
	return(0);	
}