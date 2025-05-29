// matrix median by brute force appraoch                                   
#include<bits/stdc++.h>
using namespace std;

int median(vector<vector<int>> &matrix, int m, int n) {
    vector<int> lst;

    //traverse the matrix and
    //copy the elements to list:
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            lst.push_back(matrix[i][j]);
        }
    }

    //sort the list:
    sort(lst.begin(), lst.end());
    return lst[(m * n) / 2];
}

int main() {
    vector<vector<int>> matrix = {
        {1, 2, 3, 4, 5},
        {8, 9, 11, 12, 13},
        {21, 23, 25, 27, 29}
    };
    int m = matrix.size(), n = matrix[0].size();
    int ans = median(matrix, m, n);
    cout << "The median element is: " << ans << endl;
    return 0;
}
                                    
                                