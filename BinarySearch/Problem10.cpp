#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int n,h;

    cout<<"Enter The Value of n: ";
    cin>>n;

    vector<int>piles(n);
    cout<<"Enter Elements: ";
    for(int i =0;i<n;i++){
        cin>>piles[i];
    }
    cout<<"Enter The Value of h: ";
    cin>>h;


    /*Problem: Koko Eating Bananas
    Explain: Return the min integer k such that Koko can eat all the bananas within h hours.
    where k is the number of bananas Koko can eat per hour and h is the number of hours available.*/

    /** Algorithm:
     Algorithm: Binary Search on Answer
    1. Initialize start = 1 and end = max(piles), where max(piles) is the maximum number of bananas in any pile.
    2. Initialize ans = end to store the minimum eating speed.
    3. While start <= end:
    - Calculate mid = start + (end - start) / 2. Here, mid represents Koko's eating speed in bananas per hour.
    - Initialize hours = 0.
    - Traverse each pile and calculate the hours required to finish it using ceil(pile / mid). Add these hours to hours.
    - If hours <= h, Koko can finish all bananas within the given time. Store mid in ans and set end = mid - 1 to search for a smaller speed.
    - Otherwise, set start = mid + 1 to search for a higher speed.
    4. Return ans, the minimum eating speed required to finish all bananas within h hours.
     */

    int start = 1;
    int end = *max_element(piles.begin(), piles.end());
    int ans = INT_MAX;

    while (start <= end) {

        int mid = start + (end - start) / 2;
        long long total_hours = 0;

        // Calculate total hours at speed mid
        for (int pile : piles) {
            total_hours += (pile + (long long)mid - 1) / mid;
        }

        // If Koko can finish within h hours
        if (total_hours <= h) {
            ans = mid;       // Store possible answer
            end = mid - 1;   // Try a smaller speed
        }
        else {
            start = mid + 1; // Increase eating speed
        }
    }

        cout << ans;
    
}