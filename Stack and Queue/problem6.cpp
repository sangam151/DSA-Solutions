// Check For Balanced Parentheses
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> st; // stack to store open bracket
        for (auto it : s)
        {
            if (it == '(' || it == '{' || it == '[')
            {
                st.push(it);
            }
            else
            {
                if (st.empty())
                    return false;
                char ch = st.top();
                st.pop();
                // checking for matching pair
                if ((it == ')' && ch == '(') || (it == '}' && ch == '{') || (it == ']' && ch == '['))
                    continue;
                else
                    return false;
            }
        }
        return st.empty(); // True if bracket matched
    }
};
int main()
{
    Solution sol;
    string s = "()[{}()]";
    if (sol.isValid(s))
    {
        cout << "True" << endl;
    }
    else
    {
        cout << "False" << endl;
    }
    return 0;
}