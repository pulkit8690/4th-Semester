#include <bits/stdc++.h>
using namespace std;

int minCoins(int coins[], int n, int amount)
{
    int dp[amount+1];
    dp[0] = 0;

    for(int i=1;i<=amount;i++)
    {
        dp[i] = INT_MAX;
        for(int j=0;j<n;j++)
        {
            if(coins[j]<=i)
            {
                int sub_res = dp[i-coins[j]];
                if(sub_res!=INT_MAX && sub_res+1<dp[i])
                    dp[i] = sub_res+1;
            }
        }
    }

    return dp[amount];
}

int main()
{
    int coins[] = {1,5,10,25};
    int n = sizeof(coins)/sizeof(coins[0]);
    int amount = 30;

    cout << "Minimum number of coins required: " << minCoins(coins,n,amount);

    return 0;
}
