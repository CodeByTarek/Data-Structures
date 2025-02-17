#include<bits/stdc++.h>
using namespace std;

void Build_Max_Heap(int *arr,int n);
void MAX_HEAPIFY(int *arr,int i ,int n);

int main(){
    int arr[5];
    int arr1[10];
    int i,j,n,length=0,count=0;

    cout<<"Enter the input: ";
    for(i=0; ;i++){
         cin>>arr[i];
         if(arr[i]==-1){
            break;
         }
         count++;
         Build_Max_Heap(arr,count);
         for(j=0;j<count;j++){
            cout<<arr[j]<<" ";
         }
         cout<<endl;
    }



}
void MAX_HEAPIFY(int *arr,int i ,int n){
    int l,r,largest,temp;
    l=(2*i)+1;
    r=(2*i)+2;

    if(l<n && arr[l] > arr[i]){
        largest=l;
    }
    else{
        largest=i;
    }
    if(r<n && arr[r]>arr[largest]){
        largest=r;
    }
    if(largest!=i){
        temp=arr[i];
        arr[i]=arr[largest];
        arr[largest]=temp;
        MAX_HEAPIFY(arr,largest,n);
    }
    //MAX_HEAPIFY(arr,largest,n);
}

void Build_Max_Heap(int *arr,int n){
 //int n = sizeof(arr)/sizeof(arr[0]);
 //cout<<n<<endl;
 int i;

 for(i=(n/2)-1 ; i>=0 ; i--){
    MAX_HEAPIFY(arr,i,n);
 }
}



