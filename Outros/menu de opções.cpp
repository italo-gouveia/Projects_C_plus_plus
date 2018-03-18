 #include <iostream>
 using namespace std;

 int main (void){
        long limite=20;
        long fatorial=1;

        for(int i=1;i<=limite;i++){
                fatorial=1;
                for(int j=2;j<=i;j++)
                        fatorial*=j;
                cout<<i<<"! = "<<fatorial<<endl;
        }
    return 0;
}
