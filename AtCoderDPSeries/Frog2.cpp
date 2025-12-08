#include<bits/stdc++.h>

void solve(){
    int n, k;
    std::cin>>n;
    std::cin>>k;

    std::vector<int> stones(n);
    for(int i = 0; i < n; ++i){
        std::cin>> stones[i];
    }
    // main operation
    std::vector<int> dp(n);
    // base case
    dp[0] = 0; // no cost at first stone

    // dp for 1 upto n - 1
    for(int i = 1; i < n; ++i){
        dp[i] = 1e18; // initialised to a very large value

        //inner loop for j backwards
        for(int j = 1; j <= k; ++j){
            if(i - j >= 0){
                dp[i] = std::min(dp[i], dp[i - j] + std::abs(stones[i] - stones[i - j]));
            }
        }
    }

    
    std::cout<<dp.back()<<"\n";

}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    // soln here 
    solve();
    
    return 0;
}
/*
dp[i] = min cost to reach stone i
Take min of possible previous jumps + their cost
*/

/*
Dynamic Programming (Frog k-step problem)

dp[i] = minimum cost to reach stone i

- Base case:
    dp[0] = 0 // first stone has no cost

- Recurrence:
    For each stone i (from 1 to n-1), 
    check all possible previous jumps j = 1..k:
        if i - j >= 0:
            dp[i] = min(dp[i], dp[i-j] + abs(stones[i] - stones[i-j]))

- Explanation:
    The frog can jump from any of the previous k stones to the current stone i.
    Each jump has a cost = |height difference|.
    We take the minimum of all possible jumps to fill dp[i].

- Result:
    dp[n-1] gives the minimum cost to reach the last stone.
*/
