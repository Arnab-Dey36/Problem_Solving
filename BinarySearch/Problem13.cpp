#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;



int main(){
    int n,k;

    cout<<"Enter The Value of n: ";
    cin>>n;

    vector<int>arr(n);
    cout<<"Enter Elements: ";
    for(int i =0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"Enter The Value of K: ";
    cin>>k;

    /*Problem: Allocate Books or Book Allocation 
    Explanation: There are m number of student and the task is to allocate all the books to the students. Allocate books in such a way that:
    1.Each student gets at least one book.
    2.Each book should be to only one student.
    3.Book allocation should be in a Contiguous manner
    4. The goal is: you have to allocate the books to m students such that the max number of pages assigned to a student is minimum.*/

    /** Algorithm:
     * 1. Check the edge case: If the number of books is less than the number of students, allocation is impossible
     * 2. Set the low = max_element(arr) and high = sum of all pages.
     * 3. While low <= high:
     *    - Calculate mid = low + (high - low) / 2.
     *    - Check whether it is possible to allocate books to m students with a maximum limit of mid pages per student.
     *    - If it is possible, store mid as the answer and try a smaller number of pages: high = mid - 1.
     *    - Otherwise, try a larger number of pages: low = mid + 1.
     * 4. Return the minimum number of pages found.
    */

    long long st = 0,end = 0,ans =-1;

    //Handel edge case: if number of student > number of books se then allocation not possible
    if(k>n) return -1;

    for(int i = 0;i<n;i++){
        st = max(st,(long long) arr[i]);
        end += arr[i];
    }
    
    while (st<=end)
    {
       int mid = st+(end-st)/2;

       int counStudents = 1;
       long long pageDistribute = 0;

       for(int i = 0;i<n;i++){
        pageDistribute += arr[i];
        if (pageDistribute>mid)
        {
            counStudents++;
            pageDistribute = arr[i];
        }
        
       }

       if(counStudents<=k){
        ans = mid;
        end = mid-1;
       }
       else st = mid+1;
    }
    
    cout<<ans;
    
}