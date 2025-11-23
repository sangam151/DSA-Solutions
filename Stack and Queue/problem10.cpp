// PreFix to InFix
#include <bits/stdc++.h>
using namespace std;
string prefixToInfix(string prefix)
{
    stack<string> s;
    int n = prefix.size();
    // Tranverse the postfix expression from left to right
    for (int i = n-1; i >= 0; i--)
    {
        char c = prefix[i];
        // If character is operand push it to stack
        if (isalnum(c))
        {
            s.push(string(1, c));
        }
        else
        {
            string op1 = s.top();
            s.pop();
            string op2 = s.top();
            s.pop();
            // form the new infix expression and push back to stack
            s.push("(" + op1 + c + op2 + ")");
        }
    }
    return s.top();
}
int main()
{
    string prefix = "*-A/BC-/AKL";
    cout << "Infix Expression: " << prefixToInfix(prefix) << endl;
    return 0;
}