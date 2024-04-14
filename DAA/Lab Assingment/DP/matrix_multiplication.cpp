#include <iostream>
#include <vector>
using namespace std;

int matrix_chain_multiplication(vector<int>& p)
 {
    int n = p.size() - 1;
    vector<vector<int> > dp(n, vector<int>(n, 0));
    for (int i = 1; i < n; i++) 
    {
        for (int j = 0; j < n - i; j++) 
        {
            dp[j][j + i] = INT_MAX;
            for (int k = j; k < j + i; k++) 
            {
                dp[j][j + i] = min(dp[j][j + i], dp[j][k] + dp[k + 1][j + i] + p[j] * p[k + 1] * p[j + i + 1]);
            }
        }
    }
    return dp[0][n - 1];
}

int main() {
    vector<int> p;
    int n;
    cout << "Enter the size of the vector: ";
    cin >> n;
    for (int i = 0; i < n; i++) 
    {
        int val;
        cout << "Enter value for element " << i << ": ";
        cin >> val;
        p.push_back(val);
    }
    int ans = matrix_chain_multiplication(p);
    cout << "Minimum number of scalar multiplications: " << ans << endl;
    return 0;
}
