//Largest Element Of the array by using vector sorting 
#include<bits/stdc++.h>
using namespace std;
int sortarray(vector<int>& arr)
{
    sort(arr.begin(),arr.end());
    return arr[arr.size()-1];
}
int main(){
    vector<int> arr1={5,3,2,4,1},arr2={9,8,4,5,6};
    cout<<"Largest Element of the array is arr1 "<<sortarray(arr1)<<endl;
    cout<<"Largest Element of the array is arr2 "<<sortarray(arr2)<<endl;
    

    return 0;
}