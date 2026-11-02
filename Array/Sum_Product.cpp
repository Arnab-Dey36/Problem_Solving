#include<iostream>
using namespace std;

//Calculate Sum
int Sum(int arr[], int n){
    int sum =0;
    for(int i=0;i<n;i++){
        sum += arr[i];
    }
    return sum;
}

//Product
int Product(int arr[], int n){
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

    cout<<"Enter The Array Elements: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    cout<<"The Sum is: "<<Sum(arr,n);
    cout<<"The Product is: "<<Product(arr,n);
}