 //Binary search to find X in the sorted array iterative implementation
 #include<bits/stdc++.h>
 using namespace std;
 int binarysearch(vector<int> a ,int target)
 {
    int n=a.size();//size of array
    int low=0,high=n-1;
    //perform the steps
    while(low<=high)
    {
        int mid=(low+high)/2;
        if(a[mid]==target) return mid;
        else if(target>a[mid])low=mid+1;
        else high=mid-1;
    }
    return -1;

 }
 int main()
 {
    vector<int> a={3,4,6,7,9,12,16,17};
    int target=6;
    int ind=binarysearch(a,target);
    if(ind==-1)cout<<"The target is not present"<<endl;
    else
    cout<<"The target is at index "<<ind<<endl;


    return 0;
 }
