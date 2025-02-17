#include<bits/stdc++.h>
using namespace std;

void maxheapify(int arr[],int i,int n){
    int parent=i;
    int left=(2*i)+1;
    int right= (2*i)+2;
    if(left<n && arr[left]>arr[parent]){
        parent= left;
    }
    //else{parent=i;}
     if(right<n && arr[right]>arr[parent]){
        parent= right;
    }
    if(parent!=i){
        int temp;
        temp= arr[parent];
        arr[parent]= arr[i];
        arr[i]= temp;
        maxheapify(arr,parent,n);

    }


}

void buildheap(int arr[],int n){
    int start= (n/2)-1;
    int i;
    for(i=start;i>=0;i--){
          maxheapify(arr,i,n);
    }
}

int main(){
    int a[100];

    cout<<"Number of Inputs:"<<endl;
    int n;
    cin>>n;
    int i;
    for(i=0;i<n;i++){
        cin>>a[i];
    }

    buildheap(a,n);
    for(i=0;i<n;i++){
        cout<<a[i]<<" " ;
    }


}
