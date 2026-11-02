#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n, target;
    cout << "Enter Size: ";
    cin >> n;

    int arr[100];
    cout << "Enter The Array Elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    /*Problem: Move all Zeros To end */
    /*
    Brute Froce: T.C-O(n) & S.C-O(n)
    1. First Iterate to store all non-zeros number in temp varaible
    2. Then put all non-zeros number in front of the orginal array
    3. And Then fill remaining places with zero
    */
    vector<int>temp;
   //Store All non-zero number
    for(int i=0;i<n;i++){
        if(arr[i] != 0)
        temp.push_back(arr[i]);
    }
   //fill non zero number in front
    for(int i=0;i<temp.size();i++){ //temp.size()--> jitna non-zero number hai temp ke andar utna tak to fill karna hai
        arr[i] = temp[i];
    }
   //fill zero in last
    for(int i = temp.size();i<n;i++){ // baki remaining place mean temp.size() se jitna place khali hai usme zero varo
        arr[i] = 0;
    }

   //Print Array
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }


   /*
   Optimal:
   1. Find Zero first and Assign the j
   2. start iteration with i from j+1 and compare with j 
   3. if i indicate non-zero number the swap it with j.
   4. move j in next index
   */
    int j=-1;
    //step-1
    for(int i=0;i<n;i++){
        if(arr[i] == 0){
            j=i; //j contain zero
            break;
        }
    }

    //step-2
    for(int i=j+1;i<n;i++){
        if(arr[i] != arr[j]){
            swap(arr[i],arr[j]);
            j++;
        }
    }

    //step-3: Print
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}
