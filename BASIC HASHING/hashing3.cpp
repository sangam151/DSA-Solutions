//Character Hashing 
#include<iostream>
using namespace std;

int main(){
    string s;
    cout<<"please enter the string"<<endl;
    cin>>s;
    int hash[256]={0};//we know the number of character exist is 256
    for(int i=0;i<s.size();i++)
    {
        hash[s[i]]++;


    }
    int q;
    cout<<"please enter the number of queries"<<endl;
    cin>>q;
    while(q--)
    {
        cout<<"enter the character to find how many times does it appear"<<endl;
        char c;
        cin>>c;
        cout<<"the character appears "<<hash[c]<<" times"<<endl;
    }
   
    return 0;
}