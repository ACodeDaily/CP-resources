#include "bits:stdc++.h"
using namespace std;





/// ===================YOUR CODE GOES HERE!=====================





class Solution
{
public:
    int minStoneSum(vector<int> &piles, int k)
    {
        priority_queue<int> heaps;      // a max heap!  
        for (auto &pile : piles)
            heaps.push(pile);

        while (k--)
        {
            int maxPile=heaps.top();
            heaps.pop();
            heaps.push((maxPile + 1) / 2);
        }
        int sum = 0;
        while (heaps.size())
        {
            sum += heaps.top();
            heaps.pop();
        }
        return sum;
    }
};


// ==========================================================================











int main()
{
    freopen("input.txt", "r" , stdin);
    freopen("output.txt", "w", stdout);      
    int t = 0;
    cin >> t;
    while (t--)
    {
        int n = 0;
        cin>>n;
        vector<int> vec(n, 0);
        for (auto &i : vec)
            cin >> i;
        int k = 0;
        cin >> k;
        Solution sol = Solution();
        int res = sol.minStoneSum(vec, k);
        cout<<res<< "\n";
    }
}
