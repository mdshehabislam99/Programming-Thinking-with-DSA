#include<bits/stdc++.h>
using namespace std;

int knapsack(int W, vector<int>& wt, vector<int>& val, int n) {
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int w = 1; w <= W; w++) {
            if (wt[i - 1] <= w) {
                dp[i][w] = max(dp[i - 1][w], val[i - 1] + dp[i - 1][w - wt[i - 1]]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    return dp[n][W];
}

int main() {
    int W = 50; // Maximum weight of knapsack
    vector<int> wt = {10, 20, 30}; 
    vector<int> val = {50, 100, 120}; 
    int n = wt.size(); // Number of items

    cout << "Maximum value in Knapsack = " << knapsack(W, wt, val, n) << endl;

    return 0;
}