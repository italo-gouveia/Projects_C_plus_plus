#include<stdio.h>
#define MAX 100

//fibonacci usando recursão
//mostra todos os membros da sequencia
//renato_mack - 05/2006

int fibonacci(int *p){
	int fib;

	if (*p<=2) 
		return 1;
	else
		return fib=(*p-1)+(*p-2);
}

int main(){
	int v[MAX], n, i;

	printf("\t\t\tFIBONACCI\n\n");
	printf("Digite tamanho fibinacci\n");
	scanf("%d",&n);
	printf("Sequencia fibinacci:");
	for(i=1;i<=n;i++){
		v[i]=fibonacci(&i);
		printf("%d  ", v[i]);
	}
	printf("\n\n");
	return 0;
}