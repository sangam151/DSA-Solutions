// Infix to prefix conversion
#include <bits/stdc++.h>
using namespace std;
// Function to return precedence of operators
int prec(char c)
{
    if (c == '^')
        return 3;
    else if (c == '/' || c == '*')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}
// The function that convert Infix to postfix Expression
string infixToPostFix(string s)
{
    stack<char> st;
    string result;
    for (int i = 0; i < s.length(); i++)
    {
        char c = s[i];
        // If the scanned character is an operand add it to output string
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= 0 && c <= 9))
        {
            result += c;
        }
        // If scanned character is an ( push it to the stack
        else if (c == '(')
            st.push('(');
        else if (c == ')')
        {
            while (st.top() != '(')
            {
                result += st.top();
                st.pop();
            }
            st.pop();
        }
        else
        {
            if (s[i] == '^')
            {
                while (!st.empty() && prec(s[i]) <= prec(st.top()))
                {
                    result += st.top();
                    st.pop();
                }
            }
            else
            {
                while (!st.empty() && prec(s[i]) < prec(st.top()))
                {
                    result += st.top();
                    st.pop();
                }
            }
            st.push(c);
        }
    }
    while (!st.empty())
    {
        result += st.top();
        st.pop();
    }
    return result;
}
void infixToPrefix(string infix)
{
    int l = infix.size();
    reverse(infix.begin(), infix.end());
    for (int i = 0; i < l; i++)
    {
        if (infix[i] == '(')
        {
            infix[i] = ')';
            i++;
        }
        else if (infix[i] == ')')
        {
            infix[i] = '(';
            i++;
        }
    }
    string prefix = infixToPostFix(infix);
    reverse(prefix.begin(), prefix.end());
    cout<<"Prefix Expression: "<<prefix<<endl;
}
int main()
{
    string exp = "(p+q)*(c-d)";
    cout << "Infix expression" << exp << endl;
    infixToPrefix(exp);
    return 0;
}