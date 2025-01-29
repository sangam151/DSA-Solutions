//Character Hashing 
#include<iostream>
using namespace std;

int main(){
    string s;
    cout<<"please enter the string"<<endl;
    cin>>s;
    int hash[26]={0};//this is applicable for lowercase letter because
    //we know number of lowercase letter is 26 otherwise see next file
    for(int i=0;i<s.size();i++)
    {
        hash[s[i]-'a']++;


    }
    int q;
    cout<<"please enter the number of queries"<<endl;
    cin>>q;
    while(q--)
    {
        cout<<"enter the character to find how many times does it appear"<<endl;
        char c;
        cin>>c;
        cout<<"the character appears "<<hash[c-'a']<<" times"<<endl;
    }
   
    return 0;
}