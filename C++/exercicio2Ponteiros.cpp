#include <iostream>

using namespace std;

int main(int argc, char** argv)
{
	int y, *p, x;//declarei a variavel y e x e o ponteiro p
	y = 0; //atribui o valor 0 a variável y
	cout<<"valor de y: " << y <<endl;
	cout<<"endereco de memoria de y: "<< &y << endl;
	
	
	cout<<p <<endl;
	cout<<"valor da variavel no ponteiro p: " << *p <<endl;
	cout<<"endereco de memoria de p: " << &p <<endl;
	
	p = &y; //atribui o endereço de memória de y ao valor da variavel do ponteiro p
	//ao receber o endereço de memória de y se fizermos a operação *p(que verifica o valor da variável p)
	//a operação irá passar pelo endereço de memória de p e ver que ele está apontando para o endereço de memória de y
	//e verificar que o endereço de memória de y aponta para um valor 0 
	//que foi declarado anteriormente pela atribuição y = 0 na linha 8 
	//endereco de memoria de p não muda apenas recebe um valor ponteiro para outro endereço de memória
	
	cout<<p<<endl;
	cout<<"valor da variavel no ponteiro p: " << *p <<endl;
	cout<<"endereco de memoria de p: " << &p <<endl;
	
	x = *p;//atribuindo a x o valor da variável p
	//o endereço de memória de x não muda
	cout<<"valor da variavel de x: " << x <<endl;
	cout<<"endereco de memoria de x: "<< &x <<endl;
	
	x = 4;//atribuindo a variavel x o valor 4
	cout<<"valor da variavel de x: " << x <<endl;
	
	(*p)++;//pegando o valor da variável do ponteiro p e incrementando ela com o operador ++
	//assim o valor se tornará 1, o endereço de memória não muda
	cout<<p <<endl;
	cout<<"valor da variavel no ponteiro p: " << *p <<endl;
	cout<<"endereco de memoria de p: " << &p <<endl;
	cout<<"o valor de y se tornou: "<< y <<endl;
	x--;//decrementando o valor da variável x, assim o valor se tornará 3
	//o endereço de memória não muda
	(*p) += x;//pegando o valor da variável do ponteiro p e somando com o valor da variável x, tornando se assim 4
	cout << "valor final da execucao do programa: "<<y;//como p recebeu o endereço de memória de y então
	//ao modificar o valor de p, modifica-se também o valor de y
	
	return(0);	
}