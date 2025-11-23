// PostFix to InFix
#include <bits/stdc++.h>
using namespace std;
string postfixToInfix(string postfix)
{
    stack<string> s;
    int n = postfix.size();
    // Tranverse the postfix expression from left to right
    for (int i = 0; i < n; i++)
    {
        char c = postfix[i];
        // If character is operand push it to stack
        if (isalnum(c))
        {
            s.push(string(1, c));
        }
        else
        {
            string op2 = s.top();
            s.pop();
            string op1 = s.top();
            s.pop();
            // form the new infix expression and push back to stack
            s.push("(" + op1 + c + op2 + ")");
        }
    }
    return s.top();
}
int main()
{
    string postfix = "AB*C+";
    cout << "Infix Expression: " << postfixToInfix(postfix) << endl;
    return 0;
}