 #include <iostream>
 using namespace std;

 int main (void){
        int opcao;do
        {
         cout<<"\t\t\nMenu de Opcoes\n";
         cout<<"0. Sair\n";
         cout<<"1. Alo Mundo\n";
         cout<<"2. Falar Oi\n";
         cout<<"3. Repetir o menu\n";
         cout<<"4. Ler mais uma vez o menu\n";
         cout<<"Sua opcao: ";
         cin>>opcao;

         switch(opcao) {
                case 0:
                 system("cls");
                 cout<<"Tchau ...\n";
                 break;
                case 1:
                 system("cls");
                 cout<<" Alo Mundo! \n";
                 break;
                case 2:
                 system("cls");
                 cout<<" Oi! \n";
                 break;
                case 3:
                case 4:
                 system("cls");
                 break;
                default:
                 system("cls");
                 cout<<"Op��o invalida! Tente novamente.\n";
            }
        } while(opcao!=0);
 }
