// Area of largest rectangle by optimal approach 1
#include <bits/stdc++.h>
using namespace std;
int largestArea(vector<int> &arr, int n)
{
    stack<int> st;
    int maxArea = 0;
    arr.push_back(0);
    for (int i = 0; i < arr.size(); i++)
    {
        while (!st.empty() && arr[i] < arr[st.top()])
        {
            int height = arr[st.top()];
            st.pop();
            int width = st.empty() ? i : i - st.top() - 1;
            maxArea = max(maxArea, height * width);
        }
        st.push(i);
    }
    return maxArea;
}
int main()
{
    vector<int> arr = {2, 1, 5, 6, 2, 3, 1};
    int n = 7;
    cout << "The largest area in the histogram is " << largestArea(arr, n) << endl;
    return 0;
}
