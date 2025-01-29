#include<bits/stdc++.h>
using namespace std;
void reversearray(char s[],int c,char v[])
{
    int p1=0,p2=c-1;
    while(p1<p2)
    {
        swap(s[p1],s[p2]);
        p1++; p2--;
    }
    if(strcmp(s,v)==0)
    cout<<"the string is palindrome"<<endl;
    else
    cout<<"the string is not palindrome"<<endl;

}
int main(){
    char s[20];
    char v[20];
    cout<<"enter the string";
    cin.getline(s,100);
     cout<<s<<endl;
     strcpy(v,s);
    int c=strlen(s);
   
  reversearray(s,c,v);  
   
   
    return 0;
}