#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter The Size Of Array(height): ";
    cin >> n;

    // input array
    int height[100];
    cout << "Enter the Height of Container: ";
    for (int i = 0; i < n; i++)
    {
        cin >> height[i];
    }
    /*Problem: Container with Most Water*/

    /*
     Brute Froce:
     1. find all Possible Container And Uss Sare Possible container ke andar
     kitna water wo store kar sakte hai usko nikalo And uss Sare Water ko comapre
     karke max water calculate kar le.

     Question is How to find all possible container?
     -> Kisi bhi container ko banane ke liya ek left boundary chahiye aur ek right
     boundary chahiye.

     Kitna Water Store Kiya kaise Calculate kare: width * minHeight
                    width = j-i & minHeight = min(leftHeight, rightHeight)
    */
    // int maxWater = 0;
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = i + 1; j < n; j++)
    //     {
    //         int width = j - i;
    //         int minHeight = min(height[i], height[j]);
    //         int currWater = width * minHeight;

    //         maxWater = max(currWater,maxWater);
    //     }
    // }
    // cout<<maxWater;

    /* 
    Optimized: Using Two Pointer 
    Consider left and right two pointer
    left = 0 and right=n-1
    Now Problem is Which one moved how to Decide?
    -> if hight of left pointer is min then moved left one(left++) &
        if height of right pointer is min then moved right one(right++)
    
    Note: Water kitna store hoga usko control karta hai min height wala boundary
    chahe vo left me ho or right me ho.
    */

    int left=0,right=n-1,maxWater = 0;
    while(left<right){
        //calculate width
        int w = right - left;
        //calculate minHeight
        int h = min(height[left],height[right]);
        //calculate store water of each container
        int currWater = w*h;

        //find max water
        maxWater = max(currWater,maxWater);

        // move pointer
        if(height[left]<height[right]) left++;
        else right--;

    }
    cout<<maxWater;
}