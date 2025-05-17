/*Problem Statement:Given an array/list of length ‘N’, where the array/list represents the boards and each element
 of the given array/list represents the length of each board. Some ‘K’ numbers of painters are available to paint 
 these boards. Consider that each unit of a board takes 1 unit of time to paint. You are supposed to return the 
 area of the minimum time to get this job done of painting all the ‘N’ boards under the constraint that any 
 painter will only paint the continuous sections of boards.(brute force approach)*/
#include <bits/stdc++.h>
using namespace std;

int countPainters(vector<int> &boards, int time) {
    int n = boards.size(); //size of array.
    int painters = 1;
    long long boardsPainter = 0;
    for (int i = 0; i < n; i++) {
        if (boardsPainter + boards[i] <= time) {
            //allocate board to current painter
            boardsPainter += boards[i];
        }
        else {
            //allocate board to next painter
            painters++;
            boardsPainter = boards[i];
        }
    }
    return painters;
}

int findLargestMinDistance(vector<int> &boards, int k) {
    int low = *max_element(boards.begin(), boards.end());
    int high = accumulate(boards.begin(), boards.end(), 0);

    for (int time = low; time <= high; time++) {
        if (countPainters(boards, time) <= k) {
            return time;
        }
    }
    return low;
}

int main()
{
    vector<int> boards = {10, 20, 30, 40};
    int k = 2;
    int ans = findLargestMinDistance(boards, k);
    cout << "The answer is: " << ans << "\n";
    return 0;
}


