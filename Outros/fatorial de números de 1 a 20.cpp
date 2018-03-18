 #include <iostream>
 #include <stdlib.h>
 using namespace std;

 int main(){
    int matriz[3][3];
    int linha, coluna;

        system("cls");
 for(linha = 0 ; linha < 3 ; linha++)
    for(coluna = 0 ; coluna<3 ; coluna++){
        cout<<"Posicao["<<linha+1<<"]["<<coluna+1<<"]: ";
        cin>>matriz[linha][coluna];
    }
    
 for(linha = 0 ; linha<3 ; linha++){
    for(coluna = 0 ; coluna < 3 ; coluna++)
        cout<<matriz[linha][coluna]<<" ";
    cout<<"\n";
 }
 return 0;
}
