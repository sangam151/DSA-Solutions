// Find the median from data stream
#include <bits/stdc++.h>
using namespace std;
class MedianFinder
{
private:
    vector<int> nums;

public:
    MedianFinder()
    {
    }
    void addNum(int num)
    {
        nums.push_back(num);
    }
    double findMedian()
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        if (n % 2 == 1)
        {
            return nums[n / 2];
        }
        return (nums[n / 2 - 1] + nums[n / 2] / 2.0);
    }
};
int main()
{
    MedianFinder mf;
    mf.addNum(1);
    mf.addNum(2);
    mf.addNum(3);
    cout << mf.findMedian() << endl;
    return 0;
}