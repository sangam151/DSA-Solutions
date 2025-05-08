 //Binary search to find X in the sorted array recursive implementation
 #include<bits/stdc++.h>
 using namespace std;
 int binarysearch(vector<int> a,int target,int low,int high)
 {
    
    
    int mid=(low+high)/2;
    if(a[mid]==target)return mid;
    else if(target>a[mid]) return binarysearch(a,target,mid+1,high);
    else return binarysearch(a,target,low,mid-1);
    return -1;
    
 }
 int main()
 {
    vector<int> a={3,4,6,7,9,12,16,17};
    int target=6;
    int n=a.size();

    int ind=binarysearch(a,target,0,n-1);
    if(ind==-1)cout<<"The target is not present"<<endl;
    else
    cout<<"The target is at index "<<ind<<endl;


    return 0;
   
 }
 