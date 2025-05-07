#include <bits/stdc++.h>
using namespace std;

int getMaxElement(vector<int>& arr) {
    return *max_element(arr.begin(), arr.end()); // O(N) complexity
    //Here max_element return iterator pointing to largest element of the array
}

int main() {
    vector<int> arr1 = {2, 5, 1, 3, 0};
    vector<int> arr2 = {8, 10, 5, 7, 9};

    cout << "The Largest element in the array is: " << getMaxElement(arr1) << endl;
    cout << "The Largest element in the array is: " << getMaxElement(arr2) << endl;

    return 0;
}
