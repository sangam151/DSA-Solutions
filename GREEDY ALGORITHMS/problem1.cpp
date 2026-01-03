/*Assign Cookies || Memoization || DP problem
Consider a scenario where a teacher wants to distribute cookies to students, with each student receiving at
most one cookie. Given two arrays, student and cookie, the ith value in the student array describes the minimum
size of cookie that the ith student can be assigned. The jth value in the cookie array represents the size of the jth
 cookie. If cookie[j] >= student[i], the jth cookie can be assigned to the ith student. Maximize the number of
  students assigned with cookies and output the maximum number.*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int findContentChildren(vector<int> &student, vector<int> &cookie)
    {
        sort(student.begin(), student.end());
        sort(cookie.begin(), cookie.end());
        vector<vector<int>> memo(student.size(), vector<int>(cookie.size(), -1));
        return helper(0, 0, student, cookie, memo);
    }

private:
    int helper(int studentIndex, int cookieIndex, vector<int> &student, vector<int> &cookie, vector<vector<int>> &memo)
    {
        if (studentIndex >= student.size() || cookieIndex >= cookie.size())
            return 0;
        if (memo[studentIndex][cookieIndex] != -1)
            return memo[studentIndex][cookieIndex];
        int result = 0;
        if (cookie[cookieIndex] >= student[studentIndex])
            result = max(result, 1 + helper(studentIndex + 1, cookieIndex + 1, student, cookie, memo));
        result = max(result, helper(studentIndex, cookieIndex + 1, student, cookie, memo));
        return memo[studentIndex][cookieIndex] = result;
    }
};

int main()
{
    vector<int> student = {1, 2, 3};
    vector<int> cookie = {1, 1};
    Solution solver;
    int result = solver.findContentChildren(student, cookie);
    cout << "Maximum number of content Student: " << result << endl;
}