/*
You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.
Return the fewest number of coins that you need to make up that amount. 
If that amount of money cannot be made up by any combination of the coins, return -1.
You may assume that you have an infinite number of each kind of coin.

Example 1
Input: 
    coins = [1,2,5]
    amount = 11
Output: 3
Explanation: 
11 = 5 + 5 + 1

Example 2
Input: 
    coins = [2]
    amount = 3
Output: -1

Example 3
Input: 
    coins = [1]
    amount = 0
Output: 0
*/

#include <stdio.h>
#include <stdlib.h>

int min(int a, int b) {
    return a < b ? a : b;
}

int coinChange(int* coins, int coinsSize, int amount) {
    int* dp = (int*)malloc(sizeof(int) * (amount + 1));

    for (int i = 0; i <= amount; i++) {
        dp[i] = amount + 1;
    }

    dp[0] = 0;

    for (int i = 1; i <= amount; i++) {
        for (int j = 0; j < coinsSize; j++) {
            if (coins[j] <= i) {
                dp[i] = min(dp[i], dp[i - coins[j]] + 1);
            }
        }
    }

    int result = (dp[amount] > amount) ? -1 : dp[amount];
    free(dp);

    return result;
}