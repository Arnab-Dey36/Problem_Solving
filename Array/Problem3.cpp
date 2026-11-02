

/* Write The Program To calculate Sum and Product of all Numbers */

#include<iostream>
using namespace std;

//Sum
int Sum(int arr[],int n){
    int sum = 0;
    for(int i=0;i<n;i++){
        sum += arr[i];
    }
    return sum;
}

//Product
int Product(int arr[],int n){
    int result = 1;
    for(int i=0;i<n;i++){
        result *= arr[i];
    }
    return result;
}


int main(){
    int n;
    cout<<"Enter The Size: ";
    cin>>n;

    int arr[100];
    cout<<"Enter The Arrays Elements: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    cout<<"Sum Is: "<<Sum(arr,n)<<endl;
    cout<<"Product Is: "<<Product(arr,n);
}
