#include<bits/stdc++.h>
using namespace std;
void buildheap(int arr[],int n);
void maxheapify(int arr[],int i,int n);
int main(){
    int a[100];


    int n=10;
    int count=0;
    int i;
    for(i=0;i<n;i++){
        cin>>a[i];

        buildheap(a,count);
        count++;
        int j;
        for(j=0;j<count;j++){
        cout<<a[j]<<" " ;
        j++;
        }
    }



}

void buildheap(int arr[],int n){
    int start= (n/2)-1;
    int i;
    for(i=start;i>=0;i--){
          maxheapify(arr,i,n);
    }
}

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

    }}
