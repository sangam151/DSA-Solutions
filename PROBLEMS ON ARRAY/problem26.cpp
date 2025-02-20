//print the matrix in spiral manner
#include<bits/stdc++.h>
using namespace std;
vector<int> printspiral(vector<vector<int>> mat)
{
    vector<int> spiral;
    int n=mat.size();
    int m=mat[0].size();
    int left=0,top=0,buttom=n-1,right=m-1;
    while(left<=right && top<=buttom)
    {
        for(int i=left;i<=  right;i++)
        {
            spiral.push_back(mat[top][i]);
           
        }
        top++;

        for(int i=top;i<=buttom;i++)
        {
            spiral.push_back(mat[i][right]);
            
        }
        right--;
        if(top<=buttom)
        {
        for(int i=right;i>=left;i--)
        {
            spiral.push_back(mat[buttom][i]);
            
        }
        buttom--;}
        //for moving buttom to top
        if(left<=right)
        {
            for(int i=buttom;i>=top;i--)
            spiral.push_back(mat[i][left]);
            
        }
        left++;

    }
    return spiral;
}
int main(){
    vector<vector<int>> mat={{1,2,3,4},{5,6,7,8},{9,10,11,12}};
    vector<int> ans=printspiral(mat);
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
    return 0;
}