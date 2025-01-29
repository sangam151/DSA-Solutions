#include<bits/stdc++.h>
using namespace std;
int main()
{
    /*auto it=v.begin() is equivalent to 
    vector<int>::iterator it= v.begin();
*/
int i;
    vector<int> v;
    for(i=0;i<10;i++)
    {
        v.push_back(i);
    }
    for(auto it=v.begin();it!=v.end();it++)
    {
        cout<<*it<<" ";
    }
    v.emplace_back(1500);
    v.push_back(155);
    cout<<endl;
    for(i=0;i<v.size();i++)
    {
        cout<<v[i]<<" ";
    }
    /*
    cout<<endl;
    cout<<"front element of the vector "<<v.front()<<endl;
    cout<<"last element of the vector "<<v.back()<<endl;
    cout<<"the size  of the vector "<<v.size()<<endl;
    cout << "Deleting element from the end: " << v[v.size() - 1]<<endl;
    v.pop_back();
    cout<<"printing the value after removing the last element"<<endl;
    for(int i=0;i<v.size();i++)
    {
        cout<<v[i];
    }
    cout<<endl;
    v.insert(v.begin(),5);
    v.erase(v.begin());
    cout<<"the first element is "<<v[0]<<endl;
    if(v.empty())
    {
        cout<<"vector is empty"<<endl;
    }
    else{
        cout<<"vector is not empty"<<endl;
    }
    v.clear();
    cout<<"size of vector is"<<v.size()<<endl;
    */
    return 0;
}