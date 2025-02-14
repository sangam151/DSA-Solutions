//find lexicographical permutation by using c++ build in function

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
   vector<int> arr = {1,3,2};
    
    next_permutation(arr.begin(),arr.end());//using in-built function of C++
    
    cout<<arr[0]<<" "<<arr[1]<<" "<<arr[2];
    
    return 0;
}

