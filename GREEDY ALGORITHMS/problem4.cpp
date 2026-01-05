// Lemonade Change || By Greedy Approach
#include <bits/stdc++.h>
using namespace std;
class LemonadeStand
{
public:
    bool lemonadeChange(vector<int> &bills)
    {
        int five = 0;
        int ten = 0;
        for (int bill : bills)
        {
            if (bill == 5)
            {
                five++;
            }
            else if (bill == 10)
            {
                if (five > 0)
                {
                    five--;
                    ten++;
                }
                else
                {
                    return false;
                }
            }
            else
            {
                if (five > 0 && ten > 0)
                {
                    five--;
                    ten--;
                }
                else if (five >= 3)
                {
                    five -= 3;
                }
                else
                    return false;
            }
        }
        return true;
    }
};
int main()
{
    vector<int> bills = {5, 5, 5, 10, 20};
    cout << "Queueof customers: ";
    for (int bill : bills)
        cout << bill << " ";
    cout << endl;
    LemonadeStand stand;
    bool ans = stand.lemonadeChange(bills);
    if (ans)
    {
        cout << "It is possible to provide change for all customers." << endl;
    }
    else
    {
        cout << "It is not possible to provide change for all customers" << endl;
    }
    return 0;
}