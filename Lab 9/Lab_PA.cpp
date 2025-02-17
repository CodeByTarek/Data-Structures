#include<bits/stdc++.h>
using namespace std;

void Build_Max_Heap(int *arr, int n);
void MAX_HEAPIFY(int *arr,int i ,int n);

int main(){
    int arr[]={4,1,3,2,16,9,10,14,8,7};
    int arr1[10];
    int i,n,length=0;


    cout<<"Enter the size of array"<<endl;
    cin>>length;
    cout<<"Enter input: ";
     for(i=0;i<length;i++){
        cin>>arr1[i];
    }
     Build_Max_Heap(arr1,length);
     cout<<endl<<"Output: ";
     for(i=0; i<length ; i++){
        cout<<arr1[i]<<" " ;
     }


    /*n=sizeof(arr)/sizeof(arr[0]);
    //cout<<n<<endl;
    //int m;
    Build_Max_Heap(arr,n);


    for(i=0;i<sizeof(arr)/sizeof(arr[0]);i++){
        cout<<arr[i]<<" " ;
    }*/

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


