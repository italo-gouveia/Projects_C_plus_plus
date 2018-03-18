 #include <iostream>
 #include <stdlib.h>
 using namespace std;

 int main(){
    int alunos=10, provas=2;
    float notas[alunos][provas], medias[alunos];
    int i,j;

    for(i=0; i<alunos; i++){
        for(j=0;j<provas; j++){
            cout<<"Aluno "<<i+1<<" Prova "<<j+1<<" - Digite a nota: ";
            cin>>notas[i][j];
        }
    }

    for(i=0;i<alunos;i++){
        medias[i]=0.0;
        for(j=0;j<provas;j++){
            medias[i]=medias[i]+notas[i][j];
        }
        medias[i]=medias[i]/provas;
    }
    for (i=0; i<alunos;i++){
        cout<<"Aluno "<<i+1<<" Media = "<<medias[i]<<endl;
    }
    return 0;
}
