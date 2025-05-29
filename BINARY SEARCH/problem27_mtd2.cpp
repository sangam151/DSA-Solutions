//search in row and column  wise sorted matrix by optimal approach
#include <bits/stdc++.h> 
using namespace std;
bool searchElement(vector<vector<int>> matrix,int target)
{
    int n=matrix.size();
    int m=matrix[0].size();
    int row=0,column=m-1;
    //transverse the matrix from (0,m-1)
    while(row<n && column>=0)
    {
        if(matrix[row][column]==target) return true;
        if(matrix[row][column]<target) row++;
        else column--;
    }   
    return false;
} 
int main()
{
    vector<vector<int>> matrix={{1,4,7,11,15},{2,5,8,12,19},
    {3,6,9,16,12},{10,13,14,17,24},{18,21,23,26,30}};
    searchElement(matrix,8)==true? cout<<"True"<<endl : cout<<"False"<<endl;
    return 0;
}