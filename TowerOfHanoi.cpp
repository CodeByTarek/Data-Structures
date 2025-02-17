#include <bits/stdc++.h>
using namespace std;


void towerOfHanoi(int n, char a , char c,char b);

int main(){
    int number;
    cin>>number;
    towerOfHanoi(number,'A','C','B');
    return 0;
}


void towerOfHanoi(int n,char fr, char to,char au){
    if(n==1){

        cout<<"Move Disk 1 from " << fr << " To "<< to<<endl;
        return;

    }

    towerOfHanoi(n-1,fr,au,to);
    cout<<"Move Disk "<<n<<" From "<< fr<< " To "<<to<<endl;
    towerOfHanoi(n-1,au,to,fr);
}
